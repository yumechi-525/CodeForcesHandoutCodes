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

  int n, k, x;
  cin >> n >> k >> x;

  ll A[n];
  ll res = 0;
  REP(i, n) {
      cin >> A[i];
      res |= A[i];
  }
  unique(A, A+n);


  REP(i, k) {
      int idx = 0;
      ll tmax = res;
      REP(j, n) {
          A[j] *= x;
          ll tsum = 0;
          REP(l, n) tsum |= A[l];
          A[j] /= x;
          if(tsum > tmax) {
              idx = j;
              tmax = tsum;
          }
      }

      A[idx] *= x;
      res = tmax;
  }

  cout << res << endl;
  return 0;
}
