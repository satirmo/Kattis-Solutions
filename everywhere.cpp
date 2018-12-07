#include <bits/stdc++.h>

using namespace std;

set<string> st;

int main() {
  int test;
  cin >> test;

  while (test--) {
    int n;
    cin >> n;
    cin.ignore();
    st.clear();

    while (n--) {
      string s;
      cin >> s;

      st.insert(s);
    }

    cout << st.size() << endl;
  }

  return 0;
}