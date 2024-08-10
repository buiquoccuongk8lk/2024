/// никогда не сдавайся

#include <bits/stdc++.h>
using namespace std ; 
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define FORD(i,a,b) for(int i = a ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 
#define fi first
#define se second

const int N = 1e5 + 5 ;

int n , q ;
struct Queries {
	int x ; 
} Q[N] ;

map<int,int> mp , Pre , Nxt ;
multiset<int> ms_sum , ms_sl ; 
set<int> ms_val ; 	

void init(void) {
	cin >> n >> q ; 
	FOR(i,1,q) cin >> Q[i].x ; 
}

void Change1(int x,int u,int v) {
	Pre[x] = Nxt[x] = x ;
	if(u!=0 and v!=n+1 and u+1==x and x==v-1) {
		Pre[x] = Pre[u] ; Nxt[x] = Nxt[v] ; 
		Nxt[u] = Nxt[v] ; Pre[v] = Pre[u] ; 
	} else {
		if(u+1==x and u!=0) {
			Nxt[u] = Nxt[x] ; 
			Pre[x] = Pre[u] ; 
		} else if(x==v-1 and v!=n+1) {
			Nxt[x] = Nxt[v] ; 
			Pre[v] = Pre[u] ; 
		}
	}
	ms_sl.insert(Nxt[x] - Pre[x] + 1) ; 
}

void Change2(int x,int u,int v) {
	auto it = ms_sl.find(Nxt[x] - Pre[x] + 1) ; 
	if(u!=0 and u+1==x and v!=n+1 and v==x+1) {
		Nxt[u] = u ; 
		Pre[v] = v ; 
		if(it!=ms_sl.end()) ms_sl.erase(it) ; 
		ms_sl.insert(Nxt[u] - Pre[u] + 1) ; 
		ms_sl.insert(Nxt[v] - Pre[v] + 1) ; 
	} else {
		if(u!=0 and u+1==x) {
			Nxt[u] = u ; 
			if(it!=ms_sl.end()) ms_sl.erase(it) ; 
			ms_sl.insert(Nxt[u] - Pre[u] + 1) ; 
		} else if(v!=n+1 and v==x+1) {
			Nxt[v] = v ; 
			if(it!=ms_sl.end()) ms_sl.erase(it) ; 
			ms_sl.insert(Nxt[v] - Pre[v] + 1) ; 
		} else {
			if(it!=ms_sl.end()) ms_sl.erase(it) ; 
		}
	} 
}

void solve(void) {

	ms_val.insert(0) ;
	ms_val.insert(n+1) ;
	ms_sum.insert(n) ; 
	ms_sl.insert(0) ; 
	
	FOR(i,1,q) {
		int x = Q[i].x ; 
		mp[x]++ ; 	
		if(mp[x]&1) {
			auto it = ms_val.upper_bound(x) ; 
			int v = *it ; 
			it-- ; 
			int u = *it ;
			ms_sum.erase(ms_sum.find(v - u - 1)) ;
			ms_sum.insert(v - x - 1) ; 
			ms_sum.insert(x - u - 1) ; 
			ms_val.insert(x) ;
			Change1(x,u,v) ;  
		} else {
			auto it = ms_val.upper_bound(x) ; 
			int v = *it ; 
			it-- ; 
			it-- ; 
			int u = *it ;
			ms_sum.insert(v - u - 1) ;
			ms_sum.erase(ms_sum.find(v - x - 1)) ; 
			ms_sum.erase(ms_sum.find(x - u - 1)) ; 
			ms_val.erase(x) ; 
			Change2(x,u,v) ; 
		}
		cout << max( *ms_sl.rbegin() , *ms_sum.rbegin() )<< '\n' ; 
	}

}

signed main(void) {
    #define mitsuri ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(".INP","r") ) {
        freopen(mitsuri".INP","r",stdin) ; freopen(mitsuri".OUT","w",stdout);
    }
    init() ; 
    solve() ; 
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}