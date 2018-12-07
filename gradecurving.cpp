#include <bits/stdc++.h>

using namespace std;

int main() {
  double x, ym, yM;
  cin >> x >> ym >> yM;

  x = (x / 10.0) * (x / 10.0);

  int minn = 10000000;
  int maxx = 0;

  for (int k = 0; k < 1000000; k++) {
    double t = 10.0 * sqrt(x);
    double y = ceil(t);

    if (ym <= y && y <= yM) {
      minn = min(minn, k);
      maxx = max(maxx, k);
    }

    x = t;
  }

  if (minn > maxx) {
    puts("impossible");
  }

  else if (maxx == 1000000 - 1) {
    printf("%d inf\n", minn);
  }

  else {
    printf("%d %d\n", minn, maxx);
  }

  return 0;
}