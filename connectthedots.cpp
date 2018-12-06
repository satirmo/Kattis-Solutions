#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int maxn = 1005;

ii loc[maxn];
string m[maxn];
vector<char> order;

int main() {
  for (char i = '0'; i <= '9'; i++) {
    order.push_back(i);
  }

  for (char i = 'a'; i <= 'z'; i++) {
    order.push_back(i);
  }

  for (char i = 'A'; i <= 'Z'; i++) {
    order.push_back(i);
  }

  bool space = false;

  while (getline(cin, m[0])) {
    for (int i = 0; i < maxn; i++) {
      loc[i] = ii(-1, -1);
    }

    int n = 1;

    while (getline(cin, m[n]), m[n] != "") {
      n++;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m[i].size(); j++) {
        loc[m[i][j]] = ii(i, j);
      }
    }

    for (int i = 1; i < order.size(); i++) {
      char pc = order[i - 1];
      char c = order[i];

      if (loc[c] == ii(-1, -1)) {
        break;
      }

      if (loc[pc].first == loc[c].first) {
        int minn = min(loc[pc].second, loc[c].second);
        int maxx = max(loc[pc].second, loc[c].second);

        for (int j = minn + 1; j <= maxx - 1; j++) {
          if (m[loc[c].first][j] == '.') {
            m[loc[c].first][j] = '-';
          }

          if (m[loc[c].first][j] == '|') {
            m[loc[c].first][j] = '+';
          }
        }
      }

      if (loc[pc].second == loc[c].second) {
        int minn = min(loc[pc].first, loc[c].first);
        int maxx = max(loc[pc].first, loc[c].first);

        for (int j = minn + 1; j <= maxx - 1; j++) {
          if (m[j][loc[c].second] == '.') {
            m[j][loc[c].second] = '|';
          }

          if (m[j][loc[c].second] == '-') {
            m[j][loc[c].second] = '+';
          }
        }
      }
    }

    if (space) {
      puts("");
    }

    space = true;

    for (int i = 0; i < n; i++) {
      cout << m[i] << endl;
    }
  }

  return 0;
}