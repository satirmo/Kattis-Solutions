#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<string, ll> sl;

const int maxn = 1005;
const ll mod = 1000000007LL;

int n, m;
ll dp[maxn];
string s;
vector<sl> v, tbl[maxn];

ll F(int idx) {
  if (idx == m) {
    return 1LL;
  }

  // printF( "will check %d\n", idx );

  ll &ret = dp[idx];

  if (ret != -1) {
    return ret;
  }

  ret = 0LL;

  for (sl t : tbl[s[idx]]) {
    if (t.first.size() + idx > m) {
      continue;
    }

    bool flag = true;
    for (int i = 0; i < t.first.size(); i++) {
      if (t.first[i] != s[idx + i]) {
        flag = false;
      }
    }
    if (!flag) {
      continue;
    }

    // printF( "at idx = %d (%c), will append %s\n", idx, s[ idx ],
    // t.first.c_str() );

    ll val = (F(idx + t.first.size()) * t.second) % mod;
    ret = (ret + val) % mod;
  }

  return ret;
}

int main() {
  while (cin >> n) {
    cin.ignore();
    cin >> s;
    m = s.size();

    v.clear();
    for (int i = 0; i < maxn; i++) {
      tbl[i].clear();
    }

    for (int i = 0; i < n; i++) {
      ll val;
      string t;

      cin >> t >> val;
      cin.ignore();

      v.push_back(sl(t, val));
    }

    sort(v.begin(), v.end());

    for (sl x : v) {
      tbl[x.first[0]].push_back(x);
    }

    memset(dp, -1, sizeof dp);
    cout << F(0) << endl;
  }
  return 0;
}