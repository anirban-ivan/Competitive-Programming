const int N=100005;//change accordingly
const int MOD=1e9+7;
inline void normal(int &a) { if (a >= MOD) a %= MOD; (a < 0) && (a += MOD); }
inline int mmul(int a, int b) {normal(a), normal(b); return (a*b)%MOD; }
inline int madd(int a, int b) {normal(a), normal(b); return (a+b)%MOD; }
inline int msub(int a, int b) {normal(a), normal(b); a -= b; normal(a); return a; }
inline int mpow(int b, int p) { int r = 1; while(p) { if(p&1) r = mmul(r, b); b = mmul(b, b); p >>= 1; } return r; }
inline int minv(int a) { return mpow(a, MOD-2); }
inline int mdiv(int a, int b) { return mmul(a, minv(b)); }
