#include <bits/stdc++.h>

using namespace std;

const int maxn = 205;

int dp[maxn][maxn];

int Construct(string s) {
  int n = s.size() - 1;

  for (int i = n; i > 0; i--) {
    dp[i][i] = 2;

    for (int j = i + 1; j <= n; j++) {
      int len = j - i + 1;
      dp[i][j] = min(2 * len, 2 + dp[i + 1][j]);

      for (int k = i + 1; k <= j; k++) {
        if (s[i] == s[k]) {
          int candidate = dp[i][k - 1] + dp[k + 1][j];
          dp[i][j] = min(dp[i][j], candidate);
        }
      }
    }
  }

  int ret = n + dp[1][n];
  return ret;
}

int main() {
  int test;
  cin >> test;
  cin.ignore();

  while (test--) {
    string line;
    getline(cin, line);

    int ans = Construct("-" + line);
    cout << ans << endl;
  }

  return 0;
}