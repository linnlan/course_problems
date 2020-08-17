#include<bits/stdc++.h>
using namespace std;
int F[10];
int fib_naive(int n)    //Time - O(2**n)
{
    if(n<=1)
        return n;
    if(n>1)
        return fib_naive(n-2)+fib_naive(n-1); 
}
int fib(int n)  //using memoisation
{               //Time - O(n)
    if(n<=1)
    {
        F[n]=n;
        return n;
    }
        if(F[n-2]==-1)
            F[n-2]=fib(n-2);
        if(F[n-1]==-1)
            F[n-1]=fib(n-1);
        F[n]=F[n-2]+F[n-1];
        return F[n];

}
int fib_itr(int n) //iterative approach
{   int prev=0, curr=1, s= 1;
    if(n<=1)
        return n;
    for(int i=2;i<=n;i++)
    {
        s=prev+curr;
        prev=curr;
        curr=s;
    }  
    return s; 

}
int main()
{   int i;
    for(i=0;i<10;i++)
        F[i]=-1;
    cout << fib_naive(6);
    cout << "\n" << fib(6);
    cout << "\n" << fib_itr(6);

	return 0;
}