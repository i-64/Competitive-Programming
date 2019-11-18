#include <bits/stdc++.h>
using namespace std;

bool f(pair<int,int> &a, pair<int,int> &b){
  if(a.second>b.second)
    return false;
  if(a.second==b.second){
    if(a.first>b.first)
      return false;
  }
  return true;
}

int main() {
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    int k=m;
    int a,b;
    int aux[n+1];
    memset(aux, 0, sizeof(aux));
    while(m--){
      cin>>a>>b;
      aux[a-1]+=1;
      aux[b]-=1;
    }
    for(int i=1;i<n;i++){
      aux[i]+=aux[i-1];
    }
    // for(int el:aux)cout<<el<<" ";cout<<endl;
    vector <pair<int,int>> v;
    for(int i=0;i<n;i++){
      v.push_back(make_pair(arr[i],aux[i]));
    }
    sort(v.begin(), v.end(), f);
    // cout<<"---"<<endl;
    // for(auto p:v)cout<<p.first<<" "<<p.second<<endl;
    int day=0;
    auto it=v.end();
    it--;
    for(;k>0;it--){
      k--;
      if((*it).second-day == 0)
        break;
      day++;
      if(it==v.begin())
        break;
    }
    int ans=0;
    for(auto i=v.begin();true;i++){
      ans+=(*i).first;
      if(i==it)
        break;
    }
    cout<<ans<<endl;
  }
  return 0;
}
