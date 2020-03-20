#include<iostream>
#include<string>
#include<conio.h>
#include <stack>

using namespace std;

//used to determine the precedence of the operators
int op_prec(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}
//used to apply the operator to the two opperand
float op_eval(float x, float y, char op)
{
    switch(op)
    {
    case '+': return float(x + y);
        break;
    case '-': return float(x - y);
        break;
    case '*': return float(x * y);
        break;
    case '/': return float(x / y);
        break;
    }
    return 0;
}

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

        else {
            if (oper.empty())
                oper.push(x[i]);
            else {

                while (!oper.empty() && op_prec(oper.top()) >= op_prec(x[i])) {
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
    char x[100];
        cout << "enter arithmetic expression:(max 100 characters)";
        cin.getline(x, 100);
        for (int n = 0; x[n] != NULL; ++n)
            size++;
        float result = tokens_eval(x,size);
        cout << "answer is:" << result;
        return 0;
}