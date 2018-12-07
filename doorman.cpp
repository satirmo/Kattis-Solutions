#include <bits/stdc++.h>

using namespace std;

stack<int> st;

int main() {
  int x;

  while (cin >> x) {
    cin.ignore();

    string s;
    cin >> s;

    for (int i = s.size() - 1; i >= 0; i--) {
      int v = (s[i] == 'W') ? 1 : -1;

      st.push(v);
    }

    int ans = 0;
    int diff = 0;

    while (!st.empty()) {
      int first = st.top();
      st.pop();

      if (abs(diff + first) <= x) {
        ans++;
        diff += first;
        continue;
      }

      if (st.empty()) {
        break;
      }

      int second = st.top();
      st.pop();

      if (abs(diff + second) <= x) {
        ans++;
        diff += second;
        st.push(first);
      }

      else {
        break;
      }
    }

    cout << ans << endl;

    while (!st.empty()) {
      st.pop();
    }
  }

  return 0;
}