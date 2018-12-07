#include <bits/stdc++.h>

using namespace std;

const int maxn = 25;

int a[maxn];

int main() {
  int test;
  cin >> test;

  while (test--) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    sort(a, a + n);

    int ans = 2 * (a[n - 1] - a[0]);
    cout << ans << endl;
  }

  return 0;
}