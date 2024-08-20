/* Code By Watbor */
#include <bits/stdc++.h>
using namespace std ; 
const int MAX = 1e5 + 5 ;

int n , m , q ; 

void init(void) {
	cin >> n >> m >> q ; 
}

namespace sub1 {
	multiset<int> ms_sum ;
	set<int> se_row , se_col ; 
	void cut_row(int x) {
		auto it = se_row.upper_bound(x) ; 
		int v = *(it--) , u = *it , d = 0 , last = 2e9 ; 

		for(auto y : se_col) {
			if(d==0) {
				d++ ;
			} else {
				ms_sum.erase(ms_sum.find((v-u)*(y-last))) ; 
			}
			last = y ; 
		}

		d = 0 ;
		for(auto y : se_col) { 
			if(d==0) {
				d++ ;
			} else {
				ms_sum.insert((v-x)*(y-last)) ; 
				ms_sum.insert((x-u)*(y-last)) ; 
			}
			last = y ; 
		}
		se_row.insert(x) ; 
	}	

	void cut_col(int x) {
		auto it = se_col.upper_bound(x) ; 
		int v = *(it--) , u = *it , d = 0 , last = 2e9 ; 
		for(auto y : se_row) {
			if(d==0) {
				d++ ;
			} else ms_sum.erase(ms_sum.find((v-u)*(y-last))) ; 
			last = y ; 
		}
		d = 0 ;
		for(auto y : se_row) {
			if(d==0) {
				d++ ;
			} else {
				ms_sum.insert((v-x)*(y-last)) ; 
				ms_sum.insert((x-u)*(y-last)) ; 
			}
			last = y ; 
		}
		se_col.insert(x) ; 
	}

	void solve(void) {
		ms_sum.insert(0) ;
		ms_sum.insert(0) ; 
		ms_sum.insert(n*m) ; 
		se_col.insert(1) ; se_col.insert(m+1) ; 
		se_row.insert(1) ; se_row.insert(n+1) ; 
		while(q--) {
			char t ; int x ; cin >> t >> x ; 
			x++ ; 
			if(t=='H') {
				cut_row(x) ; 
			} else {
				cut_col(x) ; 
			}
			cout << *ms_sum.rbegin() << '\n' ; 
		}
	}

}

namespace sub2 {

	multiset<int> ms_col , ms_row ; 
	set<int> se_col , se_row ; 

	void cut_row(int x) {
		auto it = se_row.upper_bound(x) ; 
		int v = *(it--) , u = *it ; 

		ms_row.erase(ms_row.find(v - u)) ; 
		ms_row.insert(v - x) ; ms_row.insert(x - u) ;
		se_row.insert(x) ; 
	}

	void cut_col(int x) {
		auto it = se_col.upper_bound(x) ; 
		int v = *(it--) , u = *it ;

		ms_col.erase(ms_col.find(v - u)) ; 
		ms_col.insert(v - x) ; ms_col.insert(x - u) ; 
		se_col.insert(x) ; 
	}

	void solve(void) {
		ms_col.insert(m) ; ms_row.insert(n) ; 
		se_col.insert(1) ; se_col.insert(m + 1) ; 
		se_row.insert(1) ; se_row.insert(n + 1) ; 	

		while(q--) {
			char t ; int x ; cin >> t >> x ; ++x ; 
			if(t=='H') {
				cut_row(x) ; 
			} else {
				cut_col(x) ; 
			}
			cout << 1ll * *ms_col.rbegin() * *ms_row.rbegin() << '\n' ; 
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
    if(n <= 1e3 && m <= 1e3) sub1::solve() ; 
    else sub2::solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms " << endl;
    return 0 ;
}