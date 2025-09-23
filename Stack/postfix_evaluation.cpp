//Evaluation of postfix Expression 
#include<stack>
#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

float evaluate_postfix(string exp)
{
    stack<float>s;
    for(int i=0; i<exp.length(); i++)
    {
        char c=exp[i];
        if (c>='0' && c<='9')
        {
            s.push(c-'0');	
        }
        else{
            float num2=s.top();
            s.pop();
            float num1=s.top();
            s.pop();
            switch(c)
            {
                case '+':
                    s.push(num1+num2);
                    break;
                case '-':
                    s.push(num1-num2);
                    break;
                case '*':
                    s.push(num1*num2);
                    break;
                case '/':
                    s.push(num1/num2);
                    break;
            }
        }	
    }
    
    return s.top();
}
int main()
{
    string exp0="65*";
    float outp0=evaluate_postfix(exp0);
    cout<<outp0<<endl;
    
    string exp1="532/15+*+7-";
    float outp1=evaluate_postfix(exp1);
    cout<<outp1<<endl;
    
    string exp2="56*32*+93/-79*21/-+";
    float outp2=evaluate_postfix(exp2);
    cout<<outp2<<endl;

    getch();
    return 0;

}