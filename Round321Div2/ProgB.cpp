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

  int n, d;
  cin >> n >> d;

  vector< vector<int> > A(n);
  REP(i, n) {
      std::vector<int> B(2);
      cin >> B[0] >> B[1];
      A[i] = B;
  }
  sort(A.begin(), A.end());

  ll res = A[0][1];
  int idx = 0;
  ll t = A[0][1];
  FOR(i, 1, n) {
      if(A[i][0] - A[idx][0] < d) {
          t += A[i][1];
      } else {
          while(A[i][0] - A[idx][0] >= d) {
              t -= A[idx][1];
              idx++;
          }
          t += A[i][1];
      }
      res = max(res, t);
  }

  cout << max(res, t) << endl;
  return 0;
}
