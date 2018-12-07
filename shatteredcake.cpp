#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  long long w;
  cin >> w >> n;

  long long area = 0LL;

  for (int i = 0; i < n; i++) {
    long long w, l;
    cin >> w >> l;

    area += w * l;
  }

  long long ans = area / w;
  cout << ans << endl;

  return 0;
}