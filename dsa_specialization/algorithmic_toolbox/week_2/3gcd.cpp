#include <iostream>
#include <algorithm>
using namespace std;

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}
int gcd_fast(int a, int b)
{
  int nume, deno,rem;
  nume=max(a,b);
  deno=min(a,b);
  rem=nume%deno;
  while(rem!=0)
  {
    nume=deno;
    deno=rem;
    rem=nume%deno;
  }
  int gcd=deno;
  return gcd;
}
int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
