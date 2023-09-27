#include <bits/stdc++.h>
using namespace std;
int n, m;
#define pii pair<int, int>
const int inf=1000005;
vector<int>adj[100005], cost[100005];
int dis[100005], bef[100005];

void dij()
{
    //vector<int>v;
    priority_queue<pii, vector<pii>, greater<pii> >pq;
    pq.push(make_pair(0, 1));
    memset(dis, inf,sizeof(dis));
    dis[1]=0;
    while(!pq.empty()) {
        int n=pq.top().second;
        int d=pq.top().first;
        //cout<<n<<endl;
        pq.pop();
        for(int i=0; i<adj[n].size(); i++) {
            int nd=adj[n][i];
            //cout<<d<<" "<<cost[n][i]<<" "<<adj[n][i]<<endl;
            if(dis[n]+cost[n][i]<dis[nd]) {
                bef[nd]=n;
                dis[nd]=dis[n]+cost[n][i];
                pq.push(make_pair(dis[nd], nd));
            }
        }
    }
}

int main()
{
    int a, b, w;
    cin>>n>>m;
    while(m--) {
        cin>>a>>b>>w;
        adj[a].push_back(b);
        adj[b].push_back(a);
        cost[a].push_back(w);
        cost[b].push_back(w);
    }
    dij();
}
