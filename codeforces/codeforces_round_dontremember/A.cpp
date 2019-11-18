#include <bits/stdc++.h>
using namespace std;

int solve(int i, k){
  bitset<2000> b("0");
  while(true){
    b+=1;
  }
}

int main() {
  int n;
  cin>>n;
  string s;
  int cnt=0;
  cin>>s;
  for(int i=0;i<n;i+=2){
    if(s[i]==s[i+1]){
      cnt++;
      if(s[i]=='a')s[i]='b';
      else s[i]='a';
    }
  }
  cout<<cnt<<endl;
  cout<<s<<endl;
  return 0;
}
