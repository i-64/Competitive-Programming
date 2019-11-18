#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("cases.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  int t;
  cin>>t;
  while(t--){
    int a,b,c;
    cin>>a>>b>>c;
    int da,db,dc,ra,rb,rc;
    int sum=a+2*b+3*c;
    if(sum%2 == 0){
      da=a/2;
      db=b/2;
      dc=c/2;
      ra=a%2;
      rb=b%2;
      rc=c%2;
      if(ra==0 && rb==0 && rc==0){
        cout<<"YES"<<endl;
        continue;
      }
      if(ra==1 && rb==1 && rc==1){
        cout<<"YES"<<endl;
        continue;
      }
      if(ra==0 && rb==1 && rc==0){
        if(a>=2){
          cout<<"YES"<<endl;
          continue;
        }
        else{
          if(c==0 || b==1){
            cout<<"YES"<<endl;
            continue;
          }
          cout<<"NO"<<endl;
          continue;
        }
      }
      if(ra==1 && rb==0 && rc==1){
        if(a>=3 || (b>=1 && a>=1)){
          cout<<"YES"<<endl;
        }
        else{
          cout<<"NO"<<endl;
        }
        continue;
      }
      assert(false);
    }
    else
      cout<<"NO"<<endl;
  }
  return 0;
}
