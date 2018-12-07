#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int maxn = 505;

int G[maxn][maxn];
vector<int> red[maxn], green[maxn];
queue<ii> qu;

bool BFS(int n) {
  for (int i = 0; i < n; i++) {
    G[i][i] = 1;
    qu.push(ii(i, i));
  }

  while (!qu.empty()) {
    ii fr = qu.front();
    qu.pop();

    int x = fr.first;
    int y = fr.second;

    for (int p : red[x]) {
      for (int q : red[y]) {
        if (G[p][q] == 0) {
          G[p][q] = 1;
          qu.push(ii(p, q));
        }
      }
    }

    for (int p : green[x]) {
      for (int q : green[y]) {
        if (G[p][q] == 0) {
          G[p][q] = 1;
          qu.push(ii(p, q));
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (G[i][j] == 0) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  int test;
  cin >> test;

  while (test--) {
    int t, n;
    cin >> t >> n;

    for (int i = 0; i < n; i++) {
      red[i].clear();
      green[i].clear();
      memset(G[i], 0, sizeof G[i]);
    }

    for (int i = 0; i < n; i++) {
      int j;
      cin >> j;

      red[j].push_back(i);
    }

    for (int i = 0; i < n; i++) {
      int j;
      cin >> j;

      green[j].push_back(i);
    }

    bool possible = BFS(n);
    string ans = (possible) ? "YES" : "NO";

    printf("%d %s\n", t, ans.c_str());
  }

  return 0;
}