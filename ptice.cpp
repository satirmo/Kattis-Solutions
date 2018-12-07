#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;

  int maxx = 0;
  int adrian = 0;
  int bruno = 0;
  int goran = 0;

  string sadrian = "ABC";
  string sbruno = "BABC";
  string sgoran = "CCAABB";

  for (int i = 0; i < n; i++) {
    char c = s[i];

    if (sadrian[i % 3] == c) {
      adrian++;
      maxx = max(maxx, adrian);
    }

    if (sbruno[i % 4] == c) {
      bruno++;
      maxx = max(maxx, bruno);
    }

    if (sgoran[i % 6] == c) {
      goran++;
      maxx = max(maxx, goran);
    }
  }

  cout << maxx << endl;

  if (adrian == maxx) {
    puts("Adrian");
  }

  if (bruno == maxx) {
    puts("Bruno");
  }

  if (goran == maxx) {
    puts("Goran");
  }

  return 0;
}