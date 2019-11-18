#include <bits/stdc++.h>
using namespace std;

int main(){

  int t;
  cin >> t;

  while (t--) {

    int n;
    cin >> n;
    int arr[4*n];

    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    sort(arr, arr+n);

    int k = 0;
    int arr2[2*n];

    for (int i = 0; i < n; i += 2) {
      if(arr[i] == arr[i+1])
        arr2[k++] = arr[i];
    }

    for (int i = 0; i < k; i++) {
      if ()
    }

    return 0;
  }
