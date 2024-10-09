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

const int N = 4e6 + 100000 ;
const int LO = 19 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n , numMin , numMax ; 
int a[N] ; 

void init(void) {
	cin >> n >> numMin >> numMax ; 
	FOR(i,1,n) cin  >> a[i] ;
}
/*namespace sub1 {
	int L[N] , R[N] ;
	ll pre[N] ;
 
	void solve(void) {
		deque<int> dq ; 
		FOR(i,1,n) {
			while(!dq.empty() and a[dq.front()] >= a[i]) dq.pop_front() ; 
			L[i] = (dq.empty() ? 1 : dq.front() + 1) ; 
			dq.push_front(i) ; 
		}
		while(!dq.empty()) dq.pop_front() ;
		FORD(i,n,1) {
			while(!dq.empty() and a[dq.front()] >= a[i]) dq.pop_front() ; 
			R[i] = (dq.empty() ? n : dq.front() - 1) ; 
			dq.push_front(i) ;
		}	
		ll ans = -inf ; 
		FOR(i,1,n) pre[i] = pre[i-1] + a[i] ; 
		int posL = -1 , posR = -1 ;
		FOR(i,1,n) {
			if(a[i] >= numMin and a[i] <= numMax) {
				FOR(u,L[i],i) {
					FOR(v,i,R[i]) {
						if( maximize(ans,pre[v] - pre[u-1]) ) {
							posL = u ;
							posR = v ;
						}
					}
				}
			}
		}
		cout << ans << endl ;
		cout << posL << ' ' << posR ;
	}
 
}

namespace sub2 {
	int L[(int)3e5+5],R[(int)3e5+5] ;
	ll pre[(int)3e5+5] ; 
	struct Node {
		ll maxi ; 
		ll mini ; 
	} ;
	Node st[4*(int)3e5 + 2] ;
	unordered_map<int,vector<int>>mp ;

	Node merge(Node a,Node b) {
		Node ans ; 
		ans.maxi = max(a.maxi,b.maxi) ; 
		ans.mini = min(a.mini,b.mini) ;
		return ans ;
	}

	void update(int id,int l,int r,int pos,ll val) {
		if(pos < l or pos > r) return ;
		if(l==r) {
			st[id].maxi = st[id].mini = val ; 
			return ; 
		}
		int mid = (l+r)>>1 ;
		update(id<<1,l,mid,pos,val) ; 
		update(id<<1|1,mid+1,r,pos,val) ; 
		st[id] = merge(st[id<<1],st[id<<1|1]) ;
	}

	Node get(int id,int l,int r,int u,int v) {
		if(l > v or r < u) return {-inf,inf} ; 
		if(l >= u and r <= v) return {st[id].maxi , st[id].mini} ;
		int mid = (l+r)>>1 ; 
		return merge( get(id<<1,l,mid,u,v) , get(id<<1|1,mid+1,r,u,v) ) ; 
	}


	void solve(void) {
		deque<int> dq ; 
		FOR(i,1,n) {
			while(!dq.empty() and a[dq.front()] >= a[i]) dq.pop_front() ; 
			L[i] = (dq.empty() ? 1 : dq.front() + 1) ; 
			dq.push_front(i) ; 
		}
		while(!dq.empty()) dq.pop_front() ;
		FORD(i,n,1) {
			while(!dq.empty() and a[dq.front()] >= a[i]) dq.pop_front() ; 
			R[i] = (dq.empty() ? n : dq.front() - 1) ; 
			dq.push_front(i) ;
		}	
		FOR(i,1,n) pre[i] = pre[i-1] + a[i] ;	
		FOR(i,0,n) mp[pre[i]].pb(i) ;
		ll ans = -inf ; 
		FOR(i,1,n) update(1,0,n,i,pre[i]) ;	
		ll bestL = -1 ;
		ll bestR = -1 ;
		ll bestI = -1 ;
		FOR(i,1,n) {
			if(a[i] >= numMin and a[i] <= numMax) {
				ll maxiR = get(1,0,n,i,R[i]).maxi - pre[i-1] ; 
				ll maxiL = pre[i-1] - get(1,0,n,L[i]-1,i-1).mini ; 
				if( maximize(ans , maxiR + maxiL ) ) {
					bestL = get(1,0,n,L[i]-1,i-1).mini ; 
					bestR = get(1,0,n,i,R[i]).maxi ;
					bestI = i ; 
				} 
			}
		}
		cout << ans << endl ;
		cout << bestL << " " << bestR << endl ;
		int posL = lower_bound(all(mp[bestL]) , L[bestI] - 1) - mp[bestL].begin() ;
		cout << mp[bestL][posL] + 1 << ' ' ;
		int posR = upper_bound(all(mp[bestR]) , R[bestI]) - mp[bestR].begin() - 1 ;
		cout << mp[bestR][posR] ;
	}

}*/


/*namespace sub3 {

	int L[N] , R[N] ; 
	ll min_left[N] , max_right[N] , pre[N] ; 
	unordered_map<ll,vector<int>>mp ;
	int dq[N] ; 

	void solve(void) {

		FOR(i,1,n) pre[i] = pre[i-1] + a[i] ; 
		pre[n+1] = -1e18 ;
		pre[0] = 0 ;

		FOR(i,1,n) {
			min_left[i] = pre[i-1] ; 
			max_right[i] = pre[i] ; 
		}

		int sz = 0 ; 

		FOR(i,1,n) {
			while(sz and a[dq[sz]] >= a[i]) {
				minimize(min_left[i] , min_left[dq[sz]]) ; 
				sz-- ; 
			}
			L[i] = (sz==0 ? 1 : dq[sz] + 1) ; 
			sz++ ; 
			dq[sz] = i ; 
		}

		while(sz)sz--;

		FORD(i,n,1) {
			while(sz and a[dq[sz]] >= a[i]) {
				maximize(max_right[i] , max_right[dq[sz]]) ;
				sz-- ; 
			}
			R[i] = (sz==0 ? n : dq[sz] - 1) ; 
			sz++ ; 
			dq[sz] = i ;
		}

		ll ans = -inf ;
		ll bestL = -1 ;
		ll bestR = -1 ;
		ll bestI = -1 ;

		FOR(i,1,n) {
			if(a[i] >= numMin and a[i] <= numMax) {
				if(maximize(ans,a[i])) {
					bestL = a[i] ; 
					bestR = a[i] ;
				}
			}
		}
		FOR(i,1,n) {
			if(a[i] >= numMin and a[i] <= numMax) {
				ll maxLeft = pre[i-1] - min_left[i] ; 
				ll maxRight = max_right[i] - pre[i-1] ;
				if ( maximize(ans,maxLeft+maxRight) ) {
					bestL = min_left[i] ; 
					bestR = max_right[i] ; 
					bestI = i ;
				}		
			}
		}
		FOR(i,0,n) mp[pre[i]].pb(i) ;
		cout << ans << endl ;
		int posL = lower_bound(all(mp[bestL]) , L[bestI] - 1) - mp[bestL].begin() ;
		cout << mp[bestL][posL] + 1 << ' ' ;
		int posR = upper_bound(all(mp[bestR]) , R[bestI]) - mp[bestR].begin() - 1 ;
		cout << mp[bestR][posR] ; 
 	}

}*/

namespace sub4 {

	ll dp[N][4] ; 
	int trace[N][4] ;
	int res[N] ;

	void solve(void) {

		FOR(i,0,n) FOR(j,0,3) dp[i][j] = -inf ;
		dp[0][0] = 0 ;
		FOR(i,0,n-1) {
			if(dp[i][0] > -inf) {
				if( maximize (dp[i+1][0] , dp[i][0] ) ) trace[i+1][0] = 0 ;  
				if(a[i+1] >= numMin) {
					if(maximize( dp[i+1][a[i+1] <= numMax ? 2 : 1] , dp[i][0] + a[i+1] ) ) { 
						trace[i+1][a[i+1] <= numMax ? 2 : 1] = 0 ; 
					} 
				}
			}
			if(dp[i][1] > -inf) {
				if(a[i+1] >= numMin) {
					if ( maximize( dp[i+1][a[i+1] <= numMax ? 2 : 1] , dp[i][1] + a[i+1] ) ) {
						trace[i+1][a[i+1] <= numMax ? 2 : 1] = 1 ; 
					}
				}
			}
			if(dp[i][2] > -inf) {
				if(a[i+1] >= numMin) {
					if( maximize( dp[i+1][2] , dp[i][2] + a[i+1] ) ) {
						trace[i+1][2] = 2 ; 
					}
				}
				if( maximize( dp[i+1][3] , dp[i][2] ) ) trace[i+1][3] = 2 ; 
			}
			if(dp[i][3] > -inf) {
				if(maximize(dp[i+1][3] , dp[i][3])) {
					trace[i+1][3] = 3 ; 
				}
			}
		}

		cout << max(dp[n][2],dp[n][3]) << endl ;
		int best ;
		int j = best = max(dp[n][2],dp[n][3]) == dp[n][2] ? 2 : 3 ;

		FORD(i,n,1) {
			if(j <= 1) res[i] = j ;
			else res[i] = j - 1 ; 
			j = trace[i][j] ; 
		}
		int cnt = 0 ; 
		FOR(i,1,n) cnt+= (res[i]==1) ; 
		if(cnt<=1) {
			FOR(i,1,n) if(res[i]==1) {
				cout << i <<  ' ' << i ; 
				return ;
			}
		}else {
			FOR(i,1,n) if(res[i]==1) {
				cout << i << ' ';
				break ;
			}
			FORD(i,n,1) if(res[i]==1) {
				cout << i ;
				break ;
			}
		}

	}

}
signed main(void) {
    #define TASK "minimum"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    /*if(n <= 500) sub1::solve() ;
    else if( n <= 3e5 ) sub2::solve() ; 
    else*/// sub3::solve() ;
    sub4::solve() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}