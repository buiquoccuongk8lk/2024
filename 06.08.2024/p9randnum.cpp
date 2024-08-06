#include <bits/stdc++.h>
#define tct template<class MITSURII,class CHANN>
using namespace std ; 

const int N = 3e5 + 5 ;

int n ;
struct Queries {
	int t , k ;
} Q[N] ;
vector<int> v ;
int fi[N] ; 
int VAL ;
struct {
	int bit[N] ; 
	void up(int u,int val) {
		for(int i(u) ; i <= VAL ; i+=i&-i) bit[i]+=val ; 
	}
	int get(int u) {
		int s = 0 ;
		for(int i(u) ; i ; i-=i&-i) s+= bit[i] ; 
		return s ; 
	}
} BIT ; 

void solve() {

	for(int i(1) ; i <= n ; i++) {
		if(Q[i].t == 1) {
			v.push_back(Q[i].k) ;
		}
	}	

	sort(v.begin(),v.end()) ; 
	v.resize(unique(v.begin(),v.end()) - v.begin()) ; 
	VAL = v.size() ; 

	for(int i(1) ; i <= n ; i++) {
		if(Q[i].t==1) {
			int p = lower_bound(v.begin(),v.end(),Q[i].k) - v.begin() + 1 ; 
			fi[p] = Q[i].k ;
			Q[i].k = p ;
		}
	}

	for(int i(1) ; i <= n ; i++) {
		if(Q[i].t == 1) {
			BIT.up(Q[i].k,1) ; 
		} else {	
			int l = 1 , r = VAL , p = 0 ;
			//if(i!=n) continue ;
			while(l <= r) {
				int mid = (l+r)>>1 ; 
				//cout << mid << endl ;
				if(BIT.get(mid) >= Q[i].k) {
					p = mid ; 
					r = mid - 1 ; 
				} else l = mid + 1 ; 
			}
			cout << fi[p] << '\n' ; 
		}
	}

}

signed main() {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    } 
    cin >> n ; 
    for(int i(1) ; i <= n ; i++) {
    	cin >> Q[i].t >> Q[i].k ; 
    }
    solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}