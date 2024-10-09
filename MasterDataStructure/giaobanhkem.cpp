#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;
int n , q , a[N] ; 
struct Node {
	long long L ; 
	long long R ; 
}st[4*N] ; 
void build(int id,int l,int r) {
	if(l==r) {
		st[id].L = a[l] - l ; 
		st[id].R = a[l] + l ; 
		return ;
	}
	int mid = (l+r) >> 1 ; 
	build(id<<1,l,mid) ; 
	build(id<<1|1,mid+1,r) ; 
	st[id].L = min(st[id<<1].L , st[id<<1|1].L ) ;
	st[id].R = min(st[id<<1].R , st[id<<1|1].R ) ;
}
void update(int id,int l,int r,int pos,int val) {
	if(pos < l or pos > r) return ; 
	if(l==r) {
		a[pos] = val ; 
		st[id].L = a[pos] - pos ; 
		st[id].R = a[pos] + pos ; 
		return ; 
	}
	int mid = (l+r)>>1 ; 
	update(id<<1,l,mid,pos,val) ;
	update(id<<1|1,mid+1,r,pos,val) ; 
	st[id].L = min(st[id<<1].L , st[id<<1|1].L ) ;
	st[id].R = min(st[id<<1].R , st[id<<1|1].R ) ;
}
Node get(int id,int l,int r,int u,int v) {
	if(l > v or r < u) return { (long long) 2e9 , (long long)2e9 } ;
	if(l >= u and r <= v) return { st[id].L , st[id].R } ; 
	int mid = (l+r)>>1;
	Node t1 = get(id<<1,l,mid,u,v) ; 
	Node t2 = get(id<<1|1,mid+1,r,u,v) ; 
	return { min(t1.L , t2.L) , min(t1.R , t2.R) } ; 
}
signed main(void) {
	#define TASK ""
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);cout.tie(nullptr);
	if( fopen(TASK".INP","r") ) {
		freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
	}
	cin >> n >> q ; 
	for(int i(1) ; i <= n ; i++) cin >> a[i] ; 
	build(1,1,n) ; 
	while(q--) {
		int t ; 
		cin >> t ; 
		if( t == 1 ) {
			int k , x ; 
			cin >> k >> x ; 
			update(1,1,n,k,x) ; 
		}else {
			int k ; 
			cin >> k ;
			long long ans1 = get(1,1,n,1,k).L + k ; 
			long long ans2 = get(1,1,n,k,n).R - k ; 
			cout << min(ans1,ans2) << '\n' ; 
		}
	}
	cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
	return 0;
}