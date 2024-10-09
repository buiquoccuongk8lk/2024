/// Code By Watborhihi:>>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int,int>
#define SZ(a) (int)a.size()
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define vii vector<ii>
#define ALL(a) a.begin() , a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define uni(v) sort(ALL(v)) , v.resize( unique( ALL(v)) - v.begin())

const int N = 1e6 + 5 , LO = 17 , base = 311 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;

void add(ll &x,const ll &y) {x+=y;if(x>=MOD)x-=MOD;}
void sub(ll &x,const ll &y) {x-=y;if(x<0)x+=MOD;}

bool maximize(ll &x,const ll &y) {if(x < y){x=y;return 1;}return 0;}
bool minimize(ll &x,const ll &y) {if(x > y){x=y;return 1;}return 0;}

ll calc(ll val,ll T)
{
    if(val==0) return 0 ;
    return val * (T/val) ; 
}
int n, q ;
ll a[N] ;

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
    cin >> n >> q ; 
    FOR(i,1,n) cin >> a[i] ; 
    cout << 1e18 / 2 ;
    FOR(i,1,q)
    {
    	ll T ; 
    	int l , r ; 
    	cin >>  T >> l >> r ;
    	//cout << T <<" "<< l <<" "<< r << endl ;
    	FOR(j,l,r)
    	{
    		if(T>=calc(a[j],T))
    		{
    			T-=calc(a[j],T) ;
    		}
    	}
    	//cout << T << '\n' ;
    }
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}