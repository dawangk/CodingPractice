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
const ll MM = 1e5+5, mod = 1e9+7;
 
ll n;
 
int main(){
    inputJunk
    cin>>n;
    for(int i = 0;i<n;i++){
        int a, cnt = 0;
        cin>>a;
        for(int i = 1;i<=sqrt(a);i++){
            if(a%i==0){
                if(i==sqrt(a)){
                    cnt++;
                }else cnt+=2;
            }
        }
        cout<<cnt<<ell;
    }
}
