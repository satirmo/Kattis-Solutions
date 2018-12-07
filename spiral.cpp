#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int maxd = 205;
const int maxn = 10005;
const int offset = 102;
const int mov[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int spiral[maxd][maxd];
ii loc[maxn];
vector<int> prime;
bitset<maxn> bit;
queue<ii> qu;
int dist[maxd][maxd];

void Sieve() {
  bit.set();
  bit[0] = false;
  bit[1] = false;

  for (int i = 2; i < maxn; i++) {
    if (bit[i]) {
      for (int j = i * i; j < maxn; j += i) {
        bit[j] = false;
      }
    }
  }
}

void GenerateSpiral() {
  int id = 1;
  int magnitude = 1;
  int x = offset, y = offset;

  for (int i = 1; id < maxn; i++) {
    for (int j = 0; j < magnitude && id < maxn; j++, id++) {
      loc[id] = ii(x, y);
      spiral[x][y] = id;
      // printf("n = %5d, x = %4d, y = %4d\n", id, x - offset, y - offset);

      x += mov[i % 4][0];
      y += mov[i % 4][1];
    }

    if (i % 2 == 0) {
      magnitude++;
    }
  }
}

string BFS(ii st, ii ed) {
  memset(dist, -1, sizeof dist);

  int sx = st.first;
  int sy = st.second;

  dist[sx][sy] = 0;
  qu.push(st);

  while (!qu.empty()) {
    ii u = qu.front();
    qu.pop();

    int ux = u.first;
    int uy = u.second;

    for (int i = 0; i < 4; i++) {
      int vx = ux + mov[i][0];
      int vy = uy + mov[i][1];

      if (vx < 0 || vx >= maxd || vy < 0 || vy >= maxd) {
        continue;
      }

      if (dist[vx][vy] != -1 || bit[spiral[vx][vy]]) {
        continue;
      }

      dist[vx][vy] = 1 + dist[ux][uy];
      qu.push(ii(vx, vy));
    }

    // printf("at %4d %4d (%5d) : %6d\n", ux-offset, uy-offset, spiral[ux][uy],
    // dist[ux][uy]);
  }

  int ex = ed.first;
  int ey = ed.second;

  string ret = (dist[ex][ey] == -1) ? "impossible" : to_string(dist[ex][ey]);

  return ret;
}

int main() {
  Sieve();
  GenerateSpiral();

  int tst, ted;

  for (int t = 1; cin >> tst >> ted; t++) {
    ii st = loc[tst];
    ii ed = loc[ted];

    string ans = BFS(st, ed);
    printf("Case %d: %s\n", t, ans.c_str());
  }

  return 0;
}