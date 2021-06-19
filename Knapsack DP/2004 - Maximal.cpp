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

const int INF = 1e9+250;
const ll P = 9973, M = 1e9+9;
const int MM = 1e4+5; int mod = 1e9+7;//998244353

int n;
double mem[MM][77];
bool v[MM][77];
int dp[MM][77];
vi primes = { 2,   3,   5,   7,   11,  13,  17,  19,  23,  29,
             31,  37,  41,  43,  47,  53,  59,  61,  67,  71,
           73,  79,  83,  89,  97,  101, 103, 107, 109, 113,
           127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
           179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
           233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
           283, 293, 307, 311, 313, 317, 331, 337, 347, 349
};

double dpp(int cur, int pos){
    if(pos==primes.size()||primes[pos]>cur)return 0;
    if(v[cur][pos])return mem[cur][pos];

    double ans = dpp(cur, pos+1);
    dp[cur][pos] = 0;
    for(int pp = primes[pos], expo = 1; pp<=cur; pp*=primes[pos], expo++){
        double pot = expo*log(primes[pos])+dpp(cur-pp, pos+1);
        if(ans<pot){
            ans=pot;
            dp[cur][pos] = pp;
        }
    }

    v[cur][pos] = true;
    return mem[cur][pos] = ans;
}

int main(){
    inputJunk
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        dpp(n, 0);
        vi ans;
        for(int i = 0;i<primes.size();n-=dp[n][i++]){
            if(dp[n][i])ans.pb(dp[n][i]);
        }
        while(n--){
            ans.pb(1);
        }
        sort(all(ans));
        for(int i = 0, j = 1;i<ans.size(); j+=ans[i++]){
            for(int d = 1;d<ans[i];d++)cout<<d+j<<" ";
            cout<<j<<" ";
        }cout<<ell;
    }
}
/*Comments of Shame
- floating error (use integer division instead)
- cin vs getline
- upperbound and lowerbound returns iterators
- use long long when number is big enough
- for dp invalid cases needs to be skipped
- some base cases won't work (review cow poetry)
- always check bounds, some TLE are due to incorrect bounds!
- dont mess up return types
- USE UR BRAIN
*/

/*CUSTOM TEST CASE 1
*/

/*CUSTOM TEST CASE 2

*/

/*CUSTOM TEST CASE 3
*/



//freopen("time.in","r", stdin);
//freopen("time.out","w", stdout);

