#include <bits/stdc++.h>

using namespace std;

string NumberToString(int n) {
  if (n == 0) {
    return "zero";
  }

  if (n == 10) {
    return "ten";
  }

  if (n == 11) {
    return "eleven";
  }

  if (n == 12) {
    return "twelve";
  }

  if (n == 13) {
    return "thirteen";
  }

  if (n == 14) {
    return "fourteen";
  }

  if (n == 15) {
    return "fifteen";
  }

  if (n == 16) {
    return "sixteen";
  }

  if (n == 17) {
    return "seventeen";
  }

  if (n == 18) {
    return "eighteen";
  }

  if (n == 19) {
    return "nineteen";
  }

  string ret = "";

  if (n < 10) {
    ret = "";
  }

  else if (n < 30) {
    ret = "twenty";
  }

  else if (n < 40) {
    ret = "thirty";
  }

  else if (n < 50) {
    ret = "forty";
  }

  else if (n < 60) {
    ret = "fifty";
  }

  else if (n < 70) {
    ret = "sixty";
  }

  else if (n < 80) {
    ret = "seventy";
  }

  else if (n < 90) {
    ret = "eighty";
  }

  else {
    ret = "ninety";
  }

  int m = n % 10;

  if (n >= 10 && n % 10 != 0) {
    ret += "-";
  }

  if (m == 1) {
    ret += "one";
  }

  else if (m == 2) {
    ret += "two";
  }

  else if (m == 3) {
    ret += "three";
  }

  else if (m == 4) {
    ret += "four";
  }

  else if (m == 5) {
    ret += "five";
  }

  else if (m == 6) {
    ret += "six";
  }

  else if (m == 7) {
    ret += "seven";
  }

  else if (m == 8) {
    ret += "eight";
  }

  else if (m == 9) {
    ret += "nine";
  }

  return ret;
}

string EditLine(string line) {
  string ret = "";

  for (int i = 0; i < line.size();) {
    if (isdigit(line[i])) {
      int n = line[i] - '0';
      int j = i + 1;

      if (i + 1 < line.size() && isdigit(line[i + 1])) {
        n = 10 * n + line[i + 1] - '0';
        j = i + 2;
      }

      string sn = NumberToString(n);

      if (i == 0) {
        sn[0] = toupper(sn[0]);
      }

      ret += sn;
      i = j;
    }

    else {
      ret += line[i++];
    }
  }

  return ret;
}

int main() {
  string line;

  while (getline(cin, line)) {
    string ans = EditLine(line);
    cout << ans << endl;
  }

  return 0;
}