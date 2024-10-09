#include <bits/stdc++.h>
using namespace std;

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

const int N = 1e6 + 5 , LO = 17 , base = 311 ; 
const long long inf = 1e18 , MOD = 1e9 + 7 ;

void add(ll &x,const ll &y) {x+=y;if(x>=MOD)x-=MOD;}
void sub(ll &x,const ll &y) {x-=y;if(x<0)x+=MOD;}
bool maximize(ll &x,const ll &y) {if(x < y){x=y;return 1;}return 0;}
bool minimize(ll &x,const ll &y) {if(x > y){x=y;return 1;}return 0;}


signed main(void) 
{
	#define TASK ""
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);cout.tie(nullptr);
	if( fopen(TASK".INP","r") ) 
	{
		freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
	}

	cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
	return 0;
}