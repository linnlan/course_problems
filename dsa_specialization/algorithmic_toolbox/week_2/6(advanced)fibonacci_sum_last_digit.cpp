#include <iostream>
using namespace std;
int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}
int fib_sum(long long n)
{   
    if(n<=1)
        return n;
    long long previous = 0;     //since we have to find the last digit of the fib, we have to do mod by 10
    long long current = 1;      //since pisano period of 10 is 60, the last digit of fib mod 10 is periodic
    long long res;              //so we have to just find the remainder and find the fib of that rem and mod by 10
    int rem=n%60;               //i have found series of sum_of_fib rather than fib
    for(int i=0;i<rem-1;i++)    //sum_of_fib like fib, for index=0 is 0(stored in previous) and index=1 is 1(stored in current)
    {                           //for subsequent indices, it is sum_of_fib(n-2)+sum_of_fib(n-1)+1=previous+current+1=res=sum_of_fib(n)
        res=previous+current+1; //like for n=4, sum_of_fib(4)=7, so viz is equal to sum_of_fib(2)+sum_of_fib(3)+1=2+4+1=7      
        previous=current;       //another approach could have been the sum_of_fib(n)=fib(n+2)-1
        current=res;            //so we could just find fib(n+2)-1 and mod by 10
                                //but the approach i used was original so i used that
    }
    return res%10;
}

int main() {
    /*while(true)
    {
        int n = rand()%100000000000000;
        cout << n << "\n";
        int res1=fibonacci_sum_naive(n);
        int res2=fib_sum(n);
        if(res1!=res2)
        {
            cout << "Wrong answer: " << res1 << " " << res2;
            break;
        }
        else
        {
            cout << "OK" << "\n";
        }
        
    }*/
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n);
    cout << fib_sum(n);
}
