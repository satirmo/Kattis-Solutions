#include <bits/stdc++.h>

using namespace std;

struct Data {
  string ti, suffix;

  Data(string ti, string suffix) {
    if (ti.size() == 4) {
      ti = "0" + ti;
    }

    if (ti.substr(0, 2) == "12") {
      ti = "00" + ti.substr(2, 3);
    }

    this->ti = ti;
    this->suffix = suffix;
  }

  bool operator<(const Data &a) const {
    if (suffix != a.suffix) {
      return suffix < a.suffix;
    }

    return ti < a.ti;
  }
};

vector<Data> v;

int main() {
  int n;
  bool flag = false;
  while (cin >> n, n) {
    if (flag) {
      puts("");
    }

    flag = true;
    v.clear();
    cin.ignore();

    while (n--) {
      string ti, suffix;
      cin >> ti >> suffix;

      v.push_back(Data(ti, suffix));
    }

    sort(v.begin(), v.end());

    for (Data it : v) {
      string ti = it.ti;
      string suffix = it.suffix;

      if (ti.substr(0, 2) == "00") {
        ti = "12" + ti.substr(2, 3);
      }

      if (ti[0] == '0') {
        ti = ti.substr(1, 4);
      }

      printf("%s %s\n", ti.c_str(), suffix.c_str());
    }
  }

  return 0;
}