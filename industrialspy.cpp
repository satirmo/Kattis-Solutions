#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000000;
const int upto = sqrt(maxn);

vector<int> prime;
bitset<upto> bit;
set<int> st;

void Sieve() {
  bit.set();

  bit[0] = false;
  bit[1] = false;

  for (int i = 2; i < upto; i++) {
    if (bit[i]) {
      for (int j = i * i; j < upto; j += i) {
        bit[j] = false;
      }

      prime.push_back(i);
    }
  }
}

bool IsPrime(int x) {
  if (x <= 1) {
    return false;
  }

  for (int p : prime) {
    if (x <= p) {
      break;
    }

    if (x % p == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  Sieve();

  int test;
  cin >> test;

  while (test--) {
    string s;
    cin >> s;

    st.clear();
    sort(s.begin(), s.end());

    do {
      string t = "";

      for (int i = 0; i < s.size(); i++) {
        t += s[i];

        int val = stoi(t);
        // printf( "checking %10d : %d\n", val, IsPrime( val ) );

        if (IsPrime(val)) {
          st.insert(val);
        }
      }
    } while (next_permutation(s.begin(), s.end()));

    int ans = st.size();
    cout << ans << endl;
  }

  return 0;
}