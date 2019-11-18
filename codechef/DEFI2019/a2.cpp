#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define watch(x) cout << (#x) << " is " << x << endl;

int eggDrop(int n, int k) {
	int eggFloor[n+1][k+1];
	int res;
	int i, j, x;
	for (i = 1; i <= n; i++)
	{
		eggFloor[i][1] = 1;
		eggFloor[i][0] = 0;
	}
	for (j = 1; j <= k; j++)
		eggFloor[1][j] = j;
	for (i = 2; i <= n; i++)
	{
		for (j = 2; j <= k; j++)
		{
			eggFloor[i][j] = INT_MAX;
			for (x = 1; x <= j; x++)
			{
				res = 1 + max(eggFloor[i-1][x-1], eggFloor[i][j-x]);
				if (res < eggFloor[i][j])
					eggFloor[i][j] = res;
			}
		}
	}
	return eggFloor[n][k];
}

int32_t main () {
  ios_base :: sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    cout << eggDrop(n, k) << endl;
  }
  return 0;
}
