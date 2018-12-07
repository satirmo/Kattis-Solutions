#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

long long squawks[maxn][maxn];
vector<int> G[maxn];

long long CalculateSquawks(int n, int s, int t) {
  squawks[0][s] = 1;

  for (int i = 1; i <= t; i++) {
    for (int u = 0; u < n; u++) {
      for (int v : G[u]) {
        squawks[i][v] += squawks[i - 1][u];
      }
    }
  }

  long long ret = 0LL;

  for (int i = 0; i < n; i++) {
    ret += squawks[t][i];
  }

  return ret;
}

int main() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;

  while (m--) {
    int x, y;
    cin >> x >> y;

    G[x].push_back(y);
    G[y].push_back(x);
  }

  long long ans = CalculateSquawks(n, s, t);
  cout << ans << endl;

  return 0;
}