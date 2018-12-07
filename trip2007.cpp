#include <bits/stdc++.h>

using namespace std;

const int maxn = 10005;

int a[maxn];
vector<int> v[maxn];

int main() {
  int n;
  bool flag = false;

  while (cin >> n, n != 0) {
    if (flag) {
      puts("");
    }

    flag = true;

    for (int i = 0; i < maxn; i++) {
      v[i].clear();
    }

    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }

    sort(a, a + n);

    int total = 0;

    for (int i = 0; i < n;) {
      int j = i;

      while (j + 1 < n && a[j + 1] == a[i]) {
        j++;
      }

      total = max(total, j - i + 1);
      i = j + 1;
    }

    cout << total << endl;

    for (int i = 0; i < n; i += total) {
      for (int j = i; j - i < total && j < n; j++) {
        v[j % total].push_back(a[j]);
      }
    }

    for (int i = 0; i < total; i++) {
      for (int j = 0; j < v[i].size(); j++) {
        if (j != 0) {
          printf(" ");
        }

        printf("%d", v[i][j]);
      }

      puts("");
    }
  }

  return 0;
}