#include <bits/stdc++.h>

using namespace std;

int val[205][5];

void GenerateValues() {
  val['A'][0] = 11;
  val['A'][1] = 11;

  val['K'][0] = 4;
  val['K'][1] = 4;

  val['Q'][0] = 3;
  val['Q'][1] = 3;

  val['J'][0] = 2;
  val['J'][1] = 20;

  val['T'][0] = 10;
  val['T'][1] = 10;

  val['9'][0] = 0;
  val['9'][1] = 14;
}

int main() {
  GenerateValues();

  int n;
  char s;
  cin >> n >> s;
  cin.ignore();

  int pts = 0;

  while (n--) {
    for (int i = 0; i < 4; i++) {
      string card;
      cin >> card;
      pts += val[card[0]][card[1] == s];
    }
  }

  cout << pts << endl;

  return 0;
}