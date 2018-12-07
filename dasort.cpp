#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

int a[maxn], b[maxn];

int main() {
  int test;
  cin >> test;

  while (test--) {
    int t, n;
    cin >> t >> n;

    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }

    int ans = 0;
    sort(b, b + n);

    for (int i = 0, j = 0; i < n; i++) {
      if (a[i] == b[j]) {
        j++;
      }

      else {
        ans++;
      }
    }

    printf("%d %d\n", t, ans);
  }

  return 0;
}