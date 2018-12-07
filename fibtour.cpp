#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;
const int maxf = 105;

int dp[maxn][maxf];
vector<int> heights[maxn];
vector<long long> fib;
vector<int> G[maxn];

void GenerateFib() {
  long long f1 = 1;
  long long f2 = 1;

  fib.push_back(f1);
  fib.push_back(f2);

  for (int i = 3; i < maxf; i++) {
    long long f3 = f1 + f2;

    f1 = f2;
    f2 = f3;

    fib.push_back(f3);
  }
}

int DFS(int u, int h) {
  int &ret = dp[u][h];

  if (ret != -1) {
    return ret;
  }

  ret = 0;

  for (int v : G[u]) {
    for (int height : heights[v]) {
      if (height - 1 == h) {
        int candidate = 1 + DFS(v, height);
        ret = max(ret, candidate);
      }
    }
  }

  return ret;
}

int main() {
  GenerateFib();

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    long long h;
    cin >> h;

    for (int j = 0; j < fib.size(); j++) {
      if (fib[j] == h) {
        heights[i].push_back(j);
      }
    }
  }

  while (m--) {
    int x, y;
    cin >> x >> y;

    G[x].push_back(y);
    G[y].push_back(x);
  }

  memset(dp, -1, sizeof dp);

  int ans = 0;

  for (int i = 1; i <= n; i++) {
    for (int height : heights[i]) {
      int candidate = 1 + DFS(i, height);
      ans = max(ans, candidate);
    }
  }

  cout << ans << endl;

  return 0;
}