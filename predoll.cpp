/*[продолжатьипродолжать]*/
/* ---------------------- *
 *     Code by watbor     *
 *                        * 
--------------------------*/

#define tct template<class MITSURII,class CHANN>

#include <bits/stdc++.h>
using namespace std ; 

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

const int N = 1e5 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const int mod = 1e9 + 7 ;
const long long inf = 1e18 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n ;
int a[N] ;

void init(void) {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i] ; 
}

namespace sub1 {
	int dp[N] ;
	int b[N] ;
	bool check() {return n <= 200 ;}
	void solve(void) {
		FOR(t,1,n) {
			FOR(i,1,t) b[i] = a[i] ; 
			FOR(i,1,n) dp[i] = 0 ;
			sort(b+1,b+1+t) ; 
			FOR(i,1,t) {
				dp[i] = 1 ;
				FOR(j,1,i-1) {
					if(b[i] - b[j] >= 2) {
						dp[i] = max(dp[i],dp[j] + 1) ; 
					}
				}
			}
			cout << *max_element(dp+1,dp+1+t) << ' '; 
		}
	}
}

namespace sub2 {
	bool check() { 
		FOR(i,1,n) if(a[i]%2==0)return 0 ;
		return 1 ; 
	}
	void solve(void) {
		map<int,int>mp ;
		FOR(i,1,n) {
			mp[a[i]]++ ;
			cout << mp.size() << ' ' ;
		}
	}
}

namespace sub3 {
	const int MAXVAL = 5e5 + 5 ;
	int CNTBLOCK[MAXVAL/4 + 5][5] ; 
	int sum = 0 ;

	bool check() {
		FOR(i,1,n) if(a[i] % 4 == 0) return 0 ;
		return 1 ; 
	}

	void ADD(int x) {
		int block_id = x / 4 + 1 ; 
		int id_in_block = x % 4 ; 
				
		if(CNTBLOCK[block_id][1] && CNTBLOCK[block_id][3]) {
		} else {
			if(CNTBLOCK[block_id][2]) sum-- ; 
			else if(CNTBLOCK[block_id][1] || CNTBLOCK[block_id][3]) sum-- ;
			CNTBLOCK[block_id][id_in_block] = 1 ; 
			if(CNTBLOCK[block_id][1] && CNTBLOCK[block_id][3]) {
				sum+= 2 ; 
			} else if(CNTBLOCK[block_id][2]) {
				sum++ ; 
			} else if(CNTBLOCK[block_id][1] || CNTBLOCK[block_id][3]) {
				sum++ ; 
			}
		}
	}	

	void solve(void) {		
		FOR(i,1,n) {
			ADD(a[i]) ; 
			cout << sum << ' ' ; 
		}
	}
}

namespace sub4 {
	const int MAXVAL = 5e5 + 5 ;
	int st[4*MAXVAL][3][3] ; 

	void MERGE(int id) {
		int L = (id * 2) ; 
		int R = (id * 2) + 1 ; 

		st[id][0][0] = max({st[L][0][1] + st[R][0][0] , 
							st[L][0][0] + st[R][1][0] , 
							st[L][0][0] + st[R][0][0] }) ; 

		st[id][1][0] = max({st[L][1][0] + st[R][0][0] , 
							st[L][1][1] + st[R][0][0] , 
							st[L][1][0] + st[R][1][0] }) ; 

		st[id][0][1] = max({st[L][0][1] + st[R][0][1] ,
							st[L][0][0] + st[R][1][1] ,
							st[L][0][0] + st[R][0][1] }) ; 

		st[id][1][1] = max({st[L][1][0] + st[R][0][1] , 
							st[L][1][0] + st[R][1][1] ,
							st[L][1][1] + st[R][0][1] }) ; 
	}

	void update(int id,int l,int r,int pos) {
		if(pos < l or pos > r) return ; 
		if(l==r) {
			st[id][1][1] = max(st[id][1][1],1) ;
			return ; 
		}
		int mid = (l+r)/2 ; 
		update(id<<1,l,mid,pos) ; 
		update(id<<1|1,mid+1,r,pos) ; 
		MERGE(id) ;
	}

	void solve(void) {
		int max_val = *max_element(a+1,a+1+n) ;
		FOR(i,1,n) {
			update(1,1,max_val,a[i]) ;
			cout << max({st[1][0][0],st[1][0][1],st[1][1][0],st[1][1][1]}) << ' ' ;  
		}	
	}

}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    init() ;
    if(sub1::check()) sub1::solve() ;
    else if(sub2::check()) sub2::solve() ;
   	else if(sub3::check()) sub3::solve() ;
   	else sub4::solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}