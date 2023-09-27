#include <bits/stdc++.h>
using namespace std;
const int N=200005;
struct edge {
    int u, v, w;
    edge(int a, int b, int c) {
        u=a;
        v=b;
        w=c;
    }
};

bool cmp(edge a, edge b) {
    return a.w<b.w;
}

vector<edge>e;
int par[N], n;

int fnd(int node)
{
    if(par[node]==node) return node;
    return par[node]=fnd(par[node]);
}

int mst()
{
    sort(e.begin(), e.end(), cmp);
    for(int i=1; i<=n; i++) par[i]=i;
    int ans=0;
    for(int i=0; i<e.size(); i++) {
        int p1=fnd(e[i].u);
        int p2=fnd(e[i].v);
        if(p1!=p2) {
            par[p1]=p2;
            cnt+=e[i].w;
        }
    }
    return cnt;
}

main()
{
    int m, a, b, c;
    cin>>n>>m;
    for(int i=0; i<m; i++) {
        cin>>a>>b>>c;
        e.push_back(edge(a, b, c));
    }
    cout<<mst();
}
