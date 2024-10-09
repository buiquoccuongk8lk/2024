// 29 . 03 . 2008 
#include <bits/stdc++.h>
using namespace std ;
//#define int long long
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> ii ;
#define FOR(i,a,b) for(int i(a) ; i <= (int)b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)b ; i--)
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define all(a) a.begin() , a.end()
#define pb push_back
#define fi first
#define se second
#define BIT(mask,i) ((mask>>i)&1)
#define builtin_popcount builtin_popcountll
#define MASK(a) (1ll << a) 

template<class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template<class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const ll inf = 1e18 ;

int d , s ;
string dist[505][5005] ;
bool dd[505][5005] ;

void init() {
	cin >> d >> s ; 
}

void solve() {
	dist[0][0] = "" ; 
	queue<ii> q ; 
	q.push({0,0}) ; 
	while(!q.empty()) {
		int cur_mod = q.front().fi ; 
		int cur_sum = q.front().se ; 
		string cost = dist[cur_mod][cur_sum] ;
		q.pop() ; 
		dd[cur_mod][cur_sum] = 1 ;
		if(cur_mod==0 && cur_sum==s) {
			cout << cost ; 
			return ; 
		}
		FOR(v,0,9) {
			int new_mod = (cur_mod * 10 + v) % d ;
			int new_sum = (cur_sum + v) ; 
			string new_cost = cost + (char)(v + '0') ; 
			if(new_sum <= s && !dd[new_mod][new_sum]) {
				q.push({new_mod,new_sum}) ; 
				dist[new_mod][new_sum] = new_cost ; 
				dd[new_mod][new_sum] = 1 ; 
			}
		}
	}
	cout << -1 ;
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */ 