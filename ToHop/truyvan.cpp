
#include<bits/stdc++.h>

using namespace std;

#define         TASK ""
#define         INPUT TASK".INP" 
#define         OUTPUT TASK".OUT"

#define int long long
#define Boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define fillchar(a,x) memset(a,x,sizeof(a))
#define endl '\n'
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define mp make_pair

const int inf = 1e18 , MOD = 1e9+7 , N  = 1e5+5;

int LT(int x,int y,int mod){
    if(y==0) return 1;
    if(y==1) return x;
    int c = LT(x,y/2,mod);
    if(y%2==1) return (((c*c)%mod)*x)%mod;
    else return (c*c)%mod;
}
void Doc() {
}
void Sol(){
    int t;
    cin >> t;
    while(t--){
        int a,b,c; cin >> a >> b >> c;
        int bmuc = LT(b,c,MOD-1);
        cout << LT(a,bmuc,MOD) <<'\n';
    }
    
}

signed main(){
    Boost
    if(fopen(INPUT,"r")){
    	freopen(INPUT,"r",stdin) ; freopen(OUTPUT,"w",stdout);
    }
    Doc();
    Sol();
}

