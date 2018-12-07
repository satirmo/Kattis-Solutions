#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

vector<int> G[maxn];
bitset<maxn> visit;

void DFS(int u) {
  visit[u] = true;
  for (int v : G[u]) {
    if (visit[v] == false) {
      DFS(v);
    }
  }
}

int main() {
  int test;
  cin >> test;

  while (test--) {
    int n;
    cin >> n;

    int m;
    cin >> m;

    for (int i = 0; i < maxn; i++) {
      visit[i] = false;
      G[i].clear();
    }

    while (m--) {
      int x, y;
      scanf("%d %d", &x, &y);

      G[x].push_back(y);
      G[y].push_back(x);
    }

    int ans = -1;
    for (int i = 0; i < n; i++) {
      if (visit[i] == false) {
        DFS(i);
        ans++;
      }
    }

    cout << ans << endl;
  }

  return 0;
}