#include<bits/stdc++.h>

using namespace std;

bool multitest  = 0;

#define         TASK ""
#define         INPUT TASK".INP" 
#define         OUTPUT TASK".OUT"

#define     nhst signed main()
#define         int long long
#define         Boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define         fr(i,a,b) for(int i=a;i<=b;i++)
#define         fd(i,a,b) for(int i=a;i>=b;i--)
#define         fi first
#define         se second
#define         endl '\n'
#define         ii pair<int,int>
#define         pb push_back
#define         vi vector<int>
#define         vii vector<pair<int,int>>


int dx[] = { -1 , 0 , 1 ,  0 };
int dy[] = {  0 , 1 , 0 , -1 };

const int inf = 1e18 , MOD = 1e9+7 , N  = 1e6+5;
const double eps = 1e-8;

int gcd(int a,int b){return __gcd(a,b);}
int bp(int a){return a*a;}
int lcm(int a,int b){return a*b/gcd(a,b);}

int n;

struct DL{
    int x;
    int l;
    int r;
    int type;
} a[N];

struct MySeg{
    int len;// tổng chiều dài bị cả đoạn phủ
    int cnt;// só lượng hcn phủ lên đoạn 
}st[4*N];

int maxi = 0;
int m = 0;
void Doc(){
    cin >> n ;
    fr(i,1,n){

        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        m++;
        a[m] = {x1,y1+1,y2,1};
        m++;
        a[m] = {x2,y1+1,y2,-1};
        maxi = max(maxi,y2);

    }

}

namespace sub{

    void update(int id,int l,int r,int u,int v,int type){
        if (  l > v || r < u ) return ;
        if ( l >= u && r<=v){
            st[id].cnt+=type;
            if(type==1) // ngoặc mở
            {
                st[id].len = r - l + 1;
                // vì đã nằm hoàn toàn thì ngoặc đóng sẽ phủ hết cả đoạn này
            }
            // xét trường hợp ngoặc đóng
            else if(st[id].cnt==0){
                st[id].len = st[id<<1].len + st[id<<1|1].len ;
                //else st[id].len = 0 ;
            }
            return ;
        }
        int mid = (l+r)>>1;
        update(id<<1,l,mid,u,v,type);
        update(id<<1|1,mid+1,r,u,v,type);
        if(st[id].cnt==0 ) st[id].len = st[id<<1].len + st[id<<1|1].len;
        
    }
    void Sol(){
        int ans = 0;

        sort(a+1,a+1+m,[&](DL u,DL v){
            if(u.x==v.x) return u.type < v.type; // để kết thúc HCN sớm khi 2 x bằng nhau
            else return u.x < v.x;
        });

        fr(i,1,m){
            ans+=st[1].len*(a[i].x - a[i-1].x);
            update(1,1,N,a[i].l,a[i].r,a[i].type);
        }
        cout << ans;

    }   

}

nhst{
    Boost
    if(fopen(INPUT,"r") ) {
        freopen(INPUT,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test = 1;
    if(multitest) cin >> test;
    fr(run,1,test){
        Doc();
        sub::Sol();
    }
}