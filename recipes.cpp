#include <bits/stdc++.h>

using namespace std;

struct Data {
  string name;
  double w, p;
};

Data a[25];

int main() {
  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    printf("Recipe # %d\n", t + 1);

    int r;
    double p, d;
    cin >> r >> p >> d;

    double sf = d / p;

    int idx = 0;
    for (int i = 0; i < r; i++) {
      cin.ignore();
      cin >> a[i].name >> a[i].w >> a[i].p;

      if (a[i].p == 100.0) {
        idx = i;
      }
    }

    double sw = a[idx].w * sf;

    for (int i = 0; i < r; i++) {
      if (i == idx) {
        a[i].w *= sf;
      }

      else {
        a[i].w = sw * a[i].p / 100.0;
      }

      printf("%s %.1lf\n", a[i].name.c_str(), a[i].w);
    }

    puts("----------------------------------------");
  }
}