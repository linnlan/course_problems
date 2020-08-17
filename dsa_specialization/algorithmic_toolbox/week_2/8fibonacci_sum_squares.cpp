#include <iostream>
using namespace std;
int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}
int get_fib(long long n)
{
    if(n<=1)
        return n;
    int rem=n%60;
    long long prev=0;
    long long curr=1;
    long long res;
    for(int i=0;i<rem-1;i++)
    {
        res=prev+curr;
        prev=curr;
        curr=res;
    }
    return res%10;
}
int fib_sum_square(long long n)
{
    return (get_fib(n)*get_fib(n+1))%10;
}

int main() {
    /*while(true)
    {
        long long n = rand()%100000000000000;
        cout << n << "\n";
        int res1=fibonacci_sum_squares_naive(n);
        int res2=fib_sum_square(n);
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
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_squares_naive(n);
    cout<<fib_sum_square(n) << "\n";
}
