#include <bits/stdc++.h>

using namespace std;

int main() {
  double r, c;
  cin >> r >> c;

  double pi = acos(-1);
  double pizza = pi * r * r;
  double cheese = pi * (r - c) * (r - c);

  double ans = 100.0 * cheese / pizza;

  printf("%.6lf\n", ans);

  return 0;
}