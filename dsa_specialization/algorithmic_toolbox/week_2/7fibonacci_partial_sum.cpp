#include <iostream>
#include <vector>
using namespace std;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}
int get_fib(long long n)
{   
    if(n<=1)
        return n;
    long long previous = 0;     //since we have to find the last digit of the fib, we have to do mod by 10
    long long current = 1;      //since pisano period of 10 is 60, the last digit of fib mod 10 is periodic
    long long res;              //so we have to just find the remainder and find the fib of that rem and mod by 10
    int rem=n%60;               
    for(int i=0;i<rem-1;i++)    
    {                           
        res=previous+current; 
        previous=current;       
        current=res;            
                                
    }
    return res%10;
}
int get_fib_partial(long long from, long long to)   //approach is sum_of_fib(n)=fib(n+2)-1
{                                                   //partial_sum_fib(m,n)=fib(m)+fib(m+1)...+fib(n)
    int res;                                        //=fib(0)+fib(1)+...+fib(n)-[fib(0)+fib(1)...+fib(m-1)]=fib(n+2)-fib(m+1) //m-1+2
    res=(get_fib(to+2)+10-get_fib(from+1))%10;      //plus 10 is done cuz if last digit of the fib(n+2)//is smaller than last digit of
}                                                   //fib(m+1) then it will not return absurd results

int main() {
    /*while(true)
    {
        int n=rand()%100000000000000;
        int m=rand()%100000000000000;
        cout << n << " " << m;
        int res1=get_fibonacci_partial_sum_naive(n,m);
        int res2=get_fib_partial(n,m);
        if(res1!=res2)
        {
            cout << "Wrong answer: " << res1 << " " << res2;
            break;
        }
        else
        {
            cout << "OK";
        }
        
    }*/
    long long from, to;
    std::cin >> from >> to;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    cout << get_fib_partial(from,to);
    
}
