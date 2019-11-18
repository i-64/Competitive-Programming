#include <bits/stdc++.h>
using namespace std;

//jumping to conclusions ans recursion and dp and harder approaches

/*
bool solve(int n, int i, int k, int* arr) {
  if (k == 0) {
    if (accumulate(arr+i+1, arr+n, 0)%2 == 0)
      return true;
    else
      return false;
  }
  //break here

  //don't break here
}*/

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int arr[n], cnt = 0;
    for (int i = 0; i < n; i++){
      cin >> arr[i];
      if (arr[i]%2 == 1)
        cnt++;
    }
    cnt -= k;
    bool flag = false;
    if (cnt == 0)
      flag = true;
    else if (cnt > 0 && cnt%2 == 0)
      flag = true;

    if (flag) {
      cout << "YES" << endl;
      for (int i = 0; i < n && k > 1; i++) {
        if (arr[i]%2 == 1){
          cout << (i+1) << " ";
          k--;
        }
      }
      cout << n << endl;
    }
    else
      cout << "NO" << endl;
  }
  return 0;
}
