#include <bits/stdc++.h>

using namespace std;

vector<char> op = {'-', '+', '/', '*'};
vector<char> ops;
vector<int> val;

void Update(int idx) {
  int nval;

  if (ops[idx] == '*') {
    nval = val[idx] * val[idx + 1];
  }

  else {
    nval = val[idx] / val[idx + 1];
  }

  val[idx] = nval;

  for (int i = idx; i + 1 < ops.size(); i++) {
    ops[i] = ops[i + 1];
    val[i + 1] = val[i + 2];
  }

  ops.resize(ops.size() - 1);
}

bool IsSolution(int x, int y, int z, int n) {
  ops.clear();
  val.clear();

  ops.push_back(op[x]);
  ops.push_back(op[y]);
  ops.push_back(op[z]);

  for (int i = 0; i < 4; i++) {
    val.push_back(4);
  }

  // multiply or divide

  for (int i = 0; i < ops.size(); i++) {
    if (ops[i] == '*' || ops[i] == '/') {
      Update(i);
      i--;
    }
  }

  int result = val[0];

  for (int i = 0; i < ops.size(); i++) {
    if (ops[i] == '-') {
      result -= val[i + 1];
    }

    else {
      result += val[i + 1];
    }
  }

  return result == n;
}

int main() {
  int test;
  cin >> test;

  while (test--) {
    int n;
    cin >> n;

    bool ans = false;

    for (int i = 0; i < op.size() && !ans; i++) {
      for (int j = 0; j < op.size() && !ans; j++) {
        for (int k = 0; k < op.size() && !ans; k++) {
          ops.push_back(op[i]);
          ops.push_back(op[j]);
          ops.push_back(op[k]);

          if (IsSolution(i, j, k, n)) {
            ans = true;
            printf("4 %c 4 %c 4 %c 4 = %d\n", op[i], op[j], op[k], n);
          }
        }
      }
    }

    if (!ans) {
      puts("no solution");
    }
  }

  return 0;
}