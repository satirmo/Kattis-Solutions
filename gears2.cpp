#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

const int maxn = 1005;

int state[maxn];
int x[maxn], y[maxn], r[maxn];
vi G[maxn];

int DFS(int u, int p) {
  int ret = 0;

  for (int v : G[u]) {
    if (state[v] == -1) {
      state[v] = p ^ 1;
      ret |= DFS(v, p ^ 1);
    }

    else if (state[v] != (p ^ 1)) {
      state[v] = 2;
      ret = 1;
    }
  }

  return ret;
}

int main() {
  int n;
  while (cin >> n) {
    memset(state, -1, sizeof state);
    for (int i = 0; i < maxn; i++) {
      G[i].clear();
    }

    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i] >> r[i];
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int dx = x[i] - x[j];
        int dy = y[i] - y[j];
        int dr = r[i] + r[j];

        if (dx * dx + dy * dy == dr * dr) {
          G[i].push_back(j);
        }
      }
    }

    state[0] = 0;
    int stuck = DFS(0, 0);

    if (stuck) {
      puts("-1");
    }

    else if (state[n - 1] == -1) {
      puts("0");
    }

    else {
      int f = __gcd(r[0], r[n - 1]);
      int a = r[n - 1] / f;
      int b = r[0] * ((state[0] == state[n - 1]) ? 1 : -1) / f;
      cout << a << " " << b << endl;
    }
  }

  return 0;
}