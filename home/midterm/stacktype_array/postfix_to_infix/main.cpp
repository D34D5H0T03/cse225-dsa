#include <iostream>
#include <cctype>
#include <string>
#include "stacktype.h"

using namespace std;

string postfix_to_infix(string postfix);
bool isOperator(char c);

string postfix_to_infix(string postfix)
{
    StackType<string> inStack;
    try
    {
        for (int i = 0; i < postfix.length(); i++)
        {
            char c = postfix.at(i);

            if (c == ' ')
            {
                continue;
            }
            else if (isalnum(c))
            {
                string temp = "";
                while(i < postfix.length() && isalnum(postfix.at(i))){
                    temp += postfix.at(i);
                    i++;
                }
                inStack.push(temp);
                i--;
            }
            else if (isOperator(c))
            {
                string rightOperand  = inStack.top();
                inStack.pop();
                string leftOperand  = inStack.top();
                inStack.pop();

                string newString = "(" + leftOperand + " " + c + " " + rightOperand + ")";
                inStack.push(newString);
            }
            else{
                return "invalid";
            }
        }
    }catch(EmptyStack){
        return "Invalid";
    }catch(FullStack){
        return "Too many characters";
    }

    return inStack.top();
}

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return true;
    }
    return false;
}

int main()
{
    string postfix;
    cout << "Enter a postfix expression: ";
    getline(cin, postfix);

    cout << '\n';
    cout << postfix_to_infix(postfix);
}