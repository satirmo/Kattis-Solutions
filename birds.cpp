#include <bits/stdc++.h>

using namespace std;

const int maxn = 20005;

int a[maxn];

int CheckSegment(int x, int y, int dist) { return (y - x - dist) / dist; }

int CalculateBirds(int n, int len, int dist) {
  int birds = 0;

  for (int i = 1; i < n; i++) {
    birds += CheckSegment(a[i - 1], a[i], dist);
  }

  return birds;
}

int main() {
  int len, dist, n;
  cin >> len >> dist >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  n += 2;

  a[n - 2] = -dist + 6;
  a[n - 1] = len + dist - 6;

  sort(a, a + n);

  int ans = CalculateBirds(n, len, dist);
  cout << ans << endl;

  return 0;
}