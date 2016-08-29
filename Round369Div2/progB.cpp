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
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define INF 1<<29
#define ALEN(ARR) (sizeof(ARR) / sizeof((ARR)[0]))
#define MP make_pair
#define mp make_pair
#define pb push_back
#define PB push_back
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DDEBUG(x,y) cout<<#x<<": "<<x<<", "<<#y<<": "<<y<<endl
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

void failedFinish() {
    cout << "-1" << endl;
    exit(0);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.precision(16);

    int n;
    cin >> n;

    if(n == 1) {
        cout << "1" << endl;
        return 0;
    }

    ll array[n][n];
    int i0, j0;
    REP(i, n) {
        REP(j, n) {
            cin >> array[i][j];
            if(array[i][j] == 0) {
                i0 = i;
                j0 = j;
            }
        }
    }

    ll onelinesum = 0;
    REP(i, n) {
        if(i0 == i) continue;
        ll tsum = 0;
        REP(j, n) {
            tsum += array[i][j];
        }
        onelinesum = tsum;
        break;
    }


    ll ans = onelinesum;
    REP(j, n) ans -= array[i0][j];
    if(ans <= 0) failedFinish();

    REP(i, n) {
        ll row = 0;
        REP(j, n) row += array[i][j];

        if(i == i0) {
            if(row != onelinesum - ans) {
                failedFinish();
            }
        } else {
            if(row != onelinesum) {
                failedFinish();
            }
        }
    }

    REP(i, n) {
        ll cal = 0;
        REP(j, n) cal += array[j][i];

        if(i == j0) {
            if(cal != onelinesum - ans) {
                failedFinish();
            }
        } else {
            if(cal != onelinesum) {
                failedFinish();
            }
        }
    }

    ll l1 = 0, l2 = 0;
    REP(i, n) {
        l1 += array[i][i];
        l2 += array[n-i-1][i];
    }

    if(i0 == j0) {
        if(l1 != onelinesum - ans) {
            failedFinish();
        }
    } else {
        if(l1 != onelinesum) {
            failedFinish();
        }
    }

    if(n - i0 - 1 == j0) {
        if(l2 != onelinesum - ans) {
            failedFinish();
        }
    } else {
        if(l2 != onelinesum) {
            failedFinish();
        }
    }

    cout << ans << endl;
}
