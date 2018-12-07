#include <bits/stdc++.h>

using namespace std;

struct flight {
  int st, ed, t;

  flight(int st, int ed, int t) : st(st), ed(ed), t(t) {}
};

const int maxn = 1005;
const int inf = 1LL << 30;

int parent[maxn];
int G[maxn][maxn];
int inspection[maxn];
int direct[maxn][maxn];
int minn[maxn][maxn];
vector<flight> flights;
queue<int> qu;

void FloydWarshall(int n) {
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int candidate = minn[i][k] + minn[k][j];
        minn[i][j] = min(minn[i][j], candidate);
      }
    }
  }
}

void GenerateMatches(int m, int st, int ed) {
  for (int i = 0; i < m; i++) {
    int x = 2 * i;
    int y = 2 * i + 1;

    G[st][x] = 1;
    G[y][ed] = 1;
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      if (i == j) {
        continue;
      }

      int tim = direct[flights[i].st][flights[i].ed];

      if (flights[i].ed != flights[j].st) {
        tim += minn[flights[i].ed][flights[j].st];
      }

      if (flights[i].t + tim <= flights[j].t) {
        int x = 2 * i;
        int y = 2 * j + 1;

        G[x][y] = 1;
      }
    }
  }
}

int BFS(int n, int st, int ed) {
  while (!qu.empty()) {
    qu.pop();
  }

  memset(parent, -1, sizeof parent);

  qu.push(st);
  parent[st] = st;

  while (!qu.empty()) {
    int u = qu.front();
    qu.pop();
    // printf( "at u = %3d (%3d)\n", u, u/2 );

    for (int v = 0; v < n; v++) {
      if (G[u][v] > 0 && parent[v] == -1) {
        // printf( "\tadding v = %3d (%3d)\n", v, v/2 );
        qu.push(v);
        parent[v] = u;

        if (v == ed) {
          break;
        }
      }
    }

    if (parent[ed] != -1) {
      break;
    }
  }

  if (parent[ed] == -1) {
    // puts( "returning 0" );
    return 0;
  }

  int flow = inf;

  for (int v = ed; v != parent[v];) {
    int u = parent[v];

    flow = min(flow, G[u][v]);
    v = u;
  }

  for (int v = ed; v != parent[v];) {
    int u = parent[v];

    G[u][v] -= flow;
    G[v][u] += flow;
    v = u;
  }

  return flow;
}

int EdmondKarp(int n, int st, int ed) {
  // puts( "extending flow" );
  int maxFlow = 0;

  while (true) {
    // puts( "FINDING NEW PATH" );
    int flow = BFS(n, st, ed);

    if (flow == 0) {
      break;
    }

    maxFlow += flow;
  }

  return maxFlow;
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> inspection[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int flightTime;
      cin >> flightTime;

      direct[i][j] = flightTime + inspection[j];
      minn[i][j] = flightTime + inspection[j];
    }
  }

  FloydWarshall(n);

  for (int i = 0; i < m; i++) {
    int st, ed, t;
    cin >> st >> ed >> t;

    flights.push_back(flight(st - 1, ed - 1, t));
  }

  int vertices = 2 * m + 2;
  int st = 2 * m;
  int ed = st + 1;

  GenerateMatches(m, st, ed);
  int flightsAvoided = EdmondKarp(vertices, st, ed);

  int ans = m - flightsAvoided;
  cout << ans << endl;

  return 0;
}