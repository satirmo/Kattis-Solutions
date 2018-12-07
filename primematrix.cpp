#include <bits/stdc++.h>

using namespace std;

const int maxn = 10005;

bitset<maxn> bit;
vector<int> primes, numbers;

void Sieve() {
  bit.set();

  for (int i = 2; i < maxn; i++) {
    if (bit[i]) {
      primes.push_back(i);

      for (int j = i * i; j < maxn; j += i) {
        bit[j] = false;
      }
    }
  }
}

int main() {
  Sieve();

  int n, b;
  cin >> n >> b;

  bool possible = true;

  if (n > b) {
    puts("impossible");
    return 0;
  }

  int sum = 0;

  for (int i = 1; i <= n; i++) {
    sum += i;
    numbers.push_back(i);
  }

  int idx = 0;

  while (primes[idx] < sum) {
    idx++;
  }

  for (int i = n - 1; i >= 0; i--) {
    int rem = primes[idx] - sum;

    if (b - numbers[i] >= rem) {
      sum += rem;
      numbers[i] += rem;
      break;
    }

    int add = b - numbers[i];

    b--;
    sum += add;
    numbers[i] += add;
  }

  if (sum < primes[idx]) {
    puts("impossible");
  }

  else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (j > 0) {
          printf(" ");
        }

        printf("%d", numbers[(i + j) % n]);
      }
      puts("");
    }
  }

  return 0;
}