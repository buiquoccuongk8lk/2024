/* Code By Watbor */
#include <bits/stdc++.h>
using namespace std ; 
const int MAX = 1e5 + 5 ;

int numChest,numKey ; 
int c[MAX] ;
struct Edge {
	int u , v ; 
} e[MAX] ; 

void init(void) {
	cin >> numChest >> numKey ;
	for(int i = 1 ; i <= numChest ; i++) cin >> c[i] ; 
	for(int i = 1 ; i <= numKey ; i++) cin >> e[i].u >> e[i].v ; 
}	

namespace sub1 {
	vector<int> keys ;
	int ID[MAX] ;
	void solve(void) {
		keys.push_back(0) ;
		for(int i = 1 ; i <= numKey ; i++) keys.push_back(i) ; 
		int n = keys.size() ; 
		for(int i = 1 ; i <= numKey ; i++) {
			int x ; cin >> x ; 
			keys[x] = 0 ; 
			long long ans = 0 ; 
			for(int mask = 0 ; mask < (1<<n) ; mask++) {
				vector<int> choose ; 
				choose.resize(numChest + 3 , 0) ; 
				long long sum = 0 ;
				for(int j = 1 ; j <= (int)keys.size() - 1 ; j++) {
					if(keys[j]==0) continue ; 
					if((mask>>j)&1 and !choose[e[keys[j]].u]) {
						sum+= c[e[keys[j]].u] ;
						choose[e[keys[j]].u] = 1 ;
					}
					else if(!choose[e[keys[j]].v]) {
						sum+= c[e[keys[j]].v] ; 
						choose[e[keys[j]].v] = 1 ; 
					}
				}
				ans = max(ans,sum) ; 
			}
			cout << ans << '\n' ; 
		}
	}
}

namespace sub2 {

	void solve(void) {

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
    if(numChest <= 16 && numKey <= 16) sub1::solve() ; 
    else sub2::solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms " << endl;
    return 0 ;
}