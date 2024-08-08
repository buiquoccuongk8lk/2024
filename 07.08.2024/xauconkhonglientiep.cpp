#include <bits/stdc++.h>
#define tct template<class MITSURII,class CHANN>
#define FOR(i,a,b) for(int i(a) ; i <= (b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (b) ; i--)
using namespace std ; 
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }
#define MAXN 100005

string s ; 
int q , n ; 
int pre[MAXN][27] , suf[MAXN][27] ; 

void init() {
	cin >> s ; n = s.size() - 1 ;  
	cin >> q ;
}

void solve() {
	memset(pre,-1,sizeof pre) ; 
	memset(suf,-1,sizeof suf) ; 

	FORD(i,n,0) {
		FOR(j,0,26) {
			suf[i][j] = ( (j + 'a' == s[i]) ? i : suf[i+1][j]) ;  
		}
	}	

	FOR(i,0,n) {
		FOR(j,0,26) {
			pre[i][j] = ( (j + 'a' == s[i]) ? i : pre[i-1][j]) ; 
		}
	}

	int ans = 0 ; 

	while(q--) {
		string x ; cin >> x ; 
		int cur = 0 ; 
		vector<int> vec ; 
		FOR(i,0,x.size()-1) {
			if(suf[cur][x[i]-'a']==-1) break ; 
			vec.push_back(suf[cur][x[i]-'a']) ; 
			cur = suf[cur][x[i] - 'a'] + 1 ; 
		}
		if(vec.size() == x.size()) {
			int len = x.size() - 1 ; 
			int cur = n ; 
			FORD(i,x.size()-1,0) {
				if(pre[cur][x[i]-'a']==-1) break ; 
				if(pre[cur][x[i]-'a'] != suf[vec[len--]][x[i]-'a']) {
					ans++ ; 
					break ;
				}
				cur = pre[cur][x[i]-'a'] - 1 ; 
			}
		}
	} 
	cout << ans ; 
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ; solve() ; 
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}