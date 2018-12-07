#include <bits/stdc++.h>

using namespace std;

int main() {
  double cost;

  while (cin >> cost) {
    int n;
    cin >> n;

    double ans = 0.0;

    while (n--) {
      double w, h;
      cin >> w >> h;

      double area = w * h;
      ans += area * cost;
    }

    printf("%.8lf\n", ans);
  }

  return 0;
}