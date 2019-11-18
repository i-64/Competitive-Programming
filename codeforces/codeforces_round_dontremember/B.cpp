#include <bits/stdc++.h>
using namespace std;

bool f(pair<int,int> &a, pair<int,int> &b){
  if(a.first>b.first)
    return true;
  return false;
}

int main() {
  int n;
  cin>>n;
  int temp;
  vector<pair<int,int>> arr;
  for(int i=0;i<n;i++){
    cin>>temp;
    arr.push_back(make_pair(temp,i+1));
  }
  sort(arr.begin(), arr.end(), f);
  int ans=0;
  int cnt=0;
  for(auto it=arr.begin();it!=arr.end();it++){
    ans=ans+(it->first*cnt)+1;
    cnt++;
  }
  cout<<ans<<endl;
  for(auto p:arr){
    cout<<p.second<<" ";
  }
  cout<<endl;
  return 0;
}
