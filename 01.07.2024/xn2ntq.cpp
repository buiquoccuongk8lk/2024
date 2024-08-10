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

int n ; 
int a[N] ; 

void init(void) {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i] ; 
}
bool mark[N] ; 
int prime[2*N] , cnt[N] ;

void sieve(void) {

	FOR(i,2,2*N) prime[i] = 1 ; 

	FOR(i,2,sqrt(2*N)) {
		for(int j = i * i ; j <= 2*N ; j+=i) {
			prime[j] = 0 ;
		}
	}

}

ll dp[(1<<20)] ; 
void process1(void) {

	sieve() ;

	FOR(mask,0,(1<<n)-1) {
		if(__builtin_popcountll(mask) % 2==1) continue ; 
		vi ones ; 
		FOR(j,0,n-1) if( (mask >> j) & 1 ) ones.pb(j) ; 

		for(auto u : ones) for(auto v : ones) {
			if(u!=v) {
				int prev_mask = mask ^ ( 1 << u ) ; 
				prev_mask ^= (1 << v) ; 
				if(prime[a[u+1] + a[v+1]]) {
					maximize(dp[mask] , dp[prev_mask] + 1 ) ; 
				}
			}
		}
	}

	int ans = 0 ;
	int bestMask = 0 ; 
	FOR(mask,0,(1<<n)-1) {
		if( maximize(ans,dp[mask]) ) {
			bestMask = mask ; 
		} 
	}
	cout << ans << endl ;

	while(1) {
		vi ones ; 
		FOR(j,0,n-1) if( (bestMask >> j ) & 1 ) {
			ones.pb(j) ;
		}
		if(ones.empty()) {
			return ; 
		}
		int prev_mask = -1 ;
		ii pairs ;
		for(auto u : ones) for(auto v : ones) {
			if(u!=v) {
				if(prime[a[u+1]+a[v+1]]) {
					int pre_mask = bestMask ^ (1 << u) ;
					pre_mask = pre_mask ^ (1 << v) ; 
					if(dp[pre_mask] + 1 == dp[bestMask]) {
						prev_mask = pre_mask ; 
						pairs.fi = u + 1 ; 
						pairs.se = v + 1 ; 
					}
				}
			}
		}
		if(prev_mask == -1) return ; 
		bestMask = prev_mask ; 
		cout << pairs.fi << ' ' << pairs.se << endl ;
	}

}

struct DL {
	int val ; 
	int pairs ; 
} pr[N] ; 
vi vec_val[N] ; 

void process2(void) {

	sieve() ; 

	vector<int> snt ; 
	FOR(i,1,N) if(prime[i]==1) snt.pb(i) ; 
	//for(auto x : snt) cout << x << ' ' ; 
	int sz = 0 ;
	//cout << snt.size() ;

    for(auto num : snt) {
    	
    	FOR(i,1,n) cnt[a[i]] = 0 ; 
    	
    	FOR(i,1,n) cnt[a[i]]++ ; 

    	int dem = 0 ; 
	    FOR(i,1,n) {
	    	if(num >= a[i]) {
	    		if(a[i] == num-a[i] and cnt[a[i]] >= 2) {
		    		dem++ ; 
		    		cnt[a[i]]-- ;
		    		cnt[num - a[i]]-- ;
		    	} 
		    	if(a[i] != num - a[i] and cnt[a[i]] >= 1 and cnt[num - a[i]] >= 1) {
		    		dem++  ;
		    		cnt[a[i]] -- ;
		    		cnt[num-a[i]]-- ; 
		    	}
	    	}
	    }
	 

    	if(dem) {
    		sz++ ; 
    		pr[sz].val = num ;
    		pr[sz].pairs = dem ; 
    	}
    }

    sort(pr + 1 , pr + 1 + sz ,[](DL u,DL v) {
    	return u.pairs < v.pairs; 
    }) ; 

    FOR(i,1,n) vec_val[a[i]].push_back(i) ; 

    int ans = 0 ;

    vii pairs ;  

    FOR(index,1,sz) {
    	int num = pr[index].val ; 	
    	int dem = 0 ;
    	FOR(i,1,n) {
	    	if(num >= a[i]) {
	    		if(a[i] == num-a[i] and sz(vec_val[a[i]]) >= 2) {
		    		dem++ ; 
		    		int id1 = vec_val[a[i]].back() ; 
		    		vec_val[a[i]].pop_back() ; 
		    		int id2 = vec_val[a[i]].back() ; 
		    		vec_val[a[i]].pop_back() ; 
		    		pairs.pb({id1 , id2}) ; 
		    	} 
		    	if(a[i] != num - a[i] and sz(vec_val[a[i]]) and sz(vec_val[num-a[i]])) {
		    		dem++  ;
		    		pairs.push_back({ vec_val[a[i]].back() , vec_val[num-a[i]].back() }) ; 
		    		vec_val[a[i]].pop_back() ; vec_val[num-a[i]].pop_back() ; 
		    	}
	    	}
	    }
	    ans+=dem ; 
    }

    cout << ans << endl ;

    for(auto x : pairs) {
    	cout << x.fi << ' ' << x.se << endl ;
    }

}

int r[N] ;
ii val[N] ; 
int vt[N] ; 

void process3(void) {

	sieve() ; 		
	

	FOR(i,1,n) {
		val[i].fi = a[i] ; 
		val[i].se = i ; 
	}

	FOR(i,1,n) vt[a[i]] = i ;

	int v = n ; 
	int ans = 0 ; 

	FORD(i,n-1,1) {
		if(prime[i+v]) {
			ans+= (v - i + 1) / 2 ;
			FOR(j,0,(v-i+1)/2 - 1) {
				r[i + j] = v - j ; 
			}
			v = i - 1 ; 
		}
	}

	cout << ans << endl ;
	FOR(i,1,n) if(r[i]) {
		cout << vt[i] << ' ' << vt[r[i]] << endl ;
	}

}
dp[i][j] = k (k >= 0)
Với các hội trường từ i -> n phục vụ được tổng thời gian là j và thằng hội trường  chắc chắc hội trường i là hội trường cuối cùng mình lấy
trước đó là xài là k

memset(dp , -1 , sizeof(dp));
i: n -> 1 (i là thằng có thứ tự điển nhỏ nhất)
	dp[i][a[i]] = 0;
	j: a[i] + 1 -> T
		dp[i][j]

		k: i + 1 -> n
			if(dp[k][j - a[i]] != -1)
			{
				dp[i][j] = k;
				break;
			}

void truyvet(int i , int j)
{
	if(i != 0)
	{
		cout << i << " ";
		truyvet(dp[i][j] , j - a[i]);		
	}
}

i: T -> 0 // tối ưu thời gina
	j: 1 -> n // = thời gian tối ưu từ điển
		if(dp[j][i] != -1)
		{
			truyvet(j , i);
			cout << i << " ";
			break;
		}


signed main(void) {
    #define TASK "XN2NTQ"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    /*if(n <= 20) process1() ; 
    else*/ process2() ;
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return (0 ^ 0) ; 
}