#include <bits/stdc++.h>

using namespace std;

const int mod = 27;
const int maxn = 1005;

int conv[maxn];
int coefficients[] = {2, 4, 5, 7, 8, 10, 11, 13};

string Check(string s) {
  long long sum = 0LL;

  for (int i = 0; i < 8; i++) {
    sum += coefficients[i] * conv[s[i]];
  }

  if (sum % mod != conv[s[8]]) {
    return "Invalid";
  }

  long long ret = 0LL;

  for (int i = 0; i < 8; i++) {
    ret = 27LL * ret + conv[s[i]];
  }

  return to_string(ret);
}

int main() {
  string s = "0123456789ACDEFHJKLMNPRTVWX";

  for (int i = 0; i < s.size(); i++) {
    conv[s[i]] = i;
  }

  conv['B'] = conv['8'];
  conv['G'] = conv['C'];
  conv['I'] = conv['1'];
  conv['O'] = conv['0'];
  conv['Q'] = conv['0'];
  conv['S'] = conv['5'];
  conv['U'] = conv['V'];
  conv['Y'] = conv['V'];
  conv['Z'] = conv['2'];

  int test;
  cin >> test;

  while (test--) {
    int t;
    string s;

    cin >> t >> s;

    string ans = Check(s);
    printf("%d %s\n", t, ans.c_str());
  }

  return 0;
}