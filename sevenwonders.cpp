#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;

  while (cin >> s) {
    int t = 0;
    int c = 0;
    int g = 0;

    for (char chr : s) {
      if (chr == 'T') {
        t++;
      }

      if (chr == 'C') {
        c++;
      }

      if (chr == 'G') {
        g++;
      }
    }

    int st = min(min(t, c), g);
    int ans = t * t + c * c + g * g + 7 * st;

    cout << ans << endl;
  }

  return 0;
}