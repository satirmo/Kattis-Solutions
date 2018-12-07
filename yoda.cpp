#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;

int tr[maxn];

string Check(string s) {
  if (s == "") {
    return "YODA";
  }

  long long tmp = stoll(s);
  string ret = to_string(tmp);

  return ret;
}

int main() {
  string s, t;
  cin >> s >> t;

  string sans = "", tans = "";
  int maxx = max(s.size(), t.size());

  s = string(maxx - s.size(), '0') + s;
  t = string(maxx - t.size(), '0') + t;

  for (int i = 0; i < maxx; i++) {
    char sv = (i < s.size()) ? s[i] : '0';
    char tv = (i < t.size()) ? t[i] : '0';

    if (sv < tv) {
      tans += tv;
    }

    else if (tv < sv) {
      sans += sv;
    }

    else {
      tans += tv;
      sans += sv;
    }
  }

  sans = Check(sans);
  tans = Check(tans);

  cout << sans << endl;
  cout << tans << endl;

  return 0;
}