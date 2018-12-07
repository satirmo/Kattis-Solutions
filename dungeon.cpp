#include <bits/stdc++.h>

using namespace std;

struct Location {
  int a, b, c;

  Location() {}

  Location(int a, int b, int c) {
    this->a = a;
    this->b = b;
    this->c = c;
  }
};

const int maxn = 35;
const int mov[][3] = {{1, 0, 0},
                      {-1, 0, 0,},  // up/down
                      {0, 1, 0},
                      {0, -1, 0},  // north/south
                      {0, 0, 1},
                      {0, 0, -1}};  // east/west

int dist[maxn][maxn][maxn];
string dungeon[maxn][maxn];
queue<Location> qu;

bool IsValidLocation(Location loc, int l, int r, int c) {
  if (loc.a < 0 || l <= loc.a) {
    return false;
  }

  if (loc.b < 0 || r <= loc.b) {
    return false;
  }

  if (loc.c < 0 || c <= loc.c) {
    return false;
  }

  if (dungeon[loc.a][loc.b][loc.c] == '#') {
    return false;
  }

  return true;
}

int BFS(Location st, Location ed, int l, int r, int c) {
  memset(dist, -1, sizeof dist);

  qu.push(st);
  dist[st.a][st.b][st.c] = 0;

  while (!qu.empty()) {
    Location u = qu.front();
    qu.pop();

    for (int i = 0; i < 6; i++) {
      int va = u.a + mov[i][0];
      int vb = u.b + mov[i][1];
      int vc = u.c + mov[i][2];

      Location v = Location(va, vb, vc);

      if (!IsValidLocation(v, l, r, c)) {
        continue;
      }

      if (dist[va][vb][vc] != -1) {
        continue;
      }

      qu.push(v);
      dist[va][vb][vc] = 1 + dist[u.a][u.b][u.c];
    }
  }

  return dist[ed.a][ed.b][ed.c];
}

int main() {
  int l, r, c;

  while (cin >> l >> r >> c) {
    if (l == 0 && r == 0 && c == 0) {
      break;
    }

    cin.ignore();

    Location st, ed;

    for (int i = 0; i < l; i++) {
      for (int j = 0; j < r; j++) {
        cin >> dungeon[i][j];

        for (int k = 0; k < c; k++) {
          if (dungeon[i][j][k] == 'S') {
            dungeon[i][j][k] = '.';
            st = Location(i, j, k);
          }

          if (dungeon[i][j][k] == 'E') {
            dungeon[i][j][k] = '.';
            ed = Location(i, j, k);
          }
        }
      }
    }

    int ans = BFS(st, ed, l, r, c);

    if (ans == -1) {
      puts("Trapped!");
    }

    else {
      printf("Escaped in %d minute(s).\n", ans);
    }
  }

  return 0;
}