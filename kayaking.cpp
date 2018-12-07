#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, long long> ll;

const long long inf = 1LL << 60;
const int maxn = 100005;

vector<long long> cayaks;
vector<ii> types;

bool CheckSpeed(vector<long long> n, vector<long long> s, long long speed) {
  int idx = 0;

  for (ii type : types) {
    while (true) {
      if (idx == cayaks.size()) {
        break;
      }

      if (n[type.first] < 1 + (type.first == type.second)) {
        break;
      }

      if (n[type.second] < 1 + (type.first == type.second)) {
        break;
      }

      int v = cayaks[idx] * (s[type.first] + s[type.second]);

      if (v < speed) {
        break;
      }

      idx++;
      n[type.first]--;
      n[type.second]--;
    }
  }

  return (idx == cayaks.size());
}

int main() {
  vector<long long> n(3), s(3);

  for (int i = 0; i < 3; i++) {
    cin >> n[i];
  }

  for (int i = 0; i < 3; i++) {
    cin >> s[i];
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j <= i; j++) {
      types.push_back(ii(i, j));
    }
  }

  for (int i = 0; i < types.size(); i++) {
    for (int j = i; j < types.size(); j++) {
      long long si = s[types[i].first] + s[types[i].second];
      long long sj = s[types[j].first] + s[types[j].second];

      if (sj < si) {
        swap(types[i], types[j]);
      }
    }
  }

  int m = (n[0] + n[1] + n[2]) / 2;

  for (int i = 0; i < m; i++) {
    long long cayak;
    cin >> cayak;

    cayaks.push_back(cayak);
  }

  sort(cayaks.begin(), cayaks.end(), greater<long long>());

  long long low = 0, high = inf;

  while (low < high) {
    long long mid = (low + high + 1) / 2;

    if (CheckSpeed(n, s, mid)) {
      low = mid;
    }

    else {
      high = mid - 1;
    }
  }

  cout << low << endl;

  return 0;
}