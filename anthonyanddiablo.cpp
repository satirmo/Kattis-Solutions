#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1);

int main() {
  double a, n;
  cin >> a >> n;

  double maxx = n * n / (4.0 * pi);

  if (a < maxx) {
    puts("Diablo is happy!");
  }

  else {
    puts("Need more materials!");
  }

  return 0;
}