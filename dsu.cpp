int findp(int node)
{
    if(p[node]==node) return node;
    return p[node]=findp(p[node]);
}

void uni(int a, int b)
{
    int pa=findp(a);
    int pb=findp(b);
    if(pa!=pb) {
        if(sz[pa]<sz[pb]) swap(pa, pb);
        p[pb]=pa;
        sz[pa]+=sz[pb];
        mx[pa]=max(mx[pa], mx[pb]);
        mn[pa]=min(mn[pa], mn[pb]);
    }
}
