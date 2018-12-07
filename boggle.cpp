#include <bits/stdc++.h>

using namespace std;

const int maxn = 300005;
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int points[] = {0, 0, 0, 1, 1, 2, 3, 5, 11};

char cs[15];
bool visit[5][5];
string candidate;
string mat[5];
set<string> st;
vector<string> words;

void Check(int x, int y) {
  if (candidate.size() > 8) {
    return;
  }

  if (visit[x][y]) {
    return;
  }

  visit[x][y] = true;
  candidate += mat[x][y];

  auto it = lower_bound(words.begin(), words.end(), candidate);

  if (it == words.end() || (*it).substr(0, candidate.size()) != candidate) {
    visit[x][y] = false;
    candidate = candidate.substr(0, candidate.size() - 1);

    return;
  }

  // cout << "\t" << candidate << "-->" << *it << endl;

  if ((*it) == candidate) {
    st.insert(candidate);
  }

  for (int i = 0; i < 8; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) {
      continue;
    }

    Check(nx, ny);
  }

  visit[x][y] = false;
  candidate = candidate.substr(0, candidate.size() - 1);
}

int main() {
  int n;
  cin >> n;
  cin.ignore();

  words.resize(n);

  for (int i = 0; i < n; i++) {
    scanf("%s", cs);

    string s(cs);
    words[i] = s;
  }

  sort(words.begin(), words.end());

  int test;
  cin >> test;
  cin.ignore();

  while (test--) {
    for (int i = 0; i < 4; i++) {
      cin >> mat[i];
    }

    st.clear();
    candidate = "";

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        Check(i, j);
      }
    }

    int score = 0;
    string longestWord = "";
    int wordsFound = 0;

    for (string word : st) {
      score += points[word.size()];

      if (longestWord.size() < word.size() ||
          (longestWord.size() == word.size() && longestWord > word)) {
        longestWord = word;
      }

      wordsFound++;
    }

    printf("%d %s %d\n", score, longestWord.c_str(), wordsFound);
  }

  return 0;
}