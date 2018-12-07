#include <bits/stdc++.h>

using namespace std;

string add[] = {"A", "C", "G", "T"};
set<string> st;

int Calculate(string s, string t) {
  int ret = 0;
  int upto = t.size() - s.size();

  for (int i = 0; i <= upto; i++) {
    bool flag = true;

    for (int j = 0; j < s.size(); j++) {
      if (s[j] != t[i + j]) {
        flag = false;
      }
    }

    if (flag) {
      ret++;
    }
  }

  return ret;
}

int main() {
  string s, t;

  while (cin >> s) {
    if (s == "0") {
      break;
    }

    cin >> t;

    int ans0 = Calculate(s, t);
    int ans1 = 0;
    int ans2 = 0;

    st.clear();

    for (int i = 0; i < s.size(); i++) {
      string r = s;
      r.erase(r.begin() + i);

      if (st.count(r) == 0) {
        st.insert(r);
        ans1 += Calculate(r, t);
      }
    }

    st.clear();

    for (int i = 0; i <= s.size(); i++) {
      for (int j = 0; j < 4; j++) {
        string r = s;
        r.insert(i, add[j]);

        if (st.count(r) == 0) {
          st.insert(r);
          ans2 += Calculate(r, t);
        }
      }
    }

    printf("%d %d %d\n", ans0, ans1, ans2);
  }

  return 0;
}