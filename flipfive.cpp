#include <bits/stdc++.h>

using namespace std;

const int maxn = 605;
const int mov[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

string a[10];
int dist[maxn];
queue<int> qu;

int BFS(int st) {
  memset(dist, -1, sizeof dist);

  qu.push(st);
  dist[st] = 0;

  while (!qu.empty()) {
    int msk = qu.front();
    qu.pop();

    for (int i = 0; i < 9; i++) {
      int nmsk = msk ^ (1 << i);

      int x = i / 3;
      int y = i % 3;

      for (int j = 0; j < 4; j++) {
        int nx = x + mov[j][0];
        int ny = y + mov[j][1];

        if (nx < 0 || nx == 3 || ny < 0 || ny == 3) {
          continue;
        }

        int bit = 3 * nx + ny;
        nmsk ^= 1 << bit;
      }

      if (dist[nmsk] == -1) {
        dist[nmsk] = dist[msk] + 1;
        qu.push(nmsk);
      }
    }
  }

  int ed = (1 << 9) - 1;
  return dist[ed];
}

int main() {
  int test;
  cin >> test;
  cin.ignore();

  while (test--) {
    for (int i = 0; i < 3; i++) {
      cin >> a[i];
    }

    int msk = 0;
    for (int i = 0; i < 9; i++) {
      int val = (a[i / 3][i % 3] == '.') ? 1 : 0;
      msk |= val << i;
    }

    int ans = BFS(msk);
    cout << ans << endl;
  }

  return 0;
}