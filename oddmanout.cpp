#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, int> ii;

vector<ii> v;

int main() {
  int test;
  cin >> test;

  for (int t = 1; t <= test; t++) {
    int n;
    cin >> n;

    v.clear();

    for (int i = 1; i <= n; i++) {
      long long x;
      cin >> x;

      v.push_back(ii(x, i));
    }

    sort(v.begin(), v.end());

    long long ans = -1LL;

    if (v.size() == 1) {
      ans = v[0].first;
    }

    else {
      for (int i = 0; i < n - 1; i += 2) {
        if (v[i].first != v[i + 1].first) {
          ans = v[i].first;
          break;
        }
      }

      if (ans == -1LL) {
        ans = v[n - 1].first;
      }
    }

    printf("Case #%d: %lld\n", t, ans);
  }

  return 0;
}