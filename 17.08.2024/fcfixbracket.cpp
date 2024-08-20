#include <bits/stdc++.h>

using namespace std;

struct node {
    long type;
    long len;
    node() {

    }
    node(long t, long l) {
        type = t;
        len = l;
    }
};

long t, q, n;
string str;

node segTree[4194304];

// the cost to make the string is the half of size of final stack
// if the first of

node combine(node a, node b) {
    if(a.len == 0) return b;
    if(b.len == 0) return a;

    bool lastA = a.type;
    if((a.len % 2) == 0) 
        lastA = !lastA;

    if(lastA != b.type)
        return node(a.type, a.len + b.len);

    if(a.len >= b.len) 
        return node(a.type, a.len - b.len);

    bool lastB = b.type;
    if((a.len % 2)) 
        lastB = !lastB;
    return node(lastB, b.len - a.len);
}

void build(long id, long l, long r) {
    if(l == r) {
        if(str[l] == '(' || str[l] == ')') segTree[id] = node(0, 1);
        else segTree[id] = node(1, 1);
        return ;
    }

    long mid = (l + r) / 2;

    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    segTree[id] = combine(segTree[id * 2], segTree[id * 2 + 1]);
}

node get(long id, long l, long r, long u, long v) {
    if(v < l || r < u) 
    {
        return node(-1, 0);
    }

    if(u <= l && r <= v) return segTree[id];

    long mid = (l + r) / 2;

    return combine(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--) {
        cin >> n >> q;
        cin >> str;
        build(1, 0, str.size() - 1);
        while(q--) {
            long L, R;
            cin >> L >> R; L--; R--;
            long tmp = get(1, 0, str.size() - 1, L, R).len;
            cout << (tmp + tmp % 2) / 2 << "\n";
        }
    }
    return 0;
}