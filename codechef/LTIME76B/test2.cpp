#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n,m,round=1;
    cin>>n>>m;
    // int arr[m];
    int cat[n+1];
    bool flag=true;
    int temp;
    memset(cat, n, sizeof(cat)+1);
    for(int i=0;i<m;i++){//cout<<round<<endl;
      cin>>temp;
      if(!flag) continue;
      round=i/n +1;
      cat[temp]++;
      if(cat[temp]>(round+1)){
        flag=false;
      }
    }
    if(flag)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
  return 0;
}
