#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>

#include <map>
#include <set>
#include <string>
#include <sstream>
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

  int n;
  cin >> n;

  vector<int> a;
  a.pb(2);
  a.pb(3);
  for(int i = 6; i-1 <= n; i += 6) {
      bool f1 = true;
      bool f2 = true;
      for(int j = 0; j < a.size(); j++) {
          if(i+1 % a[j] == 0) {
              f1 = false;
              break;
          }
      }
      for(int j = 0; j < a.size(); j++) {
          if(i-1 % a[j] == 0) {
              f2 = false;
              break;
          }
      }
      if(f1) a.pb(i+1);
      if(f2) a.pb(i-1);
  }

  stringstream res;
  int cnt = 0;
  REP(i, a.size()) {
      int t = a[i];
      while(t <= n) {
          cnt++;
          res << t << " ";
          t *= a[i];
      }
  }

  if(n == 1) {
      cout << "0\n" << endl;
  } else {
      string r = res.str();
      cout << cnt << endl;
      cout << r.substr(0, r.length()-1) << endl;
  }
  return 0;
}
