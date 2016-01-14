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
#define INF 1<<30
#define ALEN(ARR) (sizeof(ARR) / sizeof((ARR)[0]))
#define MP make_pair
#define mp make_pair
#define pb push_back
#define PB push_back
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.precision(16);

    int n;
    cin >> n;

    int sum = 0;
    int arr[n];
    REP(i, n) {
        cin >> arr[i];
        sum += arr[i];
    }

    int ave = sum/n;
    sort(arr, arr+n, greater<int>());

    ll res = 0;
    int cnt = sum % n;
    REP(i, n) {
        int t = arr[i] - ave;
        if(t > 0) res += (cnt-- > 0 ? t-1 : t);
    }

    cout << res << endl;
    return 0;
}
