#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;

int a[maxn];
long long t[2 * maxn];

void Build(int n) {
  for (int i = n - 1; i > 0; i--) {
    t[i] = t[i << 1] + t[i << 1 | 1];
  }
}

void Modify(int n, int p, int v) {
  for (t[p += n] = v; p > 1; p >>= 1) {
    t[p >> 1] = t[p] + t[p ^ 1];
  }
}

int Query(int n, int l, int r) {
  int ret = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ret += t[l++];
    if (r & 1) ret += t[--r];
  }
  return ret;
}

long long GetCost(int n, int lst, int current) {
  if (lst < current) {
    swap(current, lst);
  }

  long long dist1 = Query(n, current, lst);
  long long dist2 = Query(n, 0, n) - dist1;

  return min(dist1, dist2);
}

void PrintTree(int n) {
  int next2 = 1;
  int cnt = 0;

  for (int i = 1; i < 2 * n; i++) {
    printf("%4lld", t[i]);

    cnt++;

    if (cnt == next2) {
      next2 <<= 1;
      cnt = 0;
      puts("");
    }
  }
  puts("");
}

long long Calculate(int n) {
  int lst = 0;
  long long ret = 0LL;

  for (int i = 0; i < n; i++) {
    int current = a[i];

    ret += GetCost(n, lst, current);
    // PrintTree(n);
    // printf("cost %3d -> %3d : %10lld\n", lst, current, GetCost(n, lst,
    // current));

    Modify(n, current, 0);
    lst = current;
  }

  return ret + n;
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    t[n + i] = 1;
  }

  Build(n);

  for (int i = 0; i < n; i++) {
    int order;
    cin >> order;

    a[order - 1] = i;
  }

  long long ans = Calculate(n);
  cout << ans << endl;

  return 0;
}