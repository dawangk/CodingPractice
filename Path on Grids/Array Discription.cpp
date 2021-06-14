#include <bits/stdc++.h>
using namespace std;
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define f first
#define s second
#define debug cout<<"HERE"<<endl;
#define ell "\n"
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
 
 
const ll INF = 1e9+260;
const int MM = 1e5+5; int mod = 1e9+7;
 
ll n, m, arr[MM], dp[MM][105];
 
int main(){
    inputJunk
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
 
    if(arr[0]==0){
        for(int i = 1;i<=m;i++){
            dp[0][i] = 1;
        }
    }else{
        if(arr[0]>=1&&arr[0]<=m)dp[0][arr[0]] = 1;
    }
 
    for(int i = 1;i<n;i++){
        if(arr[i]==0){
            for(int j = 1;j<=m;j++){
                for(int k: {j-1, j, j+1}){
                    if(k>=1&&k<=m){
                        dp[i][j]+=dp[i-1][k];
                        dp[i][j]%=mod;
                    }
                }
            }
        }else{
            for(int k: {arr[i]-1, arr[i], arr[i]+1}){
                if(k>=1&&k<=m){
                    dp[i][arr[i]]+=dp[i-1][k];
                    dp[i][arr[i]]%=mod;
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 1;i<=m;i++){
        ans+=dp[n-1][i];
        ans%=mod;
    }
    cout<<ans<<ell;
 
}
