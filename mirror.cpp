#include <bits/stdc++.h>

using namespace std;

string line[25];

int main() {
  int test;
  cin >> test;

  for (int t = 1; t <= test; t++) {
    int r, c;
    cin >> r >> c;
    cin.ignore();

    for (int i = 0; i < r; i++) {
      cin >> line[i];
      reverse(line[i].begin(), line[i].end());
    }

    printf("TEST %d\n", t);
    for (int i = r - 1; i >= 0; i--) {
      cout << line[i] << endl;
    }
  }

  return 0;
}