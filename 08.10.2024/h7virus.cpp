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

const int N = 2e6 + 5 ; 

int q ;
struct Queries {
	int t ; 
	string s ; 
} Q[N] ; 

void init() {
	cin >> q ; 
	FOR(i, 1, q) cin >> Q[i].t >> Q[i].s ; 
}

namespace subtask_1 {
	
	bool check() {
		FOR(i, 1, q) if(Q[i].t == 0) if(Q[i].s.size() > 10) return 0 ; 
		return 1 ; 
	}
	
	vector <string> zip ; 
	
	int xuly(string f) {
		int ans = 0 ; 
		
		FOR(i, 0, zip.size() - 1) {
			string s = zip[i] ;
			
			if(f.size() < s.size()) continue ; 
			
			FOR(j, 0, f.size() - s.size() ) { 
				string t = "" ; 
				FOR(v, j, j + s.size() - 1) t.push_back(f[v]) ; 
				if(s == t) ans++ ; 
			}
		}
		return ans ;
	}
	
	void solve() {
		FOR(test, 1, q) {
			int t = Q[test].t ; string s = Q[test].s ; 
			if(t == 0) zip.push_back(s) ;
			else {
				cout << xuly(s) << endl ; 
			}
		}	
	}
}

namespace subtask_2 {
	bool check() { 
		// vi cur ;
		// FOR(i, 1, q) if(Q[i].t == 1) cur.push_back(i) ; 
		// FOR(i, 1, cur.size() - 1) if(cur[i] != cur[i - 1] + 1) return 0 ; 
		return 1 ;  
	}
		
	struct Node {
		Node * child[3] ; 
		int cnt ; 
		Node () {
			cnt = 0 ; 
			memset(child, 0, sizeof child) ; 
		}
	} ;
	
	Node * root ; 
	
	void add(string s) {
		Node *p = root ; 
		for(auto c : s) {
			int j = c - '0' ; 
			if(p -> child[j] == 0) p -> child[j] = new Node() ; 
			p = p -> child[j] ; 
		}
		p -> cnt++ ; 
	}
		
	void solve() {
		root = new Node() ; 
		FOR(i, 1, q) {
			if(Q[i].t==0) {
				add(Q[i].s) ; 
			} else {
				string s = Q[i].s ; 
				int ans = 0 ; 
				FOR(j, 0, s.size() - 1) {
					Node *p = root ; 
					FOR(k, j, s.size() - 1) {
						if(p -> child[s[k] - '0'] == NULL) break ; 
						p = p -> child[s[k] - '0'] ; 
						ans+= p -> cnt ; 
					}
				}
				cout << ans << endl ;
			}
		}
		
	}
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(".inp","r")) {
        freopen(".inp","r",stdin) ; freopen(".out","w",stdout) ; 
    }
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    if(subtask_1::check()) return subtask_1::solve(),0 ;
    if(subtask_2::check()) return subtask_2::solve(),0 ; 
    cerr << "\nTime : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */