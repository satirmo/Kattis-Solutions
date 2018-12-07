#include <bits/stdc++.h>

using namespace std;

const int maxn = 20005;

int head[maxn];
int knight[maxn];

int main() {
  int n, m;

  while (cin >> n >> m) {
    if (n == 0 && m == 0) {
      break;
    }

    for (int i = 0; i < n; i++) {
      scanf("%d", &head[i]);
    }

    for (int i = 0; i < m; i++) {
      scanf("%d", &knight[i]);
    }

    sort(head, head + n);
    sort(knight, knight + m);

    int cost = 0;

    int ihead = 0;
    int iknight = 0;

    while (ihead < n && iknight < m) {
      if (head[ihead] <= knight[iknight]) {
        ihead++;
        cost += knight[iknight];
      }

      iknight++;
    }

    string ans = (ihead == n) ? to_string(cost) : "Loowater is doomed!";

    cout << ans << endl;
  }

  return 0;
}