#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  string ans = "";
  bool flag = true;

  for (char c : s) {
    if (flag) {
      ans += c;
      flag = false;
    }

    if (c == '-') {
      flag = true;
    }
  }

  cout << ans << endl;

  return 0;
}