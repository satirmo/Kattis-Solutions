#include <bits/stdc++.h>

using namespace std;

int a[3];

char check(int x, int y, int z) {
  if (x + y == z) {
    return '+';
  }

  if (x - y == z) {
    return '-';
  }

  if (x * y == z) {
    return '*';
  }

  if (y != 0 && x / y == z) {
    return '/';
  }

  return '.';
}

int main() {
  int x, y, z;
  cin >> x >> y >> z;

  char a = check(x, y, z);
  char b = check(y, z, x);

  if (a != '.') {
    printf("%d%c%d=%d\n", x, a, y, z);
  }

  else {
    printf("%d=%d%c%d\n", x, y, b, z);
  }

  return 0;
}