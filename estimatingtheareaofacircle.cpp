#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1);

int main() {
  int m, c;
  double r;

  while (cin >> r >> m >> c) {
    if (r == 0 && m == 0 && c == 0) {
      break;
    }

    double actual = pi * r * r;

    double epi = (double)4.0 * c / m;
    double estimate = epi * r * r;

    printf("%.6lf %.6lf\n", actual, estimate);
  }

  return 0;
}