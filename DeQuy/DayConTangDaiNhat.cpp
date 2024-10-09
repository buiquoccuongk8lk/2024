
#include<bits/stdc++.h>

using namespace std;

bool multitest  = 0;

#define         TASK "DayConTangDaiNhat"
#define         INPUT TASK".INP" 
#define         OUTPUT TASK".OUT"

#define         int long long
#define         Boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define         FOR(i,a,b) for(int i = a ; i <= b; i++)
#define         FORD(i,a,b) for(int i = a ; i >= b ; i--)
#define         REP(i,l,r) for(int i = l ; i < r ; i++)
#define         fi first
#define         se second
#define         endl '\n'
#define         ii pair<int,int>
#define         pb push_back
#define         vi vector<int>
#define         vii vector<pair<int,int>>
#define         iii pair<int,ii>

template <class T> bool minimize(T &a, T b) { if (a > b) { a = b; return true; } return false;}
 
template <class T> bool maximize(T &a, T b) { if (a < b) { a = b; return true; } return false;}

const int dx[]={0,0,1,-1,1,1,-1,-1};
const int dy[]={1,-1,0,0,-1,1,-1,1};

const int inf = 1e18 , MOD = 1e9+7 , N  = 1e6+5;
const double eps = 1e-8;

int gcd(int a,int b){return __gcd(a,b);}
int bp(int a){return a*a;}
int lcm(int a,int b){return a*b/gcd(a,b);}

int n;
int a[25];
void Doc(){
	cin  >> n;
	FOR(i,1,n) cin >> a[i];
}
int ans = 1;

namespace sub{
	int b[25];
	int c[25];
	void ql(int pos){
		if(pos > n){
			bool ok = true;
			int m = 0;
			FOR(i,1,n){
				if(b[i]==1){
					m++;
					c[m] = a[i];
				}
			}
			FOR(i,2,m){
				if(c[i] <= c[i-1]) return;
			}
			ans = max(ans,m);
		}else{
			FOR(j,0,1){
				b[pos] = j;
				ql(pos+1); 
			}
		}
		
	}
    void Sol(){
		ql(1);
		cout << ans;
    }

}

signed main(){
    Boost
    if(fopen(INPUT,"r") ) {
        freopen(INPUT,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test = 1;
    if(multitest) cin >> test;
    FOR(run,1,test){
        Doc();
        sub::Sol();
    }
}


