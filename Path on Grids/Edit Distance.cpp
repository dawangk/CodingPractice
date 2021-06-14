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
 
const ull INF = 0x3f3f3f3f;
const int MM = 1e6+5, mod = 1e9+7;
 
string s1, s2; int dp[5005][5005];
 
int s(int i, int j){
    i--;j--;
    if(s1[i]==s2[j])return 0;
    return 1;
}
 
int main(){
    inputJunk
    //freopen("diamond.in","r", stdin);
    //freopen("diamond.out","w", stdout);
 
    cin>>s1>>s2;
 
 
    for(int i = 0;i<=s1.size();i++){
        for(int j = 0;j<=s2.size();j++){
            if(i==0||j==0){
                dp[i][j] = max(i, j);
            }else{
                dp[i][j] = min(dp[i-1][j]+1, min(dp[i][j-1]+1, dp[i-1][j-1]+ s(i, j)));
            }
        }
    }
 
 
  // for(int i = 0;i<=s1.size();i++){
  //      for(int j = 0;j<=s2.size();j++){
//            cout<<dp[i][j]<<" ";
  //      }cout<<ell;
    //}
    cout<<dp[s1.size()][s2.size()];
}
