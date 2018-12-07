#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int maxn = 100005;

vector<int> LIS(vector<int> a) {
  int n = a.size();

  if (n == 0) {
    return vector<int>(0);
  }

  vector<int> lis;
  vector<int> parent;
  vector<vector<int> > history;

  for (int i = 0; i < n; i++) {
    int x = a[i];
    auto it = lower_bound(lis.begin(), lis.end(), x);

    if (it == lis.end()) {
      lis.push_back(x);

      int len = history.size();
      int p = (len == 0) ? -1 : history[len - 1].back();
      parent.push_back(p);
      history.push_back(vector<int>(1, i));
    }

    else {
      *it = x;

      int idx = it - lis.begin();
      int p = (idx == 0) ? -1 : history[idx - 1].back();
      parent.push_back(p);
      history[it - lis.begin()].push_back(i);
    }
  }

  vector<int> ret;

  for (int i = history.back().back(); i != -1; i = parent[i]) {
    ret.push_back(i);
  }

  reverse(ret.begin(), ret.end());

  return ret;
}

int main() {
  int n;
  cin >> n;

  vector<int> a(n + 2);

  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  a[n + 1] = n + 1;

  auto increasing = LIS(a);

  auto b = a;
  reverse(b.begin(), b.end());
  for (int i = 0; i < b.size(); i++) {
    b[i] *= -1;
  }

  auto decreasing = LIS(b);

  int r = increasing.size();

  for (int i = 0; i < r; i++) {
    increasing[i] = a[increasing[i]];
  }

  reverse(decreasing.begin(), decreasing.end());
  for (int i = 0; i < r; i++) {
    decreasing[i] = -b[decreasing[i]];
  }

  vector<int> critical;

  for (int i = 0, j = 0; i < r && j < r;) {
    if (increasing[i] == 0 || increasing[i] == n + 1) {
      i++;
      continue;
    }

    if (decreasing[j] == 0 || decreasing[j] == n + 1) {
      j++;
      continue;
    }

    if (increasing[i] < decreasing[j]) {
      i++;
    }

    else if (increasing[i] > decreasing[j]) {
      j++;
    }

    else {
      critical.push_back(increasing[i]);
      i++, j++;
    }
  }

  if (critical.size() == 0) {
    puts("-1");
  }

  else {
    bool space = false;

    for (int x : critical) {
      if (space) {
        printf(" ");
      }

      space = true;
      cout << x;
    }

    puts("");
  }

  return 0;
}