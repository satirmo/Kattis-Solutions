#include <bits/stdc++.h>

using namespace std;

typedef pair<int, string> is;

const int maxn = 1005;

int dist[maxn][maxn];
string keyboard[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
set<is> st;

void Preprocess() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < keyboard[i].size(); j++) {
      for (int k = 0; k < 3; k++) {
        for (int l = 0; l < keyboard[k].size(); l++) {
          char a = keyboard[i][j];
          char b = keyboard[k][l];

          dist[a][b] = abs(i - k) + abs(j - l);
        }
      }
    }
  }
}

int main() {
  Preprocess();

  int test;
  cin >> test;
  cin.ignore();

  while (test--) {
    string s;
    int words;

    cin >> s >> words;
    cin.ignore();

    int n = s.size();
    st.clear();

    while (words--) {
      string t;
      cin >> t;

      int total = 0;

      for (int i = 0; i < n; i++) {
        total += dist[s[i]][t[i]];
      }

      st.insert(is(total, t));
    }

    for (auto it : st) {
      printf("%s %d\n", it.second.c_str(), it.first);
    }
  }

  return 0;
}