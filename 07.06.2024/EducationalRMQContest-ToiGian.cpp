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
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define uni(a) sort(all(a)) , a.resize(unique(a.begin(),a.end())-a.begin()) 

const int N = 3e5 + 5 ;
const int LO = log2(N) + 1 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if(x>y){x=y;return true;}else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if(x<y){x=y;return true;}else return false;}

int n ; 
int a[N] , L[N] , rmq_gcd[N][LO] , R[N] ; 

void init(void) {
	cin >> n ;
	FOR(i,1,n) cin >> a[i] ; 
}

void process(void) {
	FOR(i,1,n) rmq_gcd[i][0] = a[i] ; 
	for(int j(1) ; 1<<j <= n ; j++) {
		for(int i(1) ; i + (1<<j) - 1 <= n ; i++) { 
			rmq_gcd[i][j] = __gcd(rmq_gcd[i][j-1],rmq_gcd[i+(1<<(j-1))][j-1]) ; 
		}
	}
	auto get_gcd = [&] (int l,int r,int rmq[N][LO]) {
		int k = log2(r-l+1) ; 
		return __gcd(rmq[l][k],rmq[r-(1<<k)+1][k]) ;
	};
	int ans = 0 ; 
	deque<int> dq ; 
	FOR(i,1,n) {
		while(!dq.empty() and a[dq.front()] > a[i]) dq.pop_front() ;
		if(dq.empty()) L[i] = 1 ; 
		else L[i] = dq.front() + 1 ; 
		dq.push_front(i) ; 
	}
	while(!dq.empty()) dq.pop_front() ; 
	FORD(i,n,1) {
		while(!dq.empty() and a[dq.front()] > a[i]) dq.pop_front() ; 
		if(dq.empty()) R[i] = n ;
		else R[i] = dq.front() - 1 ;
		dq.push_front(i) ; 
	}
	FOR(i,1,n) {
		int l = L[i] ; 
		int r = i ; 
		int posL = i ; 
		while(l <= r) {
			int mid = (l+r)>>1 ; 
			if( get_gcd(mid,i,rmq_gcd) == a[i] ) posL = mid , r = mid - 1 ; 
			else l = mid + 1 ; 
		}
		int posR = i ; 
		l = i ; 
		r = R[i] ; 
		while(l <= r) {
			int mid = (l+r)>>1 ; 
			if( get_gcd(i,mid,rmq_gcd) == a[i] ) posR = mid , l = mid + 1 ; 
			else r = mid - 1 ;  
		}
		ans+= (i-posL+1) * (posR-i+1) - 1 ; 
	}
	cout << ans ;
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
    return 0;
}