/* ---------------------- *
 *   * Code by watbor     *
 *   * Need Her and VOI   *
 *   :>                   *
--------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define rep(i,a,b) for(int i(a) ; i <= b ; i++) 
#define repd(i,a,b) for(int i(a) ; i >= b ; i--)
typedef pair<int,int> ii ;
typedef vector<int> vi ;
typedef vector<pair<int,int>>vii ;

const int N = 1e6 + 5 , LO = 17 , base = 311 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if (x > y) {x=y;return true;} else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if (x < y) {x=y;return true;} else return false;}

int n ; 
int a[N],st[4*N] ; 
long long pre[N] ; 

void update(int id,int l,int r,int pos,int val) {
	if(pos < l or pos > r) return;
	if(l==r) {
		st[id] = val ; 
		return;
	}
	int mid = (l+r)>>1;
	update(id<<1,l,mid,pos,val);
	update(id<<1|1,mid+1,r,pos,val);
	st[id] = max(st[id<<1],st[id<<1|1]);
}
int WalkL(int id,int l,int r,int u,int v,int val) {
	if(l > v or r < u or st[id] <= val) return -1 ; 
	if(l==r) return l ;
	//cout << l << " "  << r << endl ;
	int mid = (l+r) >> 1 ; 
	int ret = WalkL(id<<1|1,mid+1,r,u,v,val) ; 
	if(ret==-1) ret = WalkL(id<<1,l,mid,u,v,val) ; 
	return ret ; 
}
int WalkR(int id,int l,int r,int u,int v,int val) {
	if(l > v or r < u or st[id] <= val) return -1 ; 
	if(l==r) return l ;
	int mid = (l+r) >> 1 ; 
	int ret = WalkR(id<<1,l,mid,u,v,val) ; 
	if(ret==-1) ret = WalkR(id<<1|1,mid+1,r,u,v,val) ; 
	return ret ; 
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    cin >> n ; 
    rep(i,1,n) cin >> a[i] ; 
    rep(i,1,n) pre[i] = pre[i-1] + a[i] ;
    long long ans = 0 ;
    rep(i,1,n) update(1,1,n,i,a[i]) ; 
    rep(i,1,n) {
    	int L = WalkL(1,1,n,1,i,a[i]) ; 
    	int R = WalkR(1,1,n,i,n,a[i]) ;
    	if(L==R || L == R - 1 || (L==-1 and R==-1)) continue ;
    	if(L==-1) L = i ; 
    	if(R==-1) R = i ;
    	if(L==R) continue ; 
    	int val = 0 ;
    	int len = R - L - 1 ; 
    	if(L==i) {
    		val = min(a[L]+1,a[R]) ; 
    	}
    	if(R==i) {
    		val = min(a[R]+1,a[L]) ; 
    	}
    	ans = max(ans , len * val - (pre[R-1] -pre[L]) ) ; 
    }

    cout << ans ;
    cerr << endl << "watborhi	hi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}