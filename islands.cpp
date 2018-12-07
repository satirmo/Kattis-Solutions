#include <bits/stdc++.h>

using namespace std;

stack<int> st;

int main() {
  int test;
  cin >> test;

  while (test--) {
    int t;
    cin >> t;

    int ans = 0;

    for (int i = 0; i < 12; i++) {
      int level;
      cin >> level;

      while (!st.empty() && st.top() > level) {
        ans++;
        st.pop();
      }

      if (st.empty() || st.top() < level) {
        st.push(level);
      }
    }

    while (!st.empty()) {
      st.pop();
    }

    printf("%d %d\n", t, ans);
  }

  return 0;
}