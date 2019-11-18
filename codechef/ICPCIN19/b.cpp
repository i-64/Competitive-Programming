#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

int main () {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string word;
    // string words[n];
    unordered_set <string> words;
    bool spam;
    int k = 0;
    map <string,int> mt;
    map <string,int> mf;
    while (n--) {
      cin >> word >> spam;
      words.insert(word);
      if (spam) {
        mt[word]++;
      }
      else {
        mf[word]++;
      }
    }
    int ret = 0;
    for (string str:words) {
      ret += max(mt[str], mf[str]);
    }
    cout << ret << endl;
  }
  return 0;
}
