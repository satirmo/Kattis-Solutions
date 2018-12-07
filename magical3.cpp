#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

using namespace std;

const ll upto = 1000005;

set<ll> st;

string CalcBase(ll n) {
  st.clear();

  if (n < 3) {
    return "No such base";
  }

  if (n == 3) {
    return to_string(4LL);
  }

  n -= 3LL;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0LL) {
      st.insert(i);
      st.insert(n / i);
    }
  }

  for (ll x : st) {
    if (x > 3) {
      return to_string(x);
    }
  }

  return "No such base";
}

int main() {
  ll n;
  while (cin >> n, n != 0LL) {
    cout << CalcBase(n) << endl;
  }

  return 0;
}