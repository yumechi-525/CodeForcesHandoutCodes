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

    vector<pair<int, int>> _pv(n + 1);
    _pv[0] = make_pair(0, 0);
    for(int i = 1; i < n + 1; i++) {
        int a, b;
        cin >> a >> b;
        _pv[i] = make_pair(a, b);
    }

    int m = 0;
    vector<pair<int, int>> pv(n + 1);
    for(int i = 0; i < n; i++) {
        if(_pv[i] != _pv[i + 1]) {
            pv[m] = _pv[i];
            m++;
        }
    }
    pv[m] = _pv[n];

    ll ans = 0;
    int last_cross = -1;
    for(int i = m; i > 0; i--) {
        _DDEBUG(pv[i].first, pv[i].second);
        _DDEBUG(pv[i - 1].first, pv[i - 1].second);
        int d1 = pv[i].first - pv[i - 1].first;
        int d2 = pv[i].second - pv[i - 1].second;
        int maxn = max(pv[i].first, pv[i].second);
        int minn = min(pv[i].first, pv[i].second);
        int maxm = max(pv[i - 1].first, pv[i - 1].second);
        int minm = min(pv[i - 1].first, pv[i - 1].second);
        if(maxm > minn) {
            // no action
            _DEBUG("No Action");
        } else {
            ans += minn - maxm;
            if(minn != last_cross) {
                ans++;
            }
            last_cross = maxm;
        }
        _DEBUG(ans);
    }
    if(m == 0) {
        ans = 1;
    }

#if DEBUG
    cout << "** RESULT **" << endl; // debug
#endif
    cout << ans << endl;

    return 0;
}
