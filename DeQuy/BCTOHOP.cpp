#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5 + 5;
int n , q;
int a[N] , b[N] , c[N] , ans[N] , prea[N] , preb[N];
priority_queue < pair < int , int > , vector < pair < int , int > > , greater < pair < int , int > > >  pq;

main()
{
    //freopen("gen.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        prea[i] = prea[i - 1] + a[i];
    }
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> b[i];
        preb[i] = preb[i - 1] + b[i];
    }
    for(int i = 1 ; i <= n ; i++)
        c[i] = a[i] + preb[i - 1];

    /// bài toán thành với mỗi truy vấn cho số x
    /// tìm i đầu tiên thoả mãn x < c[i]
    /// -> trả lời offline, đây các truy vấn vào priority_queue theo x tăng dần,
    /// -> duyệt i từ trái qua phải, check thằng đầu priority_queue có thoả mãn x < c[i]
    /// nếu thoả thì đáp án của thằng x đó là tổng a[1] + ... + a[i - 1] (vì nó không đi được tới ô thứ i)

    for(int i = 1 ; i <= q ; i++)
    {
        int x;
        cin >> x;
        pq.push(pair < int , int > (x , i));
    }
    c[n + 1] = 1e18; /// gán ô (n + 1) để các thằng vượt quá n khi gặp n + 1 đều ngừng
    for(int i = 1 ; i <= n + 1 ; i++)
    {
        while(!pq.empty())
        {
            int cost = pq.top().first;
            int query = pq.top().second;
            if(cost < c[i])
            {
                ans[query] = prea[i - 1];
                pq.pop();
            }
            else
                break;
        }
    }

    for(int i = 1 ; i <= q ; i++)
        cout << ans[i] << "\n";
}
