#include <bits/stdc++.h>

using namespace std;

const int inf = 1 << 30;
const int maxn = 3005;

typedef pair<long long, long long> ii;
typedef pair<long long, ii> iii;

int par[maxn];
int G[maxn][maxn];
bitset<maxn> visit;
queue<int> qu;
map<string, int> nameToId;

string Conv(int x) {
  for (auto it : nameToId) {
    if (it.second == x) {
      return it.first;
    }
  }
}

int BFS(int n, int st, int ed) {
  while (!qu.empty()) {
    qu.pop();
  }

  visit.reset();
  memset(par, -1, sizeof par);

  qu.push(st);
  visit[st] = true;

  while (!qu.empty()) {
    int u = qu.front();
    qu.pop();

    bool foundSink = false;

    for (int v = 0; v < n; v++) {
      if (G[u][v] > 0 && visit[v] == false) {
        qu.push(v);
        visit[v] = true;
        par[v] = u;

        if (v == ed) {
          foundSink = true;
          break;
        }
      }
    }

    if (foundSink) {
      break;
    }
  }

  if (visit[ed] == false) {
    return 0;
  }

  int ret = inf;

  for (int v = ed; v != st;) {
    int u = par[v];
    ret = min(ret, G[u][v]);
    v = u;
  }

  // printf("%4s", Conv(ed).c_str());

  for (int v = ed; v != st;) {
    int u = par[v];
    G[u][v] -= ret;
    G[v][u] += ret;
    v = u;

    // printf(" -> %4s", Conv(u).c_str());
  }
  // puts("");

  return ret;
}

int EdmondKarp(int n, int st, int ed) {
  int ret = 0;

  while (true) {
    int flow = BFS(n, st, ed);

    if (flow == 0) {
      break;
    }

    /*for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                    printf("%3d", G[i][j]);
            }
            puts("");
    }*/

    ret += flow;
  }

  return ret;
}

int GetId(string s) {
  if (nameToId.count(s) == 0) {
    nameToId[s] = nameToId.size();
  }

  return nameToId[s];
}

int main() {
  int s, r, f, t;
  cin >> s >> r >> f >> t;

  string source = "_source";
  string sink = "_sink";

  int st = GetId(source);
  int ed = GetId(sink);

  for (int i = 0; i < r; i++) {
    string name;
    cin >> name;

    int id = GetId(name);

    G[0][id] = 1;
    // printf("adding %3d -> %3d\n", 0, id);
  }

  for (int i = 0; i < f; i++) {
    string name;
    cin >> name;

    int id = GetId(name);

    G[id][1] = 1;
    // printf("adding %3d -> %3d\n", id, 1);
  }

  for (int i = 0; i < t; i++) {
    // puts("------------------");
    string sx = "_a" + to_string(i);
    string sy = "_b" + to_string(i);

    int xid = GetId(sx);
    int yid = GetId(sy);

    int x = 2 + r + f + 2 * i;
    int y = x + 1;

    if (xid != x || yid != y) {
      // return 293982;
      // cout << "NOT WORKING: " << i << " " << x << " " << xid << " " << y << "
      // " << yid << endl;
      // break;
    }

    G[x][y] = 1;
    // printf("adding %3d -> %3d\n", xid, yid);
  }

  for (int i = 0; i < t; i++) {
    int xid = 2 + r + f + 2 * i;
    int yid = xid + 1;

    int m;
    cin >> m;

    while (m--) {
      string name;
      cin >> name;

      int id = GetId(name);

      if (id < 2 + r) {
        G[id][xid] = 1;
        // printf("adding %3d -> %3d\n", id, xid);
      }

      else if (id < 2 + r + f) {
        G[yid][id] = 1;
        // printf("adding %3d -> %3d\n", yid, id);
      }

      else {
        G[id][xid] = 1;
        G[yid][id] = 1;
        // printf("adding %3d -> %3d\n", id, xid);
        // printf("adding %3d -> %3d\n", yid, id);
      }
    }
  }

  int n = nameToId.size();

  /*printf("n = %3d\n", n);
  printf("st = %3d\n", st);
  printf("ed = %3d\n", ed);*/

  /*for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
                  printf("%3d", G[i][j]);
          }
          puts("");
  }*/

  for (auto it : nameToId) {
    // printf("%10s ... %10d\n", it.first.c_str(), it.second );
  }

  int ans = EdmondKarp(n, st, ed);
  cout << ans << endl;

  return 0;
}