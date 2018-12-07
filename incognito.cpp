#include <bits/stdc++.h>

using namespace std;

map<string, int> mapa;

int main() {
  int test;
  cin >> test;

  while (test--) {
    int n;
    cin >> n;
    cin.ignore();

    while (n--) {
      string garment, type;
      cin >> garment >> type;

      mapa[type]++;
    }

    int outfits = 1;

    for (auto it : mapa) {
      outfits *= (it.second + 1);
    }

    int ans = outfits - 1;
    cout << ans << endl;

    mapa.clear();
  }

  return 0;
}