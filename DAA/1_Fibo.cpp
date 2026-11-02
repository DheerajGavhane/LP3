//Iterative method
#include<iostream>
using namespace std;

int main()
{
    int n,a=0,b=1,c;

    cout<<"Enter number of terms: ";
    cin>>n;

    cout<<"Fibonacci Series: ";
    cout<<a<<" "<<b<<" ";
    for(int i=2;i<n;i++)
    {
        c=a+b;
        a=b;
        b=c;
        cout<<c<<" ";
    }

    return 0;
}

//Recursive method
#include<iostream>
using namespace std;

int fibonacci(int n)
{
    if(n==0)
        return 0;

    if(n==1)
        return 1;

    return fibonacci(n-1)+fibonacci(n-2);
}

int main()
{
    int n;

    cout<<"Enter number of terms: ";
    cin>>n;

    cout<<"Fibonacci Series: ";

    for(int i=0;i<n;i++)
    {
        cout<<fibonacci(i)<<" ";
    }

    return 0;
}

/*Approach	Time Complexity	Space Complexity
Iterative	O(n)	O(1)
Recursive	O(2ⁿ)	O(n)
They are used in:
- Computer algorithms and Fibonacci Search.
- Financial market technical analysis.
- Mathematical modelling.
- Patterns in nature, such as certain plant arrangements and spiral patterns.
 */