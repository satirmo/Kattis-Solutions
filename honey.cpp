#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int maxn = 25;
const int mov[6][2] = {{-1, -1}, {1, 1}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

long long dp[2 * maxn][2 * maxn][maxn];
queue<iii> qu;

long long CountPaths(int n) {
  memset(dp, 0, sizeof dp);

  qu.push(iii(0LL, ii(maxn, maxn)));
  dp[maxn][maxn][0] = 1LL;

  while (!qu.empty()) {
    iii fr = qu.front();
    qu.pop();

    int st = fr.first;
    int x = fr.second.first;
    int y = fr.second.second;

    for (int i = 0; i < 6; i++) {
      int nx = x + mov[i][0];
      int ny = y + mov[i][1];
      int ns = st + 1;

      dp[nx][ny][ns] += dp[x][y][st];

      if (st + 1 < n && dp[nx][ny][ns] == dp[x][y][st]) {
        qu.push(iii(ns, ii(nx, ny)));
      }
    }
  }

  return dp[maxn][maxn][n];
}

int main() {
  int test;
  cin >> test;

  while (test--) {
    int n;
    cin >> n;

    long long ans = CountPaths(n);
    cout << ans << endl;
  }

  return 0;
}