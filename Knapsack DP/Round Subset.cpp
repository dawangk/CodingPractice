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
const int MM = 200+5; int mod = 1e9+7;//998244353

int n, k, two[MM], five[MM], dp[MM][7070], nex[MM][7070];
int ans = 0;
int main(){
    inputJunk
    cin>>n>>k;
    for(int i = 0;i<n;i++){
        ll a; cin>>a;
        while(a%2==0){two[i]++; a/=2;}
        while(a%5==0){five[i]++; a/=5;}
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int a = 0;a<n;a++){
        for(int i = 0;i<=k;i++)
            for(int j = 0;j<7000;j++)
                nex[i][j] = -1;
        for(int i = 0;i<=min(a+1,k);i++){
            for(int j = 0;j<7000;j++){
                if(dp[i][j]!=-1){
                    nex[i][j] = max(nex[i][j], dp[i][j]);
                    nex[i+1][j+five[a]] = max(nex[i+1][j+five[a]], dp[i][j]+two[a]);
                }
            }
        }
        /*cout<<a<<ell;
        for(int i = 0;i<=k;i++){
            for(int j = 0;j<18;j++){
                cout<<nex[i][j]<<" ";
            }cout<<ell;
        }*/
        for(int i = 0;i<=k;i++)
            for(int j = 0;j<7000;j++)
                dp[i][j] = nex[i][j];
    }
    for(int i = 0;i<7000;i++){
        ans = max(ans, min(dp[k][i], i));
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

