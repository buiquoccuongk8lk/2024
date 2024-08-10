/*[продолжатьипродолжать]*/
/* ---------------------- *
 *     Code by watbor     *
 *                        * 
--------------------------*/

#define tct template<class MITSURII,class CHANN>

#include <bits/stdc++.h>
using namespace std ; 

#define ll long long 
#define fi first
#define se second
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
#define endl '\n' 
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define FORN(i,a,b) for(int i(a) ; i < b ; i++)
#define uni(a) sort(all(a)) , a.resize(unique(a.begin(),a.end())-a.begin()) 

const int N = 3e5 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const int mod = 1e9 + 7 ;
const long long inf = 1e18 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n ; 
ii a[N] ; 

void init(void) {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i].fi >> a[i].se ; 
}

namespace sub1 {
	int dmin[N] ;
	int dist(ii u,ii v) {
		return abs(u.fi - v.fi) + abs(u.se - v.se) ;
	}
	void solve(void) {
		FOR(i,1,n) {
			dmin[i] = oo ;
			FOR(j,1,n) if(i!=j) dmin[i] = min(dmin[i],dist(a[i],a[j])) ; 
		}
		int ans = 0 ; 
		FOR(i,1,n) FOR(j,i+1,n) FOR(k,j+1,n) {
			if(dmin[i]==dmin[j] && dmin[i]==dmin[k]) {
				int dij = dist(a[i],a[j]) ; 
				int dik = dist(a[i],a[k]) ;
				int djk = dist(a[j],a[k]) ;
				if(dij==dik && dij==djk && dij==dmin[i]) {
					ans++ ; 
				}
			}
		}
		cout << ans ; 
	}
}

namespace sub2 {
	vi v ;
	ll st[4*N][3] ; 

	unordered_map<int,int>mp ;
	map<ll,vector<int>> ID_DMIN ; 
	map<int,vector<ii>> sweep ;
	struct DL {
		ll val ; 
		int id ; 
	} dmin[N] ;
	vi g[N] ; 

	int dist(ii u,ii v) {
		return abs(u.fi - v.fi) + abs(u.se - v.se) ;
	}

	void update(int id,int l,int r,int pos,ll val,int t) {
		if(pos < l or pos > r) return ; 
		if(l==r) {
			st[id][t] = min(st[id][t],val) ; 
			return ; 
		}
		int mid = (l+r)>>1 ; 
		update(id<<1,l,mid,pos,val,t) ; 
		update(id<<1|1,mid+1,r,pos,val,t) ;
		st[id][t] = min(st[id<<1][t],st[id<<1|1][t]) ; 
	}

	ll get(int id,int l,int r,int u,int v,int t) {
		if(l > v or r < u) return inf ; 
		if(l >= u and r <= v) return st[id][t] ; 
		int mid = (l+r)>>1 ; 
		return min(get(id<<1,l,mid,u,v,t),get(id<<1|1,mid+1,r,u,v,t)) ; 
	}

	void pre_calc(void) {
		sort(a+1,a+1+n) ;
		vi v ; 
		FOR(i,1,n) v.pb(a[i].se) ; 
		uni(v) ; 
		int VAL = v.size() ; 
		memset(st,0x3f3f3f3f,sizeof st) ; 
		FOR(i,1,n) dmin[i] = {inf , 0} ; 
		FOR(i,1,n) {
			int p = lower_bound(all(v),a[i].se) - v.begin() + 1 ;
			dmin[i].val = a[i].fi + a[i].se + get(1,1,VAL,1,p,0) ;
			dmin[i].val = min(dmin[i].val , a[i].fi - a[i].se + get(1,1,VAL,p,VAL,1) ) ;  
			update(1,1,VAL,p,-a[i].fi - a[i].se,0) ; 
			update(1,1,VAL,p,-a[i].fi + a[i].se,1) ; 
			dmin[i].id = i ; 
		}
		//FOR(i,1,4*VAL) st[i][0] = st[i][1] = inf ; 
		memset(st,0x3f3f3f3f,sizeof st) ; 
		FORD(i,n,1) {
			int p = lower_bound(all(v),a[i].se) - v.begin() + 1 ;
			dmin[i].val = min(dmin[i].val , -a[i].fi + a[i].se + get(1,1,VAL,1,p,0) ) ;
			dmin[i].val = min(dmin[i].val , -a[i].fi - a[i].se + get(1,1,VAL,p,VAL,1) ) ; 
			update(1,1,VAL,p,a[i].fi - a[i].se,0) ;
			update(1,1,VAL,p,a[i].fi + a[i].se,1) ;  
			dmin[i].id = i ; 
		}	
	}
	
	void PUSH(int id,int l,int r,vii &a) {
		int L = lower_bound(all(a),l,[](ii x ,int val){return x.se<val;}) - a.begin();
		int R = upper_bound(all(a),r,[](int val , ii x){return val<x.se;})- a.begin() - 1 ;
		FOR(i,L,R) if(a[i].fi!=id) g[id].pb(a[i].fi) ; 
	}

	void factories(ll val) {
		for(auto x: sweep) {
			vii L , R ;
			if(sweep.count((x.fi-val))) L = sweep[x.fi-val] ; 
			if(sweep.count((x.fi+val))) R = sweep[x.fi+val] ; 	
			for(auto u : x.se) {
				int id = u.fi ;
				PUSH(id,u.se-val,u.se+val,L);
				PUSH(id,u.se-val,u.se+val,R) ; 
			}
		}
		sweep.clear() ;
	}

	void solve(void) {
		pre_calc() ;
		FOR(i,1,n) ID_DMIN[dmin[i].val].push_back(i) ;
		for(auto val : ID_DMIN) {
			for(auto id : val.se) sweep[a[id].fi+a[id].se].pb({id,a[id].fi - a[id].se}) ; 
			factories(val.fi) ; 
			for(auto id : val.se) sweep[a[id].fi-a[id].se].pb({id,a[id].fi + a[id].se}) ;
			factories(val.fi) ; 
		}		
		int ans = 0 ; 
		FOR(i,1,n) uni(g[i]) ; 
		FOR(i,1,n) {
			for(auto j : g[i]) for(auto k : g[i]) {
				if(j < k) {
					if(dist(a[j],a[k])==dmin[i].val) ans++ ; 
				}
			}
		}
		cout << ans/3 ; 
	}

}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    init() ; 
    /*if(n <= 100) sub1::solve() ; 
    else*/ sub2::solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}