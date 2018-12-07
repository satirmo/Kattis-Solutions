#include <bits/stdc++.h>

using namespace std;

const int maxn = 10005;

long long sum[maxn], odd[maxn], even[maxn];

int main() {
  int test;
  cin >> test;

  for (long long i = 1; i < maxn; i++) {
    sum[i] = sum[i - 1] + i;
    odd[i] = odd[i - 1] + 2 * i - 1;
    even[i] = even[i - 1] + 2 * i;
  }

  while (test--) {
    int t, n;
    cin >> t >> n;

    cout << t << " " << sum[n] << " " << odd[n] << " " << even[n] << endl;
  }
  return 0;
}