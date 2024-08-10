/// hello a Tons
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define fi first
#define se second
#define pb push_back
#define rep(i,a,b) for(int i(a) ; i <= b ; i++) 
#define repd(i,a,b) for(int i(a) ; i >= b ; i--)
typedef vector<int> vi ;
typedef pair<int,int> ii ;
typedef vector<ii> vii ; 

const int N = 2e5 + 5 , LO = 17 , base = 311 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if(x>y){x=y;return true;}else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if(x<y){x=y;return true;}else return false;}

int n , m , k , d ; 
int a[12][N] ;
int dp[12][N] ; 
int st[4*N] ;
int pre[N] ;
void init(void) {
	cin >> n >> m >> k >> d ; 
	rep(i,1,n) rep(j,1,m) cin >> a[i][j] ; 
}
void update(int id,int l,int r,int pos,int val) {
	if(pos < l or pos > r) return;
	if(l==r) {
		st[id] = val ;
		return;
	}
	int mid = (l+r)>>1;
	update(id<<1,l,mid,pos,val);
	update(id<<1|1,mid+1,r,pos,val);
	st[id] = min(st[id<<1],st[id<<1|1]);
}
int get(int id,int l,int r,int u,int v) {
	if( l > v or r < u ) return inf ;
	if( l >= u and r <= v) return st[id];
	int mid = (l+r)>>1;
	int t1 = get(id<<1,l,mid,u,v);
	int t2 = get(id<<1|1,mid+1,r,u,v);
	return min(t1,t2);
}
void process(void) {
	rep(i,1,n) {
		rep(j,1,4*m) st[j] = inf ; 
		dp[i][1] = a[i][1] + 1 ;
		update(1,1,m,1,dp[i][1]) ;  
		rep(j,2,m) {
			dp[i][j] = get(1,1,m,max(1ll*1,j-d-1),j) + a[i][j] + 1 ;
			update(1,1,m,j,dp[i][j]) ; 
		}
		pre[i] = pre[i-1] + dp[i][m] ;
	}
	int ans = inf ; 
	rep(i,1,n-k+1) {
		ans = min(ans , pre[i+k-1] - pre[i-1]) ;
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