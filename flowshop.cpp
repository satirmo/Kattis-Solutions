#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

long long t[maxn][maxn];
long long p[maxn][maxn];

void Calculate(int n, int m) {
  long long ans = 0LL;

  t[0][0] = p[0][0];

  for (int i = 1; i < m; i++) {
    t[0][i] = p[0][i] + t[0][i - 1];
  }

  for (int i = 1; i < n; i++) {
    t[i][0] = p[i][0] + t[i - 1][0];
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      t[i][j] = p[i][j] + max(t[i - 1][j], t[i][j - 1]);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%lld", &p[i][j]);
    }
  }

  Calculate(n, m);

  for (int i = 0; i < n; i++) {
    if (i > 0) {
      printf(" ");
    }

    cout << t[i][m - 1];
  }

  puts("");

  return 0;
}