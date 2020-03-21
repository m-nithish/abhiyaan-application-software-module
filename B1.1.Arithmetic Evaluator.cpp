/*
THIS PROGRAM GETS AN ARITHMETIC EXPRESSION AS INPUT IN A CHAR ARRAY OF MAXIMUM SIZE 1000
AND EVALUATES IT BY USING STACK IMPLEMENTATION (LAST IN FIRST OUT).
*/
#include<iostream>
#include<string>
#include<conio.h>
#include <stack>

using namespace std;

//used to apply the operator to the two opperand
float op_eval(float a, float b, char oper)
{
    switch(oper)
    {
    case '+': return float(a + b);
        break;
    case '-': return float(a - b);
        break;
    case '*': return float(a * b);
        break;
    case '/': return float(a / b);
        break;
    }
    return 0;
}

//used to determine the precedence of the operators
int oper_prec(char opers)
{
    if (opers == '+' || opers == '-')
        return 1;
    else if (opers == '*' || opers == '/')
        return 2;
    return 0;
}

// this function evaluates what is to be done on encountering each character in the expression given
//to be evaluated
float tokens_eval(char x[],int size)
{
    int i = 0;

    stack <float> values;
    stack <char> oper;

    for (; i < size; i++)
    {
        if (x[i] == ' ')
            continue;

        else if (x[i] == '(')
            oper.push(x[i]);	

//converts the number when encountered from string to int
        else if (isdigit(x[i]))
        {
            float num = 0;
            while (i < size && isdigit(x[i]))
            {
                num= num*10+ (x[i] - '0');
                i++;
            }
            i--;
            values.push(num);

//pops elements and evaluates them and pushes them back into the stack on encountering
//a closing bracket
        }
        else if (x[i] == ')')
        {
            while (!oper.empty() && oper.top() != '(') {
                float val1 = values.top();
                values.pop();
                float val2 = values.top();
                values.pop();
                char op = oper.top();
                oper.pop();
                values.push(op_eval(val2, val1, op));
            }
            if (!oper.empty())
                oper.pop();
         }
//evaluates operators based on precedence once an operator is encountered
        else {
            if (oper.empty())
                oper.push(x[i]);
            else {

                while (!oper.empty() && oper_prec(oper.top()) >= oper_prec(x[i])) {
                    float val1 = values.top();
                    values.pop();
                    float val2 = values.top();
                    values.pop();
                    char op = oper.top();
                    oper.pop();
                    values.push(op_eval(val2, val1, op));
                }
                oper.push(x[i]);

            }
            
        }
        
    }
//evaluates the remaining expression once all brackets have have been dealt with
    while (!oper.empty()) {
        float val1 = values.top();
        values.pop();
        float val2 = values.top();
        values.pop();
        char op = oper.top();
        oper.pop();
        values.push(op_eval(val2, val1, op));
    }

    return values.top();
}

int main() {
    int size=0;
    char input[1000];  //we assume a maximum size of the input expression to be 100
        cout << "enter arithmetic expression:(max 1000 characters)";
        cin.getline(input, 1000);
        for (int n = 0; input[n] != NULL; ++n)
            size++;
        float result = tokens_eval(input,size);
        cout << "answer is:" << result;
        return 0;
}