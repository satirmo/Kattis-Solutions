#include <bits/stdc++.h>

using namespace std;

const int maxp = 105;

template <class T>
class Matrix {
 public:
  vector<vector<T> > M;

  Matrix(vector<vector<T> > M) : M(M) {}

  Matrix GetIdentity(int n) {
    vector<vector<T> > ret(n);

    for (int i = 0; i < n; i++) {
      ret[i].resize(n);
      ret[i][i] = 1;
    }

    return Matrix(ret);
  }

  Matrix operator^(int p) {
    int n = M.size();

    Matrix<T> X = *this;
    Matrix<T> I = GetIdentity(n);
    Matrix<T> R = I;

    while (p > 0) {
      if (p & 1) {
        R = X * R;
      }

      p >>= 1;
      X = X * X;
    }

    return R;
  }

  Matrix operator*(Matrix A) {
    auto N = A.M;

    int a = M.size();
    int b = M[0].size();
    int c = N[0].size();

    vector<vector<T> > R(a);

    for (int i = 0; i < a; i++) {
      R[i].resize(c);

      for (int j = 0; j < c; j++) {
        for (int k = 0; k < b; k++) {
          R[i][j] += M[i][k] * N[k][j];
        }
      }
    }

    return Matrix(R);
  }
};

double Exp(double x, int p) {
  double ret = 1.0;

  while (p--) {
    ret *= x;
  }

  return ret;
}

Matrix<double> Generate(int n, double p) {
  vector<vector<double> > M(102);

  for (int i = 0; i < 102; i++) {
    M[i].resize(102);
  }

  M[101][101] = 1.0;

  for (int k = 0; k <= 100; k++) {
    M[k].resize(102);

    for (int i = 0; i < k; i++) {
      M[k][k - i - 1] = Exp(1.0 - p, i) * p;
    }

    M[k][100] = Exp(1.0 - p, k);
    M[k][101] = Exp(1.0 - p, k) * 5.0;
  }

  return Matrix<double>(M);
}

int main() {
  int n;
  double p;
  cin >> n >> p;

  Matrix<double> M = Generate(n, p);
  Matrix<double> N = M ^ n;

  vector<vector<double> > v0(102);
  for (int i = 0; i < 102; i++) {
    v0[i].resize(1);
    v0[i][0] = 1.0;
  }

  Matrix<double> V0 = Matrix<double>(v0);
  Matrix<double> R = N * V0;
  double ans = R.M[100][0] - 1.0;

  printf("%.9lf\n", ans);

  return 0;
}