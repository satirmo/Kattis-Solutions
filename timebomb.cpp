#include <bits/stdc++.h>

using namespace std;

string s[10];
string numbers[10];

int main() {
  numbers[0] = "***   * *** *** * * *** *** *** *** ***";
  numbers[1] = "* *   *   *   * * * *   *     * * * * *";
  numbers[2] = "* *   * *** *** *** *** ***   * *** ***";
  numbers[3] = "* *   * *     *   *   * * *   * * *   *";
  numbers[4] = "***   * *** ***   * *** ***   * *** ***";

  bool flag = true;

  for (int i = 0; i < 5; i++) {
    getline(cin, s[i]);

    if (i > 0) {
      if (s[i].size() != s[i - 1].size() && s[i].size() % 4 == 3) {
        flag = false;
      }
    }
  }

  if (flag) {
    long long n = 0LL;

    for (int i = 0; i < s[0].size(); i += 4) {
      long long val = -1LL;

      for (int j = 0; j < numbers[0].size(); j += 4) {
        bool valid = true;

        for (int k = 0; k < 5 && valid; k++) {
          for (int l = 0; l < 3 && valid; l++) {
            if (numbers[k][j + l] != s[k][i + l]) {
              valid = false;
            }
          }
        }

        if (valid) {
          val = j / 4;
        }
      }

      if (val == -1) {
        n = 1;
        break;
      }

      else {
        n = 10 * n + val;
      }
    }

    if (n % 6 != 0LL) {
      flag = false;
    }
  }

  string ans = (flag) ? "BEER!!" : "BOOM!!";
  cout << ans << endl;

  return 0;
}
