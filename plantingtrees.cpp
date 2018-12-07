#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;

int tr[maxn];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> tr[i];
  }

  sort(tr, tr + n);
  reverse(tr, tr + n);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, tr[i] + i + 2);
  }

  cout << ans << endl;

  return 0;
}