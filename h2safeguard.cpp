/*[продолжатьипродолжать]*/
/* ---------------------- *
 *     Code by watbor     *
 *                        * 
--------------------------*/

#define tct template<class MITSURII,class CHANN>

#include <bits/stdc++.h>
using namespace std ; 

#define int long long
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

const int N = 1e5 + 5 ;
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

int n , m ;
struct point {
	int x , y ; 
} D[N] , C[N] , H[N] ; 
ll SH ;
int sz ; 

void init(void) {
	cin >> n ;
	FOR(i,1,n) cin >> D[i].x >> D[i].y ; 
	cin >> m ; 
	FOR(i,1,m) cin >> C[i].x >> C[i].y ; 
}

int ccw(point a,point b,point c) {
	return (b.x - a.x) * (c.y-b.y) - (b.y-a.y) * (c.x-b.x) ; 
}

int dist(point a,point b) {
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) ; 
}

int DTTG(point A,point B,point C){
	return abs ( 1ll * (B.x - A.x ) * ( C.y - A.y ) - ( 1ll * C.x - A.x )* ( B.y - A.y ) );
}

bool OK(point P) {
	int l = 2 ; 
	int r = sz - 1 ; 
	int i = 0 ; 
	while(l <= r) {
		int mid = (l+r)>>1 ; 
		if(ccw(H[1],H[mid],P) > 0) {
			i = mid ; 
			l = mid + 1 ; 
		} else r = mid - 1 ; 
	}
	ll sABC = DTTG(H[1],H[i],H[i+1]) ; 
	ll sP = DTTG(P,H[1],H[i]) + DTTG(P,H[i],H[i+1]) + DTTG(P,H[1],H[i+1]) ;
	return sABC == sP ; 
}

void solve(void) {
	sort(D+1,D+1+n,[](point u,point v) {
		if(u.y==v.y) return u.x < v.x ;
		else return u.y < v.y ; 
	}) ;
	sort(D+2,D+1+n,[](point a,point b) {
		if(ccw(D[1],a,b)==0) return dist(D[1],a) < dist(D[1],b) ;
		return ccw(D[1],a,b) > 0 ;
	}) ;
	sz = 2 ; 
	D[n+1] = D[1] ;
	H[1] = D[1] ; 
	H[2] = D[2] ; 
	FOR(i,3,n+1) {
		while(sz >= 2 && ccw(H[sz-1],H[sz],D[i]) <= 0) --sz ;
		sz++ ; 
		H[sz] = D[i] ; 
	}
	H[sz+1] = H[1] ; 
	SH = 0 ;
	FOR(i,1,sz) {
		SH+= H[i].x * H[i+1].y - H[i+1].x*H[i].y ; 
	}
	if(SH==0) {
		cout << 0 ;
		return ;
	}
	int ans = 0 ; 
	FOR(i,1,m) {
		if(OK(C[i])) ans++ ; 
	}
	cout << ans ; 
}	

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    init() ; solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}