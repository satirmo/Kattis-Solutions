#include <bits/stdc++.h>

using namespace std;

const int maxn = 2005;

int a[maxn], b[maxn];
map<int, int> mapa;

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int t = b[j] - a[i];

      if (t >= 0) {
        mapa[t]++;
      }
    }
  }

  int ans = -1;
  int maxx = -1;

  for (auto it : mapa) {
    if (ans == -1 || it.second > maxx ||
        (it.second == maxx && it.first < ans)) {
      ans = it.first;
      maxx = it.second;
    }

    // cout << it.first << " " << it.second << endl;
  }

  ans = max(ans, 0);

  cout << ans << endl;

  return 0;
}