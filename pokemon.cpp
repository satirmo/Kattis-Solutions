#include <bits/stdc++.h>

using namespace std;

const int inf = 1 << 30;
const int maxn = 1005;

int par[maxn][maxn];
int dist[maxn * maxn];
string s[maxn];
vector<int> G[maxn * maxn];
queue<int> qu;

void ConnectNodes(int r, int c) {
  for (int i = 1; i < r - 1; i++) {
    for (int j = 1; j < c - 1; j++) {
      int idx = i * c + j;

      if (s[i][j] != '#' && par[i][j] != idx) {
        G[par[i][j]].push_back(idx);
      }
    }
  }
}

void CreateGraph(int r, int c) {
  for (int i = 1; i < r - 1; i++) {
    for (int j = 1; j < c - 1; j++) {
      if (s[i][j - 1] == '#') {
        par[i][j] = i * c + j;
      }

      if (s[i][j - 1] == '.') {
        par[i][j] = i * c + (j - 1);
      }

      if (s[i][j - 1] == '_') {
        par[i][j] = par[i][j - 1];
      }
    }
  }

  ConnectNodes(r, c);

  for (int i = 1; i < r - 1; i++) {
    for (int j = c - 2; j > 0; j--) {
      if (s[i][j + 1] == '#') {
        par[i][j] = i * c + j;
      }

      if (s[i][j + 1] == '.') {
        par[i][j] = i * c + (j + 1);
      }

      if (s[i][j + 1] == '_') {
        par[i][j] = par[i][j + 1];
      }
    }
  }

  ConnectNodes(r, c);

  for (int i = 1; i < c - 1; i++) {
    for (int j = 1; j < r - 1; j++) {
      if (s[j - 1][i] == '#') {
        par[j][i] = j * c + i;
      }

      if (s[j - 1][i] == '.') {
        par[j][i] = (j - 1) * c + i;
      }

      if (s[j - 1][i] == '_') {
        par[j][i] = par[j - 1][i];
      }
    }
  }

  ConnectNodes(r, c);

  for (int i = 1; i < c - 1; i++) {
    for (int j = r - 2; j > 0; j--) {
      if (s[j + 1][i] == '#') {
        par[j][i] = j * c + i;
      }

      if (s[j + 1][i] == '.') {
        par[j][i] = (j + 1) * c + i;
      }

      if (s[j + 1][i] == '_') {
        par[j][i] = par[j + 1][i];
      }
    }
  }

  ConnectNodes(r, c);
}

void BFS(int st) {
  for (int i = 0; i < maxn * maxn; i++) {
    dist[i] = inf;
  }

  qu.push(st);
  dist[st] = 0;

  while (!qu.empty()) {
    int u = qu.front();
    qu.pop();

    for (int v : G[u]) {
      if (dist[v] == inf) {
        qu.push(v);
        dist[v] = 1 + dist[u];
      }
    }
  }
}

int main() {
  int c, r;
  cin >> c >> r;
  cin.ignore();

  int st = -1;

  for (int i = 0; i < r; i++) {
    cin >> s[i];

    for (int j = 0; j < c; j++) {
      if (s[i][j] == 'M') {
        s[i][j] = '.';
        st = i * c + j;
      }
    }
  }

  CreateGraph(r, c);
  BFS(st);

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      int idx = i * c + j;

      if (j > 0) {
        printf(" ");
      }

      if (dist[idx] == inf) {
        dist[idx] = -1;
      }

      printf("%d", dist[idx]);
    }
    puts("");
  }

  return 0;
}