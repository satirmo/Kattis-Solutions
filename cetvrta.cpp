#include <bits/stdc++.h>

using namespace std;

int x[10], y[10];

int main() {
  for (int i = 0; i < 3; i++) {
    cin >> x[i] >> y[i];
  }

  sort(x, x + 3);
  sort(y, y + 3);

  int ax, ay;

  if (x[1] == x[0]) {
    ax = x[2];
  }

  else {
    ax = x[0];
  }

  if (y[1] == y[0]) {
    ay = y[2];
  }

  else {
    ay = y[0];
  }

  cout << ax << " " << ay << endl;

  return 0;
}