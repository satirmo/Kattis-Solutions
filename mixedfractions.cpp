#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b;

  while (cin >> a >> b, a != 0) {
    long long whole = a / b;
    long long num = a % b;
    long long den = b;

    printf("%lld %lld / %lld\n", whole, num, den);
  }

  return 0;
}