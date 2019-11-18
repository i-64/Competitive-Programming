#include <bits/stdc++.h>
using namespace std;

int getmin (int* arr, int i, int num) {
  // int ret = arr[i-1];
  // ret = min(arr[i-2], ret);
  // ret = min(arr[i-3], ret);
  // ret = min(arr[i-4], ret);
  // ret = min(arr[i-5], ret);
  // return ret;
  if(num>=arr[i-1]||num>=arr[i-2]||num>=arr[i-3]||num>=arr[i-4]||num>=arr[i-5])
    return false;
  return true;
}

int main () {
  int t;
  cin >> t;
  while (t--) {
    int n, ans = 0;
    cin >> n;
    int arr[n+5];
    arr[0] = arr[1] = arr[2] = arr[3] = arr[4] = INT_MAX;
    for (int  i = 0; i < n; i++) {
      cin >> arr[i+5];
      // cout<<getmin(arr,i+5)<<" "<<arr[i+5]<<endl;
      if (/*arr[i+5] < */getmin(arr, i+5, arr[i+5])) {
        ans++;
      }
    }
    // for(int& el:arr)cout<<el<<" ";cout<<endl;
    cout << ans << endl;
  }
  return 0;
}
