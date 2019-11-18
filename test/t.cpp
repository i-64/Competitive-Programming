#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using i64 = long long;

vector <int> getans (vector <int> arr, int target) {
  int n = arr.size();
  vector <int> ret;
  unordered_set <int> s;
  unordered_map <int,int> m;
  for (int i = 0; i < n; i++) {
    auto res = s.find(arr[i]);
    if (res != s.end()) {
      ret.pb(i);
      ret.pb(m[target - arr[i]]);
      return ret;
    }
    else {
      s.insert(target - arr[i]);
      m[arr[i]] = i;
    }
  }
  return ret;
}

int main () {
  int n, target;
  cin >> n >> target;
  vector <int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector <int> v = getans(arr, target);
  for (int el : v) {
    cout << el << " ";
  }
  cout << endl;
  return 0;
}
