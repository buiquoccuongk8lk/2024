/// Code By Watborhihi:>>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define vii vector<ii>
#define ALL(a) a.begin() , a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define uni(v) sort(ALL(v)) , v.resize( unique( ALL(v)) - v.begin())

const int N = 2e5  , LO = 17 , base = 311 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;

void add(ll &x,const ll &y) {x+=y;if(x>=MOD)x-=MOD;}
void sub(ll &x,const ll &y) {x-=y;if(x<0)x+=MOD;}

bool maximize(ll &x,const ll &y) {if(x < y){x=y;return 1;}return 0;}
bool minimize(ll &x,const ll &y) {if(x > y){x=y;return 1;}return 0;}
ll __lcm(ll a,ll b){return a*b/__gcd(a,b) ; }
int n , q ;
void doc(void) 
{
	cin >> n >> q ;  
}
struct Node
{
	ll sum ;
	int maxi ; 
	int cnt_maxi ; 
	int mini ;
	int cnt_mini ;  
	int gcd ; 
	int cnt_gcd ; 
	int lcm ; 
	int cnt_lcm ;   
	int lazy; 
	Node ()
	{
		sum = 0 ; maxi = 0 ; cnt_maxi = 0 ; mini = 0 ;cnt_mini = 0 ;gcd = 0 ;cnt_gcd = 0 ;lcm = 0 ;cnt_lcm = 0 ; lazy = 0 ; 
	}
	friend Node operator +(Node a,Node b)
	{
		Node ans ; 
		if(a.lcm == 0) return b ; 
		if(b.lcm == 0) return a ;

		ans.sum = a.sum + b.sum ;

		ans.maxi = max(a.maxi,b.maxi) ; 
		if(ans.maxi==a.maxi) ans.cnt_maxi+=a.cnt_maxi ; 
		if(ans.maxi==b.maxi) ans.cnt_maxi+=b.cnt_maxi ; 

		ans.mini = min(a.mini,b.mini) ; 
		if(ans.mini==a.mini) ans.cnt_mini+=a.cnt_mini ; 
		if(ans.mini==b.mini) ans.cnt_mini+=b.cnt_mini ; 

		ans.gcd = __gcd(a.gcd,b.gcd) ; 
		if(ans.gcd==a.gcd) ans.cnt_gcd+=a.cnt_gcd ; 
		if(ans.gcd==b.gcd) ans.cnt_gcd+=b.cnt_gcd ;

		ans.lcm = __lcm(a.lcm,b.lcm) ; 
		if(ans.lcm==a.lcm) ans.cnt_lcm+=a.cnt_lcm ;
		if(ans.lcm==b.lcm) ans.cnt_lcm+=b.cnt_lcm ;
		
		return ans ;
	}
}st[4*N] ;  
void down(int id,int l,int r)
{
	int &val = st[id].lazy ; 
	if(!val) return ;

	int mid = (l+r) >> 1 ;

	st[id<<1].sum =  (mid-l+1)* val ;  
	st[id<<1|1].sum = (r-mid)*val ; 

	st[id<<1].maxi = val ; 
	st[id<<1|1].maxi = val ; 
	st[id<<1].cnt_maxi = mid - l + 1 ; 
	st[id<<1|1].cnt_maxi = r - mid ;  

	st[id<<1].mini = val ; 
	st[id<<1|1].mini = val ;
	st[id<<1].cnt_mini = mid - l + 1 ;
	st[id<<1|1].cnt_mini = r - mid ;  

	st[id<<1].gcd = val ; 
	st[id<<1|1].gcd = val ; 
	st[id<<1].cnt_gcd = mid - l + 1 ; 
	st[id<<1|1].cnt_gcd = r - mid ; 

	st[id<<1].lcm = val ; 
	st[id<<1|1].lcm = val ;
	st[id<<1].cnt_lcm = mid - l + 1 ; 
	st[id<<1|1].cnt_lcm = r - mid ; 

	st[id<<1].lazy = val ; 
	st[id<<1|1].lazy = val ; 

	val = 0 ;
}
void update(int id,int l,int r,int u,int v,int val)
{
	if(l > v or r < u) return ;
	if(l >= u and r <= v)
	{
		st[id].sum = (ll) (r-l+1) * val ;

		st[id].mini = val ; 
		st[id].cnt_mini = r - l + 1 ;

		st[id].cnt_maxi = r - l + 1 ;
		st[id].maxi = val ;

		st[id].gcd = val ;
		st[id].cnt_gcd = r - l + 1 ;

		st[id].lcm = val ; 
		st[id].cnt_lcm = r - l + 1 ; 

		st[id].lazy = val  ; 
		return ;
	}
	int mid = (l+r) >> 1 ; 
	down(id,l,r) ; 
	update(id<<1,l,mid,u,v,val) ; 
	update(id<<1|1,mid+1,r,u,v,val) ; 
	st[id] = st[id<<1] + st[id<<1|1] ; 
}
Node get(int id,int l,int r,int u,int v)
{
	if(l > v or r < u){ Node emp ; return emp;}
	if(l >= u and r <= v) return st[id] ; 
	int mid = (l+r) >> 1 ;
	down(id,l,r) ; 
	return get(id<<1,l,mid,u,v) + get(id<<1|1,mid+1,r,u,v) ; 
}
void solve(void)
{
	FOR(i,1,n) 
	{
		int x  ;
		cin >> x ; 
		update(1,1,n,i,i,x) ; 
	}
	while(q--)
	{
		int t , l , r , x ;
		cin >> t >> l >> r  ;
		if(t==1)
		{
			cin >> x ;
			update(1,1,n,l,r,x) ;
			continue ; 
		}
		Node ans = get(1,1,n,l,r) ; 
		if(t==2)
		{
			cout << ans.sum << endl ; 
		}
		if(t==3)
		{
			cout << ans.mini << endl ; 
		}
		if(t==4)
		{
			cout << ans.cnt_mini << endl ; 
		}
		if(t==5)
		{
			cout << ans.maxi << endl ; 
		}
		if(t==6)
		{
			cout << ans.cnt_maxi << endl ; 
		}
		if(t==7)
		{
			cout << ans.gcd << endl ; 
		}
		if(t==8)
		{
			cout << ans.cnt_gcd << endl; 
		}
		if(t==9)
		{
			cout << ans.lcm << endl ; 
		}
		if(t==10)
		{
			cout << ans.cnt_lcm << endl ;
		}
	}
}

signed main(void) 
{
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if( fopen(TASK".INP","r") ) 
    {
        freopen(TASK".INP","r",stdin) ; 
        freopen(TASK".OUT","w",stdout);
    }
    doc() ; 
    solve() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}