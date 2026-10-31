#include <iostream>
#include <string>
#include "stacktype.h"

using namespace std;

bool isMatchingPair(char c1, char c2);
bool validParenthesis(string text);

bool validParenthesis(string text)
{
    StackType<char> charStack;
    try
    {
        for (int i = 0; i < text.length(); i++)
        {
            if (text.at(i) == '(' || text.at(i) == '{' || text.at(i) == '[' || text.at(i) == '<')
            {
                charStack.push(text.at(i));
            }
            else if (text.at(i) == ')' || text.at(i) == '}' || text.at(i) == ']' || text.at(i) == '>')
            {
                if (charStack.isEmpty())
                {
                    return false;
                }
                char c1 = charStack.top();
                char c2 = text.at(i);
                if (!(isMatchingPair(c1, c2)))
                {
                    return false;
                }
                else
                {
                    charStack.pop();
                }
            }
        }
    }
    catch (FullStack)
    {
        cout << "Stack Full!" << endl;
        return false;
    }
    catch (EmptyStack)
    {
        cout << "Stack Empty!" << endl;
        return false;
    }

    if (!(charStack.isEmpty()))
    {
        return false;
    }

    return true;
}

bool isMatchingPair(char c1, char c2)
{
    if (c1 == '(' && c2 == ')')
    {
        return true;
    }
    else if (c1 == '{' && c2 == '}')
    {
        return true;
    }
    else if (c1 == '[' && c2 == ']')
    {
        return true;
    }
    else if (c1 == '<' && c2 == '>')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string paranthesis;
    cin >> paranthesis;

    if (validParenthesis(paranthesis))
    {
        cout << "Valid set of parenthesis!";
    }
    else
    {
        cout << "Invalid set of parenthesis!";
    }
    return 0;
}