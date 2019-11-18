#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007

ll p[100001],ip[100001];

ll mul(ll a,ll b){
    return ((a%mod)*(b%mod))%mod;   // multiplying two numbers under modulo mod
}

ll add(ll a,ll b){
    return (a+b)%mod; // adding two numbers under modulo 10^9+7
}

ll sub(ll a,ll b){  // subtracting two numbers under modulo 10^9+7
    ll ans=(a-b)%mod;

    ans=add(mod ,ans);  // making answer positve if its negative (why ? google :p)
    return ans;
}


ll mul(ll a,ll b,ll c){   // multiply three numbers under modulo 10^9+7
    return mul(mul(a,b),c);
}

ll mi(ll a){    // finding mod inverse of a ( google it :p ) PS: you can't use
                // "/"  for dividing when you are playing with modulo
    int b=mod-2;
    ll ans=1;
    while(b){
        if(b%2)
            ans=mul(ans,a);
        a=mul(a,a);
        b/=2;
    }

    return ans;
}

ll find3(string &s,ll n){   // find f(x) given x ( PS: x=s )
    ll ans=mul( (s[0]-'0') , p[n-1] ), i;

    for(i=1;i<n;i++)
        if(s[i]!=s[i-1])
            ans=add( ans, mul( (s[i]-'0') , p[n-1-i]) );
    return ans;
}

ll find(string &s,ll n,ll i,char j,ll pre[],ll suf[]){

    /*
        n =  no. of digits in s

        This function finds how many numbers in range 1 to s (both inclusive) have ith digit = j

    */

    if(i>=n || i<0)
        return 0;

    ll ans;

    if(s[i]>j)
        ans=p[n-1-i];
    else if(s[i]==j){
       ans=1;
       if(i+1<n)
        ans=add( ans , suf[i+1]);
    }else
        ans=0;

    if(i)
        ans=add(ans, mul( pre[i-1] , ip[1] ) );
    return ans;
}

ll find2(string &s,ll n,ll i,char j,ll pre[],ll suf[]){

    /*
        n =  no. of digits in s

        This function finds how many numbers in range 1 to s (both inclusive) have ith and (i+1)th digit = j
    */

    if(i>=n || i<0)
        return 0;

    ll ans;

    if( (s[i]>j) || ((s[i]==j) && (s[i+1]>j)))
        ans=p[n-2-i];
    else if(s[i]==j && s[i+1]==j){
        ans=1;
        if(i+2<n)
            ans=add( ans , suf[i+2]);
    }else
        ans=0;

    if(i)
        ans=add(ans, mul( pre[i-1] , ip[2] ) );

    return ans;
}


int main()
{
    FIO;
    ll t,n1,n2,k,i,j,ans,tmp,tmp2;
    string s1,s2;

    p[0]=1;
    ip[0]=1;

    for(i=1;i<100001;i++){
        p[i]=(p[i-1]*10)%mod;  // p[i]= 10^i mod 10^9+7
        ip[i]=mi(p[i]);       // mod inverse (remember I asked to google ?) of p[i]
    }

    cin >> t;
    while(t--){
        cin >> n1 >> s1 >> n2 >> s2;

        ll pre1[n1],suf1[n1],pre2[n2],suf2[n2];

        pre1[0]=mul( (s1[0]-'0') , p[n1-1] );

        suf1[n1-1]= (s1[n1-1]-'0');

        for(i=1;i<n1;i++){
            pre1[i]=add( pre1[i-1] ,  mul( (s1[i]-'0') , p[n1-1-i]) );
            suf1[n1-1-i]=add( suf1[n1-i] , mul( (s1[n1-1-i]-'0'), p[i] ) );
        }


        pre2[0]=mul( (s2[0]-'0') , p[n2-1] );
        suf2[n2-1]= (s2[n2-1]-'0');

        for(i=1;i<n2;i++){
            pre2[i]=add( pre2[i-1] ,  mul( (s2[i]-'0') , p[n2-1-i]) );
            suf2[n2-1-i]=add( suf2[n2-i] , mul( (s2[n2-1-i]-'0'), p[i] ) );
        }

        /*
                if N=12451
            we just compued  the following part
            where pre1 and suf1 are for s1 ( i.e. L )and
            pre2 and suf2 are for s2 ( i.e R )

            I will precompute ( prefix part)
                10000
                12000
                12400
                12450
                12451
            and I will also precompute (Suffix part)
                00001
                00051
                00451
                02451
                12451
        */


        ans=0;
        j=n2-n1;

        for(i=0;i<n2;i++)   // for each position in s2
            for(char c='1';c<='9';c++){  // for each digit in 1 to 9
                tmp = sub( find(s2,n2,i,c,pre2,suf2) , find(s1,n1,i-j,c,pre1,suf1) ) ;
                /*
                    tmp = number of digits in range L+1 to R such that ith digit = char c
                */

                tmp=mul( tmp , (c-'0') , p[n2-1-i] );

                /*
                   as value to be added is frequency * 10^position * digit
                */

                if(i){ // it doesn't exist when i=0
                    tmp2 = sub ( find2(s2,n2,i-1,c,pre2,suf2) , find2(s1,n1,i-1-j,c,pre1,suf1) ) ;

                    /*
                        tmp2 = number of digits in range L+1 to R such that    (i-1)th and ith digit = char c
                    */


                    tmp2=mul( tmp2 ,(c-'0') , p[n2-i-1] );
                    /*
                       as actual value is frequency * 10^position * digit
                    */
                }else
                    tmp2=0;

                ans= add( ans , sub( tmp , tmp2  ) );
                // add final contribution of ith place such that ith digit is char c
            }

        ans= add( ans , find3(s1,n1)  );

        /*
            add contribution of L  separetely
        */

        cout << ans << "\n";  // print answer
    }

	return 0;
}
