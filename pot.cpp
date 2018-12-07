#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  while (cin >> n) {
    long long ans = 0;

    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;

      long long base = x / 10LL;
      long long exp = x % 10LL;

      long long t = 1LL;
      for (int i = 1; i <= exp; i++) {
        t *= base;
      }

      ans += t;
    }

    cout << ans << endl;
  }

  return 0;
}