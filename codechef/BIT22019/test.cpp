#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
const i64 mod = 1e9+7;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n,sum=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    int x;
    cin>>x;
    int cnt1,cnt2;
    int i,j;
    int s1=accumulate(arr,arr+n,0);
    int as=s1/(x+1);
    for(i=0;i<n&&sum+x<as;i++){
      sum+=arr[i];
    }
    // cout<<sum<<s1<<as;
    int a=i+1;
    // cout<<s1%(x+1);
    if(arr[a]==(s1%(x+1)))a++;
    cout<<a<<" "<<n-a<<endl;
    /*
    bool flag=true;
    int a=0,b=0,ai=0,bi=n-1,cnt1=0,cnt2=0;
    while(true){
      flag=false;
      int xdash=x;
      while(xdash!=0){
        int sub=min(xdash, arr[ai]);
        xdash-=sub;
        if(sub<arr[ai]){arr[ai]-=sub;break;}
        else{arr[ai]=0;ai++;}
        if(ai+1==bi&&arr[bi]<=0&&arr[ai]<=0){flag=true;break;}
      }
      if(flag)break;
      if(ai+1==bi&&arr[bi]<=0&&arr[ai]<=0){break;}
      arr[bi]--;
      if(arr[bi]==0){bi--;cnt2++;}
      if(ai+1==bi||arr[bi]<=0&&arr[ai]<=0){break;}
      // for(int el:arr)cout<<el<<" ";cout<<endl;
    }
    cout<<ai<<" "<<cnt2<<endl;*/
  }
  return 0;
}

/*
i64 myp(i64 x, i64 y){
    x = x % mod;
    i64 ret = 1;
    while (y > 0){
        if (y & 1)
            ret = (ret*x) % mod;
        x = (x*x) % mod;
        y = y>>1;
    }
    return ret;
}

i64 solve(i64 n){
  i64 ans=1;
  for(i64 i=1;i<n;i++){
    ans=((ans%mod)*(myp(i+1,n-i)))%mod;
  }
  return ans;
}

int fact(int n){
  int ans=1;
  for(int i=1;i<=n;i++){
    ans=(ans*i)%mod;
  }
  return ans;
}

int main(){
  i64 t;
  cin>>t;
  while(t--){
    i64 n;
    cin>>n;
    i64 arr[n+2];
    i64 cnt=1;
    arr[1]=1;
    // for(int i=2;i<=n+1;i++){
    //   arr[i]=((arr[i-1]%mod)*(arr[i-1]%mod)*(cnt%mod))%mod;
    //   cnt++;
    // }
    // for(int i=2;i<=n+1;i++){
    //   arr[i]=(arr[i-1]*arr[i])%mod;
    // }
    cout<<fact(n)<<endl;
    // for(int i=2;i<=11;i++){cout<<(arr[i]%mod)<<endl;}cout<<endl;
    cout<<solve(n)<<endl;
  }
  return 0;
}
*/
