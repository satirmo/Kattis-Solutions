#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int inf = 1 << 30;
const int maxn = 1005;
const int mov[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

string s[maxn];
queue<ii> qu;

vector<vector<int> > BFS(int n, int m, vector<ii> sts) {
  vector<vector<int> > ret(n);

  for (int i = 0; i < n; i++) {
    ret[i].resize(m);

    for (int j = 0; j < m; j++) {
      ret[i][j] = -1;
    }
  }

  for (ii st : sts) {
    qu.push(st);
    ret[st.first][st.second] = 0;
  }

  while (!qu.empty()) {
    ii u = qu.front();
    qu.pop();

    for (int i = 0; i < 4; i++) {
      int vx = u.first + mov[i][0];
      int vy = u.second + mov[i][1];

      if (vx < 0 || vx == n || vy < 0 || vy == m) {
        continue;
      }

      if (ret[vx][vy] != -1 || s[vx][vy] == '#') {
        continue;
      }

      qu.push(ii(vx, vy));
      ret[vx][vy] = 1 + ret[u.first][u.second];
    }
  }

  // for (auto it : ret) {
  //	for (int x : it) {
  //		printf("%3d ", x);
  //	}
  //	puts("");
  //}
  // puts("------------------");

  return ret;
}

int main() {
  int r, c;
  cin >> r >> c;
  cin.ignore();

  vector<ii> sts, eds, fires;

  for (int i = 0; i < r; i++) {
    cin >> s[i];

    for (int j = 0; j < c; j++) {
      if (s[i][j] == 'F') {
        s[i][j] = '#';
        fires.push_back(ii(i, j));
      }

      if (s[i][j] == 'J') {
        s[i][j] = '.';
        sts.push_back(ii(i, j));
      }

      if (s[i][j] == '.') {
        if (i == 0 || i == r - 1 || j == 0 || j == c - 1) {
          eds.push_back(ii(i, j));
        }
      }

      // printf("processing %3d %3d : %c\n", i, j, s[i][j]);
    }
  }

  auto distF = BFS(r, c, fires);
  auto distJ = BFS(r, c, sts);

  int minn = inf;

  for (ii ed : eds) {
    int x = ed.first;
    int y = ed.second;

    // printf("checking %3d %3d : %3d %3d\n", x, y, distF[x][y], distJ[x][y]);

    if (distJ[x][y] == -1) {
      continue;
    }

    if (distF[x][y] == -1 || distF[x][y] > distJ[x][y]) {
      minn = min(minn, 1 + distJ[x][y]);
    }
  }

  if (minn == inf) {
    puts("IMPOSSIBLE");
  }

  else {
    cout << minn << endl;
  }

  return 0;
}