#include <bits/stdc++.h>

using namespace std;

int main() {
  string john, doctor;

  while (cin >> john >> doctor) {
    int pos = john.find(doctor);
    string ans = (pos != string::npos) ? "go" : "no";

    cout << ans << endl;
  }

  return 0;
}