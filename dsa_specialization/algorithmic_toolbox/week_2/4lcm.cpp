#include <iostream>
#include <algorithm>
using namespace std;
long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}
long long lcm_fast(int a, int b)
{
  int nume, deno, rem;
  nume=max(a,b);
  deno=min(a,b);
  rem=nume%deno;
  while(rem!=0)
  {
    nume=deno;
    deno=rem;
    rem=nume%deno;
  }
  long long lcm= static_cast <long long> (a)/deno * b;
  return lcm;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
