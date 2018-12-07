#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

int x[maxn], y[maxn];

int main() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int n;
      cin >> n;

      x[n] = i;
      y[n] = j;
    }
  }

  double ans = 0.0;

  for (int i = 2; i < 10; i++) {
    ans += hypot(x[i] - x[i - 1], y[i] - y[i - 1]);
  }

  printf("%.15lf\n", ans);

  return 0;
}