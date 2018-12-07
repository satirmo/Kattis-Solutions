#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

struct Edge {
  int u, v;
  double w;

  Edge(int u, int v, double dist) {
    this->u = u;
    this->v = v;
    this->w = dist;
  }
};

int par[maxn];
double x[maxn], y[maxn];
vector<Edge> G;

bool Cmp(const Edge &a, const Edge &b) { return a.w < b.w; }

int Find(int x) {
  while (x != par[x]) {
    int &p = par[x];

    p = par[p];
    x = par[p];
  }

  return x;
}

double Kruskal(int n) {
  sort(G.begin(), G.end(), Cmp);

  int cnt = 0;
  double ret = 0.0;

  for (int i = 0; cnt < n - 1; i++) {
    int su = Find(G[i].u);
    int sv = Find(G[i].v);

    if (su != sv) {
      cnt++;
      ret += G[i].w;
      par[su] = par[sv];
    }
  }

  return ret;
}

int main() {
  int test;
  cin >> test;

  while (test--) {
    int n;
    cin >> n;

    G.clear();
    for (int i = 0; i < n; i++) {
      scanf("%lf %lf", &x[i], &y[i]);
      par[i] = i;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        double dist = hypot(x[i] - x[j], y[i] - y[j]);
        G.push_back(Edge(i, j, dist));
      }
    }

    double ans = Kruskal(n);
    printf("%.10lf\n", ans);
  }

  return 0;
}