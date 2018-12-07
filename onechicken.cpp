#include <bits/stdc++.h>

using namespace std;

int main() {
  int m, n;
  cin >> m >> n;

  string pieces = (abs(m - n) == 1) ? "piece" : "pieces";

  if (m < n) {
    printf("Dr. Chaz will have %d %s of chicken left over!\n", n - m,
           pieces.c_str());
  }

  else {
    printf("Dr. Chaz needs %d more %s of chicken!\n", m - n, pieces.c_str());
  }

  return 0;
}