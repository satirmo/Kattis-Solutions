#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  int ans = 1;

  for (char c : s) {
    if (c == 'A' && ans == 1) {
      ans = 2;
    }

    else if (c == 'A' && ans == 2) {
      ans = 1;
    }

    if (c == 'B' && ans == 2) {
      ans = 3;
    }

    else if (c == 'B' && ans == 3) {
      ans = 2;
    }

    if (c == 'C' && ans == 1) {
      ans = 3;
    }

    else if (c == 'C' && ans == 3) {
      ans = 1;
    }
  }

  cout << ans << endl;

  return 0;
}