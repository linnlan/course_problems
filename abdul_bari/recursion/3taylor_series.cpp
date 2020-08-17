#include<bits/stdc++.h>
using namespace std;
double e(int x,int n)
{   static double p {1}, f {1};
   if(n==0)
        return 1;
   if(n>0)
    {   double r= e(x,n-1); //first call it then operate on it
        p=p*x;              //Time - O(n*n)
        f=f*n;
        return r+p/f;

    }

}
int main()
{  cout << e(2,3);
	return 0;
}
