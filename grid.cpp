#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

const int maxn = 505;

int visit[maxn][maxn];
string a[maxn];
queue<ii> qu;

int BFS(int n, int m) {
  memset(visit, -1, sizeof visit);
  qu.push(ii(0, 0));
  visit[0][0] = 0;

  int ans = -1;
  while (!qu.empty()) {
    ii tp = qu.front();
    int x = tp.first;
    int y = tp.second;
    qu.pop();

    if (x == n - 1 && y == m - 1) {
      ans = visit[x][y];
    }

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i] * (a[x][y] - '0');
      int ny = y + dy[i] * (a[x][y] - '0');

      if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
        continue;
      }

      if (visit[nx][ny] != -1) {
        continue;
      }

      visit[nx][ny] = visit[x][y] + 1;
      qu.push(ii(nx, ny));
    }
  }

  return ans;
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    cin.ignore();

    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    cout << BFS(n, m) << endl;
  }

  return 0;
}