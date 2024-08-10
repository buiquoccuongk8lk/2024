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

const int N = 200 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if(x>y){x=y;return true;}else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if(x<y){x=y;return true;}else return false;}

int n , k ;
string s ; 

void init(void) {
	cin >> k ;
	cin >> s ; 
	n = s.size() ; 
	s = "*" + s ;
}

namespace sub1 {
	char a[N] ; 
	int ans = 0 ; 
	int pre[N] , prev[N] ;
	int st[4*N] ; 
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
	int get(int id,int l,int r,int u,int v) {
	 	if( l > v or r < u ) return -2e9;
	 	if( l >= u and r <= v) return st[id];
	 	int mid = (l+r)>>1;
	 	int t1 = get(id<<1,l,mid,u,v);
	 	int t2 = get(id<<1|1,mid+1,r,u,v);
	 	return max(t1,t2);
	} 
	void backtrack(int pos) {
		if(pos > n) {
			deque<int> dq ; 
			int sum = 0 ; 
			FOR(i,1,n) {
				sum += (a[i] == '(' ? 1 : -1) ; 
				if(sum < 0) return ; 
			}
			if(sum!=0) return ; 
			FOR(i,1,n) {
				if(a[i]==')') {
					if(!dq.empty()) {
						prev[i] = dq.back() ; 
						dq.pop_back() ; 
					}
				}else {
					dq.pb(i) ; 
				}
				pre[i] = pre[i-1] + (a[i] == '(' ? 1 : -1 ) ; 
				update(1,1,n,i,pre[i]) ; 
			}
			int deg = 0 ; 
			FOR(i,1,n) {
				if(prev[i]) {
					maximize(deg,get(1,1,n,prev[i],i) - pre[prev[i]-1]) ; 
				}
			}
			if(deg==k) ans++ ; 
			return ; 
		}else {
			if(s[pos]!='?') {
				a[pos] = s[pos] ; 
				backtrack(pos+1) ; 
			}else {
				FOR(j,0,1) {
					if(j==0) a[pos] = '(' ; 
					else a[pos] = ')' ; 
					backtrack(pos+1) ; 
				}
			}
		}
	}
	void solve(void) {
		backtrack(1) ; 
		cout << ans ;
	}
}
namespace sub2 {
	// gọi dp[i][sum][deg] là tổng số dãy ngoặc khi xét 1...i và có tổng sum và bậc deg
	deque<int> dq ; 
	int prev[N] , st[4*N] ;
	string dp[N][N][N] ;  
	string sum_str(string a, string b) {
	    while(a.size()<b.size()) a = "0" +a;
		while(b.size()<a.size()) b = "0" +b;
	    ll du=0;
	    ll sum ;
	    ll x,y;
	    FORD(i,(int)a.size()-1,0){
	    	x = a[i] - '0';
	    	y = b[i] - '0';
	    	sum = x + y + du;
	    	a[i] = sum%10 + '0';
	    	du = sum/10;
		}
	    if(du>0) a= "1"+a;
	    return a;
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
	 	st[id] = max(st[id<<1],st[id<<1|1]);
	}
	int get(int id,int l,int r,int u,int v) {
	 	if( l > v or r < u ) return -2e9;
	 	if( l >= u and r <= v) return st[id];
	 	int mid = (l+r)>>1;
	 	int t1 = get(id<<1,l,mid,u,v);
	 	int t2 = get(id<<1|1,mid+1,r,u,v);
	 	return max(t1,t2);
	} 
	string calc(int i,int sum,int deg) {
		if(sum < 0) return "0" ; 
		if(deg > k) return "0" ;
		if(i > n) {
			if(deg==k and sum==0) {
				dp[i][sum][deg] = "1" ; 
				return "1" ; 
			}else return dp[i][sum][deg] = "0" ; 
		}
		if(dp[i][sum][deg]!="-1") return dp[i][sum][deg] ; 
		dp[i][sum][deg] = "0" ;
		string &val = dp[i][sum][deg] ; 
		if(s[i] == '(') {
			val = sum_str(val , calc(i+1,sum+1,max(deg,sum+1)) ) ;
		}
		else if(s[i] == ')') {
			val = sum_str(val , calc(i+1,sum-1,deg) ) ; 
		}else {
			val = sum_str(val , calc(i+1,sum+1,max(deg,sum+1)) ) ;
			val = sum_str(val , calc(i+1,sum-1,deg) ) ; 
		}
		return val ;
	}
	void solve(void) {
		FOR(i,0,n) FOR(sum,0,n) FOR(deg,0,k) dp[i][sum][deg] = "-1" ;
		cout << calc(1,0,0) ;
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
    if(n <= 30) sub1::solve() ;
    else sub2::solve() ;   
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}