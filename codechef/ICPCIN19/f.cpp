#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define blue ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007;

bool overlap(int s1,int e1,int s2,int e2) {
    bool c = false;
    // if ((s2 <= e1 || e1 <= e2) || (s2 <= s1 || s1 <= e2)  )
    bool one,two,thr,four;

    one = (s1 <= s2) && (e2 <= e1);
    two = (s2 <= s1) && (e1 <= e2);
    thr = (s2 <= s1) && (e2 <= e1);
    four = (s1 <= s2) && (e1 <= e2);

    if ((one)|| (two) || (thr)|| (four) )
        c = true;
    return c;
}

int main () {

    blue

    int t;

    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        int st[n],en[n],sp[n];
        set<int> r,l;
        for (int i = 0; i < n ; i++) {
            cin >> st[i] >> en[i] >> sp [i];
        }
        r.insert(0);    // first

        bool mflag = true;

        for (int i = 1 ; i < n ; i++) {
            bool rflag = true;
            for (auto el : r) {
                if (overlap(st[i],en[i],st[el],en[el]))  {
                    if (sp[i] == sp[el]) {
                        rflag = false;
                        break;
                    }
                }
            }
            if (rflag) {
                r.insert(i);
                continue;
            }
            bool lflag = true;
            for (auto el : l) {
                if (overlap(st[i],en[i],st[el],en[el]))  {
                    if (sp[i] == sp[el]) {
                        lflag = false;
                        break;
                    }
                }
            }
            if (lflag) {
                l.insert(i);
                continue;
            }

            cout << "NO" << "\n";
            mflag = false;
            break;

        }
        // cout <<" r" << "\n";
        // for (auto i : r) {
        //     cout << i << "\t";
        // }
        // cout << endl;

        // cout <<" l" << "\n";
        // for (auto i : l) {
        //     cout << i << "\t";
        // }
        // cout << endl;
        if (mflag) cout << "YES" <<"\n";
    }

    return 0;
}
