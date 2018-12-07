#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

int a[maxn];

int main() {
  int n;

  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    sort(a, a + n);

    for (int i = 0; i < n;) {
      int j = i;

      while (j + 1 < n && a[j] + 1 == a[j + 1]) {
        j++;
      }

      if (i != 0) {
        cout << " ";
      }

      if (j == i) {
        cout << a[i];
      }

      else if (j == i + 1) {
        cout << a[i] << " " << a[j];
      }

      else {
        printf("%d-%d", a[i], a[j]);
      }

      i = j + 1;
    }

    puts("");
  }

  return 0;
}