const int N=200005;
int ar[N];

struct info {
    int lazy, sum;
};
info tree[N*4];

void prop(int node, int b, int e)
{
    tree[node].sum+=(e-b+1)*tree[node].lazy;
    if(b!=e) {
        tree[node*2].lazy+=tree[node].lazy;
        tree[node*2+1].lazy+=tree[node].lazy;
    }
    tree[node].lazy=0;
}

void make(int node, int b, int e)
{
    if(b==e) {
        tree[node].sum=ar[b];
        tree[node].lazy=0;
        return;
    }
    int l=node*2, r=node*2+1, mid=(b+e)/2;
    make(l, b, mid);
    make(r, mid+1, e);
    tree[node].sum=tree[l].sum+tree[r].sum;//change according to ques
    tree[node].lazy=0;
}

void upd(int node, int b, int e, int i, int j, int val)
{
    if(tree[node].lazy) prop(node, b, e);
    if(e<i || b>j) return;
    if(b>=i && e<=j) {
        tree[node].lazy+=val;
        if(tree[node].lazy) prop(node, b, e);
        return;
    }
    int l=node*2, r=node*2+1, mid=(b+e)/2;
    upd(l, b, mid, i, j, val);
    upd(r, mid+1, e, i, j, val);
    tree[node].sum=tree[r].sum+tree[l].sum;
}

int query(int node, int b, int e, int i, int j)
{
    if(tree[node].lazy) prop(node, b, e);
    if(e<i || b>j) return 0;
    if(b>=i && e<=j) return tree[node].sum;
    int l=node*2, r=node*2+1, mid=(b+e)/2;
    int p1=query(l, b, mid, i, j);
    int p2=query(r, mid+1, e, i, j);
    return p1+p2;
}
