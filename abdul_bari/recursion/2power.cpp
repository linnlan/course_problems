#include<bits/stdc++.h>
using namespace std;
int power(int x,int n)
{
    if(n==0)
        return 1;
    if(n%2)
        return x*power(x*x,n/2);
    if(n%2==0)
    {
        return power(x*x,n/2);
    }
}
int main()
{
    cout << power(2,9);
}