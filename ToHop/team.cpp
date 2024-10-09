
#include<bits/stdc++.h>

using namespace std;

#define 		TASK ""
#define 		INPUT TASK".INP"
#define 		OUTPUT TASK".OUT"

#define 		int long long
#define         Boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define         fr(i,a,b) for(int i=a;i<=b;i++)
#define         fd(i,a,b) for(int i=a;i>=b;i--)
#define         fi first
#define         se second
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
const int inf = 1e18 , MOD = 1e9+7 , N  = 1e5+5;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l,int r){
	return l + rd()%(r-l+1);
}

int n,a,b,d;
int fact[(int)1e6+5];

int add(int a,int b){
    return (a+b)%MOD;
}
int mul(int a,int b){
    return (a*b)%MOD;
}
int LT(int x,int y){
    if(y==0) return 1;
    if(y==1) return x;
    int c = LT(x,y/2);  
    if(y%2==1) return mul(c,mul(c,x));
    else return mul(c,c);
}
int C(int n,int k){
    return mul(  fact[n] , LT( mul(fact[k],fact[n-k]) ,MOD-2   )   );
}

void Doc() {
    fact[0] = 1;
    fr(i,1,1e6){
        fact[i] = mul(fact[i-1],i);
    }

}
void Sol1(){
    while(cin >> n >> a >> b >> d){
        // số cách chọn học sinh của 1 trường : C(b,d)
        // số cách chọn học sinh của a trường : C(b,d)^a
        // chọn chính xác  a trường trong n trường : C(n,a);
        // kết quả : C(b,d)^a * C(n,a);
        int s1 = LT(C(b,d),a);
        int s2 = C(n,a);
        cout << mul(s1,s2) << '\n';
    }


}

void Sol2(){


}
signed main(){
    Boost
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }

    Doc();
    Sol1();
    Sol2();
}


