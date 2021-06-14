class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        text1 = " "+text1; text2 = " "+text2;
        int l1 = text1.size(), l2 = text2.size();
        int dp[l1+1][l2+1];
        for(int i = 0;i<l1;i++){
            dp[i][0] = 0;
        }
        for(int i = 0;i<l2;i++){
            dp[0][i] = 0;
        }
        for(int i = 1;i<=l1;i++){
            for(int j = 1;j<=l2;j++){
                if(text1[i]==text2[j]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[l1][l2]-1;
    }   
};
