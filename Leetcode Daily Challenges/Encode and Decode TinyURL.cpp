class Solution {
public:
    unordered_map<int, string > hash;
    int cnt = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        hash[cnt] = longUrl;
        string ret = to_string(cnt++);
        return ret;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return hash[stoi(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
