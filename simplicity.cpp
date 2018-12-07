#include <bits/stdc++.h>

using namespace std;

map<char, int> mapa;

int main() {
  string s;
  while (cin >> s) {
    mapa.clear();

    for (char c : s) {
      mapa[c]++;
    }

    int m1 = -1;
    int m2 = -1;
    for (auto it : mapa) {
      if (it.second > m1) {
        m1 = it.second;
      }

      if (m1 > m2) {
        swap(m1, m2);
      }
    }

    int ans = s.size() - m2;
    if (m1 != -1) {
      ans -= m1;
    }

    cout << ans << endl;
  }

  return 0;
}