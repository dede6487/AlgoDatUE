#include "Stack.h"
#include <iostream>
#include <string>
using namespace std; 

int precedence(char op){ 
	if (op == '+' || op == '-') 
		return 1; 
	if (op == '*' || op == '/') 
		return 2; 
	return 0; 
} 
  
int applyOperator (int a, int b, char op) { 
	switch(op){ 
		case '+': return a + b; 
		case '-': return a - b; 
		case '*': return a * b; 
		case '/': return a / b; 
	} 
} 
  
int evaluate(string expression) { 
	int i;

	Stack <int> operands;
	Stack <char> operators;
	bool isOperator = false;
	short sign = 1;

	for(i = 0; i < expression.length(); i++) {
		//nothing to do
		if (expression[i] == ' ') 
			continue;
		// '(' gets pushed to the operators stack
		else if (expression[i] == '(') { 
			operators.push(expression[i]); 
			isOperator = false;
		}
		// collect all digits and push the number to the operands stack
		else if (isdigit(expression[i])) { 
			int val = 0; 
			while(i < expression.length() &&  isdigit(expression[i])) { 
				val = (val * 10) + (expression[i]-'0'); 
				i++;
			}
			i--;
			val *= sign;
			sign = 1;
			isOperator = true;
			operands.push(val);
		}
		// evaluate what is inside ()
		else if (expression[i] == ')') { 
			while (!operands.isEmpty() && operators.top() != '(') { 
				int val2 = operands.pop(); 
				int val1 = operands.pop(); 
				char op = operators.pop(); 
				  
				operands.push(applyOperator(val1, val2, op)); 
			} 
			operators.pop(); // for '('
			isOperator = true;
		}
		else if (!isOperator && expression[i] == '-')
			sign *= -1;
		else { 
			// Operators
			// If the current one has smaller or equal precedence, we should evaluate what is already in the stack
			while (!operators.isEmpty() && precedence(operators.top()) >= precedence(expression[i])) { 
				int val2 = operands.pop(); 
				int val1 = operands.pop(); 
				char op = operators.pop(); 

				operands.push(applyOperator(val1, val2, op)); 
				isOperator = false;
			} 
			operators.push(expression[i]); 
		}
	}
//} 
	// evaluate the expression remaining in the stack	
	while (!operators.isEmpty()){ 
		int val2 = operands.pop(); 
		int val1 = operands.pop(); 
		char op = operators.pop(); 
			  
		operands.push(applyOperator(val1, val2, op)); 
	} 

	// the final result is on top of the stack
	return operands.top(); 	
} 
  
int main() { 
    cout << evaluate("8 / 2 + 4 / 4 + (5 * 2) * 3") << "\n";
    cout << evaluate("2 * 4 + 8") << "\n"; 
    cout << evaluate("12 / 2 - 2") << "\n"; 
    cout << evaluate("-12 / 2 - 2") << "\n"; 
    cout << evaluate("12 / (-2) - 2") << "\n"; 
    cout << evaluate("( 3 + 4 ) * ( ( 15 / 5 ) + ( 0 * 3 ) )") << "\n"; 
    cout << evaluate("( -3 + 4 ) * ( ( 15 / 5 ) + ( 0 * 3 ) )") << "\n"; 
    cout << evaluate("( 3 + 4 ) * ( 15 / 5 + 0 * 3 )") << "\n"; 
    cout << evaluate("4 * ( 15 / 5 + 0 * 3 ) - 2") << "\n";
    cout << evaluate("2 - ( 10 * 4 ) / ( 2 * 2 ) - 1") << "\n";
    return 0; 
} 
