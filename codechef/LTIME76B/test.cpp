#include <bits/stdc++.h>
using namespace std;
typedef long long i64;


int main() {
  i64 t;
  cin >> t;
  while (t--) {
    string s,r;
    cin>>s>>r;
    int n=r.length();
    char st=s[0];
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
    string ans="";
    for(auto p:m){
      if(p.first == st){
        while(p.second--) ans+=p.first;
        for(int i=0;i<s.length();i++){
          ans+=s[i];
          m[s[i]]--;
        }
        break;
      }
      else{
        while(p.second--) ans+=p.first;
      }
    }
    for(auto p:m){
      if(p.second<=0)continue;
      while(p.second--) ans+=p.first;
    }
    cout<<ans<<endl;
  }
  return 0;
}
