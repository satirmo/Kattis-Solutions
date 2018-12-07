#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007LL;

long long TrueMod(long long x) {
  while (x < 0LL) {
    x += mod;
  }

  return x % mod;
}

long long CalculateNumbers(long long p) {
  long long base = 9LL;
  long long ret = 1LL;

  while (p != 0LL) {
    if (p % 2LL == 1LL) {
      ret = TrueMod(ret * base);
    }

    base = TrueMod(base * base);
    p >>= 1;
  }

  return ret - 1LL;
}

int main() {
  int test;
  cin >> test;

  while (test--) {
    long long d;
    cin >> d;

    long long ans = TrueMod(CalculateNumbers(d) - CalculateNumbers(d - 1));
    cout << ans << endl;
  }

  return 0;
}