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
const ll MM = 2e5+5, mod = 1e9+7;
 
int n, arr[MM], cnt[MM*5], ans = 1;
 
int main(){
    inputJunk
    //freopen("diamond.in","r", stdin);
    //freopen("diamond.out","w", stdout);
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    for(int i = 0;i<n;i++){
        int cur = arr[i];
        for(int k = 1;k<=sqrt(cur);k++){
            if(cur%k==0){
                cnt[k]++;
                if(k!=sqrt(cur))cnt[cur/k]++;
            }
        }
    }
 
    for(int i = 1000000;i>=1;i--){
        if(cnt[i]>=2){cout<<i<<ell;break;}
    }
 
}
