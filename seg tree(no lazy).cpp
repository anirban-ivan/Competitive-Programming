const int N=200005;
int ar[N], tree[4*N];

void make(int node, int b, int e)
{
    if(b==e) {
        tree[node]=ar[b];
        return;
    }
    int l=node*2, r=node*2+1, mid=(b+e)/2;
    make(l, b, mid);
    make(r, mid+1, e);
    tree[node]=tree[l]+tree[r];//change according to ques
}

void upd(int node, int b, int e, int i, int j, int val)
{
    if(e<i || b>j) return;
    if(b>=i && e<=j) {
        tree[node]=val;
        return;
    }
    int l=node*2, r=node*2+1, mid=(b+e)/2;
    upd(l, b, mid, i, j, val);
    upd(r, mid+1, e, i, j, val);
    tree[node]=tree[r]+tree[l];
}

int query(int node, int b, int e, int i, int j)
{
    if(e<i || b>j) return 0;
    if(b>=i && e<=j) return tree[node];
    int l=node*2, r=node*2+1, mid=(b+e)/2;
    int p1=query(l, b, mid, i, j);
    int p2=query(r, mid+1, e, i, j);
    return p1+p2;
}
