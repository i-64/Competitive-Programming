#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long i64;
i64 a[5000005];
// has[5000005],mat[1001][1001],pr[5000005],b[5000005],c[5000005],sat[1001][1001],cat[1001][1001],pref[1001][1001],ans[1001][1001];

int main(){

    i64 t;
    cin >> t;
    while (t--) {
    	i64 n;
      cin >> n;
    	i64 sum = 0;
    	for (i64 i = 0; i < n; i++){ cin >> a[i]; sum += a[i];}
    	sort(a, a + n);
    	i64 beg = 0, end = 1000000000, mid = ( beg + end) / 2;
    	i64 mini = LLONG_MAX;
    	priority_queue <i64,vector<i64>,greater<i64>> pp;
    	while (beg <= end){
    		mid = (beg + end) / 2;
    		i64 val = mid * n;
    		if (val >= sum) {
    			end = mid - 1;
    			pp.push(mid);
    		}
    		else beg = mid + 1;
    	}
    	cout << pp.top() << endl;
    }
	return 0;
}

// int main () {
  // int t;
  // cin >> t;
  // while (t--) {
  //   int n, temp, sum = 0;
  //   cin >> n;
  //   int m = n;
  //   while (n--) {
  //     cin >> temp;
  //     sum += temp;
  //   }
  //   cout << ceil(sum/(double)m) << endl;
  // }
  // return 0;
// }
