#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int maxn = 205;

long long a[maxn];
ii dp[maxn];
vector<long long> ans;

void UpdateAns(int idx, int n) {
  ans.clear();

  for (int i = 0; i < n; i++) {
    ans.push_back(a[idx]);
    idx = dp[idx].second;
  }
}

int main() {
  int n;

  while (cin >> n, n != 0) {
    for (int i = 0; i < maxn; i++) {
      dp[i] = ii(1, i);
    }

    for (int i = 0; i < n; i++) {
      scanf("%lld", &a[i]);
    }

    // generate increasing paths
    // dp[ i ].first : size of longest increasing subsequence starting at i
    // dp[ i ].second : child index

    int maxx = 1;

    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j > i; j--) {
        if (a[i] >= a[j]) {
          continue;
        }

        int nextSize = dp[j].first + 1;

        if (nextSize > dp[i].first ||
            (nextSize == dp[i].first && a[j] < a[dp[i].second])) {
          dp[i].first = nextSize;
          dp[i].second = j;
        }
      }

      maxx = max(maxx, dp[i].first);
    }

    // generate longest increasing subsequence

    ans.clear();

    for (int i = 0; i < n; i++) {
      if (ans.size() == 0) {
        UpdateAns(i, maxx);
      }

      else if (dp[i].first == maxx) {
        for (int j = i, k = 0; k < maxx; j = dp[j].second, k++) {
          if (ans[k] != a[j]) {
            if (ans[k] > a[j]) {
              UpdateAns(i, maxx);
            }

            break;
          }
        }
      }
    }

    // print solution
    cout << maxx;
    for (long long x : ans) {
      printf(" %lld", x);
    }
    cout << endl;
  }

  return 0;
}