#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;
int n , q ; 
int a[N] ; 
int st[4*N];
struct Queries{
	char ch ; 
	int L ; 
	int R ;
}Q[N] ; 
void update(int id,int l,int r,int pos,int val) {
	if(pos < l or pos > r) return;
	if(l==r){
		st[id]+=val;
		return;
	}
	int mid = (l+r)>>1;
	if(pos<=mid) update(id<<1,l,mid,pos,val);
	else update(id<<1|1,mid+1,r,pos,val);
	st[id] = st[id<<1] + st[id<<1|1];
}
long long get(int id,int l,int r,int u,int v) {
	if( l > v or r < u ) return 0;
	if( l >= u and r <= v) return st[id];
	int mid = (l+r)>>1;
	int t1 = get(id<<1,l,mid,u,v);
	int t2 = get(id<<1|1,mid+1,r,u,v);
	return t1 + t2;
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
	for(int i(1) ; i <= q ; i++) {
		cin >> Q[i].ch >> Q[i].L >> Q[i].R ;
	}
	vector<int> v;
	unordered_map<int,int> mp ;
	for(int i(1) ; i <= q ; i++) {
		v.push_back(Q[i].L);
		v.push_back(Q[i].R);
	}
	for(int i(1) ; i <= n ; i++) {
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end() ) - v.begin() );
	for(int i(0) ; i <= (int)v.size() - 1 ; i++) mp[v[i]] = i + 1 ; 
	int m = v.size() ; 
	for(int i(1) ; i <= n ; i++)  {
		update(1,1,m,mp[a[i]],1);
	}
	for(int i(1) ; i <= q ; i++) {
		if(Q[i].ch == '?') {
			cout << get(1,1,m,mp[Q[i].L],mp[Q[i].R]) << endl;
		}else {
			update(1,1,m,mp[a[Q[i].L]],-1);
			a[Q[i].L] = Q[i].R;
			update(1,1,m,mp[Q[i].R],1);
		}
	}
	cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
	return 0;
}