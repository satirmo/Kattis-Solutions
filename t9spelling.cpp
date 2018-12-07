#include <bits/stdc++.h>

using namespace std;

string conv[1005];

void FillConv() {
  conv[' '] = "0";
  conv['a'] = "2";
  conv['b'] = "22";
  conv['c'] = "222";
  conv['d'] = "3";
  conv['e'] = "33";
  conv['f'] = "333";
  conv['g'] = "4";
  conv['h'] = "44";
  conv['i'] = "444";
  conv['j'] = "5";
  conv['k'] = "55";
  conv['l'] = "555";
  conv['m'] = "6";
  conv['n'] = "66";
  conv['o'] = "666";
  conv['p'] = "7";
  conv['q'] = "77";
  conv['r'] = "777";
  conv['s'] = "7777";
  conv['t'] = "8";
  conv['u'] = "88";
  conv['v'] = "888";
  conv['w'] = "9";
  conv['x'] = "99";
  conv['y'] = "999";
  conv['z'] = "9999";
}

int main() {
  int test;
  cin >> test;
  cin.ignore();

  FillConv();

  for (int t = 1; t <= test; t++) {
    printf("Case #%d: ", t);

    string line;
    getline(cin, line);

    char lstChr = '-';

    for (char c : line) {
      if (lstChr == conv[c][0]) {
        printf(" ");
      }

      lstChr = conv[c][0];
      printf("%s", conv[c].c_str());
    }

    puts("");
  }

  return 0;
}