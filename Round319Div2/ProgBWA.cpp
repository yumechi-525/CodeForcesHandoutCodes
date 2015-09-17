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

  int n, m;
  cin >> n >> m;

  int A[n];
  REP(i, n) cin >> A[i];

  vector<int> table;
  table.pb(0);
  REP(i, n) {
      int ts = table.size();
      REP(j, ts) {
          int t = table[j] + A[i];
          if(t % m == 0) {
              cout << "YES" << endl;
              return 0;
          }
          vector<int>::iterator cfind = find( table.begin(), table.end() , t);
          if(cfind == table.end()) {
              table.pb(t);
          }
      }
  }

  cout << "NO" << endl;
  return 0;
}
