#include<bits/stdc++.h>
using namespace std;
double e(int x, int n)      //recursive approach
{   static double s{1};     //Time - O(n)
    if(n==0)
        return s;
    s=1+x*s/n;
    return e(x,n-1);
}
double e_itr(int x,int n)   //iterative approach
{   double s {1};
    for(;n>0;n--)
    {
        s=1+x*s/n;
    }
    return s;
}
int main()
{
    cout << e(2,3) << " " << e_itr(2,3);
}