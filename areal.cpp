#include <bits/stdc++.h>

using namespace std;

int main() {
  double area;
  cin >> area;

  double side = sqrt(area);
  double ans = 4.0 * side;

  printf("%.10lf\n", ans);

  return 0;
}