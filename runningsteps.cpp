#include <bits/stdc++.h>

using namespace std;

const int maxn = 205;

long long c[maxn][maxn];

long long GenerateCombinations() {
  for (int i = 0; i < maxn; i++) {
    for (int j = 0; j <= i; j++) {
      if (i == 0 || i == j) {
        c[i][j] = 1LL;
      }

      else {
        c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
      }
    }
  }
}

long long F(int n) {
  long long ret = 0LL;

  for (int one = 0; true; one++) {
    int two = (n - 2 * one) / 4;
    if (two < one) {
      break;
    }

    if (2 * one + 4 * two == n) {
      int strides = one + two;

      ret += c[strides][one] * c[strides][one];
    }
  }

  return ret;
}

int main() {
  int test;
  cin >> test;

  GenerateCombinations();

  while (test--) {
    int t, n;
    cin >> t >> n;

    long long ans = F(n);
    printf("%d %lld\n", t, ans);
  }
  return 0;
}