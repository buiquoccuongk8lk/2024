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

const int N = 1e6 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if(x>y){x=y;return true;}else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if(x<y){x=y;return true;}else return false;}

int n , t ; 
ii seg[N] ;
int pos[N] ; 
void init(void) {
	cin >> n >> t ; 
	FOR(i,1,n) {
		cin >> seg[i].fi >> seg[i].se ; 
	}
}
int st[4*N] ; 
void update(int id,int l,int r,int pos,int val) {
	if(pos < l or pos > r) return;
	if(l==r) {
		st[id]+= val ;
		return;
	}
	int mid = (l+r)>>1;
	update(id<<1,l,mid,pos,val);
	update(id<<1|1,mid+1,r,pos,val);
	st[id] = st[id<<1] + st[id<<1|1] ;
}
int get(int id,int l,int r,int u,int v) {
	if( l > v or r < u ) return 0;
	if( l >= u and r <= v) return st[id];
	int mid = (l+r)>>1;
	int t1 = get(id<<1,l,mid,u,v);
	int t2 = get(id<<1|1,mid+1,r,u,v);
	return t1 + t2 ; 
}
void process(void) {
	sort(seg+1,seg+1+n) ; 
	vi vec ; 
	FOR(i,1,n) {
		vec.pb(seg[i].se) ; 
	}
	vi v ;
	FOR(i,1,n) v.pb(seg[i].se) ; 
	sort(all(v)) ;
	FOR(i,0,sz(v)-1) {
		pos[v[i]] = i + 1 ; 
	}
	int ans = 0 ;
	int VAL = v.size() ;
	FOR(i,1,n) {
		int L = seg[i].fi ; 
		int R = seg[i].fi + t ; 
		int sum = upper_bound(all(vec) , R) - vec.begin() ; 
		cout << sum << endl ;
		int diff = get(1,1,VAL,pos[seg[i].se] + 1 , VAL ) ; 
		maximize(ans,sum - diff ) ;  
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