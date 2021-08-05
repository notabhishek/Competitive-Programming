class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    int dp[n + 1][m + 1];
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int j = 0; j<= m; j++) dp[0][j] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int res[256] = {0};
    for(int k = 0; k < n; k++) res[s1[k]]++;
    for(int k = 0; k < m; k++) res[s2[k]]++;
    string lcs{};
    int i = n, j = m;
    while (i && j){
        if (s1[i - 1] == s2[j - 1]){
            lcs.push_back(s1[i - 1]);
            i--, j--;
        }else{
            if(dp[i][j - 1] > dp[i - 1][j]) j--;
            else i--;
        }
    }
    string ans = "" ; //s2 + s1;
    reverse(lcs.begin(), lcs.end());
    cout << "lcs : " << lcs << endl;
    i = 0 , j = 0;
    cout <<"s " << s1 << " " << s2 << endl;
    for(int k = 0; k < lcs.length(); ++k) {
        while(i < n && s1[i] != lcs[k]) {
            ans += s1[i]; ++i;
        }
        while(j < m && s2[j] != lcs[k]) {
            ans += s2[j]; ++j;
        }
        // lcs[k] came in both strings but added once 
        // so both strings will come as subseq but we removed 1 char
        ans += lcs[k];
        ++i;
        ++j;
    }
    ans += s1.substr(i);
    ans += s2.substr(j);
        
    return ans;
}
};
