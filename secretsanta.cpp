#include <bits/stdc++.h>

using namespace std;

const long long maxn = 25;

double dp[maxn];
double val[maxn];

void Precalculate() {
  dp[1] = 0.0;
  dp[2] = 1.0;

  for (int i = 3; i < maxn; i++) {
    dp[i] = (double)(i - 1) * (dp[i - 1] + dp[i - 2]);
  }

  double factorial = 1.0;

  for (int i = 1; i < maxn; i++) {
    factorial = (double)i * factorial;
    val[i] = dp[i] / factorial;
  }
}

int main() {
  Precalculate();

  long long n;

  while (cin >> n) {
    long long m = min(n, maxn - 1LL);
    double ans = 1.0 - val[m];

    printf("%.10lf\n", ans);
  }

  return 0;
}