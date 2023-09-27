const int N=100005;//change accordingly
vector<int>adj[N];
int lg, sub[N], par[N][20], dep[N], head[N], ind[N], pos[N], base[N], tree[4*N], ptr, cnt, ar[N];

//LCA
void dfs(int node, int p)
{
    par[node][0]=p;
    sub[node]=1;
    for(int i=0; i<adj[node].size(); i++) {
        if(adj[node][i]==p) continue;
        dep[adj[node][i]]=dep[node]+1;
        dfs(adj[node][i], node);
        sub[node]+=sub[adj[node][i]];
    }
}

int lca(int a, int b)
{
    if(dep[b]>dep[a]) swap(a, b);
    for(int i=lg; i>=0; i--) {
        if(dep[a]-(1<<i)>=dep[b]) a=par[a][i];
    }
    if(a==b) return a;
    if(a!=b) {
        for(int i=lg; i>=0; i--) {
            if(par[a][i]!=-1 && par[a][i]!=par[b][i]) {
                a=par[a][i];
                b=par[b][i];
            }
        }
    }
    return par[a][0];
}

void sp_table(int n)
{
    for(int j=1; (1<<j)<n; j++) {
        for(int i=1; i<=n; i++) {
            if(par[i][j-1]!=-1) par[i][j]=par[par[i][j-1]][j-1];
        }
    }
}

//Seg Tree
void make(int node, int b, int e)
{
    if(b==e) {
        tree[node]=base[b];
        return;
    }
    int l=node*2;
    int r=node*2+1;
    int mid=(b+e)/2;
    make(l, b, mid);
    make(r, mid+1, e);
    tree[node]=tree[l]+tree[r];
}

void upd(int node, int b, int e, int i, int val)
{
    if(e<i || b>i) return;
    if(b>=i && e<=i) {
        tree[node]=val;
        return;
    }
    int l=node*2;
    int r=node*2+1;
    int mid=(b+e)/ 2;
    upd(l, b, mid, i, val);
    upd(r, mid+1, e, i, val);
    tree[node]=tree[l]+tree[r];
}

int query(int node, int b, int e, int i, int j)
{
    if(e<i || b>j) return 0;
    if(b>=i && e<=j) return tree[node];
    int l=node*2;
    int r=node*2+1;
    int mid=(b+e)/2;
    int p1=query(l, b, mid, i, j);
    int p2=query(r, mid+1, e, i, j);
    return p1+p2;
}

//HLD
void hld(int node, int par, int cost)
{
    if(head[cnt]==-1) head[cnt]=node;
    ind[node]=cnt;
    pos[node]=ptr;
    base[ptr++]=ar[node];
    int sc=-1, ncost;
    for(int i=0; i<adj[node].size(); i++) {
        if(adj[node][i]!=par && (sc==-1 || sub[sc]<sub[adj[node][i]])) {
            sc=adj[node][i];
            ncost=adj[node][i];
        }
    }
    if(sc!=-1) hld(sc, node, ncost);
    for(int i=0; i<adj[node].size(); i++) {
        if(adj[node][i]!=par && sc!=adj[node][i]) {
            cnt++;
            hld(adj[node][i], node, adj[node][i]);
        }
    }
}

int query_up(int u, int v, int n)
{
    int uchain, vchain=ind[v], ans=0;
    while(1) {
        uchain=ind[u];
        if(uchain==vchain) {
            ans+=query(1, 0, n-1, pos[v], pos[u]);
            break;
        }
        ans+=query(1, 0, n-1, pos[head[uchain]], pos[u]);
        u=head[uchain];
        u=par[u][0];
    }
    return ans;
}

void clr(int n)
{
    for(int i=0; i<=n; i++) {
        adj[i].clear();
        head[i]=-1;
        for(int j=0; j<=lg; j++) par[i][j]=-1;
    }
}
