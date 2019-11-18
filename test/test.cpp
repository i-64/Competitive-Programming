#include <bits/stdc++.h>
using namespace std;

int main () {
  int n;
  cin >> n;
  vector <int> arr({/*1, 2, 3, 4, 5, 6, 7, 8, 9, 10*/1, 1, 1, 1, 1, 1});
  sort(arr.begin(), arr.end());
  auto u = upper_bound(arr.begin(), arr.end(), n), l = lower_bound(arr.begin(), arr.end(), n);
  cout << *u << " " << *l << " " << u - l << endl;
  if (u == arr.begin()) cout << "yo1" << endl;
  if (u == arr.end()) cout << "yo2" << endl;
  if (l == arr.begin()) cout << "yo3" << endl;
  if (l == arr.end()) cout << "yo4" << endl;
  return 0;
}
