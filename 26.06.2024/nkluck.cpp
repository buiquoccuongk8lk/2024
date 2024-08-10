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

int n , k ; 
int a[N] ;

void init(void) {
	cin >> n >> k ; 
	FOR(i,1,n) cin >> a[i] ; 
}

namespace sub1 {
	void solve(void) {
	    long double Pall = n * (n + 1) / 2 ; 
	   	long double  ans = 0 ; 
	   	FOR(i,1,n) {
	   		vi vec ;  
	   		FOR(j,i,n) {
				vec.pb(a[j]) ; 
				int m = sz(vec) ; 
				sort(all(vec)) ; 
				if(vec[m/2]== k) {
					ans++ ; 
				}
	   		}
	   	}
	   	cout << setprecision(6) << fixed  << (long double)ans/Pall ; 
	}
}
namespace sub2 {

	int pos[N] ;

	int st[4*N] ; 

	void update(int id,int l,int r,int pos,int val) {
		if(pos < l or pos > r) return ; 
		if(l==r) {
			st[id]+=val ; 
			return ; 
		}
		int mid = (l+r)>> 1 ; 
		update(id<<1,l,mid,pos,val) ; 
		update(id<<1|1,mid+1,r,pos,val) ; 
		st[id] = st[id<<1] + st[id<<1|1] ; 
	}

	int get(int id,int l,int r,int u,int v) {
		if(l > v or r < u) return 0 ; 
		if(l >= u and r <= v) return st[id] ; 
		int mid = (l+r)>> 1 ; 
		return get(id<<1,l,mid,u,v) + get(id<<1|1,mid+1,r,u,v) ; 
	}

	void solve(void) {

		long double ans = 0 ; 
		long double Pall = n * (n + 1) / 2;  
		
		vi v ; 

		v.pb(k) ;

		FOR(i,1,n) v.pb(a[i]) ; 

		uni(v) ; 

		k = lower_bound(all(v),k) - v.begin() + 1 ; 

		FOR(i,1,n) {
			a[i] = lower_bound(all(v),a[i]) - v.begin() + 1 ; 
		}

		int VAL = sz(v) ;

		FOR(i,1,n) {
			
			FOR(j,i,n) {
				update(1,1,VAL,a[j],1) ; 
				int l = 1 ; 
				int r = VAL ; 
				int median_val = -1 ; 
				while(l <= r) {
					int mid = (l+r)>>1 ; 
					if(get(1,1,VAL,1,mid) >= (j-i+1)/2 + 1) {
						median_val = mid ; 
						r = mid - 1 ; 
					} else l = mid + 1 ; 
				}
				if(median_val==k) {
					ans++ ;  
				}
			}

			FOR(i,1,4*VAL) st[i] = 0 ; 

		}

		cout << setprecision(6) << fixed  << (long double)ans/Pall ; 
	}

}

namespace sub3 {

	ll pre[N] ; 
	ll st[4*N] ; 

	void update(int id,int l,int r,int pos,int val) {
		if(pos < l or pos > r) return ; 
		if(l==r) {
			st[id]+=val ; 
			return ; 
		}
		int mid = (l+r)>> 1 ; 
		update(id<<1,l,mid,pos,val) ; 
		update(id<<1|1,mid+1,r,pos,val) ; 
		st[id] = st[id<<1] + st[id<<1|1] ; 
	}

	int get(int id,int l,int r,int u,int v) {
		if(l > v or r < u) return 0 ; 
		if(l >= u and r <= v) return st[id] ; 
		int mid = (l+r)>> 1 ; 
		return get(id<<1,l,mid,u,v) + get(id<<1|1,mid+1,r,u,v) ; 
	}


	ll calc(int median_val) { 
		unordered_map<ll,int>mp ; 
		ll ret = 0 ;
		FOR(i,1,n) pre[i] = pre[i-1] + (a[i] >= median_val) ; 
		vi vec ; 
		vec.pb(0) ; 
		FOR(i,1,n) vec.pb(2 * pre[i] - i) ; 
		uni(vec) ; 
		FOR(i,0,sz(vec)-1) {
			mp[vec[i]] = i + 1 ; 
		}
		int VAL = sz(vec) ; 
		FOR(i,0,n) {
			ret+= get(1,1,VAL,1,mp[2*pre[i] - i]) ; 
			update(1,1,VAL,mp[2*pre[i] - i],1) ; 
		}
		FOR(i,1,4*VAL) st[i] = 0 ;
		return ret ; 
	}	

	void solve(void) {
		long double Pall = 1ll * n * (n + 1) / 2 ; 
		long double ans = calc(k) - calc(k+1) ; 	
		cout << setprecision(7) << fixed  << (long double)ans/Pall ; 	
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
    if(n <= 50) sub1::solve() ;
    else if(n <= 500) sub2::solve() ;
    else sub3::solve() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return (0 ^ 0) ; 
}