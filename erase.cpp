#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  cin.ignore();

  int expected = (n & 1);

  string s, t;
  cin >> s >> t;

  bool flag = true;

  for (int i = 0; i < s.size(); i++) {
    int actual = (s[i] + t[i] - 2 * '0') % 2;

    if (actual != expected) {
      flag = false;
    }
  }

  string ans = (flag) ? "Deletion succeeded" : "Deletion failed";
  cout << ans << endl;

  return 0;
}