#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int maxn = 1505;

int positive[maxn], negative[maxn];

long long CalculateTrips(int *v, int k) {
  long long ret = 0LL;

  for (int i = maxn - 1; i > 0; i--) {
    if (v[i] > 0) {
      int current = v[i];

      for (int j = i - 1; j > 0; j--) {
        if (current % k == 0) {
          break;
        }

        int take = min(v[j], k - (current % k));

        v[j] -= take;
        current += take;
      }

      long long dist = 2 * i;
      long long trips = (current + (k - 1)) / k;
      ret += dist * trips;
    }
  }

  return ret;
}

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    int x, cards;
    cin >> x >> cards;

    if (x > 0) {
      positive[x] += cards;
    }

    else if (x < 0) {
      negative[-x] += cards;
    }
  }

  long long ptrips = CalculateTrips(positive, k);
  long long ntrips = CalculateTrips(negative, k);

  long long ans = ptrips + ntrips;
  cout << ans << endl;

  return 0;
}