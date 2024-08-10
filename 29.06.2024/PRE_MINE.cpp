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

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l,int r) {
    return l + rd()%(r-l+1);
}

struct bg {
	int x , val , len ; 
	void input() {
		cin >> x >> val >> len ; 
	}
	bool operator <(const bg &y) const {
		return x < y.x ; 
	}
} a[N] ;
int n ;
ll pre_len[N] , pre_val[N] ; 

void init(void) {
	cin >> n ;
	FOR(i,1,n) a[i].input() ;

	/*n = Rand(1,10) ; 
	cout << n << endl ; 
	FOR(i,1,n) {
		a[i].x = Rand(-20,10) ;
		a[i].val = Rand(1,10) ; 
		a[i].len = Rand(1,2) ; 
		cout << a[i].x << ' ' << a[i].val << ' ' << a[i].len << endl ;
	}*/

}

ll st[4*N] ;

void update(int id,int l,int r,int pos,ll val) {
	if(pos < l or pos > r) return ; 
	if(l==r) {
		st[id]+=val ;
		return ; 
	}
	int mid = (l+r)>>1 ; 
	update(id<<1,l,mid,pos,val) ; 
	update(id<<1|1,mid+1,r,pos,val) ;
	st[id] = min(st[id<<1],st[id<<1|1]) ; 
}

int Walk(int id,int l,int r,int u,int v,ll val) {
	if(l > v or r < u or st[id] > val) return n + 1; 
	if(l==r) return l ;
	int mid = (l+r)>>1 ; 
	int ret = Walk(id<<1,l,mid,u,v,val) ; 
	if(ret==n + 1) ret = Walk(id<<1|1,mid+1,r,u,v,val) ;  	
	return ret ;
}

void process1(void) {
	ll ans = 0 ; 
	sort(a+1,a+1+n) ;
	FOR(i,1,n) {
		pre_val[i] = pre_val[i-1] + a[i].val ;
		pre_len[i] = pre_len[i-1] + a[i].len ; 
	}
	FOR(i,1,n) FOR(j,i,n) {
		if(pre_len[j] - pre_len[i-1] >= a[j].x - a[i].x) {
			maximize(ans , pre_val[j] - pre_val[i-1]) ; 
		}
	}
	cout << ans << endl ;
}

void process2(void) {

	ll ans = 0 ;

	sort(a+1,a+1+n) ;

	FOR(i,1,n) maximize(ans , a[i].val) ;

	FOR(i,1,n) {
		pre_val[i] = pre_val[i-1] + a[i].val ; 
		pre_len[i] = pre_len[i-1] + a[i].len ; 
	}


	FOR(i,1,n) {
		if(pre_len[i] - pre_len[0] >= a[i].x - a[1].x) maximize(ans , pre_val[i] - pre_val[0]) ; 
		int pos_prev = Walk(1,1,n,1,i,pre_len[i] - a[i].x) ; 
		update(1,1,n,i,pre_len[i-1] - a[i].x) ; 
		maximize(ans , pre_val[i] - pre_val[pos_prev - 1]) ; 
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
    process2() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return (0 ^ 0) ; 
}