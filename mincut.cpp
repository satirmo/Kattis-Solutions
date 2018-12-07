#include <bits/stdc++.h>

using namespace std;

const int maxn = 505;
const long long inf = 1LL << 60;

int parent[maxn];
long long G[maxn][maxn];
queue<int> qu;
bitset<maxn> visited, isInU;

long long FindFlow(int n, int st, int ed) {
  while (!qu.empty()) {
    qu.pop();
  }

  memset(parent, -1, sizeof parent);

  parent[st] = st;
  qu.push(st);

  while (!qu.empty()) {
    int u = qu.front();
    qu.pop();

    for (int v = 0; v < n; v++) {
      if (G[u][v] > 0LL && parent[v] == -1) {
        parent[v] = u;
        qu.push(v);

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
    return 0LL;
  }

  long long flow = inf;

  for (int v = ed; parent[v] != v;) {
    int u = parent[v];

    flow = min(flow, G[u][v]);
    v = u;
  }

  for (int v = ed; parent[v] != v;) {
    int u = parent[v];

    G[u][v] -= flow;
    G[v][u] += flow;
    v = u;
  }

  return flow;
}

void EdmondKarp(int n, int st, int ed) {
  while (true) {
    long long flow = FindFlow(n, st, ed);

    if (flow == 0LL) {
      break;
    }
  }
}

void FindVertices(int n, int u) {
  visited[u] = true;

  for (int v = 0; v < n; v++) {
    if (!visited[v] && G[u][v] > 0LL) {
      FindVertices(n, v);
    }
  }
}

int main() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;

  while (m--) {
    int u, v;
    long long w;
    cin >> u >> v >> w;

    if (u == v) {
      continue;
    }

    G[u][v] += w;
  }

  // for (int i = 0; i < n; i++) {
  //	for (int j = 0; j < n; j++) {
  //		printf("%4lld", G[i][j]);
  //	}
  //	puts("");
  //}

  EdmondKarp(n, s, t);
  FindVertices(n, s);

  cout << visited.count() << endl;

  long long cutw = 0LL;

  for (int i = 0; i < n; i++) {
    if (visited[i]) {
      cout << i << endl;

      // for (int j = 0; j < n; j++) {
      //	if (G[i][j] == 0LL && G[j][i] > 0LL) {
      //		cutw += G[i][j] + G[j][i];
      //	}
      //}
    }
  }

  // printf("cut weight: %10lld\n", cutw);

  // for (int i = 0; i < n; i++) {
  //	for (int j = 0; j < n; j++) {
  //		printf("%4lld", G[i][j]);

  //		if (G[i][j] == 0LL && G[j][i] > 0LL) {
  //			cutw += G[j][i];
  //		}
  //	}
  //	puts("");
  //}

  return 0;
}