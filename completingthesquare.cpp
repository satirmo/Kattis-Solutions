#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int x[5], y[5];

int CalculateDistance(int a, int b) {
  int dx = x[a] - x[b];
  int dy = y[a] - y[b];

  return dx * dx + dy * dy;
}

void FindFourthPoint(int &rx, int &ry) {
  for (int i = 0; i < 3; i++) {
    int j = (i + 1) % 3;
    int k = (i + 2) % 3;

    if (CalculateDistance(i, j) != CalculateDistance(i, k)) {
      continue;
    }

    int dx = x[i] - x[j];
    int dy = y[i] - y[j];

    rx = x[k] - dx;
    ry = y[k] - dy;

    break;
  }
}

int main() {
  while (cin >> x[0] >> y[0]) {
    for (int i = 1; i < 3; i++) {
      cin >> x[i] >> y[i];
    }

    int ansx, ansy;

    FindFourthPoint(ansx, ansy);

    cout << ansx << " " << ansy << endl;
  }

  return 0;
}