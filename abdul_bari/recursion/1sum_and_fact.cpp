#include<bits/stdc++.h>
using namespace std;
int sum(int n)
{
    if(n>0)
    {
        return sum(n-1)+n;
    }
    return 0;
}
int fact(int n)
{
    if(n>0)
    {
        return fact(n-1)*n;
    }
    return 1;
}
int main()
{
    cout << sum(5);
    cout << "\n" << fact(5);
}
