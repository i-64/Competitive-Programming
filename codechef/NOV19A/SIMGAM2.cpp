#include <bits/stdc++.h>
using namespace std;
using i64 = long long int;

vector <pair<int,int>> chef;
vector <pair<int,int>> ramsay;
deque <int> arr[10001];
int n;

int getmaxchef () {
  if (chef.size() == 0) {
    return -1;
  }
  else {
    return (chef.end()-1);
  }
  // delete this one
  auto it = chef.end();
  it--;
  int pos = it->second;
  arr[pos].pop_front();
  // insert next in its place
  it->first = arr[pos].front();
  // update in original coin store
  
  // update chef
  // update ramsay
}

int getmaxramsay () {
  return 0;
}

void solve () {
  int temp, rn, ret = 0, rmx, cmx, cnt = 0;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> rn;
    while (rn--) {
      cin >> temp;
      arr[i].push_back(temp);
      cnt++;
    }
  }

  bool turn = false;
  for (int i = 0; i < cnt; i++) {
    turn = !turn;
    if (turn) {
      cmx = getmaxchef();
      ret += cmx;
    }
    else {
      rmx = getmaxramsay();
    }
  }
}

int main () {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
