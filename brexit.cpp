#include <bits/stdc++.h>

using namespace std;

const int maxn = 200005;

int degree[maxn], haveLeft[maxn];
queue<int> willLeave;
bitset<maxn> inUnion;
set<int> G[maxn];

int main() {
  int c, p, x, l;
  while (cin >> c >> p >> x >> l) {
    for (int i = 0; i < maxn; i++) {
      G[i].clear();
      degree[i] = 0;
      haveLeft[i] = 0;
    }

    while (p--) {
      int a, b;
      scanf("%d %d", &a, &b);

      degree[a]++;
      degree[b]++;
      G[a].insert(b);
      G[b].insert(a);
    }

    inUnion.set();

    inUnion[l] = false;
    willLeave.push(l);

    while (!willLeave.empty()) {
      int u = willLeave.front();
      willLeave.pop();

      for (int v : G[u]) {
        haveLeft[v]++;

        if (inUnion[v] && haveLeft[v] >= (degree[v] + 1) / 2) {
          inUnion[v] = false;
          willLeave.push(v);
        }
      }
    }

    cout << (inUnion[x] ? "stay" : "leave") << endl;
  }

  return 0;
}