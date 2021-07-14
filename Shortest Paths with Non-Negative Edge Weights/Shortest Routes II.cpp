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
 
const ll INF = 1e15+1;
const int MM = 505, mod = 1e9+7;
 
ll n, m, q, arr[MM][MM];
 
int main(){
    inputJunk
    //freopen("poopoo.in","r", stdin);
    //freopen("poopoo.out","w", stdout);
    cin>>n>>m>>q;
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=n;j++)
            arr[i][j] = INF;
    }
 
    for(int i = 0;i<=n;i++){
        arr[i][i] = 0;
    }
 
    for(int i = 0;i<m;i++){
        int a, b, c;cin>>a>>b>>c;
        arr[a][b]=min(arr[a][b],(ll)c);
        arr[b][a]=min(arr[b][a],(ll)c);
    }
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j]);
            }
        }
    }
    //for(int i = 1;i<=n;i++){
    //    for(int j = 1;j<=n;j++){
    //       cout<<arr[i][j]<<" ";
    //   }cout<<ell;
    //}
    for(int i = 0;i<q;i++){
        int a,b;cin>>a>>b;
        if(arr[a][b]==INF){
            cout<<-1<<ell;
        }else
            cout<<arr[a][b]<<ell;
    }
}
