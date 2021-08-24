#include <bits/stdc++.h>
using namespace std;
//#include <ext/rope>
//using namespace __gnu_cxx;
#include <ext/pb_ds/assoc_container.hpp>
#include <stdlib.h>
using namespace __gnu_pbds;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
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
typedef pair<int, pi> trip;
typedef pair<pll, ll> tripll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<trip> vtrip;
typedef vector<tripll> vtripll;

const int INF = 1e9+1212;
const ll P = 9973, M = 1e9+9;
const int MM = 1e5+5; int mod = 998244353;//1e9+7

int n, m, k, grid[26][26], cost[MM][26], p[MM][26], dp[MM][26], moo[MM];
string s;
int main(){
    inputJunk
    freopen("cowmbat.in","r", stdin);
    freopen("cowmbat.out","w", stdout);
    cin>>n>>m>>k>>s;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    for(int k = 0;k<m;k++){
        for(int i = 0;i<m;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][k]+grid[k][j]<grid[i][j]){
                    grid[i][j] = grid[i][k]+grid[k][j];
                }
            }
        }
    }

    for(int i = 1;i<=n;i++){
        int cur = s[i-1]-'a';
        for(int j = 0;j<m;j++){
            cost[i][j] = grid[cur][j];
            p[i][j] = cost[i][j];
            p[i][j]+=p[i-1][j];
        }
    }
    for(int i = 0;i<=n;i++){
        moo[i] = INF;
        for(int j = 0;j<m;j++){
            dp[i][j] = INF;
        }
    }
    moo[0] = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<m;j++){
            dp[i][j] = min(dp[i][j], dp[i-1][j]+cost[i][j]);
            if(i>=k)dp[i][j] = min(p[i][j]-p[i-k][j]+moo[i-k], dp[i][j]);
            moo[i] = min(moo[i], dp[i][j]);
        }
    }

    cout<<moo[n]<<ell;
}
/*CUSTOM TEST CASE 1
20 20 5
clfedihbldtdlpencbbl
0 799 269 877 468 642 378 287 570 742 872 563 915 667 794 749 649 618 906 802
463 0 879 935 26 717 496 733 916 848 620 847 222 571 423 844 346 661 321 740
901 726 0 240 628 156 588 739 957 7 558 506 628 1000 541 569 814 335 710 579
710 687 665 0 863 933 922 922 218 638 375 757 786 872 956 918 852 252 379 625
458 95 23 981 0 591 392 15 205 858 493 869 892 887 620 811 949 480 824 259
676 147 921 804 721 0 905 37 532 797 747 755 981 306 943 624 933 229 318 810
977 459 554 698 760 918 0 642 848 919 589 260 956 290 538 927 390 442 13 423
774 754 584 804 704 461 715 0 544 788 708 565 821 584 706 650 934 20 921 791
905 618 727 15 650 968 901 472 0 382 726 616 514 792 469 527 644 990 564 192
777 799 449 609 379 434 253 319 18 0 876 993 664 399 231 213 740 952 581 782
331 665 608 394 357 405 571 530 528 406 0 640 196 310 705 365 686 762 841 890
497 952 190 230 443 677 426 968 675 347 572 0 885 568 420 896 711 911 555 901
513 883 760 266 675 886 617 746 404 773 881 705 0 262 794 934 803 388 917 684
658 102 268 599 756 313 909 437 464 622 453 555 282 0 324 227 221 658 886 738
274 620 327 907 970 771 956 312 299 927 908 100 943 530 0 834 977 491 252 763
102 840 732 923 243 718 902 544 783 616 820 592 685 873 650 0 463 824 893 697
436 581 943 621 776 699 273 675 859 781 716 959 448 548 225 833 0 573 613 527
287 613 974 998 352 980 865 408 771 834 945 318 515 627 906 906 901 0 429 262
708 900 984 740 856 565 316 717 838 877 866 331 766 447 348 973 259 991 0 663
519 952 445 583 979 867 332 641 823 904 863 501 804 937 659 29 182 520 900 0

*/

/*CUSTOM TEST CASE 2
*/

/*CUSTOM TEST CASE 3
*/

/*Comments of Shame
- floating error (use integer division instead)
- cin vs getline
- upperbound and lowerbound returns iteratorsf
- use long long when number is big enough
- for dp invalid cases needs to be skipped
- some base cases won't work (review cow poetry)
- always check bounds, some TLE are due to incorrect bounds!
- dont mess up return types
= RESET ARRAYS!!!!!!!!!!
- USE UR BRAIN
- INF setting problems
- push vs pb
- check if things are used properly
- read the PROBLEM (directed vs undirected graph)
*/
/*
    freopen("time.in","r", stdin);
    freopen("time.out","w", stdout);
*/
