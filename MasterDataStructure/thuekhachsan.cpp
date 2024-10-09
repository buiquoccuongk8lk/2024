#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;

int n , m , a[N] , b[N] ; 
int st[4*N];
void update(int id,int l,int r,int pos,int val) {
	if(pos < l or pos > r) return;
	if(l==r) {
		a[pos] = val ; 
		st[id] = val;
		return;
	}
	int mid = (l+r)>>1;
	update(id<<1,l,mid,pos,val);
	update(id<<1|1,mid+1,r,pos,val);
	st[id] = max(st[id<<1],st[id<<1|1]);
}
long long get(int id,int l,int r,int u,int v) {
	if( l > v or r < u ) return -inf;
	if( l >= u and r <= v) return st[id];
	int mid = (l+r)>>1;
	int t1 = get(id<<1,l,mid,u,v);
	int t2 = get(id<<1|1,mid+1,r,u,v);
	return max(t1,t2);
}
int Walk(int id,int l,int r,int u,int v,int val) {
	if(l > v or r < u or st[id] < val) return -1;
	if(l==r) return l;
	int mid = (l+r)>>1;
	int ret = Walk(id<<1,l,mid,u,v,val);
	if(ret==-1) ret = Walk(id<<1|1,mid+1,r,u,v,val);
	return ret;
}

signed main(void) {
	#define TASK ""
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);cout.tie(nullptr);
	if( fopen(TASK".INP","r") ) {
		freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
	}
	cin >> n >> m;
	for(int i(1) ; i <= n ; i++) cin >> a[i];
	for(int i(1) ; i <= m ; i++) cin >> b[i];
	for(int i(1) ; i <= n ; i++) {
		update(1,1,n,i,a[i]);
	}
	for(int i(1) ; i <= m ; i++) {
		int pos = Walk(1,1,n,1,n,b[i]);
		cout << ( (pos == -1) ? 0 : pos) <<" ";
		update(1,1,n,pos,a[pos] - b[i]);
	}
	cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
	return 0;
}