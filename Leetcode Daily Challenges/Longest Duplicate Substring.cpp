class Solution {
public:
    string longestDupSubstring(string s) {
        // binary search + rolling hash | nlogn * (logn for set, can be removed using hashmap)
        int M1 = 1e9 + 7, M2 = 1e9 + 9; // for rolling hash
        int p1 = 31, p2 = 37;
        
        int n = s.length();
        int lo = 1, hi = n-1;
        int maxLen = 0, start = 0;
        while(lo <= hi) {
            int mid = (lo + hi)/2;
            set<pair<int,int>> seen; // seen hashes
            long long hash1 = 0, hash2 = 0;
            long long pow1 = 1, pow2 = 1; 
            int idx = -1;
            for(int i = 0; i < mid-1; ++i) {
                hash1 = (hash1*p1 + s[i]-'a') % M1;
                hash2 = (hash2*p2 + s[i]-'a') % M2;
                pow1 = (pow1 * p1) % M1;
                pow2 = (pow2 * p2) % M2;
            }
            for(int i = mid-1; i < n; ++i) {
                hash1 = (hash1*p1 + s[i]-'a') % M1;
                hash2 = (hash2*p2 + s[i]-'a') % M2;
                if(seen.count({hash1, hash2})){
                    idx = i;
                    break;
                } else {
                    seen.insert({hash1, hash2});
                }
                // subtract 
                hash1 = (hash1 - pow1 * (s[i-mid+1]-'a') % M1 + M1) % M1;
                hash2 = (hash2 - pow2 * (s[i-mid+1]-'a') % M2 + M2) % M2;
            }
            if(idx == -1) {
                hi = mid - 1;
            } else {
                maxLen = mid;
                start = idx - mid+1;
                lo = mid + 1;
            }
        }
        return s.substr(start, maxLen);
    }
};
