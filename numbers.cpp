#include <bits/stdc++.h>

using namespace std;

const int num[] = {2, 4};

string Solve(string s) {
  if (s.size() == 1 || s == "22") {
    return s;
  }

  int sum = 0;

  for (int i = 0; i <= s.size(); i++) {
    for (int j = 0; j < 2; j++) {
      if ((i == s.size() || s[i] - '0' > num[j]) && (sum & num[j])) {
        string add = to_string(num[j]);
        s.insert(i, add);
      }
    }

    if (i < s.size()) {
      sum += s[i] - '0';
    }
  }

  while (sum & (sum - 1)) {
    s += "8";
    sum += 8;
  }

  return s;
}

int main() {
  int test;
  cin >> test;
  cin.ignore();

  while (test--) {
    string s;
    cin >> s;

    string ans = Solve(s);
    cout << ans << endl;
  }

  return 0;
}