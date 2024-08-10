/* Code By Watbor */
#include <bits/stdc++.h>
using namespace std ; 
const int MAX = 1e6 + 5 ; 

int n , len ; 
string t[MAX] ;
string s ;

void init(void) {
	cin >> n ; 
}

namespace sub1 {
	unordered_map<string,int> ans , dd ; 
	int dp[5005][5005] , d[5005][5005] ;  
	int calc(int l,int r) {
		if(l > r) return 0 ; 
		if(l + 1 == r) {
			if(s[l]=='(' && s[r]==')') return 0 ;
			else if(s[l]==')' && s[r]=='(') return 2 ; 
			else return 1 ; 
		} 
		if(d[l][r]) return dp[l][r] ; 
		d[l][r] = 1 ; 
		int &val = dp[l][r] ; 
		if(s[l]=='(' && s[r]==')') val = min(val, calc(l+1,r-1) ) ; 
		else if(s[l] == ')' and s[r]=='(') val = min(val, calc(l+1,r-1) + 2 ) ;
		else val = min(val , calc(l+1,r-1) + 1) ;  
		for(int k = l ; k <= r - 1 ; k++) {
			val = min(val , calc(l,k) + calc(k+1,r) ) ; 
		}
		return val ; 
	}
	void solve(void) {
		for(int q = 1 ; q <= n ; q++) {
			string x ; cin >> x ; 
			if(x[0]>='0' && x[0]<='9') {
				int sum = 0 ; 
				for(auto c : x) sum = sum * 10 + (c - '0') ; 
				t[q] = t[sum-1] ;
			} else {
				t[q] = t[q-1] + x ; 
			}
			if(dd[t[q]]) cout << ans[t[q]] << '\n' ; 
			else {
				s = "" ;
				s = t[q] ; len = s.size() ; s = "*" + s ;
				for(int i = 1 ; i <= len ; i++) for(int j = 1 ; j <= len ; j++) d[i][j] = 0 , dp[i][j] = 1e9 ; 
				ans[t[q]] = calc(1,len) ;
				cout << ans[t[q]] << '\n' ; 
				for(int i = 1 ; i <= len ; i++) for(int j = 1 ; j <= len ; j++) d[i][j] = 0 , dp[i][j] = 1e9 ; 	
			}
			dd[t[q]] = 1 ; 
		}
	}
}

namespace sub2 {

	struct DL {
		int sum , mini  ;
	} CUR[MAX] ; 

	void add(int i,string x) {
		CUR[i] = CUR[i-1] ; 
		for(auto c : x) {
			if(c=='(') CUR[i].sum++ ; 
			else {
				CUR[i].sum-- ; 
				CUR[i].mini = min(CUR[i].mini,CUR[i].sum)  ;
			}
		}
	}

	void undo(int i,string x) {
		int sum = 0 ;
		for(auto c : x) sum = sum * 10 + (c - '0') ;
		CUR[i] = CUR[sum - 1] ; 
	}

	int calc(int i) {
		int sum = CUR[i].sum ; int mini = CUR[i].mini ; 
		int r1 = 0 ; 
		if(mini < 0) r1 = (abs(mini) + 1) / 2 ; 
		int r2 = (sum + 2 * r1 + 1) / 2 ; 
		return r1 + r2 ; 
	}

	void solve(void) {
		for(int i = 1 ; i <= n ; i++) {
			string x ; cin >> x ; 
			if(x[0] >= '0' && x[0] <= '9') undo(i,x) ;
			else add(i,x) ;
			cout << calc(i) << '\n' ; 
		}
	}
}

signed main(void) {
    #define mitsuri ""
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if( fopen(mitsuri".inp","r") ) {
        freopen(mitsuri".inp","r",stdin) ; freopen(mitsuri".out","w",stdout);
    }
    init() ; 
    if(n <= 500) sub1::solve() ; 
    else sub2::solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms " << endl;
    return 0 ;
}