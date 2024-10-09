#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;

int n , a[N] , b[N] ; 
int st[4*N] ; 

void update(int id,int l,int r,int pos,int val) {
	if(pos < l or pos > r) return ; 
	if( l == r ) {
		st[id] = val;
		return;
	}
	int mid = (l+r)>>1;
	if(pos<=mid) update(id<<1,l,mid,pos,val);
	else update(id<<1|1,mid+1,r,pos,val);
	st[id] = st[id<<1] + st[id<<1|1];
}
int get(int id,int l,int r,int u,int v){
	if(l > v or r < u) return 0 ; 
	if( l >= u and r <= v) return st[id];
	int mid = (l+r)>>1;
	return get(id<<1,l,mid,u,v) + get(id<<1|1,mid+1,r,u,v);
}
int Walk(int id,int l,int r,int val) {
	if(l > r) return 0 ;
	if(l==r) return l ;
	int mid = (l +r) >> 1 ;
	if(st[id<<1] >= val) return Walk(id<<1,l,mid,val) ; 
	else return Walk(id<<1|1,mid+1,r,val - st[id<<1]) ; 
}

signed main(void) {
	#define TASK ""
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);cout.tie(nullptr);
	if( fopen(TASK".INP","r") ) {
		freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
	}
	cin >> n ; 
	for(int i(1) ; i <= n ; i++) cin >> a[i] ;
	for(int i(1) ; i <= n ; i++) cin >> b[i] ;
	for(int i(1) ; i <= n ; i++) {
		update(1,1,n,i,1) ;
	}
	for(int i(1) ; i <= n ; i++) {
		int pos = Walk(1,1,n,b[i]) ; 
		cout << a[pos] <<" " ;
		update(1,1,n,pos,0);
	}

	cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
	return 0;
}