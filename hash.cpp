#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(a) cerr<<#a<<" --> "<<(a)<<endl;
#define int long long
#define pii make_pair
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define endl "\n"
int ceil(int a, int b) { if(a%b==0) return a/b; else return a/b+1; }
bool checkbit(int pos, int mask) { return mask&(1LL<<pos); }
int turnon(int pos, int mask) { return mask|(1LL<<pos); }
const int N=1505;
int mod[]={1000000007, 1000000009};
int bases[]={137, 281};
int pw[3][N], ph[3][N];

void pre()
{
    pw[0][0]=pw[1][0]=1;
    for(int i=0; i<2; i++) {
        for(int j=1; j<N; j++) {
            pw[i][j]=(pw[i][j-1]*bases[i])%mod[i];
        }
    }
}

void build_hash(string &s)
{
    int n=s.size();
    ph[0][n]=0;
    ph[1][n]=0;
    for(int i=n-1; i>=0; i--) {
        for(int j=0; j<2; j++) {
            ph[j][i]=(ph[j][i+1]*bases[j]+s[i]-'a'+1)%mod[j];
            ph[j][i]=(ph[j][i]+mod[j])%mod[j];
        }
    }
}

pair<int, int>get_hash(int i, int j)///0 based indexing
{
    int t1=ph[0][i]-(ph[0][j+1]*pw[0][j-i+1]%mod[0])%mod[0];
    int t2=ph[1][i]-(ph[1][j+1]*pw[1][j-i+1]%mod[1])%mod[1];
    if(t1<0) t1+=mod[0];
    if(t2<0) t2+=mod[1];
    return pii(t1, t2);
}

main()
{
    fastio;
    pre();
    string s, lt;
    set<pair<int, int> >st;
    int k;
    cin>>s>>lt>>k;
    build_hash(s);
    for(int i=0; i<(int)s.size(); i++) {
        int cnt=0;
        for(int j=i; j<(int)s.size(); j++) {
            if(lt[s[j]-'a']=='0') cnt++;
            if(cnt>k) break;
            st.insert(get_hash(i, j));
        }
    }
    cout<<st.size();
}
