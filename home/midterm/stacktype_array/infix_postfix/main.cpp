#include <iostream>
#include <string>
#include <cctype>
#include "stacktype.h"

using namespace std;

int getOperatorPresedence(char op);
string infixToPostfix(string infix);

int getOperatorPresedence(char op)
{
    if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '-' || op == '+')
    {
        return 1;
    }
    return 0;
}

string infixToPostfix(string infix)
{
    StackType<char> operatorStack;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char current = infix.at(i);

        if (current == ' ')
        {
            continue;
        }
        else if (isalnum(current))
        {
            while(i < infix.length() && isalnum(infix.at(i))){
                postfix += infix.at(i);
                i++;
            }
            postfix += " ";
            i--;
        }
        else if (current == '(')
        {
            operatorStack.push(current);
        }
        else if (current == ')')
        {
            while (!(operatorStack.isEmpty()) && operatorStack.top() != '(')
            {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.isEmpty())
            {
                operatorStack.pop(); //popping the '('
            }
        }

        else
        {
            while (!(operatorStack.isEmpty()) && operatorStack.top() != '(' && getOperatorPresedence(operatorStack.top()) >= getOperatorPresedence(current))
            {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(current);
        }
    }
    while (!operatorStack.isEmpty())
    {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main()
{
    string infix;
    cout << "Enter infix Mathematical expression: ";

    getline(cin, infix);

    string postfix = infixToPostfix(infix);

    cout << '\n';
    cout << postfix;
    return 0;
}