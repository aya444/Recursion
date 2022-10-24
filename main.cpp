#include <iostream>
#include <stack>

using namespace std;

int Function(int n){
    struct Functioncall //stack Structure
    {
        int a,b,d; //local variables
        int n; //parameter variable
        int stage; //which recursion are we in
    };

    int c=0; //Initialize default Variables
    int result=0;

    stack<Functioncall> s; //Create Stack

    Functioncall Fcall; //Initialize Fcall Stack
    Fcall.n=n;
    Fcall.a=0;
    Fcall.b=0;
    Fcall.d=0;
    Fcall.stage=0;
    s.push(Fcall);


    while(true) //In place of recursion use iteration and stack
    {
        Fcall=s.top(); //get top stack and pop it with each iteration
        s.pop();

        switch(Fcall.stage)
        {
            case 0:
            {
                if(Fcall.n<=1)
                {
                    if(!s.empty())
                    {
                        result=1;//In case Stack not empty return 1 to the result to be calculated with the variabls
                    }
                    else
                    {
                        return 1; //In case Stack is empty just return 1
                    }
                }
                else
                {
                    Fcall.stage = 1; //To jump from state to other
                    s.push(Fcall);  //push to stack

                    Functioncall newFcall; //create temporary object

                    newFcall.n=Fcall.n-1; //represents the code in the recursive function that is processed before the next recursive call is made
                    newFcall.a=0; //Initialize the variables in temporary object newFcall
                    newFcall.b=0;
                    newFcall.d=0;
                    newFcall.stage=0;
                    s.push(newFcall); //push newFcall to stack
                    continue;
                }
                break;
            }
            case 1:
            {
                Fcall.stage = 2;
                Fcall.a=result+Fcall.n;
                s.push(Fcall);

                Functioncall newFcall;

                newFcall.stage=0;
                newFcall.n=Fcall.n/2;
                newFcall.a=0;
                newFcall.b=0;
                newFcall.d=0;
                s.push(newFcall);
                break;
            }
            case 2:
            {
                Fcall.stage = 3;
                Fcall.b=result*Fcall.n;
                s.push(Fcall);
                c=Fcall.n-2-(Fcall.a+Fcall.b)%2;

                Functioncall newFcall;

                newFcall.stage=0;
                newFcall.n=c;
                newFcall.a=0;
                newFcall.b=0;
                newFcall.d=0;
                s.push(newFcall);
                break;
            }
            case 3:
            {
                Fcall.d=result;


                if(!s.empty())
                {
                    result=Fcall.a+Fcall.b+Fcall.d;// In case Stack not empty return the sum of a,b,d of that stack to the next variable
                }
                else
                {
                    return Fcall.a+Fcall.b+Fcall.d;//In case Stack is empty just return result
                }
                break;
            }
        }
    }
    return result;
}

int main()
{
    for(int i=1;i<=20;i++) //Test Cases
        cout<<"F("<<i<<")= "<<Function(i)<<endl;
    return 0;
}
