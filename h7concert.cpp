#include <bits/stdc++.h>
using namespace std ; 
#define int long long
#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

const int maxn = 2e5 + 5 ;
const ll inf = 1e18 ; 

int n ; 
struct BG {
    int x , w , d ; 
} a[maxn] ; 

namespace sub1 {

    ll calc(ll i) {
        ll sum = 0 ;
        FOR(j,1,n) {
            if(a[j].x <= i) {
                if( i - a[j].x > a[j].d ) {
                    sum+= ( i - a[j].d - a[j].x ) * a[j].w ; 
                }
            } else {
                if( a[j].x - i > a[j].d ) {
                    sum+= ( a[j].x - i - a[j].d  ) * a[j].w ; 
                }
            }
        }
        return sum ; 
    }

    void solve(void) {
        
        sort(a+1,a+1+n,[](BG u,BG v) {
            return u.x < v.x ; 
        }) ;  

        ll ans = inf ;

        FOR(i,1,n) {
            ll vt = a[i].x ;
            ans = min(ans,calc(vt)) ; 
            vt = a[i].x - a[i].d ; 
            ans = min(ans,calc(vt)) ; 
            vt = a[i].x + a[i].d ;
            ans = min(ans,calc(vt)) ;  
        }

        cout << ans ; 
    }

}

namespace sub2 {

    unordered_map<int,int> pos ;
    int VAL ;

    struct Node {
        ll sum1 ; 
        ll sum2 ; 
        friend Node operator + (Node a,Node b) {
            Node ans ; 
            ans.sum1 = a.sum1 + b.sum1 ; 
            ans.sum2 = a.sum2 + b.sum2 ; 
            return ans ; 
        }
    } ; 

    Node st[4*(int)3e5][3] ; 

    void update(int id,int l,int r,int pos,ll val1,ll val2,int t) {
        if(pos < l or pos > r) return ; 
        if(l==r) {
            st[id][t].sum1+= val1 ;
            st[id][t].sum2+= val2 ; 
            return ; 
        }
        int mid = (l+r)>>1 ; 
        if(pos <= mid) update(id<<1,l,mid,pos,val1,val2,t) ;
        else update(id<<1|1,mid+1,r,pos,val1,val2,t) ;
        st[id][t] = st[id<<1][t] + st[id<<1|1][t] ; 
    }

    Node get(int id,int l,int r,int u,int v,int t) {
        if(l > v or r < u) return { 0 , 0 } ; 
        if(l >= u and r <= v) return st[id][t] ; 
        int mid = (l+r)>>1 ; 
        return get(id<<1,l,mid,u,v,t) + get(id<<1|1,mid+1,r,u,v,t) ; 
    }

    ll calc(ll VT) {

        Node getL = get(1,1,VAL,1,pos[VT]-1,1) ; 
        ll sumL = VT * getL.sum1 - getL.sum2 ; 

        Node getR = get(1,1,VAL,pos[VT]+1,VAL,2) ; 
        ll sumR = -VT * getR.sum1 + getR.sum2 ; 

        return sumL + sumR ; 
    }


    void solve(void) {

        vector<int> vec ; 

        FOR(i,1,n) {
            vec.pb(a[i].x + a[i].d) ; 
            vec.pb(a[i].x) ; 
            vec.pb(a[i].x - a[i].d) ; 
        }

        sort(all(vec)) ; 

        vec.resize(unique(all(vec))-vec.begin()) ; 

        FOR(i,0,(int)vec.size()-1) {
            pos[vec[i]] = i + 1 ; 
        }

        VAL = vec.size() ;          

        FOR(i,1,n) {
            update(1,1,VAL,pos[a[i].x+a[i].d],a[i].w,a[i].w*(a[i].d + a[i].x),1) ; 
            update(1,1,VAL,pos[a[i].x-a[i].d],a[i].w,a[i].w*(a[i].x - a[i].d),2) ; 
        }

        ll ans = inf ;  

        sort(a+1,a+1+n,[](BG u,BG v) {
            return u.x < v.x ; 
        }) ;

        FOR(i,1,n) {
            ll vt = a[i].x ; 
            ans = min(ans,calc(vt)) ; 
            vt = a[i].x + a[i].d ; 
            ans = min(ans,calc(vt)) ; 
            vt = a[i].x - a[i].d ; 
            ans = min(ans,calc(vt)) ; 
        }
        
        cout << ans ;
    }
}


namespace sub3 {

    unordered_map<int,int> pos ;
    int VAL ;

    struct Data {
        ll sum1 ; 
        ll sum2 ; 
    } bit[3*maxn][3] ;

    void up(int u,ll val1,ll val2,int t) {
        for(int i(u) ; i <= VAL ; i+=i&-i) {
            bit[i][t].sum1+=val1 ; 
            bit[i][t].sum2+=val2 ; 
        }
    }

    Data get(int u,int t) {
        ll ret1 = 0 , ret2 = 0 ; 
        for(int i(u) ; i ; i-=i&-i) {
            ret1+= bit[i][t].sum1 ; 
            ret2+= bit[i][t].sum2 ; 
        }
        return {ret1 , ret2} ; 
    }

    Data get(int l,int r,int t) {
        ll ret1 = get(r,t).sum1 - get(l-1,t).sum1 ;
        ll ret2 = get(r,t).sum2 - get(l-1,t).sum2 ; 
        return {ret1 , ret2} ;  
    }


    ll calc(ll VT) {
        Data getL = get(1,pos[VT]-1,1) ; 
        ll sumL = VT * getL.sum1 - getL.sum2 ; 

        Data getR = get(pos[VT]+1,VAL,2) ; 
        ll sumR = -VT * getR.sum1 + getR.sum2 ; 

        return sumL + sumR ; 
    }


    void solve(void) {

        vector<int> vec ; 

        FOR(i,1,n) {
            vec.pb(a[i].x + a[i].d) ; 
            vec.pb(a[i].x) ; 
            vec.pb(a[i].x - a[i].d) ; 
        }

        sort(all(vec)) ; 

        vec.resize(unique(all(vec))-vec.begin()) ; 

        FOR(i,0,(int)vec.size()-1) {
            pos[vec[i]] = i + 1 ; 
        }

        VAL = vec.size() ;          

        FOR(i,1,n) {
            up(pos[a[i].x+a[i].d],a[i].w,a[i].w*(a[i].d + a[i].x),1) ; 
            up(pos[a[i].x-a[i].d],a[i].w,a[i].w*(a[i].x - a[i].d),2) ; 
        }

        ll ans = inf ;  

        sort(a+1,a+1+n,[](BG u,BG v) {
            return u.x < v.x ; 
        }) ;

        FOR(i,1,n) {
            ll vt = a[i].x ; 
            ans = min(ans,calc(vt)) ; 
            vt = a[i].x + a[i].d ; 
            ans = min(ans,calc(vt)) ; 
            vt = a[i].x - a[i].d ; 
            ans = min(ans,calc(vt)) ; 
        }
        
        cout << ans ;
    }
}


signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    cin >> n ; 
    FOR(i,1,n) cin >> a[i].x >> a[i].w >> a[i].d ; 
    if(n <= 1e4) sub1::solve() ; 
    else if(n <= 1e5) sub2::solve() ;
    else sub3::solve() ;  
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}