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

const int N = 3e5 + 5 ;
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

int n , k , r , t ;
int a[N] , flag[N]  ;

void init(void) {
	cin >> n >> k >> r >> t ; 
	FOR(i,1,k) {
		cin >> a[i] ; 
		flag[a[i]]++ ; 
	}
}

namespace sub1 {
	int pre[N] ;
	int dd[N] ; 

	void solve(void) {
		int ans = 2e9 ; 
		vi res ;

		FOR(mask,0,(1<<n)-1) {
			vi ones ;
			FOR(j,0,n-1) pre[j] = 0 ; 
			FOR(j,0,n-1) {
				pre[j] = pre[j-1] + ( flag[j+1] || ( (mask >> j) & 1 ) ) ;   
				if( (mask >> j ) & 1 ) ones.pb(j+1) ;
			}
			bool ok = true ; 		
			FOR(j,0,n-1-r+1) {
				if( (pre[j+r-1] - pre[j-1]) < t ) {
					ok = false ; 
					break ; 
				}
			}
			if(ok) {
				if ( minimize(ans , __builtin_popcountll(mask) ) ) {
					res.clear() ; 
					for(auto x : ones) {
						if(!flag[x]) {
							res.pb(x) ; 
						}
					}
				}
			}
		}
		cout << ans << endl ; 
		for(auto x : res) cout << x << ' ' ;

	}

}

namespace sub2 {

	void solve(void) {

		cout << n / t + (n%t!=0) << endl ; 
		FOR(i,1,n) {
			if(i%t==0) cout << i << ' ' ;
		}
		if(n%t!=0) cout << n ; 
	}	

}

namespace sub3 {

	void solve(void) {
		cout << (n - k) << endl ; 
		FOR(i,1,n) if(!flag[i]) cout << i << ' ' ; 
	}

}

namespace sub4 {
	struct seg {
			int n ; 
			vector<int> lazy , st ; 
		private:
			/*void down(int id,int l,int r) {
				if(lazy[id]==-1) return ;
	
				int mid = (l+r)>>1 ; 
	
				lazy[id<<1]+= lazy[id] ; 
				lazy[id<<1|1]+= lazy[id] ; 
	
				st[id<<1] = (mid-l+1) * lazy[id] ;
				st[id<<1|1] = (r-mid) * lazy[id] ; 
	
				lazy[id] = -1 ; 
			}*/
			void up(int id,int l,int r,int pos,int val) {
				if(pos < l or pos > r) return ;
				if(l==r){
					st[id]+=val ;
					return ;
				}
				int mid = (l+r)>>1 ; 
				up(id<<1,l,mid,pos,val) ; up(id<<1|1,mid+1,r,pos,val) ; 
				st[id] = st[id<<1] + st[id<<1|1] ; 
			}
			ll get(int id,int l,int r,int u,int v) {
				if(l>v or r<u) return 0 ; 
				if(l >= u and r <= v) return st[id] ; 
				//down(id,l,r) ; 
				int mid = (l+r)>>1 ; 
				return get(id<<1,l,mid,u,v) + get(id<<1|1,mid+1,r,u,v) ; 
			}
		public:
			seg(int n) : n(n) { st.assign(4*n+1,0) ; }
			void up(int pos,int val) { up(1,1,n,pos,val) ; }
			ll get(int l,int r) {return get(1,1,n,l,r) ; }  
	} ; 

	void solve(void) {
		seg st(n)  ; 
			
		FOR(i,1,n) if(flag[i]) st.up(i,1) ; 

		vi ans ; 

		FOR(i,1,n) {
			if(i >= r) {
				if(st.get(i-r+1,i) < t) {
					int j = i ; 
					int need = t - st.get(i-r+1,i) ;
					while(j >= 1 and need >= 1) {
						if(flag[j]==0) {
							need-- ; 
							flag[j] = 2 ; 
							ans.pb(j) ; 
							st.up(j,1) ; 
						}
						j-- ;
					}
				}
			}
		}
		
		sort(all(ans)) ;
		cout << ans.size() << endl ;
		for(auto x : ans) cout << x << ' ' ; 
	}

}

signed main(void) {
    #define TASK "camera"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    if( n <= 28 ) sub1::solve() ; 
    else sub4::solve() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}