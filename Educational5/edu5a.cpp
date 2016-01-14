#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <regex>

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
  
  string first, second;
  cin >> first >> second;
  
  // if we use regex, TLE or MLE show up
  /*
  cout << [=] (regex pattern) {
	  return [=] (string f, string s) {
		  if(f.size() != s.size()) return f.size() > s.size() ? ">" : "<";
		  return f == s ? "=" :
		  f > s ? ">" : "<";
	  } (regex_replace(first, pattern, ""), regex_replace(second, pattern, ""));
  } (regex("^0+")) << endl;
  */
  
  cout << [=] () {
	  auto shaping = [=] (string str) {
		  int length = str.size();
		  for(int i = 0; i < length; i++) 
			  if(str[i] != '0') return str.substr(i);
		  return string("");
	  };
	  return [=] (string f, string s) {
		  if(f.size() != s.size()) return f.size() > s.size() ? ">" : "<";
		  return f == s ? "=" :
		  f > s ? ">" : "<";
	  } ( shaping(first), shaping(second) );
  } () << endl;
  
  return 0;
}
