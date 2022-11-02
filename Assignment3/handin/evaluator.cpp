#include "Stack.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std; 

int evaluate(string expression) {
    Stack<int> operand;
    Stack<char> operation;

    stringstream exp(expression);
    string c;

    while (exp >> c) {
        if (c != " " && c != "(")
        {
            if(c == ")")
            {
                int a = operand.pop();
                int b = operand.pop();
                char op = operation.pop();

                if (op == '*')
                {
                    operand.push(a * b);
                }
                else if (op == '+')
                {
                    operand.push(a + b);
                }
                else if (op == '/')
                {
                    operand.push((int)(b / a));
                }
                else if (op == '-')
                {
                    operand.push(b - a);
                }
            }
            else if (c == "+" || c == "*" || c == "/" || c == "-")
            {
                operation.push(c[0]);
            }
            else if (c != "+" && c != "*" && c != "/" && c != "-")
            {
                operand.push(stoi(c));
            }
        }
    }

    while(!operation.isEmpty())
    {
        int a = operand.pop();
        int b = operand.pop();
        char op = operation.pop();

        if (op == '*')
        {
            operand.push(a * b);
        }
        else if (op == '+')
        {
            operand.push(a + b);
        }
        else if (op == '/')
        {
            operand.push((int)(b / a));
        }
        else if (op == '-')
        {
            operand.push(b - a);
        }
    }

    return operand.pop();
} 


//added bracket, could not figure out how it should work without them in time
int main() { 
    cout << evaluate("( 2 * 4 ) + 8") << "\n"; //= 16
    cout << evaluate("( 12 / 2 ) - 2") << "\n"; //= 4
    cout << evaluate("( 3 + 4 ) * ( ( 15 / 5 ) + ( 0 * 3 ) )") << "\n"; //= 21
    cout << evaluate("( 3 + 4 ) * ( ( 15 / 5 ) +  ( ( 0 * 3 ) )") <<"\n"; //= 21
    return 0; 
} 
