#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int inf = 1 << 30;
const int maxw = 55;
const int maxn = 305;
const int maxo = 105;

int options[maxw];
int bestChoice[maxw];
int p[maxw][maxo], s[maxw][maxo];
int smallest[maxw][maxn];
int dp[maxw][maxn];
// week tickets option

ii GetEarnings(int n, int w) {
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < maxn; i++) {
    smallest[0][i] = inf;
  }

  for (int i = 0; i < options[0]; i++) {
    int sold = min(s[0][i], n);
    int price = p[0][i];
    int earned = sold * price;

    int leftover = n - sold;

    if (dp[0][leftover] < earned ||
        (dp[0][leftover] == earned && price < smallest[0][leftover])) {
      dp[0][leftover] = earned;
      smallest[0][leftover] = price;
    }
  }

  for (int i = 1; i <= w; i++) {
    for (int j = 0; j <= n; j++) {
      if (dp[i - 1][j] == -1) {
        continue;
      }

      for (int k = 0; k < options[i]; k++) {
        int sold = min(s[i][k], j);
        int price = p[i][k];
        int earned = sold * price;

        int before = j;
        int leftover = before - sold;

        int candidate = earned + dp[i - 1][before];

        if (dp[i][leftover] < candidate) {
          dp[i][leftover] = candidate;
          smallest[i][leftover] = smallest[i - 1][before];
        }

        else if (dp[i][leftover] == candidate) {
          dp[i][leftover] = candidate;
          smallest[i][leftover] =
              min(smallest[i][leftover], smallest[i - 1][before]);
        }
      }
    }
  }

  int maxEarnings = 0;
  int bestChoice = 0;

  for (int i = 0; i <= n; i++) {
    if (maxEarnings < dp[w][i]) {
      maxEarnings = dp[w][i];
      bestChoice = smallest[w][i];
    }

    else if (maxEarnings == dp[w][i]) {
      maxEarnings = dp[w][i];
      bestChoice = min(bestChoice, smallest[w][i]);
    }
  }

  return ii(maxEarnings, bestChoice);
}

int main() {
  int n, w;
  cin >> n >> w;

  for (int i = 0; i <= w; i++) {
    cin >> options[i];
    int k = options[i];

    for (int j = 0; j < k; j++) {
      cin >> p[i][j];
    }

    for (int j = 0; j < k; j++) {
      cin >> s[i][j];
    }
  }

  ii ans = GetEarnings(n, w);
  cout << ans.first << endl;
  cout << ans.second << endl;

  return 0;
}