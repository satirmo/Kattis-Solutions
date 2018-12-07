#include <bits/stdc++.h>

using namespace std;

long long ModExp(long long b, long long p, long long m) {
  long long ret = 1LL;
  long long mult = b;

  while (p > 0) {
    if (p & 1) {
      ret = (ret * mult) % m;
    }

    mult = (mult * mult) % m;
    p >>= 1;
  }

  return ret;
}

int main() {
  long long a, b;
  cin >> a >> b;

  long long ans = (a % 2LL == 1LL) ? 0LL : ModExp(a / 2LL, b, a);
  cout << ans << endl;

  return 0;
}