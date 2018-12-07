#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

int a[maxn];
vector<int> v;

int main() {
  int n;
  for (int t = 1; cin >> n; t++) {
    v.clear();

    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);

      for (int j = 0; j < i; j++) {
        v.push_back(a[i] + a[j]);
      }
    }

    printf("Case %d:\n", t);

    int m;
    cin >> m;

    while (m--) {
      int q;
      cin >> q;

      int idx = 0;
      for (int i = 0; i < v.size(); i++) {
        if (abs(v[i] - q) < abs(v[idx] - q)) {
          idx = i;
        }
      }

      printf("Closest sum to %d is %d.\n", q, v[idx]);
    }
  }

  return 0;
}