/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
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

const int N = 5e5 + 5 ;
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

int n,k,q ;
struct DL {
	int x ; 
	int y ; 
	ll sm ; 
} xe[N] ;

void init(void) {
	cin >> n >> k >> q ; 
	FOR(i,1,k) {
		cin >> xe[i].x >> xe[i].y >> xe[i].sm ;
	}
}

/*namespace sub_task1 {
	ll a[2005][2005] ;
	ll b[2005][2005] ;

	int calc(int x,int y) {
		ll sum_xor = 0 ; 
		FOR(j,1,y-1) sum_xor^=a[x][j] ; 
		FOR(j,y+1,n) sum_xor^=a[x][j] ; 
		FOR(i,1,x-1) sum_xor^=a[i][y] ; 
		FOR(i,x+1,n) sum_xor^=a[i][y] ; 
		return (sum_xor > 0) ;
	}

	void solve(void) {

		FOR(i,1,k) {
			a[xe[i].x][xe[i].y] = xe[i].sm ;
		}	

		while(q--) {
			int r1,c1,r2,c2 ;
			cin >> r1 >> c1 >> r2 >> c2 ; 
			a[r2][c2] = a[r1][c1] ; 
			a[r1][c1] = 0 ;
			int ans = 0 ; 
			FOR(i,1,n) {
				FOR(j,1,n) {
					ans+=calc(i,j) ; 
				}
			}
			cout << ans << ' ' ; 
		}

	}

}

namespace sub_task2 {
	ll a[2005][2005] ; 
	ll xor_col[2005] , xor_row[2005] ;

	void solve(void) {
		
		FOR(i,1,k) {
			a[xe[i].x][xe[i].y] = xe[i].sm ; 
			xor_col[xe[i].y]^=xe[i].sm ; 
			xor_row[xe[i].x]^=xe[i].sm ;
 		}

 		while(q--) {
 			int r1,c1,r2,c2 ;
 			cin >> r1 >> c1 >> r2 >> c2 ;
 			xor_col[c1]^= a[r1][c1] ; 
 			xor_col[c2]^= a[r1][c1] ; 
 			xor_row[r1]^= a[r1][c1] ; 
 			xor_row[r2]^= a[r1][c1] ; 
 			a[r2][c2] = a[r1][c1] ; 
 			a[r1][c1] = 0 ;
 			int ans = 0 ; 
 			FOR(i,1,n) FOR(j,1,n) if( (xor_row[i] ^ xor_col[j]) > 0 )ans++ ;
 			cout << ans << ' ' ;
 		}

	}

}*/
namespace sub_task3 {

	struct Queries {
		int r1,c1,r2,c2 ;
	}Q[N] ;
	unordered_map<int,ll> val[N] ; 
	ll xor_row[N] ,xor_col[N] ;
	unordered_map<ll,int> cntRow ;
	unordered_map<ll,int> cntCol ; 
	ll res ; 
	
	void update(ll xor_row[] , unordered_map<ll,int>&cntRow , unordered_map<ll,int>&cntCol , int i, ll p) {
		ll old = xor_row[i] ; xor_row[i]^= p ; ll cur = xor_row[i] ;
		res-=cntCol[old] ;
		res+=cntCol[cur] ;
		cntRow[old]-- ;
		cntRow[cur]++ ;
	}

	void query(int r1,int c1,int r2,int c2) {
		int v = val[r1][c1] ;
		val[r1][c1] = 0 ;
		val[r2][c2] = v ;
		if(r1!=r2) {
			update(xor_row,cntRow,cntCol,r1,v) ; 
			update(xor_row,cntRow,cntCol,r2,v) ; 
		}	
		if(c1!=c2) {
			update(xor_col,cntCol,cntRow,c1,v) ; 
			update(xor_col,cntCol,cntRow,c2,v) ; 
		}	
		cout << 1ll* n * n - res << ' ' ;
	}	

	void solve(void) {
		vi vec_col ;
		vi vec_row ;
		FOR(i,1,k) {
			vec_row.push_back(xe[i].x) ; 
			vec_col.push_back(xe[i].y) ; 
		}
		FOR(i,1,q) {
			cin >> Q[i].r1 >> Q[i].c1 >> Q[i].r2 >> Q[i].c2 ;
			vec_row.pb(Q[i].r1) ; 
			vec_row.pb(Q[i].r2) ; 
			vec_col.pb(Q[i].c1) ; 
			vec_col.pb(Q[i].c2) ; 
		}

		uni(vec_row) ;
		uni(vec_col) ;

		FOR(i,1,k) {
			xe[i].x = lower_bound(all(vec_row),xe[i].x) - vec_row.begin() + 1 ; 
			xe[i].y = lower_bound(all(vec_col),xe[i].y) - vec_col.begin() + 1 ;
			//cout << xe[i].x << ' '<< xe[i].y << endl ;
		}

		FOR(i,1,q) {
			Q[i].r1 = lower_bound(all(vec_row),Q[i].r1) - vec_row.begin() + 1 ; 
			Q[i].r2 = lower_bound(all(vec_row),Q[i].r2) - vec_row.begin() + 1 ; 
			Q[i].c1 = lower_bound(all(vec_col),Q[i].c1) - vec_col.begin() + 1 ; 
			Q[i].c2 = lower_bound(all(vec_col),Q[i].c2) - vec_col.begin() + 1 ;
			//cout << Q[i].r1 << ' '<< Q[i].c1 <<' ' << Q[i].r2 << ' ' << Q[i].c2 << endl ; 
		}
		cntCol[0] = cntRow[0] = n ;
		res = n * n ;
		//cout << xe[1].x << ' ' ;
		FOR(i,1,k) {
			val[xe[i].x][xe[i].y] = xe[i].sm ;
			update(xor_row,cntRow,cntCol,xe[i].x,xe[i].sm) ; 
			update(xor_col,cntCol,cntRow,xe[i].y,xe[i].sm) ;
		} 

		FOR(i,1,q) {
			query(Q[i].r1,Q[i].c1,Q[i].r2,Q[i].c2) ;
		}

	}

}

signed main(void) {
    #define TASK "topovi"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    /*if(n <= 50 and k <= 200 and q <= 200) sub_task1::solve() ;
    else if(n <= 200 and k <= 2000 and q <= 2000) sub_task2::solve() ;
    else if(n <= 2000 and k <= 20000 and q <= 20000)*/ sub_task3::solve() ;
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}