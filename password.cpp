#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

double prob[maxn];
double dp[maxn];

int main() {
  int n;
  cin >> n;
  cin.ignore();

  for (int i = 0; i < n; i++) {
    string s;

    cin >> s >> prob[i];
    cin.ignore();
  }

  sort(prob, prob + n);
  reverse(prob, prob + n);

  double ans = 0.0;

  for (int i = 0; i < n; i++) {
    ans += (double)(i + 1) * prob[i];
  }

  printf("%.4lf\n", ans);

  return 0;
}