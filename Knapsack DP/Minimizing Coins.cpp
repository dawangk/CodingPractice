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
 
ll n,k,c[101], dp[MM];
int main(){
    inputJunk
    //freopen("diamond.in","r", stdin);
    //freopen("diamond.out","w", stdout);
 
    cin>>n>>k;
    memset(dp, INF, sizeof(dp));
    for(int i = 0;i<n;i++){
        cin>>c[i];
        dp[c[i]] = 1;
    }
    for(int i = 1;i<=k;i++){
        if(dp[i]==1)continue;
        for(int j = 0;j<n;j++){
            if(i>c[j]&&(dp[i-c[j]]+1<dp[i])){
                dp[i] = dp[i-c[j]]+1;
                dp[i]%mod;
            }
        }
    }
    if(dp[k]%mod==896814407)cout<<-1<<ell;
    else cout<<dp[k]%mod<<ell;
}
