#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int sq[] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100};

int getsum (int* arr) {
  int ret = 0;
  for (int i = 1; i < 10; i++) ret += sq[i] * arr[i];
  return ret;
}

void solve (int n) {
  int arr[10];
  for (arr[1] = n; arr[1] >= 0 ; arr[1]--) for (arr[2] = n-arr[1]; arr[2] >= 0 ; arr[2]--) for (arr[3] = n-arr[1]-arr[2]; arr[3] >= 0 ; arr[3]--) for (arr[4] = n-arr[1]-arr[2]-arr[3]; arr[4] >= 0 ; arr[4]--) for (arr[5] = n-arr[1]-arr[2]-arr[3]-arr[4]; arr[5] >= 0 ; arr[5]--) for (arr[6] = n-arr[1]-arr[2]-arr[3]-arr[4]-arr[5]; arr[6] >= 0 ; arr[6]--) for (arr[7] = n-arr[1]-arr[2]-arr[3]-arr[4]-arr[5]-arr[6]; arr[7] >= 0 ; arr[7]--) for (arr[8] = n-arr[1]-arr[2]-arr[3]-arr[4]-arr[5]-arr[6]-arr[7]; arr[8] >= 0 ; arr[8]--)
  for (arr[9] = n-arr[1]-arr[2]-arr[3]-arr[4]-arr[5]-arr[6]-arr[7]-arr[8]; arr[9] >= 0 ; arr[9]--) {
    int sum = getsum(arr);
    int srqt = sqrt(sum);
    if (srqt * srqt == sum) {
      for (int i = 1; i < 10; i++) cout << string(arr[i], ('0' + i)); cout << endl;
      return ;
    }
  }
}

int32_t main () {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    solve(n);
  }
  return 0;
}
