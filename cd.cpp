#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000005;

int a[maxn], b[maxn];

int main() {
  int n, m;

  while (cin >> n >> m) {
    if (n == 0 && m == 0) {
      break;
    }

    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }

    for (int i = 0; i < m; i++) {
      scanf("%d", &b[i]);
    }

    sort(a, a + n);
    sort(b, b + m);

    int ans = 0;

    for (int i = 0, j = 0; i < n && j < m;) {
      if (a[i] == b[j]) {
        ans++;
        i++, j++;
      }

      else if (a[i] < b[j]) {
        i++;
      }

      else {
        j++;
      }
    }

    cout << ans << endl;
  }

  return 0;
}