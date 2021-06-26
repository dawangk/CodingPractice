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

const int INF = 1e9+1212;
const ll P = 9973, M = 1e9+9;
const int MM = 504+5; int mod = 1e9+7;//998244353

int n, k, arr[MM], dp[MM][MM];

int main(){
    inputJunk
    freopen("snakes.in","r", stdin);
    freopen("snakes.out","w", stdout);
    cin>>n>>k;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
    }
    int mx = 0, sum = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=k;j++){
            dp[i][j] = INF;
        }
    }
    for(int i = 1;i<=n;i++){
        mx = max(mx, arr[i]);
        sum+=arr[i];
        for(int j = 0;j<=k;j++){
            if(j==0){
                dp[i][j] = mx*i-sum;
            }else{
                int mxx = 0;
                int mxsum = 0; int c = 0;
                for(int k = i;k>=1;k--){
                    c++;
                    mxx = max(mxx, arr[k]);
                    mxsum+=arr[k];
                    dp[i][j] = min(dp[i][j], dp[k-1][j-1]+mxx*c-mxsum);
                }
            }
        }
    }
    cout<<dp[n][k]<<ell;
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
- for dp invalid cases needs to be skipped
- some base cases won't work (review cow poetry)
- always check bounds, some TLE are due to incorrect bounds!
- dont mess up return types
= RESET ARRAYS!!!!!!!!!!
- USE UR BRAIN
*/
/*
    freopen("time.in","r", stdin);
    freopen("time.out","w", stdout);
*/
