#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>

#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define INF (1<<30)
#define ALEN(ARR) (sizeof(ARR) / sizeof((ARR)[0]))
#define MP make_pair
#define mp make_pair
#define pb push_back
#define PB push_back

#if DEBUG
#define _DEBUG(x) cout<<#x<<": "<<x<<endl
#define _DDEBUG(x,y) cout<<#x<<": "<<x<<", "<<#y<<": "<<y<<endl
#else
#define _DEBUG(x) ;
#define _DDEBUG(x,y) ;
#endif

#define ll long long
#define ull unsigned long long
#define MOD 1000000007

/** FOR VECTOR DEBUG */
template <typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
    if ( !v.empty() ) {
        out << '[';
        copy (v.begin(), v.end(), ostream_iterator<T>(out, ", "));
        out << "\b\b]";
    }
    return out;
}


/* template end */


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.precision(16);

    int n;
    cin >> n;

    vector<int> v(n);
    REP(i, n) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    vector<int> v1(n);
    vector<int> v2(n);
    v1[0] = v2[0] = v.back();
    int c1 = 0, c2 = 0;
    for(int i = n - 2; i >= 0; i--) {
        int d1 = v1[c1] - v[i];
        int d2 = v2[c2] - v[i];
        if(d1 > d2) {
            v1[c1 + 1] = v[i];
            c1++;
        } else {
            v2[c2 + 1] = v[i];
            c2++;
        }
    }

    int c = 0;
    vector<int> ans(n);
    for(int i = c1; i >= 1; i--) {
        _DDEBUG(c, i);
        ans[c] = v1[i];
        c++;
    }

    ans[c] = v.back();
    c++;
    for(int i = 1; i <= c2; i++) {
        _DDEBUG(c, i);
        ans[c] = v2[i];
        c++;
    }

#if DEBUG
    cout << "** RESULT **" << endl; // debug
#endif
    for(int i = 0; i < n; i++) {
        cout << ans[i];
        if(i != n - 1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }

    return 0;
}
