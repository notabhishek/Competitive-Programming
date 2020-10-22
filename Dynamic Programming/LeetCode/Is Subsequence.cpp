class Solution {
public:
    bool isSubsequence(string s, string t) {
        // O(m + n) Matching , slow for multiple matching
        // int l1=s.size();
        // int l2=t.size();
        // int i=0,j=0;
        // while (i<l1 and j<l2)
        // {
        //     if (s[i]==t[j])
        //         i++;
        //     j++;
        // }
        // if (i==l1)return true;
        // return false;
        
        // O( s.length() * log n  ) matching 
        vector< int > pos[256];
        for(int i = 0 ; i < t.length(); ++i) 
            pos[t[i]].push_back(i);
        
        int cur = 0;
        for(char i : s) {
            int lo = 0 , hi = pos[i].size() - 1;
            int idx = -1;
            while( lo <= hi ) {
                int mid = (lo + hi) >> 1;
                if(pos[i][mid] >= cur) {
                    idx = pos[i][mid];
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            if( idx == -1 ) // No char found
                return false;
            cur = idx + 1;
        }
        return true;
    }
};