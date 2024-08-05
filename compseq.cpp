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

int n , q ; 
int x[N] , y[N] ;

void init(void) {
	cin >> n >> q ; 
	FOR(i,1,n) cin >> x[i] ; 
	FOR(i,1,n) cin >> y[i] ; 
}

struct Node {
	int mini , maxi ; 
} st[4*N] ;

void update(int id,int l,int r,int pos,int val) {
	if(pos < l or pos > r) return ; 
	if(l==r) {
		st[id].mini = val ; 
		st[id].maxi = val ; 
		return ; 
	}
	int mid = (l+r)>>1 ; 
	update(id<<1,l,mid,pos,val) ; 
	update(id<<1|1,mid+1,r,pos,val) ; 
	st[id].maxi = max(st[id<<1].maxi,st[id<<1|1].maxi) ; 
	st[id].mini = min(st[id<<1].mini,st[id<<1|1].mini) ; 
}
int Walk(int id,int l,int r,int u,int v,int val) {
	if(l > v or r < u or st[id].maxi <= val) return -1 ; 
	if(l==r) return l ; 
	int mid = (l+r)>>1 ; 
	int ret = Walk(id<<1,l,mid,u,v,val) ; 
	if(ret==-1) ret = Walk(id<<1|1,mid+1,r,u,v,val) ; 
	return ret ; 
}
int get(int id,int l,int r,int u,int v) {
	if(l > v or r < u) return 2e9 ; 
	if(l >= u and r <= v) return st[id].mini ;
	int mid = (l+r)>>1 ; 
	return min( get(id<<1,l,mid,u,v) , get(id<<1|1,mid+1,r,u,v) ) ; 
}

void process(void) {

	FOR(i,1,n) update(1,1,n,i,x[i] - y[i]) ;

	while(q--) {
		int u,v ; 
		cin >> u >> v ; 
		x[u] = v ; 
		update(1,1,n,u,x[u]-y[u]) ; 
		if(x[1] > y[1]) {
			cout << "Y" << endl ; 
			continue ; 
		}
		int val = x[1] - y[1] ; 
		int pos = Walk(1,1,n,1,n,val) ; 
		if(pos == -1 || get(1,1,n,1,pos-1) < 0) cout << "N" ; 
		else cout << "Y" ; 
		cout << endl ;
	}


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