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
const int MM = 1e3+5; int mod = 1e9+7;//998244353

int n, arr1[MM],arr2[MM], dp[MM][MM];

bool valid(int a, int b){
    return abs(a-b)<=4;
}

int main(){
    inputJunk
    freopen("nocross.in","r", stdin);
    freopen("nocross.out","w", stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>arr1[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>arr2[i];
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            dp[i][j] = dp[i-1][j-1]+valid(arr1[i], arr2[j]);
            dp[i][j] = max(max(dp[i-1][j],dp[i][j-1]), dp[i][j]);
        }
    }/*
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }cout<<ell;
    }*/
    cout<<dp[n][n]<<ell;

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

