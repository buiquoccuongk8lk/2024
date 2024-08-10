/* ---------------------- *
 *   * Code by watbor     *
 *   * Need Her and VOI   *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;
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
#define rep(i,a,b) for(int i(a) ; i <= b ; i++)
#define repd(i,a,b) for(int i(a) ; i >= b ; i--)
#define uni(a) sort(all(a)) , a.resize(unique(a.begin(),a.end())-a.begin()) 

const int N = 5e5 + 5 ;
const int LO = 20 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if(x>y){x=y;return true;}else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if(x<y){x=y;return true;}else return false;}

int n , q ; 
int a[N] , L[N] , R[N] ;
int last[N] ;
int rmq_max[N][LO] , rmq_min[N][LO] ; 
void init(void) {
	cin >> n >> q ; 
	rep(i,1,n) cin >> a[i] ; 
}
void init_RMQ(void) {
	rep(i,1,n) {
		rmq_max[i][0] = L[i] ; 
		rmq_min[i][0] = R[i] ; 
	}
	for(int j(1) ; (1<<j) <= n ; j++) {
		for(int i(1) ; i + (1<<j) - 1 <= n ; i++) {
			rmq_max[i][j] = max(rmq_max[i][j-1],rmq_max[i+(1<<(j-1))][j-1]) ; 
			rmq_min[i][j] = min(rmq_min[i][j-1],rmq_min[i+(1<<(j-1))][j-1]) ; 
		}
	}

}
int get_max(int l,int r) {
	int k = log2(r-l+1) ; 
	return max(rmq_max[l][k],rmq_max[r-(1<<k)+1][k]) ; 
}
int get_min(int l,int r) {
	int k = log2(r-l+1) ; 
	return min(rmq_min[l][k],rmq_min[r-(1<<k)+1][k]) ; 
}
void solve(void) {
	vi v ; 
	rep(i,1,n) v.pb(a[i]) ; 
	uni(v) ; 
	rep(i,1,n) {
		a[i] = lower_bound(all(v) , a[i]) - v.begin() ; 
	}
	rep(i,1,n) {
		if(last[a[i]]) L[i] = last[a[i]] ; 
		else L[i] = 0 ; 
		last[a[i]] = i ;  
	}
	rep(i,1,n) last[a[i]] = 0 ;
	repd(i,n,1) {
		if(last[a[i]]) R[i] = last[a[i]] ; 
		else R[i] = n + 1 ; 
		last[a[i]] = i ; 
	}
	init_RMQ() ; 
	while(q--) {
		int L , R ; 
		cin >> L >> R ; 
		int l = L + 1 ;
		int r = R  ;
		int posL = -1 ; 
		while(l <= r) {
			int mid = (l+r)>>1 ; 
			if( get_max(mid,R) < mid ) posL = mid , r = mid - 1 ; 
			else l = mid + 1 ; 
		}
		if(posL==-1 || get_min(L,posL-1) <= posL-1) {
			cout << 0 << endl ; 
			continue ; 
		}
		l = L ;
		r = R - 1 ; 
		int posR = -1 ;
		while(l <= r ) {
			int mid = (l+r)>> 1 ; 
			if( get_min(L,mid) > mid ) posR = mid , l = mid + 1 ; 
			else r = mid - 1 ; 
		}
		if(posR==-1 || get_max(posR+1,R) >= posR + 1) {
			cout << 0 << endl ; 
			continue ; 
		}
		cout << posR - posL + 2 << endl ;
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
    solve() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}