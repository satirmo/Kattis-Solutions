#include <bits/stdc++.h>

using namespace std;

const int maxn = 1 << 20;
const int inf = 1 << 30;

int dist[maxn];
queue<int> qu;

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < maxn; i++) {
    dist[i] = inf;
  }

  cin.ignore();

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    int si = 0;

    for (int j = 0; j < k; j++) {
      si |= (1 << j) * (s[j] - '0');
    }

    qu.push(si);
    dist[si] = 0;
  }

  int ans = -1;

  while (!qu.empty()) {
    int u = qu.front();
    qu.pop();

    ans = u;

    for (int i = 0; i < k; i++) {
      int v = u ^ (1 << i);

      if (dist[u] + 1 < dist[v]) {
        qu.push(v);
        dist[v] = dist[u] + 1;
      }
    }
  }

  for (int i = 0; i < k; i++) {
    cout << ((ans >> i) & 1);
  }

  cout << endl;

  return 0;
}