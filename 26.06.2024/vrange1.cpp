/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define myClass class WORK,class HARD
#define tct template<myClass>
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

const int N = 2e5 + 5 ;
const int LO = __lg(N)  ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n , q ;
struct Queries {
	int t , l , r , id ; 
	void input(int i) {
		cin >> t >> l >> r ; 
		id = i ; 
	}
}Q[N] ; 
int a[N] ;
int last[N] ; 
int ans[N] ;

void init(void) {
	cin >> n >> q ; 
	FOR(i,1,n) cin >> a[i] ; 
	FOR(i,1,q) Q[i].input(i) ;
}


int T[4*N] ; 
void update(int id,int l,int r,int pos,int val) {
	if(pos < l or pos > r) return ;
	if(l==r) {
		T[id]+=val ; 
		return ; 
	}
	int mid = (l+r)>>1 ; 
	update(id<<1,l,mid,pos,val) ; 
	update(id<<1|1,mid+1,r,pos,val) ; 
	T[id] = T[id<<1] + T[id<<1|1] ; 
}

int get(int id,int l,int r,int u,int v) {
	if(l > v or r < u) return 0 ; 
	if(l >= u and r <= v) return T[id] ; 
	int mid = (l+r)>>1 ; 
	return get(id<<1,l,mid,u,v) + get(id<<1|1,mid+1,r,u,v) ; 
}

int fi[N] ;
vi Quer[N] ; 
vi pos[N] ;
int bit[N] ; 
int L[N] , R[N] ;

void up(int u,int val) {
	for(int i(u) ; i <= n ; i+=i&-i) bit[i]+=val ; 
}

int get(int u) {
	int ret = 0 ;
	for(int i(u) ; i ; i-=i&-i) ret+=bit[i] ; 
	return ret ; 
}

int get_sum(int l,int r) {
	return get(r) - get(l-1) ; 
}

void process(void) {
	
	vi vec ; 

	FOR(i,1,n) {
		vec.pb(a[i]) ; 
	}

	uni(vec) ; 

	FOR(i,1,n) {
		int pos = lower_bound(all(vec),a[i]) - vec.begin() + 1 ; 
		fi[pos] = a[i] ; 
		a[i] = lower_bound(all(vec),a[i]) - vec.begin() + 1 ; 	
	}	

	int VAL = sz(vec) ; 

	FOR(i,1,q) {
		if(Q[i].t==2) {
			L[i] = 1 ;
			R[i] = VAL ; 
		}
	}

	FOR(i,1,n) pos[a[i]].pb(i) ;

	while(1) {

		bool ok = false ;

		FOR(i,1,q) {
			if(Q[i].t==2) {
				if(L[i]<=R[i]) {
					Quer[(L[i]+R[i])>>1].pb(i) ; 
					ok = true ; 
				}
			}
		}

		if(!ok) break ;

		FOR(val,1,VAL) {
			for(auto x : pos[val]) up(x,1) ; 	
			for(auto id : Quer[val]) {
				if(get_sum(Q[id].l,Q[id].r) >= (Q[id].r - Q[id].l + 2)/2) {
					ans[id] = fi[val] ;  
					R[id] = val - 1 ; 
				} else L[id] = val + 1 ;
			}
		}

		FOR(i,1,n) bit[i] = 0 ;
		FOR(i,1,VAL) Quer[i].clear() ;
	}


	sort(Q+1,Q+1+q,[](Queries u,Queries v) {
		return u.r < v.r ; 
	}) ; 

	int j = 1 ; 

	FOR(i,1,q) { 
		if(Q[i].t==1) {	
			while(j <= Q[i].r) {
				update(1,1,n,last[a[j]],-1) ; 
				last[a[j]] = j ; 
				update(1,1,n,last[a[j]],1) ; 
				j++ ; 
			}
			ans[Q[i].id] = get(1,1,n,Q[i].l,Q[i].r) ; 
		}
	}

	FOR(i,1,q) cout << ans[i] << endl ;

}


signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    process() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return (0 ^ 0) ; 
}