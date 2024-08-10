/* Code By Watbor */
#include <bits/stdc++.h>
using namespace std ; 
#define MAX 1e5 + 5 

int n , q ; 
multiset<int> ms_sum1 , ms_sum2 , ms_val ; 
unordered_map<int,int> dd , pre , nxt ;  

void init(void) {
	cin >> n >> q ; 
}

void add(int x) {
	auto it = ms_val.lower_bound(x) ; 
	int v = *(it--) ; int u = *it ; 
	ms_sum1.erase(ms_sum1.find(v - u - 1)) ;
	ms_sum1.insert(v - x - 1) ; ms_sum1.insert(x - u - 1) ; 
	ms_val.insert(x) ;  
}

void del(int x) {
	auto it = ms_val.upper_bound(x) ; 
	int v = *(it--) ; int u = *(--it) ; 
	ms_sum1.insert(v - u - 1) ; 
	ms_sum1.erase(ms_sum1.find(v - x - 1)) ; ms_sum1.erase(ms_sum1.find(x - u - 1)) ;
	ms_val.erase(x) ; 
}

void process(void) {
	ms_val.insert(0) ; ms_val.insert(n+1) ;
	ms_sum1.insert(n) ; 
	int x ; 
	while(q--) {
		cin >> x ; 
		dd[x]++ ; 
		if(dd[x] & 1) {
			add(x) ; 
		} else {
			del(x) ; 
		}
		int cnt = 0 , last = 0 , ma = 1 ;
		for(auto x : ms_val) {
			if(x!=0 && x!=n+1) {
				if(x==last+1) cnt++ , ma = max(ma,cnt) ;
				else ma = max(ma,cnt) , cnt = 1 ;
			}
			last = x ; 
		}
		cout << max(ma , *ms_sum1.rbegin()) << '\n' ;
	}	
}

signed main(void) {
    #define mitsuri ""
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if( fopen(mitsuri".INP","r") ) {
        freopen(mitsuri".INP","r",stdin) ; freopen(mitsuri".OUT","w",stdout);
    }
    init() ; process() ; 
    cerr << endl << "watborhihi : " << clock() << "ms " << endl;
    return 0 ;
}