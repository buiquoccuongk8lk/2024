/* Code By Watbor */
#include <bits/stdc++.h>
using namespace std ; 
#define MAX (int)500000
#define int long long

int n , VAL ; 
int a[MAX] ; 
vector<int> pos[MAX] ; 
long long st[8*MAX] , lazy1[8*MAX] , lazy2[8*MAX] ;
vector<int> node_participate ; 

long long tinh(int l,int r,int val) {
	return (r-l+1)*(r+l)/2 - (r-l+1)*val + (r-l+1) ;
}

void dolazy1(int id,int l,int r) {
	if(lazy1[id]==0) return ; 
	int mid = (l+r)>>1 ; 

	st[id<<1]+= tinh(l,mid,lazy1[id]) ; 
	st[id<<1|1]+= tinh(mid+1,r,lazy1[id]) ;

	lazy1[id<<1]+= lazy1[id] ; 
	lazy1[id<<1|1]+= lazy1[id] ; 

	lazy1[id] = 0 ;
}

void dolazy2(int id,int l,int r) {
	if(lazy2[id]==0) return ; 
	int mid = (l+r)>>1 ; 

	st[id<<1]+= (mid-l+1)*lazy2[id] ; 
	st[id<<1|1]+= (r-mid)*lazy2[id] ; 

	lazy2[id<<1]+= lazy2[id] ; 
	lazy2[id<<1|1]+= lazy2[id] ; 

	lazy2[id] = 0 ; 
}

void update1(int id,int l,int r,int u,int v,int val) {
	if(l > v or r < u) return ; 
	if(l >= u and r <= v) {
		st[id]+= (r-l+1)*(r+l)/2 - (r-l+1)*u + (r-l+1) ;
		lazy1[id]+= u ;
		node_participate.push_back(id) ; 
		return ; 
	}
	int mid = (l+r)>>1 ; 
	dolazy1(id,l,r) ; 
	update1(id<<1,l,mid,u,v,val) ; 
	update1(id<<1|1,mid+1,r,u,v,val) ; 
	st[id] = st[id<<1] + st[id<<1|1] ; 
	node_participate.push_back(id<<1) ; 
	node_participate.push_back(id<<1|1) ; 
}

void update2(int id,int l,int r,int u,int v,int val) {
	if(l > v or r < u) return ; 
	if(l >= u and r <= v) {
		st[id]+= (r-l+1)*val ; 
		lazy2[id]+= val ; 
		node_participate.push_back(id) ; 
		return ; 
	}
	int mid = (l+r)>>1 ; 
	dolazy2(id,l,r); 	
	update2(id<<1,l,mid,u,v,val) ;
	update2(id<<1|1,mid+1,r,u,v,val) ; 
	st[id] = st[id<<1] + st[id<<1|1] ; 
	node_participate.push_back(id<<1) ; 
	node_participate.push_back(id<<1|1) ; 
}

int get(int id,int l,int r,int u,int v) {
	if(l > v or r < u) return 0 ; 
	if(l >= u and r <= v) {
		node_participate.push_back(id) ; 
		return st[id] ; 
	}
	int mid = (l+r)>>1 ; 
	dolazy1(id,l,r) ; 
	dolazy2(id,l,r) ; 
	node_participate.push_back(id<<1) ; 
	node_participate.push_back(id<<1|1) ; 
	return get(id<<1,l,mid,u,v) + get(id<<1|1,mid+1,r,u,v) ; 
}

long long calc(int val) {
	int cnt = 0 ; long long ans = 0 ;
	for(int i(1) ; i <= (int)pos[val].size() - 1 ; i++) {
        int a = 2*cnt - (pos[val][i] - 1) + n + 1 ;
        int b = 2*cnt - pos[val][i-1] + n + 1 ;
        ans += get(1,1,4*n+1,max(1ll*1,a-1),b-1)  ;
        update1(1,1,4*n+1,a,b,1) ;
        update2(1,1,4*n+1,b+1,2*n+1,b-a+1) ;
        ++cnt ;
    }
    while(!node_participate.empty()) {
    	int id = node_participate.back() ; 
    	st[id] = lazy1[id] = lazy2[id] = 0 ;
    	node_participate.pop_back() ;
    }
    return ans ; 
}

void solve(void) {	
	int VAL = *max_element(a+1,a+1+n) ;
	for(int i(1) ; i <= n ; i++) pos[i].push_back(0) ; 
	for(int i(1) ; i <= n ; i++) pos[a[i]].push_back(i) ; 
	for(int i(1) ; i <= n ; i++) pos[i].push_back(n+1) ;
	long long ans = 0 ; 	
	for(int i(1) ; i <= VAL ; i++) if(!pos[i].empty()) {
		ans+= 1LL * calc(i) ; 
	}
	cout << n * (n + 1) / 2 - ans ;
}

signed main(void) {
    #define mitsuri "majval"
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if( fopen(mitsuri".INP","r") ) {
        freopen(mitsuri".INP","r",stdin) ; freopen(mitsuri".OUT","w",stdout);
    }
    cin >> n ;
    for(int i(1) ; i <= n ; i++) cin >> a[i] ; 
    solve() ;
    cerr << endl << "watborhihi : " << clock() << "ms " << endl;
    return 0 ;
}