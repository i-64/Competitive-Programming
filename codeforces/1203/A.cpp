#include <bits/stdc++.h>
using namespace std;

//my approach 2*n array-WA somehow
//editorial approach, normal array, find 1, traverse left&right using mod

int main(){

  int t;
  cin >> t;

  while (t--) {

    int n;
    cin >> n;
    int arr[2*n];

    int i, pos = -1;
    bool flag1 = true, flag2 = true;

    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      if (arr[i] == 1)
        pos = i;
      // arr[n+i] = arr[i];
    }

    for (int i = 1; i < n; i++) {
      flag1 &= (arr[(pos - i + n)%n] == i+1);
      flag2 &= (arr[(pos + i + n)%n] == i+1);
    }

    /*for (i = 0; i < n; i++) {
      if (arr[i] == 1)
        break;
    }

    for(; i < )*/

    /*for (i = 0; i < n && arr[i] != 1; i++);

    for (; i < 2*n && arr[i] != n; i++) {
      if( arr[i]+1 != arr[i+1]) {
        flag1 = false;
        break;
      }
    }

    for (i = 2*n-1; i >= n && arr[i] != 1; i--);

    if (flag1)
    for (; i >= 0 && arr[i] != n; i--) {
      if (arr[i] != arr[i-1]-1) {
        flag2 = false;
        break;
      }
    }*/

    if (flag1 || flag2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
