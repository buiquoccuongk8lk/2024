#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define vii vector<ii>
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)

const int N = 1e6 + 5 , LO = 17 , base = 311 ; 
const long long inf = 1e18 , MOD = 1e9 + 7 ;

void add(ll &x,const ll &y) {x+=y ; if(x>=MOD) x-=MOD ;}
void sub(ll &x,const ll &y) {x-=y ; if(x<0) x+=MOD ;}

int n , q ; 
string s ;
ll pre[N] ; 

void doc(void)
{
	cin >> n >> q ; 
	cin >> s ; 
	s = "*" + s ; 
	FOR(i,1,(int)s.size() - 1) pre[i] = pre[i-1] + ( s[i] == '*' ? 1 : -1 ) ;
}

namespace sub1
{
	struct Node
	{
		ll maxi ; 
		ll mini ; 
		friend Node operator + (Node a ,Node b)
		{
			Node ans ; 
			ans.maxi = max(a.maxi,b.maxi) ; 
			ans.mini = min(a.mini,b.mini) ; 
			return ans ;
		}
	} st[4*N] ; 
	void update(int id,int l,int r,int pos,ll val)
	{
		if(pos < l or pos > r) return ; 
		if( l == r ) 
		{
			st[id] = {val ,  val }; 
			return ; 
		}
		int mid =  ( l + r ) >> 1 ; 
		update(id<<1,l,mid,pos,val) ;
		update(id<<1|1,mid+1,r,pos,val) ; 
		st[id] = st[id<<1] + st[id<<1|1] ; 
 	}
	Node get(int id,int l,int r,int u,int v)
	{
		if(l > v or r < u ) return { -inf , inf } ; 
		if(l >= u and r <= v) return st[id] ; 
		int mid = (l + r) >> 1;
		return get(id<<1,l,mid,u,v) + get(id<<1|1,mid+1,r,u,v) ;
	}
	int Walk(int id,int l,int r,int u,int v,ll val)
	{
		if( l > v or r < u or st[id].mini >= val ) return -1 ; 
		if( l == r ) return l ;
		int mid = (l+r)>>1 ; 
		int ret = Walk(id<<1,l,mid,u,v,val) ; 
		if(ret==-1) ret = Walk(id<<1|1,mid+1,r,u,v,val) ; 
		return ret ; 
	}
	void xuly(void)
	{
		FOR(i,1,n) update(1,0,n,i,pre[i]) ; 
		while(q--)
		{
			int l , r ; 
			cin >> l >> r ; 
			ll ans = 0 ; 
			ll val = pre[l-1] ; 
			int pos = Walk(1,0,n,l,r,val) ; 
			if(pos == l)
			{
				cout << 2 << '\n' ;
				continue ; 
			}
			ans = (pos!=-1) ; 
			if(pos==-1) pos = r + 1  ; 
			Node res = get(1,0,n,l,pos - 1) ; 
			ans+= res.maxi - res.mini + 1 ;
			ans+= ( (res.mini - pre[l-1]) != 0 ) ;
			cout << ans << '\n' ; 
		}
	}
}

signed main(void) 
{
	#define TASK ""
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);cout.tie(nullptr);
	if( fopen(TASK".INP","r") ) 
	{
		freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
	}
	doc();
	sub1::xuly() ; 
	cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
	return 0;
}