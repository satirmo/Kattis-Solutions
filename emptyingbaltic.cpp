#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, ii> li;

const int maxn = 505;
const int mov[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0},
                      {0, 1},   {1, -1}, {1, 0},  {1, 1}};

bool visit[maxn][maxn];
long long G[maxn][maxn];
priority_queue<li> pq;

long long Dijkstra(int n, int m, int x, int y) {
  long long ret = 0LL;

  visit[x][y] = true;

  li st = li(G[x][y], ii(x, y));
  pq.push(st);

  while (!pq.empty()) {
    li u = pq.top();
    pq.pop();

    long long h = u.first;
    int x = u.second.first;
    int y = u.second.second;

    ret += h;

    for (int i = 0; i < 9; i++) {
      int nx = x + mov[i][0];
      int ny = y + mov[i][1];

      if (nx < 0 || n <= nx || ny < 0 || m <= ny) {
        continue;
      }

      if (visit[nx][ny]) {
        continue;
      }

      visit[nx][ny] = true;

      long long nh = min(h, G[nx][ny]);
      li v = li(nh, ii(nx, ny));
      pq.push(v);
    }
  }

  return ret;
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int h;
      cin >> h;

      visit[i][j] = false;
      G[i][j] = (h > 0) ? 0LL : -h;
    }
  }

  int x, y;
  cin >> x >> y;

  long long ans = Dijkstra(n, m, x - 1, y - 1);
  cout << ans << endl;

  return 0;
}