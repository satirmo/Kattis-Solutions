#include <bits/stdc++.h>

using namespace std;

const int maxn = 200005;

long long a[maxn];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a, a + n);

  long long ans = 0LL;
  for (int i = n - 3; i >= 0; i -= 3) {
    ans += a[i];
  }

  cout << ans << endl;

  return 0;
}