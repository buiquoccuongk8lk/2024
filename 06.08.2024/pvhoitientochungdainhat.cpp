#include <bits/stdc++.h>
#define tct template<class MITSURII,class CHANN>
#define ii pair<int,int>
#define fi first
#define se second
using namespace std ; 

const int N = 5e3 + 5 ;
const int base = 311 ; 
const int mod1 = 1e9 + 7 , mod2 = 1e9 + 3 ; 

int n , k ; 
string s[N] ;

namespace sub1 {
	bool check() {
		for(int i = 1 ; i <= n ; i++) {
			for(int j(2) ; j <= (int)s[i].size() - 1 ; j++) if(s[i][j]!=s[i][j-1]) return 0 ; 
		}
		return 1 ; 
	} 
	vector<int> ch[27] ; 
	int suf[N] ;
	void solve() {
		for(int i(1) ; i <= n ; i++) {
			ch[s[i][1] - 'a'].push_back(i) ; 
		}	
		long long ans = 0 ;

		for(int t = 0 ; t <= 26 ; t++) {
			long long sum = 0 ; 			
			sort(ch[t].begin(),ch[t].end(),[](int u,int v) {
				return s[u].size() > s[v].size() ; 
			}) ; 
			int m = min(k,(int)ch[t].size()) - 1 ; 
			for(int i(m) ; i >= 0 ; i--) suf[i] = suf[i+1] + s[ch[t][i]].size() - 1 ; 
			for(int i(0) ; i <= m ; i++) {
				sum+= suf[i+1] ; 
			}
			ans = max(ans,sum) ; 
			for(int i(0) ; i <= m ; i++) suf[i] = 0 ; 
		}

		cout << ans ; 
	}
}

namespace sub2 {
	bool check() {
		return (k == n) ;
	}
	int trie[(int)5e6][27] , End[(int)5e6+5] ; 
	int node = 1 ;
	void add(string s) {
		int root = 1 ; 
		int d = 0 ;
		for(auto c : s) {
			if(d == 0) {
				d++ ; 
				continue ; 
			}
			int j = c - 'a' ; 
			if(trie[root][j]==-1) trie[root][j] = ++node ;  
			root = trie[root][j] ; 
			End[root]++ ; 
		}
	}
	long long ans = 0 ; 
	void dfs(int root) {
		ans+= 1ll * End[root] * (End[root] - 1) / 2 ;
		for(int j(0) ; j <= 25 ; j++) {
			if(trie[root][j]!=-1) dfs(trie[root][j]) ; 
		}
	}
	void solve() {	
		memset(trie,-1,sizeof trie) ; 
		for(int i(1) ; i <= n ; i++) add(s[i]) ; 
		dfs(1) ; 
		cout << ans ; 
	}
}

namespace sub3 {

	void solve() {

		
	}

}

signed main() {
    #define TASK "lcp"
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    cin >> n >> k ; 
    for(int i(1) ; i <= n ; i++) cin >> s[i] , s[i] = "*" + s[i] ;
    /*if(sub1::check()) sub1::solve() ; 
	else if(sub2::check()) sub2::solve() ;
	else if(k == 3)*/ sub3::solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}