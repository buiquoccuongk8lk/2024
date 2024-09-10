#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 1e6 + 5;

struct FenwickTree
{
    int n, a[N];
    FenwickTree()
    {
        memset(a, 0, sizeof a);
    }

    void Update(int p, int v)
    {
        for (; p <= n; p += p & -p)
            a[p] += v;
    }

    int Get(int p)
    {
        int ans = 0;
        for (; p; p -= p & -p)
            ans += a[p];
        return ans;
    }

    int Get(int l, int r)
    {
        return Get(r) - Get(l - 1);
    }
} f;

int n, q;
vector<int> adj[N];
int a[N];
int in[N], out[N], l;
int par[N][20], ranks[N];

struct com
{
    bool operator()(const int &x, const int &y) const
    {
        return in[x] < in[y];
    }
};

multiset<int, com> s[N];

void Read()
{
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    cin >> q;
}

void dfs(int v, int p = -1)
{
    in[v] = ++l;

    for (int i = 1; i < 20; ++i)
        par[v][i] = par[par[v][i - 1]][i - 1];

    for (auto i : adj[v])
        if (i != p)
        {
            par[i][0] = v;
            ranks[i] = ranks[v] + 1;
            dfs(i, v);
        }

    out[v] = l;
}

int LCA(int u, int v)
{
    if (ranks[u] < ranks[v])
        swap(u, v);

    for (int i = 19; ~i; --i)
        if (ranks[par[u][i]] >= ranks[v])
            u = par[u][i];

    for (int i = 19; ~i; --i)
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }

    return u == v ? u : par[u][0];
}

void Add(int x, int v)
{
    auto i = s[x].lower_bound(v);
    auto j = prev(i);
    f.Update(in[LCA(*i, *j)], 1);

    f.Update(in[v], 1);
    f.Update(in[LCA(*i, v)], -1);
    f.Update(in[LCA(v, *j)], -1);

    s[x].insert(v);
}

void Erase(int x, int v)
{
    auto i = s[x].lower_bound(v);
    assert(i != s[x].end() && *i == v);

    auto t = prev(i),
         j = next(i);

    f.Update(in[v], -1);
    f.Update(in[LCA(v, *j)], 1);
    f.Update(in[LCA(*t, v)], 1);

    f.Update(in[LCA(*j, *t)], -1);

    s[x].erase(i);
}

void Solve()
{
    adj[n + 1].emplace_back(1);
    adj[n + 1].emplace_back(n + 2);
    ranks[n + 1] = 1;
    dfs(n + 1);

    f.n = l;

    for (int i = 0; i < N; ++i)
    {
        s[i].insert(n + 2);
        s[i].insert(n + 1);
    }

    for (int i = 1; i <= n; ++i)
        if (a[i] != -1)
            Add(a[i], i);

    int ans = 0;

    q *= 2;

    while (q--)
    {
        string s;
        int u, v;
        cin >> s >> u >> v;

        if (s == "BLOOM")
            Add(u ^ ans, v ^ ans);
        else if (s == "DISSOLVE")
            Erase(u ^ ans, v ^ ans);
        else
        {
            if (ranks[u] < ranks[v])
                swap(u, v);

            cout << (ans = f.Get(in[u], out[u])) << "\n";
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Read();
    Solve();
}
