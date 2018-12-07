#include <bits/stdc++.h>

using namespace std;

int main() {
  int w, h;

  while (cin >> w >> h) {
    if (w == 0 && h == 0) {
      break;
    }

    int n;
    cin >> n;
    cin.ignore();

    int actualx = 0, actualy = 0;
    int thinkx = 0, thinky = 0;

    while (n--) {
      int steps;
      char dir;

      cin >> dir >> steps;

      if (dir == 'u') {
        actualy = min(actualy + steps, h - 1);
        thinky += steps;
      }

      if (dir == 'd') {
        actualy = max(actualy - steps, 0);
        thinky -= steps;
      }

      if (dir == 'l') {
        actualx = max(actualx - steps, 0);
        thinkx -= steps;
      }

      if (dir == 'r') {
        actualx = min(actualx + steps, w - 1);
        thinkx += steps;
      }
    }

    printf("Robot thinks %d %d\n", thinkx, thinky);
    printf("Actually at %d %d\n\n", actualx, actualy);
  }

  return 0;
}