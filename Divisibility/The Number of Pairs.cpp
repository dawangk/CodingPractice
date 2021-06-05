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
const int MM = 2e7+5; int mod = 1e9+7;

int divv[MM], val[MM];
int c, d, x;

void solve(){
    int ans = 0;
    cin>>c>>d>>x;
    for(int i = 1;i*i<=x;i++){
        if(x%i!=0)continue;
        int k = x/i+d;
        if(k%c==0)ans+=1<<val[k/c];
        if(i*i==x)continue;
        int k1 =i+d;
        if(k1%c==0)ans+=1<<val[k1/c];
    }
    cout<<ans<<ell;
}
int main(){
    inputJunk
    memset(divv, -1, sizeof(divv));
    divv[1] = 1;
    for(int i = 2;i<MM;i++){
        if(divv[i]==-1)
            for(int j = i;j<MM;j+=i)
                if(divv[j]==-1)
                    divv[j] = i;
    }

    for(int i = 2;i<MM;i++){
        int j = i/divv[i];
        val[i] = val[j]+(divv[i]!=divv[j]);
    }
    int t; cin>>t;
    while(t--){
        solve();
    }
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

