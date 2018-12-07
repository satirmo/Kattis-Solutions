#include <bits/stdc++.h>

using namespace std;

int main() {
  int test;
  cin >> test;

  while (test--) {
    int k;
    cin >> k;

    int ans = (1 << k) - 1;
    cout << ans << endl;
  }

  return 0;
}