const int N=100005;//change accordingly
vector<int>adj[N];
int lg, par[N][20], dep[N];

void dfs(int node, int p)
{
    par[node][0]=p;
    for(int i=0; i<adj[node].size(); i++) {
        if(adj[node][i]==p) continue;
        dep[adj[node][i]]=dep[node]+1;
        dfs(adj[node][i], node);
    }
}

int lca(int a, int b)
{
    if(dep[b]>dep[a]) swap(a, b);
    for(int i=lg; i>=0; i--) {//define lg
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

int kth_anstr(int a, int kth)
{
    int koto=dep[a]-kth;
    for(int i=lg; i>=0; i--) {//define lg
        if(dep[a]-(1<<i)>=koto) {
            a=par[a][i];
        }
    }
    return a;
}

void sp_table(int n)
{
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=lg; j++) par[i][j]=-1;
    }
    for(int j=1; (1<<j)<n; j++) {
        for(int i=1; i<=n; i++) {
            if(par[i][j-1]!=-1) par[i][j]=par[par[i][j-1]][j-1];
        }
    }
}

