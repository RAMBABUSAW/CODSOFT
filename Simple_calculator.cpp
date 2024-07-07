#include<iostream>
using namespace std;
int main()
{
    double num1,num2 ;
    char operation ;

    cout<<"Enter the first number :";
    cin>>num1;
    cout<<"Enter the operation (+,-,*,/) :";
    cin>>operation ;
    cout<<"Enter teh second number :";
    cin>>num2;

    switch(operation )
    // The program uses a 'switch' statement to determine which operation to perform based on the input operator.
    {
        case  '+':
        cout<<"Result :"<<num1 + num2<<endl;
        break;

        case  '-':
        cout<<"Result :"<<num1 - num2<<endl;
        break;

        case  '*':
        cout<<"Result :"<<num1 * num2<<endl;
        break;

        case  '/':
        if (num2 !=0)
        {
        cout<<"Result :"<<num1 / num2<<endl;
        }
        else
        {
            cout<<"Error : Devision by zero is not allowed :"<<endl;

        }
        break;

        default :
            cout<<"Error :Invalid open :";

             
    }

    return 0;
}

