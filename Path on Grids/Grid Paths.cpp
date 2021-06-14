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
const ll MM = 1e3+5; ull mod = 1e9+7;
 
ll n, dp[MM][MM]; char grid[MM][MM];
int main(){
    inputJunk
    //freopen("diamond.in","r", stdin);
    //freopen("diamond.out","w", stdout);
    cin>>n;
 
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=n;j++){
            if(i==0||j==0){
                grid[i][j] = '.';
            }else{
                cin>>grid[i][j];
            }
        }
    }
    if(grid[1][1]=='.')dp[1][1] = 1;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i==1&&j==1)continue;
            if(grid[i][j]=='.'){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
                dp[i][j]%=mod;
            }
        }
    }
    cout<<dp[n][n]<<ell;
}
