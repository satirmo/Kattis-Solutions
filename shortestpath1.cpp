#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, int> ii;

const int maxn = 10005;
const long long inf = 1LL << 60;

long long dist[maxn];
vector<ii> G[maxn];
set<ii> st;

void Dijkstra(int n, int s) {
  dist[s] = 0LL;
  st.insert(ii(0, s));

  while (!st.empty()) {
    int u = (*st.begin()).second;
    st.erase(st.begin());

    for (ii edge : G[u]) {
      long long w = edge.first;
      int v = edge.second;

      if (dist[u] + w < dist[v]) {
        st.erase(ii(dist[v], v));

        dist[v] = dist[u] + w;
        st.insert(ii(dist[v], v));
      }
    }
  }
}

int main() {
  int n, m, q, s;

  while (cin >> n >> m >> q >> s, n != 0 || m != 0 || q != 0 || s != 0) {
    for (int i = 0; i < maxn; i++) {
      G[i].clear();
      dist[i] = inf;
    }

    while (m--) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);

      G[u].push_back(ii(w, v));
    }

    Dijkstra(n, s);

    while (q--) {
      int v;
      scanf("%d", &v);

      if (dist[v] == inf) {
        puts("Impossible");
      }

      else {
        printf("%lld\n", dist[v]);
      }
    }

    puts("");
  }

  return 0;
}