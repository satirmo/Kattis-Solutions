#include <bits/stdc++.h>

using namespace std;

vector<string> v;
set<string> st;

int main() {
  string input;

  while (getline(cin, input)) {
    stringstream ss(input);
    string s;

    while (ss >> s) {
      v.push_back(s);
    }
  }

  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v.size(); j++) {
      if (i != j) {
        st.insert(v[i] + v[j]);
      }
    }
  }

  for (string word : st) {
    if (word != "") {
      printf("%s\n", word.c_str());
    }
  }

  return 0;
}