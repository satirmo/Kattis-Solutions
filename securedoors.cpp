#include <bits/stdc++.h>

using namespace std;

set<string> st;

int main() {
  int n;
  cin >> n;
  cin.ignore();

  while (n--) {
    string direction, name;
    cin >> direction >> name;

    string ans = name;

    if (direction == "exit") {
      ans += " exited";

      if (st.count(name) == 0) {
        ans += " (ANOMALY)";
      }

      st.erase(name);
    }

    else {
      ans += " entered";

      if (st.count(name) == 1) {
        ans += " (ANOMALY)";
      }

      st.insert(name);
    }

    cout << ans << endl;
  }

  return 0;
}