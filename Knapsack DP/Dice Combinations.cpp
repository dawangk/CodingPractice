#include <bits/stdc++.h>
using namespace std;
#define inputJunk cin.sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define f first
#define s second
#define debug cout<<"HERE"<<endl;
#define ell "\n"
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
 
const int INF = 0x3f3f3f3f;
const ll MM = 1e6+5; ull mod = 1e9+7;
 
ll n, dp[MM];
int main(){
    inputJunk
    //freopen("diamond.in","r", stdin);
    //freopen("diamond.out","w", stdout);
 
    cin>>n;
 
 
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;
 
    for(int i = 7;i<=n;i++){
        dp[i]+= dp[i-1];
        dp[i]%=mod;
        dp[i]+= dp[i-2];
        dp[i]%=mod;
        dp[i]+= dp[i-3];
        dp[i]%=mod;
        dp[i]+= dp[i-4];
        dp[i]%=mod;
        dp[i]+= dp[i-5];
        dp[i]%=mod;
        dp[i]+= dp[i-6];
        dp[i]%=mod;
    }
 
    cout<<dp[n]<<ell;
}
