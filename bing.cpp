#include <bits/stdc++.h>

using namespace std;

struct Node {
  char value;
  bool end;
  int cnt;
  struct Node* child[26];

  Node(char value) {
    cnt = 0;
    this->value = value;
    for (int i = 0; i < 26; i++) child[i] = NULL;
  }

  ~Node() {}
};

struct Trie {
  Node* root;

  Trie() {
    root = new Node(' ');
    root->end = true;
  }

  ~Trie() {}

  int add(string word) {
    Node* node = root;
    root->end = false;
    int n = word.size();
    int ret = 0;
    for (int i = 0; i < n; i++) {
      char c = tolower(word[i]);
      int ind = c - 'a';
      if (node->child[ind] == NULL) {
        Node* tnode = new Node(c);
        node->child[ind] = tnode;
      }
      node = node->child[ind];
      ret = node->cnt++;
    }
    node->end = true;
    return ret;
  }
};

int main() {
  int n;
  while (cin >> n) {
    cin.ignore();

    Trie t = Trie();

    while (n--) {
      string s;
      cin >> s;

      printf("%d\n", t.add(s));
    }
  }

  return 0;
}