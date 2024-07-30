/*Write a program to evaluate a postfix expression using stacks.*/

#include <iostream>
#include "Header Files\StackArray.h"
using namespace std;

int postfixEvaluation(char *exp)
    {
        ArrayStack<char> travStack;
        int i;

        // Scan all character one by one
        for (i = 0; i <= exp[i]; ++i)
        {
            if (isdigit(exp[i]))
                travStack.push(exp[i] - '0');

            else
            {
                int val1 = travStack.top();
                travStack.pop();
                int val2 = travStack.top();
                travStack.pop();
                switch (exp[i])
                {
                case '+':
                    travStack.push(val2 + val1);
                    break;
                case '-':
                    travStack.push( val2 - val1);
                    break;
                case '*':
                    travStack.push(val2 * val1);
                    break;
                case '/':
                    travStack.push( val2 / val1);
                    break;
                }
            }
        }
        int result = travStack.top(); 
        travStack.pop();
        return result;
        
    }

int main()
{
    char exp[] = "231*+9-";
    cout<<"postfix evaluation: "<< postfixEvaluation(exp); 
    return 0;
}