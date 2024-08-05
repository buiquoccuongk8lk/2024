/*[продолжатьипродолжать]*/
#include <bits/stdc++.h>
using namespace std ; 
const int MAX = 2e5 + 5 ;

int n,m,q ; 
vector<int> g[MAX] ; 
int s[MAX] , st[4*MAX] , dist[MAX] ;

void init(void) {
	cin >> n >> m >> q ; 
	for(int i = 1 ; i <= m ; i++) {
		int u,v ; cin >> u >> v ; 
		g[v].push_back(u) ; 
	}
	for(int i = 1 ; i <= n ; i++) cin >> s[i] ; 
}

void update(int id,int l,int r,int pos,int val) {
	if(pos < l or pos > r) return ; 
	if(l==r) {
		st[id] = val ; 
		return ; 
	}
	int mid = (l+r)>>1 ; 
	update(id<<1,l,mid,pos,val) ; 
	update(id<<1|1,mid+1,r,pos,val) ; 
	st[id] = min(st[id<<1],st[id<<1|1]) ; 
}

int get(int id,int l,int r,int u,int v) {
	if(l > v or r < u) return 2e9 ; 
	if(l >= u and r <= v) return st[id] ; 
	int mid = (l+r)>>1 ; 
	return min(get(id<<1,l,mid,u,v),get(id<<1|1,mid+1,r,u,v)) ; 
}

void solve(void) {
	for(int i = 1 ; i <= n ; i++) dist[i] = 2e9 ; 
	dist[n] = 0 ; 
	deque<int> dq ; 
	dq.push_back(n) ; 
	while(!dq.empty()) {
		int u = dq.front() ; dq.pop_front() ; 
		for(auto v : g[u]) {
			if(dist[v] > dist[u] + 1) {
				dist[v] = dist[u] + 1 ; 
				dq.push_back(v) ; 
			}
		}
	}
	for(int i = 1 ; i <= n ; i++) update(1,1,n,s[i],dist[s[i]] + i) ; 
	while(q--) {
		int x , y ; cin >> x >> y ;
		swap(s[x],s[y]) ; 
		update(1,1,n,s[x],dist[s[x]] + x) ; 
		update(1,1,n,s[y],dist[s[y]] + y) ; 
		cout << st[1] - 1 << '\n' ; 
	}
}		

signed main(void) {
    #define NAME ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(NAME".inp","r") ) {
        freopen(NAME".inp","r",stdin) ; freopen(NAME".out","w",stdout);
    }
    init() ; solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}