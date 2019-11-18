#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

int solve (int n) {
  int arr[10],first0, ans = 0, k=0, d;
  bool zcase = false;
  int mx, pos;
  bool flag = false;
  while(n>0) {
    d = n%10;
    n = n/10;
    arr[k++] = d;
    if (d==0)
      zcase = true;
  }

  if(zcase){
    reverse(arr, arr+k);
    for (int i = 0; i < k; i++) {
      if (arr[i] == 0) {
        pos = i;
        break;
      }
    }
    int mx = *max_element(arr, arr+pos);

    for (int i = 0; i < k; i++) {
      if (flag == false && arr[i] == mx) {
        flag = true;
        continue;
      }
      ans = ans * 10 + arr[i];
    }
    return ans;
  }

  else {
    int mx = *max_element(arr, arr+k);

    for (int i = k-1; i >= 0; i--) {
      if (flag == false && arr[i] == mx) {
        flag = true;
        continue;
      }
      ans = ans * 10 + arr[i];
    }
    return ans;
  }
}

int main () {
  int t;
  cin >> t;
  while (t--) {
    int n, ans = 0;
    string num;
    cin >> num;
    bool done=false;
    int end=num.length();
    for(int i=1;i<end;i++) {
        if(num[i]-'0' < num[i-1]-'0') {
            num[i-1]='*';
            done=true;
            break;
        }
    }
    if(!done) num[end-1] = '*';
    for(int i=0;i<end;i++) {
        // cout<<num[i];
        if(num[i]=='*') continue;
        ans*=10;
        ans+=(num[i]-'0');
    }
    // cout<<endl;
    cout<<ans<<endl;
    // cout << solve(n) << endl;
  }
  return 0;
}
