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

const int N = 1e6 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n,q ;
ll b ; 

void init(void) {
	cin >> n >> q >> b ;
}

ll st[4*N] , lazy[4*N] ;

void down(int id,int l,int r) {
	if(lazy[id]==-1) return ; 
	int mid = (l+r)>>1 ;

	st[id<<1] = 1LL * (mid - l + 1) * lazy[id] ; 
	st[id<<1|1] = 1LL * (r - mid) * lazy[id] ; 

	lazy[id<<1] = lazy[id] ; 
	lazy[id<<1|1] =lazy[id] ; 

	lazy[id] = -1 ; 
}

void update(int id,int l,int r,int u,int v,ll val) {
	if(l > v or r < u) return ;
	if(l >= u and r <= v) {
		st[id] = 1LL * (r - l + 1) * val ;
		lazy[id] =val ; 
		return ;  
	}
	int mid = (l+r)>>1 ; 
	down(id,l,r) ; 
	update(id<<1,l,mid,u,v,val) ; 
	update(id<<1|1,mid+1,r,u,v,val) ; 
	st[id] = st[id<<1] + st[id<<1|1] ;
}	

ll get(int id,int l,int r,int u,int v) {
	if(l > v or r < u) return 0 ; 
	if(l >= u and r <= v) return st[id] ; 
	int mid = (l+r)>>1 ; 
	down(id,l,r) ;
	return get(id<<1,l,mid,u,v) + get(id<<1|1,mid+1,r,u,v) ; 
}

void process(void) {

	FOR(i,1,4*n) lazy[i] = -1 ; 

	FOR(i,1,n) update(1,1,n,i,i,b) ; 

	while(q--) {
		int r ;
		ll p ; 
		cin >> r >> p ;
		int l = r ; 
		int d = 1 ; 
		int c = r ; 
		while(d <= c) {
			int mid = (d+c)>>1 ;
			ll aMid = get(1,1,n,mid,mid) ; 
			ll sum = aMid * ( r - mid + 1 ) - get(1,1,n,mid,r) ; 
			if(sum <= p) {
				l = mid ; 
				c = mid - 1 ; 
			} else {
				d = mid + 1 ; 
			}
		}
		ll aL = get(1,1,n,l,l) ; 
		p-= aL * ( r - l + 1) - get(1,1,n,l,r) ; 
		ll aNew = aL + p / (r - l + 1) ;  
		int m = l + p % (r - l + 1) - 1 ;
		update(1,1,n,l,m,aNew + 1) ; 
		update(1,1,n,m+1,r,aNew) ; 
	}

	FOR(i,1,n) cout << get(1,1,n,i,i) << ' ' ;
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