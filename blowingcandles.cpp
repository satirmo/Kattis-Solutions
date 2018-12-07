#include <bits/stdc++.h>

using namespace std;

const int maxn = 200005;
const double eps = 1e-9;

struct Point {
  double x, y;

  bool operator<(const Point &p) const {
    return x < p.x || (x == p.x && y < p.y);
  }
};

int Cross(const Point &O, const Point &A, const Point &B) {
  double v = (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);

  if (abs(v) < eps) {
    return 0;
  }

  return (v > eps) ? 1 : -1;
}

vector<Point> ConvexHull(vector<Point> P) {
  int n = P.size();
  int k = 0;

  if (n <= 3) {
    return P;
  }

  vector<Point> H(2 * n);

  sort(P.begin(), P.end());

  for (int i = 0; i < n; i++) {
    while (k >= 2 && Cross(H[k - 2], H[k - 1], P[i]) <= 0) k--;
    H[k++] = P[i];
  }

  for (int i = n - 1, t = k + 1; i > 0; i--) {
    while (k >= t && Cross(H[k - 2], H[k - 1], P[i - 1]) <= 0) k--;
    H[k++] = P[i - 1];
  }

  H.resize(k - 1);
  return H;
}

double DistancePointToLine(Point P, Point Q, Point R) {
  // printf( "CALCULATING DISTANCE:\n" );
  // printf( "\tPOINT: %8.5lf %8.5lf\n", P.x, P.y );
  // printf( "\tLINE: %8.5lf %8.5lf\n", Q.x, Q.y );
  // printf( "\tLINE: %8.5lf %8.5lf\n", R.x, R.y );
  double a = (R.y - Q.y) * P.x - (R.x - Q.x) * P.y + R.x * Q.y - R.y * Q.x;
  double b = (R.y - Q.y) * (R.y - Q.y) + (R.x - Q.x) * (R.x - Q.x);

  // printf( "\tDISTANCE: %8.5lf\n", a*a/b );
  return a * a / b;
}

int main() {
  int n;
  double r;
  cin >> n >> r;

  vector<Point> points;

  for (int i = 0; i < n; i++) {
    double x, y;
    scanf("%lf %lf", &x, &y);

    Point point;
    point.x = x;
    point.y = y;

    points.push_back(point);
  }

  vector<Point> hull = ConvexHull(points);

  // for( int i = 0; i < hull.size(); i++ ){
  // 	printf( "HULL: %8.5lf %8.5lf\n", hull[ i ].x, hull[ i ].y );
  // }

  int k = hull.size();
  double ans = -1.0;

  for (int i = 0, j = 1; i < k; i++) {
    int i1 = (i + 1) % k;
    int j1 = (j + 1) % k;

    double d = DistancePointToLine(hull[j], hull[i], hull[i1]);
    double d1 = DistancePointToLine(hull[j1], hull[i], hull[i1]);

    while (d < d1) {
      j = j1;
      d = d1;

      j1 = (j1 + 1) % hull.size();
      d1 = DistancePointToLine(hull[j1], hull[i], hull[i1]);
    }

    if (ans < 0.0 || ans - eps > sqrt(d)) {
      ans = sqrt(d);
    }

    // puts( "-------------------------" );
  }

  printf("%.10lf\n", ans);

  return 0;
}