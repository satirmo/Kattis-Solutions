#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;
const int inf = 1 << 30;

struct Edge {
  int u, v;
  char color;

  Edge(int u, int v, char color) : u(u), v(v), color(color) {}

  bool operator<(Edge a) { return color == 'R'; }

  bool operator!=(Edge a) {
    if (u != a.u) {
      return true;
    }

    if (v != a.v) {
      return true;
    }

    return color != a.color;
  }
};

int par[maxn];
vector<Edge> reds, blues, mandatoryBlues, G;

int Find(int x) {
  while (x != par[x]) {
    int &p = par[x];

    p = par[p];
    x = par[p];
  }

  return x;
}

void Kruskal(int k, vector<Edge> Edges) {
  for (Edge e : Edges) {
    if (G.size() >= k) {
      return;
    }

    int su = Find(e.u);
    int sv = Find(e.v);

    if (su != sv) {
      par[su] = par[sv];
      G.push_back(e);
    }
  }
}

int FindSpanningTree(int n, int k) {
  for (int i = 0; i < maxn; i++) {
    par[i] = i;
  }

  Kruskal(inf, reds);
  Kruskal(inf, blues);

  for (Edge e : G) {
    if (e.color == 'B') {
      mandatoryBlues.push_back(e);
    }
  }

  G.clear();

  for (int i = 0; i < maxn; i++) {
    par[i] = i;
  }

  Kruskal(inf, mandatoryBlues);
  Kruskal(k, blues);

  int blueEdges = G.size();

  Kruskal(inf, reds);

  if (G.size() == n - 1 && blueEdges == k) {
    return 1;
  }

  return 0;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  while (m--) {
    cin.ignore();

    char color;
    int u, v;
    cin >> color >> u >> v;

    if (color == 'R') {
      reds.push_back(Edge(u, v, color));
    }

    else {
      blues.push_back(Edge(u, v, color));
    }
  }

  int ans = FindSpanningTree(n, k);
  cout << ans << endl;

  return 0;
}