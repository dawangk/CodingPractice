#include <bits/stdc++.h>
using namespace std;
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define debug cout<<"HERE"<<endl;
#define ell "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<pi, int> trip;
typedef pair<pll, ll> tripll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<trip> vtrip;

const ll INF = 1e15+250;
const ll P = 9973, M = 1e9+9;
const int MM = 1e6+5; int mod = 1e9+7;//998244353

ll frac[2*MM], inv[MM], ans = 0;

ll add (ll a, ll b){
    while(a<0)a+=mod;
    while(b<0)b+=mod;
    return (a+b)%mod;
}

ll mult (ll a, ll b){
    return (a%mod*b%mod)%mod;
}

ll binpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = mult(res, a);
		a = mult(a, a);
		b >>= 1;
	}
	return res;
}

ll nCk (ll a, ll b){
    if(b>a)return 0;
    return mult(frac[a], mult(inv[b], inv[a-b]));
}

int main(){
    inputJunk
    int n; cin>>n;
    frac[0] = 1;
    for(int i = 1;i<=2*n;i++){
        frac[i] = mult(frac[i-1], i);
    }
    for(int i = 0;i<=n;i++){
        inv[i] = binpow(frac[i], mod-2);
    }
    ll v = 1;
    for(int i = 0;i<=2*n;i+=1){
        ans = add(ans, v);
        v = add(mult(2, v), mult(-2, nCk(i, n)));
    }
    cout<<ans<<ell;
}



/*CUSTOM TEST CASE 1
*/

/*CUSTOM TEST CASE 2

*/

/*CUSTOM TEST CASE 3

*/
/*Comments of Shame
- floating error (use integer division instead)
- cin vs getline
- upperbound and lowerbound returns iterators
- use long long when number is big enough
*/

//freopen("time.in","r", stdin);
//freopen("time.out","w", stdout);

