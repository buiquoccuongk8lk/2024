/* 29 . 03 . 2008 */
#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> pii ;
typedef pair<ll,int> pli ;
typedef pair<int,ll> pil ;
typedef pair<ll,ll> pll ;
#define FOR(i,a,b) for(int i(a) ; i <= (int)b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)b ; i--)
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define all(a) a.begin() , a.end()
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define BIT(mask,i) ((mask>>i)&1)
#define builtin_popcount builtin_popcountll
#define MASK(a) (1ll << a)

template <class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template <class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int N = 55 ;
const int mod = 1e9 + 7 ;
const int base = 331 ; 

int n, m ;
string s ;

void init() {
    cin >> n ;
    cin >> s ;
    m = s.size() ; s = "*" + s ;
}

namespace subtask_1 {
    char a[N] ;
    unordered_map<string, int> cnt ;

    void Try(int i) {
        if(i > m) {
            string t = "" ;
            FOR(i, 1, m) t.push_back(a[i]) ;
            cnt[t]++ ;
            return ;
        }
        if(s[i] == '*') {
            for(char j = '0'; j <= '1'; j++) {
                a[i] = j ;
                Try(i + 1) ;
            }
        } else {
            a[i] = s[i] ;
            Try(i + 1) ;
        }
    }

    void solve() {
        Try(1) ;
        int ans = 0 ;
        FOR(mask, 0, (1 << n) - 1) {
            string t = "" ;
            FOR(j, 0, n - 1) {
                if(BIT(mask, j)) t.push_back('1') ;
                else t.push_back('0') ;
            }
            FOR(i, 0, t.size() - m) {
                if(cnt[t.substr(i, m)]) {
                    ans++ ;
                    break ;
                }
            }
        }
        cout << ans ;
    }
}

namespace subtask_2 {
	char a[N] ;
	unordered_map <string, int> mp ;
	unordered_map <string, int> dd[N], dp[N] ; 
	
	void Try(int i) {
        if(i > m) {
            string t = "" ;
            FOR(i, 1, m) t.push_back(a[i]) ;
            mp[t] = 1 ;
            return ;
        }
        if(s[i] == '*') {
            for(char j = '0'; j <= '1'; j++) {
                a[i] = j ;
                Try(i + 1) ;
            }
        } else {
            a[i] = s[i] ;
            Try(i + 1) ;
        }
    }
	
	ll calc(int i, string t) {
		if(i > n) return 1 ; 
		if(dd[i][t]) return dp[i][t] ; 
		dd[i][t] = 1 ; 
			
		string x = t ; 
		
		x.erase(0, 1) ; 
		x = x + "0" ;
		
		ll sum = 0 ; 
		if(mp[x] == 0) sum+= calc(i + 1, x) ; 
		
		x.back() = '1' ; 
		if(mp[x] == 0) sum+= calc(i + 1, x) ; 
		
		dp[i][t] = sum ; 
		return sum ; 
	}
	
	void solve() {
		Try(1) ; 
		ll sumAll = pow(2, n) ; 
		
		string t = "" ; 
		FOR(i, 1, m) t.push_back('0') ; 
		
		cout << sumAll - calc(1, t) ; 
	}
}

namespace subtask_3 {
	int node = 1 ; 
	int trie[(1 << 20) + 300][3], cnt[(1 << 20) + 300], nxt[(1 << 20) + 300][3] ;
	ll dp[N][(1 << 20) + 300] ; 

	ll calc(int i, int root) {
		if(i > n) return 1 ; 
		if(dp[i][root] != - 1) return dp[i][root] ; 
		
		ll &sum = dp[i][root] ; 
		sum = 0 ; 
		
		sum+= calc(i + 1, nxt[root][0]) ; 
		if(cnt[nxt[root][1]] == 0) sum+= calc(i + 1, nxt[root][1]) ; 
		
		return sum ; 
	}
	
	void build(int i, int root) {
		if(i > m) {
			cnt[root] = 1 ; 
			return ; 
		}
		
		if(s[i] == '*') {
			if(trie[root][0] == -1) {
				trie[root][0] = ++node ; 
			}
			build(i + 1, trie[root][0]) ; 
		}
		
		trie[root][1] = ++node ; 
		build(i + 1, trie[root][1]) ; 
	}
	
	void DFS(int root, string s) {
		if(trie[root][0] == - 1) {
			nxt[root][0] = 1 ;
			
			string x = s + "0" ;
			
			while(x.size()) {
				x.erase(0, 1) ; 
				
				int c = 1, ok = 1 ; 
				
				FOR(i, 0, x.size() - 1) {
					if(trie[c][x[i] - '0'] == - 1) {
						ok = 0 ; 
						break ; 
					} else c = trie[c][x[i] - '0'] ; 
				}	
				
				if(ok) {
					nxt[root][0] = c ; 
					break ; 
				}
			} 
		}
		
		if(trie[root][0] != - 1) {
			nxt[root][0] = trie[root][0] ; 
			DFS(trie[root][0], s + '0') ; 
		}
		
		if(trie[root][1] != -1) {
			nxt[root][1] = trie[root][1] ; 
			DFS(trie[root][1], s + '1') ; 
		}
	}
	
	void solve() {
		memset(trie, -1, sizeof trie) ;
		memset(nxt, -1, sizeof nxt) ;
		memset(dp, -1, sizeof dp) ; 
		
		build(1, 1) ; 
		
		string t = "" ; 
		DFS(1, t) ; 
		ll sumAll = 1 ; 
		FOR(i, 1, n) sumAll*= 2 ; 
		 
		cout << sumAll - calc(1, 1) ; 
	}	
}


signed main() {
    #define task "seed"
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    if(fopen(".inp","r")) {
        freopen(".inp","r",stdin) ; freopen(".out","w",stdout) ;
    }
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ;
    }
    init() ;
    // if(n <= 20) return subtask_1::solve(), 0 ;
    // if(m <= 20) return subtask_2::solve(), 0 ;
    return subtask_3::solve(),0 ; 
    cerr << "\nTime : " << clock() * 0.001 << "s" << endl ;
    return 0 ;
}
/* Watbor */