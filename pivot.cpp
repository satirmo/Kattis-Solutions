#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;
const long long inf = 1LL << 60;

long long a[maxn];
long long minn[maxn];
long long maxx[maxn];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  maxx[0] = -inf;
  for (int i = 1; i < n; i++) {
    maxx[i] = max(maxx[i - 1], a[i - 1]);
  }

  minn[n - 1] = inf;
  for (int i = n - 2; i >= 0; i--) {
    minn[i] = min(minn[i + 1], a[i + 1]);
  }

  int ans = 0;

  for (int i = 0; i < n; i++) {
    if (maxx[i] < a[i] && a[i] < minn[i]) {
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}