#include <iostream>
using namespace std;
long long pisano_period(long long m)    //calculates pisano period
{
    long long a {0},b{1},c {a+b};
    for(long long i=1;i<m*m;i++)        //upper bound of pisano period is m*m, written in onlineMOOC book as a challengebreak
    {                                   
        c=(a+b)%m;                      //this loop finds fib mod m as in i=1, it finds fib mod m for indices 1 and 2 and stores in a and b. 
        a=b;                            //it does not find fib mod m for index 0 as it would satisfy if condition and loop would break, so iteration starts wud stop at i=1
        b=c;                            //it finds the period in nth iteration and since i starts from 1 only, it returns i
        if(a==0 && b==1)                 //likewise for i=2, compares for indices 2 and 3
            return i;
    }
}
long long get_fib(long long n, long long m)
{
    long long rem = n % pisano_period(m);
    long long first {0}, second {1};
    long long res;
    for(long long i=2;i<=rem;i++)
    {   
        res=(first + second)%m;               //this is fib mod m for i=2 (for the first iteration)
        first=second;                         //inputting variables first, second for the next iteration
        second=res;
    }
    return res%m;
}
int main()
{
    long long n, m;
    cin >> n >> m;
    cout << get_fib(n,m) << "\n";
}