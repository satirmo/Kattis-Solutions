#include <bits/stdc++.h>

using namespace std;

const int maxn = 400005;

int pi[3 * maxn];

vector<string> Process(vector<int> a) {
  int n = a.size();
  vector<string> ret;
  sort(a.begin(), a.end());

  // for( int x : a ){
  // 	printf( "%7d", x );
  // }
  // puts( "" );

  for (int i = 0; i < n; i++) {
    int r = (a[(i + 1) % n] - a[i] + 360000) % 360000;
    ret.push_back(to_string(r));
    // printf( "%7d", r );
  }
  // puts( "" );

  return ret;
}

string Construct(vector<string> a) {
  string ret = "";

  for (string x : a) {
    ret += "-" + x;
  }

  return ret;
}

void ComputePrefix(string s) {
  memset(pi, 0, sizeof pi);

  int n = s.size();

  for (int i = 1; i < n; i++) {
    int k = pi[i - 1];

    while (k > 0 && s[i] != s[k]) {
      k = pi[k - 1];
    }

    if (s[i] == s[k]) {
      k++;
    }

    pi[i] = k;
  }
}

bool KnuthMorrisPratt(string p, string t) {
  string s = p + "$" + t;

  ComputePrefix(s);

  vector<int> occurrences;

  for (int i = p.size() + 1; i < s.size(); i++) {
    if (pi[i] == p.size()) {
      return true;
    }
  }

  return false;
}

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  vector<int> b(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<string> sa = Process(a);

  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  vector<string> sb = Process(b);

  string s = Construct(sa) + Construct(sa);
  string t = Construct(sb);

  // printf( "s: %s\n", s.c_str() );
  // printf( "t: %s\n", t.c_str() );

  string ans = (KnuthMorrisPratt(t, s)) ? "possible" : "impossible";
  cout << ans << endl;

  return 0;
}