#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int maxn = 105;
const int mov[][2] = {{-1, -2}, {1, -2}, {-1, 2}, {1, 2},
                      {-2, -1}, {-2, 1}, {2, -1}, {2, 1}};

int visit[maxn][maxn];
queue<ii> qu;

void BFS(int x, int y) {
  visit[x][y] = 0;
  qu.push(ii(x, y));

  while (!qu.empty()) {
    int u = qu.front().first;
    int v = qu.front().second;

    qu.pop();

    for (int i = 0; i < 8; i++) {
      int nu = u + mov[i][0];
      int nv = v + mov[i][1];

      if (nu < 0 || nu >= 8 || nv < 0 || nv >= 8) {
        continue;
      }

      if (visit[nu][nv] != -1) {
        continue;
      }

      qu.push(ii(nu, nv));
      visit[nu][nv] = 1 + visit[u][v];
    }
  }
}

int main() {
  int test;
  cin >> test;

  while (test--) {
    string input;
    cin >> input;

    int x = input[0] - 'a';
    int y = input[1] - '1';

    memset(visit, -1, sizeof visit);

    BFS(y, x);

    int maxx = 0;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        maxx = max(maxx, visit[i][j]);
      }
    }

    cout << maxx;
    for (int i = 7; i >= 0; i--) {
      for (int j = 0; j < 8; j++) {
        if (visit[i][j] == maxx) {
          int n = i + 1;
          char c = 'a' + j;
          string ans = c + to_string(n);

          cout << " " << ans;
        }
      }
    }

    cout << endl;
  }

  return 0;
}