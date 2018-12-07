#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

long long a[maxn], b[maxn], c[maxn];

int main() {
  int test;
  cin >> test;

  while (test--) {
    int m, n;

    cin >> m;
    for (int i = 0; i <= m; i++) {
      cin >> a[i];
    }

    cin >> n;
    for (int i = 0; i <= n; i++) {
      cin >> b[i];
    }

    cout << m + n << endl;

    int p = m + n;
    for (int i = 0; i <= p; i++) {
      long long t = 0LL;
      for (int j = 0; j <= m; j++) {
        int k = i - j;

        if (0 <= k && k <= n) {
          t += a[j] * b[k];
        }
      }
      if (i) {
        cout << " ";
      }

      cout << t;
    }

    cout << endl;
  }

  return 0;
}