#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b, c, d;

  for (int t = 1; cin >> a >> b >> c >> d; t++) {
    long long det = a * d - b * c;

    printf("Case %d:\n", t);
    printf("%lld %lld\n", d / det, -b / det);
    printf("%lld %lld\n", -c / det, a / det);
  }

  return 0;
}