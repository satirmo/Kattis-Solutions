#include <bits/stdc++.h>

using namespace std;

int main() {
  int test;
  cin >> test;

  while (test--) {
    long long prev = -1LL;
    long long n;

    long long ans = 0LL;

    while (cin >> n, n != 0) {
      if (prev == -1) {
        prev = n;
        continue;
      }

      if (2 * prev < n) {
        ans += n - 2 * prev;
      }

      prev = n;
    }

    cout << ans << endl;
  }

  return 0;
}