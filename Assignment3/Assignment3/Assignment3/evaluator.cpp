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
                    cout << "operand push *" << endl;
                    operand.push(a * b);
                }
                else if (op == '+')
                {
                    cout << "operand push +" << endl;
                    operand.push(a + b);
                }
                else if (op == '/')
                {
                    cout << "operand push /" << endl;
                    operand.push(b / a);
                }
            }
            else if (c == "+" || c == "*" || c == "/")
            {
                cout << "operation push" << endl;
                int n = c.length();
                char* temp = new char[n+1];
                strcpy(temp, c.c_str());
                operation.push(temp[0]);
            }
            else if (c != "+" && c != "*" && c != "/")
            {
                cout << "operand push number" << endl;
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
            cout << "operand push *" << endl;
            operand.push(a * b);
        }
        else if (op == '+')
        {
            cout << "operand push +" << endl;
            operand.push(a + b);
        }
        else if (op == '/')
        {
            cout << "operand push /" << endl;
            operand.push(b / a);
        }
    }

    return operand.pop();
} 


//added bracket, could not figure out how it should work without them in time
int main() { 
    cout << evaluate("(2 * 4) + 8") << "\n"; //= 16
    cout << evaluate("(12 / 2) - 2") << "\n"; //= 4
    cout << evaluate("( 3 + 4 ) * ( ( 15 / 5 ) + ( 0 * 3 ) )") << "\n"; //= 21
    cout << evaluate("( 3 + 4 ) * (( 15 / 5 ) +  (( 0 * 3 ))") <<"\n"; //= 21
    return 0; 
} 
