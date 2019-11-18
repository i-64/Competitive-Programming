#include <bits/stdc++.h>
using namespace std;

bool check (string str) {
  int vowels = 0, consonants = 0;
  for (char ch : str) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||ch == 'u') {
      vowels++;
    }
    else {
      consonants++;
    }
  }
  if (vowels >= consonants)
    return true;
  else {//cout<<str<<endl;
    return false;}
}

bool alice (string str) {
  for (int i = 0; i < str.length(); i++) {
    for (int j = i + 1; j < str.length(); j++) {
      string s(str.begin()+i, str.begin()+j+1);
      // cout<<s<<endl;
      if (check(s) == false) {//cout<<i<<" "<<j<<endl;
        return false;}
    }
  }
  return true;
}

int main () {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <string> v;
    while (n--) {
      string str;
      cin >> str;
      v.push_back(*(new string(str)));
    }
    vector <string> a, b;
    for (auto el : v) {
      if (alice(el)) {
        a.push_back(*(new string(el)));
      }
      else {
        b.push_back(*(new string(el)));
      }
    }
    // for(auto el:a)cout<<el<<" ";
    int char_freq[26], chars_in_recipe[26];
    memset(char_freq, 0, sizeof char_freq);
    memset(chars_in_recipe, 0, sizeof chars_in_recipe);
    double score_a = 1.0, score_b = 1.0;
    for (auto el : a) {// cout<<"test";
      bool char_in_recipe[26];
      memset(char_in_recipe, false, sizeof char_in_recipe);
      for (int i = 0; i < el.length(); i++) {
        char_freq[el[i] - 'a']++;// cout<<"test";
        char_in_recipe[el[i] - 'a'] = true;
      }
      for (int i = 0; i < 26; i++) {
        if (char_in_recipe[i]) {// cout<<"tets";
          chars_in_recipe[i]++;
        }
      }
    }
    // for(int el:char_freq){cout<<el<<" ";}cout<<endl;
    // for(int el:chars_in_recipe){cout<<el<<" ";}cout<<endl;
    for (int i = 0; i < 26; i++) {
      if (chars_in_recipe[i]) {// cout << "test";
        double tmp = (1.0d * chars_in_recipe[i]) / pow(char_freq[i], (int)a.size());
        // cout<<setprecision(20)<<fixed<<tmp<<endl;
        score_a = score_a * tmp;
      }
    }

    memset(char_freq, 0, sizeof char_freq);
    memset(chars_in_recipe, 0, sizeof chars_in_recipe);
    for (auto el : b) {// cout<<"test";
      bool char_in_recipe[26];
      memset(char_in_recipe, false, sizeof char_in_recipe);
      for (int i = 0; i < el.length(); i++) {
        char_freq[el[i] - 'a']++;// cout<<"test";
        char_in_recipe[el[i] - 'a'] = true;
      }
      for (int i = 0; i < 26; i++) {
        if (char_in_recipe[i]) {// cout<<"tets";
          chars_in_recipe[i]++;
        }
      }
    }
    for (int i = 0; i < 26; i++) {
      if (chars_in_recipe[i]) {// cout << "test";
        double tmp = (1.0d * chars_in_recipe[i]) / pow(char_freq[i], (int)a.size());
        // cout<<setprecision(20)<<fixed<<tmp<<endl;
        score_b = score_b * tmp;
      }
    }

    if (score_b <  std :: numeric_limits<double> :: epsilon() && score_b > -std :: numeric_limits<double> :: epsilon()) {
      cout << "Infinity" << endl;
      continue;
    }
    double ret = (score_a / score_b);
    if (ret > 10000000.0d) {
      cout << "Infinity" << endl;
      continue;
    }
      cout << setprecision(7) << fixed << ret << endl;
  }
  return 0;
}
