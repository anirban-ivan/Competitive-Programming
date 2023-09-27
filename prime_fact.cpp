const int N=1000005;//change according to upto which number we are to find primes
bool arr[N];
vector<int>prime, tmp;

void sieve()
{
    memset(arr, true, sizeof(arr));
    for(int i=2; i*i<=N; i++) {
        if(arr[i]) {
            for(int j=i*i; j<=N; j+=i) arr[j]=false;
        }
    }
    for(int i=2; i<=N; i++) {
        if(arr[i]) prime.push_back(i);
    }
}

void cnt(int k)//prime_factorization
{
    for(int i=0; i<prime.size() && prime[i]*prime[i]<=k; i++) {
        if(k%prime[i]==0) {
            tmp.pb(prime[i]);
            while(k%prime[i]==0) k/=prime[i];
        }
    }
    if(k>1) tmp.pb(k);
}
