/***************************************************************
*        User :Bui Quoc Cuong aka WatborInDaHood               *
*                   Age :15 -2k8                               *
*      School : 10Ti Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
*             Truoc Khi Em Ton Tai...?                         *
*   https://www.facebook.com/profile.php?id=1000...99784529    *
****************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define goi5gviettel ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define fr(i,a,b) for(i=a;i<=b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define lb lower_bound
#define up upper_bound
ll m,c,n,j,k,x,y,z,t,l,r;ll maxx=-2e9;ll minn=2e9;
const ll SIZE =1e7;
//ll mi[10000000];
//ll ma[10000000];
//ll ps[1000000];
//ll a[SIZE];
//ll b[SIZE];
//ll dp[SIZE];
ll gcd(ll a,ll b) {ll temp;while(b!=0) {temp = a%b;a=b;b=temp;}return a;}
ll lcm(ll a,ll b) {return a/gcd(a,b) *b;}
/*ll prime[1000007];const ll N =1000007;ll cnt=1;
void Sang() {
    for(i=2;i<=N;i++) {
        prime[i] = 1;
    }
    prime[1]=prime[0] =0;
    for(i=2;i<=sqrt(N);i++) {
        if(prime[i]==1){
            for(j=i*i;j<=N;j+=i) {
                prime[j] =0;}
        }   
    }
    fr(i,1,N){
        if(prime[i]){
            b[cnt++] = i;
        }
    }
}*/
ll i;
ll dp[SIZE];
void Doc() {
    cin >> n;
}
void Sol(){
    dp[0] = 3;
    dp[1] = 10;
    fr(i,2,1e7){
        dp[i] = dp[i-1] + dp[i-1] + i+3;
        cout << dp[i] ;
    }

}
    
void LamMau(){
    cerr<< endl<<  "Time:" <<" " << 0.001*clock() << "s" << endl;
    cerr<< " WatborInDaHood " << endl; 
}
int main(){
    goi5gviettel
    /*if(fopen("Watbor.inp","r")){
        freopen("Watbor.inp","r",stdin);
        freopen("Watbor.out","w",stdout);
    }*/
    Doc();
    Sol();
    LamMau();
}