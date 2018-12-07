#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;

int ga[maxn], ma[maxn];

int main() {
  int test;
  cin >> test;

  while (test--) {
    int g, m;
    cin >> g >> m;

    for (int i = 0; i < g; i++) {
      scanf("%d", &ga[i]);
    }

    for (int i = 0; i < m; i++) {
      scanf("%d", &ma[i]);
    }

    sort(ga, ga + g);
    sort(ma, ma + m);

    int gi = 0, mi = 0;
    while (gi != g && mi != m) {
      if (ga[gi] < ma[mi]) {
        gi++;
      }

      else {
        mi++;
      }
    }

    cout << (gi != g ? "Godzilla" : "MechaGodzilla") << endl;
  }
  return 0;
}