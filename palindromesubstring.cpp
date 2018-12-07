#include <bits/stdc++.h>

using namespace std;

set<string> st;

bool IsPalindrome(string &s, int l, int r) {
  while (l < r) {
    if (s[l++] != s[r--]) {
      return false;
    }
  }

  return true;
}

int main() {
  string s;

  while (cin >> s) {
    for (int i = 0; i < s.size(); i++) {
      for (int j = i + 1; j < s.size(); j++) {
        if (IsPalindrome(s, i, j)) {
          st.insert(s.substr(i, j - i + 1));
        }
      }
    }

    for (string t : st) {
      printf("%s\n", t.c_str());
    }

    puts("");
    st.clear();
  }

  return 0;
}