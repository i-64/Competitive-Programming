#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    string s,r;
    cin>>s>>r;
    map<char,int> ms,mr,mres,mpend;
    int n=r.length();

    map<char,int> m2;
    for(char ch:s){
      m2[ch]++;
    }
    map<char,int> m;
    for(int i=0;i<n;i++){
      m[r[i]]++;
    }bool flag=true;
    // for(auto p:m2){
    //   if(m[p.first]<p.second){
    //     flag=false;
    //     break;
    //   }
    // }
    for(auto p:m2){
      m[p.first]=m[p.first]-p.second;
      if(m[p.first]<0){
        flag=false;
        break;
      }
    }
    if(!flag){cout<<"Impossible"<<endl;continue;}

    for(char ch:s){
      ms[ch]++;
    }
    for(char ch:r){
      mr[ch]++;
    }
    for(auto p:mr){
      mres[p.first]=p.second-ms[p.first];
    }
    string ans="";
    // for(auto p:mres)cout<<p.first<<" "<<p.second<<endl;cout<<endl;
    for(auto& p:mres){
      if(p.first==s[0])break;
      if(p.second>0){
        while(p.second--){ans+=p.first;}
      }
    }
    // for(auto p:mres)cout<<p.first<<" "<<p.second<<endl;cout<<endl;

    ans+=s;
    for(auto p:mres){
      if(p.second<=0)continue;
      while(p.second--){
        ans+=p.first;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
