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
	pre[x] = nxt[x] = x ; 
	if(x-1==u && u!=0 && x+1==v && v!=n+1) {
		pre[x] = pre[v] = pre[u] ; 
		nxt[x] = nxt[u] = nxt[v] ; 
	} else if(x-1==u && u!=0) {
		pre[x] = pre[u] ; 
		nxt[u] = nxt[x] ; 
	} else if(x+1==v && v!=n+1) {
		pre[v] = pre[x] ; 
		nxt[x] = nxt[v] ; 
	}
	ms_sum2.insert(nxt[x] - pre[x] + 1) ; 
}

void del(int x) {
	auto it = ms_val.upper_bound(x) ; 
	int v = *(it--) ; int u = *(--it) ; 
	ms_sum1.insert(v - u - 1) ; 
	ms_sum1.erase(ms_sum1.find(v - x - 1)) ; ms_sum1.erase(ms_sum1.find(x - u - 1)) ;
	ms_val.erase(x) ; 
	auto it_f = ms_sum2.find(nxt[x] - pre[x] + 1) ; 
	if(x-1==u && u!=0 && x+1==v && v!=n+1) {
		nxt[u] = u ; 
		pre[v] = v ; 
		if(it_f!=ms_sum2.end()) ms_sum2.erase(it_f) ;
		ms_sum2.insert(nxt[u] - pre[u] + 1) ; 
		ms_sum2.insert(nxt[v] - pre[v] + 1) ;  
	} else if(x-1==u && u!=0) {
		nxt[u] = u ; 
		if(it_f!=ms_sum2.end()) ms_sum2.erase(it_f) ;
		ms_sum2.insert(nxt[u] - pre[u] + 1) ; 
	} else if(x+1==v && v!=n+1) {
		pre[v] = v ; 
		if(it_f!=ms_sum2.end()) ms_sum2.erase(it_f) ;
		ms_sum2.insert(nxt[v] - pre[v] + 1) ; 
	} else {
		if(it_f!=ms_sum2.end()) ms_sum2.erase(it_f) ;
	}
}

void process(void) {
	ms_val.insert(0) ; ms_val.insert(n+1) ;
	ms_sum1.insert(n) ; 
	int x ; 
	ms_sum2.insert(0) ; ms_sum2.insert(0) ;
	while(q--) {
		cin >> x ; 
		dd[x]++ ; 
		if(dd[x] & 1) {
			add(x) ; 
		} else {
			del(x) ; 
		}
		cout << max(*ms_sum1.rbegin(),*ms_sum2.rbegin()) << '\n' ; 
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