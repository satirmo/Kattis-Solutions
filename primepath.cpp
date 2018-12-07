#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

const int maxn = 10005;

int idx[maxn], dist[maxn];
bitset<maxn> bit;
vi prime, G[maxn];
queue<int> qu;

void Sieve() {
  bit.set();

  for (int i = 2; i < maxn; i++) {
    if (bit[i]) {
      for (int j = i * i; j < maxn; j += i) {
        bit[j] = false;
      }

      if (i > 1000) {
        idx[i] = prime.size();
        prime.push_back(i);
      }
    }
  }
}

void GenerateEdges() {
  for (int i = 0; i < prime.size(); i++) {
    string sp = to_string(prime[i]);

    for (int j = 0; j < i; j++) {
      string sq = to_string(prime[j]);

      int dist = 0;
      for (int k = 0; k < 4; k++) {
        dist += sp[k] != sq[k];
      }

      if (dist == 1) {
        G[i].push_back(j);
        G[j].push_back(i);
      }
    }
  }
}

int BFS(int st, int ed) {
  memset(dist, -1, sizeof dist);

  dist[st] = 0;
  qu.push(st);

  while (!qu.empty()) {
    int u = qu.front();
    qu.pop();

    for (int v : G[u]) {
      if (dist[v] == -1) {
        qu.push(v);
        dist[v] = 1 + dist[u];
      }
    }
  }

  return dist[ed];
}

int main() {
  Sieve();
  GenerateEdges();

  int test;
  cin >> test;

  while (test--) {
    int st, ed;
    cin >> st >> ed;

    int nst = idx[st];
    int ned = idx[ed];

    int minn = BFS(nst, ned);

    string ans = (minn != -1) ? to_string(minn) : "Impossible";
    cout << ans << endl;
  }

  return 0;
}