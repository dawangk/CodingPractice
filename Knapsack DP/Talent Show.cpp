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
const int MM = 1e3+5; int mod = 1e9+7;//998244353

int n, w, arr1[MM],arr2[MM];
ll dp[MM];

bool valid(int x){
    for(int i = 0;i<=w;i++){
        dp[i] = -INF;
    }
    dp[0] = 0;
    for(int i = 0;i<n;i++){
        ll val = 1000*(ll)arr2[i]-(ll)arr1[i]*x;
        for(int k = w;k>=0;k--){
            int kk = min(w, k+arr1[i]);
            if(dp[k]!=-INF){
                if (dp[kk] < dp[k] + val) {
                    dp[kk] = dp[k] + val;
                }
            }
        }
    }
    //for(int i = 0;i<=w;i++)cout<<dp[i]<<" ";
    //cout<<endl;
    return dp[w]>=0;
}

int main(){
    inputJunk
    freopen("talent.in","r", stdin);
    freopen("talent.out","w", stdout);
    cin>>n>>w;
    for(int i = 0;i<n;i++){
        cin>>arr1[i]>>arr2[i];
    }
    //cout<<boolalpha;
    int lo = 0;
    int hi = (250*1000*1000)+1;
    while(hi>lo+1){
        int mid = (hi+lo)/2;
        //cout<<mid<<" "<<valid(mid)<<endl;
        if(valid(mid)){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    cout<<lo<<ell;
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

//freopen("time.in","r", stdin);
//freopen("time.out","w", stdout);

