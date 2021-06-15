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
const int MM = 500+5; int mod = 1e9+7;//998244353

ll n, dp[MM][MM], p[MM][MM];
char arr[MM][MM];

bool valid(int c){
    return c>=0&&c<n;
}

int main(){
    inputJunk
    freopen("palpath.in","r", stdin);
    freopen("palpath.out","w", stdout);
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    for(int i = 0;i<n;i++){
        p[i][i] = 1;
    }
    for(int num = n-1;num>=1;num--){
        for(int i = 0;i<n;i++){
            for(int j  =0;j<n;j++){
               dp[i][j] = 0;
            }
        }
        for(int a = 0;a<n;a++){
            int row1 = a;
            int col1 = num-1-a;
            if(col1<0)continue;
            for(int b = 0;b<n;b++){

                int row2 = b;
                int col2 = 2*n-num-b-1;
                if(col2>=n)continue;
                if(arr[row1][col1]!=arr[row2][col2])continue;
                dp[a][b]+=p[a][b];
                if(a+1<n)dp[a][b]+=p[a+1][b];
                if(b-1>=0)dp[a][b]+=p[a][b-1];
                if(a+1<n&&b-1>=0)dp[a][b]+=p[a+1][b-1];
                dp[a][b]%=mod;
            }
        }
        for(int i = 0;i<n;i++){
            for(int j  =0;j<n;j++){
                p[i][j] = dp[i][j];
            }
        }
    }
    cout<<p[0][n-1]<<ell;
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

