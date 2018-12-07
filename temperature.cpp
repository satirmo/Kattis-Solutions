#include <bits/stdc++.h>

using namespace std;

int main() {
  double x, y;

  while (cin >> x >> y) {
    if (y == 1.0) {
      if (x != 0.0) {
        puts("IMPOSSIBLE");
      }

      else {
        puts("ALL GOOD");
      }

      continue;
    }

    double c = x / (1.0 - y);
    printf("%.7lf\n", c);
  }
  return 0;
}