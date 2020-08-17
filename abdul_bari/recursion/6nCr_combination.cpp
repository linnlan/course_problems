#include<bits/stdc++.h>
using namespace std;
int nCr(int n,int r)                    //using Pascal's triangle
{                                       //or nCr= n-1 C r-1 + n-1 C r
    if(r==0||r==n)
        return 1;
    return nCr(n-1,r)+nCr(n-1,r-1);
}
int main()
{   cout << nCr(4,2);
	return 0;
}