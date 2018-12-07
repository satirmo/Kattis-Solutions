#include <bits/stdc++.h>

using namespace std;

const int maxk = 30;
const int maxn = 2005;
const long long inf = 1LL << 60;

long long a[maxn];
long long dp[maxn][maxk];
long long cost[maxn][maxn];

priority_queue<long long> lower;
priority_queue<long long, vector<long long>, greater<long long> > upper;

void CalculateMedianCost(int n) {
  for (int i = 1; i <= n; i++) {
    while (!lower.empty()) {
      lower.pop();
    }

    while (!upper.empty()) {
      upper.pop();
    }

    int cnt = 0;
    long long sumDifference = 0LL;

    for (int j = i; j <= n; j++) {
      if (lower.empty() || a[j] <= lower.top()) {
        lower.push(a[j]);
        sumDifference -= a[j];
      }

      else {
        upper.push(a[j]);
        sumDifference += a[j];
      }

      cnt++;

      int cntLower = cnt / 2;
      int cntUpper = cnt - cntLower;

      if (lower.size() > cntLower) {
        upper.push(lower.top());
        sumDifference += 2 * lower.top();
        lower.pop();
      }

      if (upper.size() > cntUpper) {
        lower.push(upper.top());
        sumDifference -= 2 * upper.top();
        upper.pop();
      }

      while (lower.size() && upper.size() && upper.top() < lower.top()) {
        long long l = lower.top();
        lower.pop();

        long long u = upper.top();
        upper.pop();

        lower.push(u);
        upper.push(l);

        sumDifference += 2LL * l;
        sumDifference -= 2LL * u;
      }

      long long difference = sumDifference;

      if (upper.size() > lower.size()) {
        difference -= upper.top();
      }

      cost[i][j] = abs(difference);
    }
  }
}

long long Solve(int n, int segments) {
  CalculateMedianCost(n);

  for (int i = 0; i < maxn; i++) {
    for (int j = 0; j < maxn; j++) {
      dp[i][j] = inf;
    }
  }

  dp[0][0] = 0LL;

  for (int i = 1; i <= n; i++) {
    for (int j = i; j > 0; j--) {
      int uptok = min(maxk - 1, j);

      for (int k = 1; k <= uptok; k++) {
        long long candidate = dp[j - 1][k - 1] + cost[j][i];
        dp[i][k] = min(dp[i][k], candidate);
      }
    }
  }

  return dp[n][segments];
}

int main() {
  int n, segments;
  cin >> n >> segments;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  long long ans = Solve(n, segments);
  cout << ans << endl;

  return 0;
}