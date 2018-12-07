#include <bits/stdc++.h>

using namespace std;

stack<int> st;

int main() {
  int test;
  cin >> test;

  while (test--) {
    int n;
    cin >> n;

    int ans = 0;

    while (n != 0) {
      int candidate = __builtin_popcount(n);

      ans = max(ans, candidate);
      n /= 10;
    }

    cout << ans << endl;
  }

  return 0;
}