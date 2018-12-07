#include <bits/stdc++.h>

using namespace std;

const int maxn = 5005;
int a[maxn], b[maxn], c[maxn];

int main() {
  int n;
  bool flag = false;
  while (cin >> n, n) {
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      c[i] = a[i];
    }

    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + n);

    if (flag) {
      puts("");
    }
    flag = true;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (c[i] == a[j]) {
          printf("%d\n", b[j]);
          break;
        }
      }
    }
  }

  return 0;
}