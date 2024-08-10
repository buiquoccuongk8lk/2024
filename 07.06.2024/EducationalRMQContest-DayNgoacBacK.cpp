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

const int N = 1e5 + 5;
const int LO = log2(N) + 1;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if(x>y){x=y;return true;}else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if(x<y){x=y;return true;}else return false;}

string s ; 
int n , K ;
int dp[N] , rmq[N][LO] , pre[N] , pos[N] , L[N] , R[N] ; 

void init(void) {
	cin >> s ; 
	n = sz(s) ;
	s = "*" + s ;
	cin >> K ; 
}
void init_RMQ(void) {
	for(int j(1) ; (1<<j) <= n ; j++) {
		for(int i(1) ; i + (1<<j) - 1 <= n ; i++) {
			rmq[i][j] = max(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]) ; 
		}
	}
}
int get_max(int l,int r) {
	int k = log2(r-l+1) ; 
	return max(rmq[l][k],rmq[r-(1<<k)+1][k]) ; 
}
int calc_bracket(int k) {
	memset(dp,0,sizeof(dp)) ; 
	int ret = 0 ;
	FOR(i,1,n) {
		if(pos[i] and get_max(pos[i],i) - pre[pos[i]-1] <= k) {
			dp[i] = dp[pos[i]-1] + 1 ; 
			ret+=dp[i] ; 
		}
	}
	return ret ; 
}
int calc_maxbracket(int k) {
	FOR(i,1,n) if(pos[i] and get_max(pos[i],i) - pre[pos[i] - 1] <= k) {
		L[i] = L[pos[i]-1] + i - pos[i] + 1 ; 
	}
	FORD(i,n,1) if(pos[i] and get_max(pos[i],i) - pre[pos[i]-1]  <= k) {
		R[pos[i]] = R[i+1] + i - pos[i] + 1 ; 
	}
	int ret = 0 ; 
	FOR(i,1,n) {
		if(pos[i] and get_max(pos[i],i) - pre[pos[i]-1] == k) {
			maximize(ret , L[i] + R[i+1]) ;
		}
	}
	return ret ; 
}
void process(void) {
	deque<int> dq ; 
	FOR(i,1,n) {
		pre[i] = pre[i-1] + ( s[i] == '(' ? 1 : -1 ) ; 
		if(s[i] == '(') {
			dq.push_back(i) ; 
		}else {
			if(!dq.empty()) {
				pos[i] = dq.back() ; 
				dq.pop_back() ; 
			}
		}
	}
	FOR(i,1,n) rmq[i][0] = pre[i] ; 
	init_RMQ() ; 
	cout << calc_bracket(K) - calc_bracket(K-1) << endl ;
	if(calc_bracket(K) - calc_bracket(K-1) == 0) {
		cout << -1 ;
		return ; 
	}
	cout << calc_maxbracket(K) << endl ; 
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