class Trie{
    public:
    bool isLeaf;
    vector<Trie*> child;
    Trie() {
        isLeaf = false;
        child.assign(26, NULL);
    }
    
    void insert(string &w) {
        Trie *cur = this;
        for(char i : w) {
            if(cur->child[ i-'a' ] == NULL) 
                cur->child[ i-'a' ] = new Trie();
            cur = cur -> child[ i-'a' ];
        }
        cur->isLeaf = true;
    }
    
    bool search(string &w) {
        Trie *cur = this;
        for(char i : w) {
            if(cur->child[ i - 'a' ] == NULL) return false;
            cur = cur -> child[ i - 'a' ];
        }
        return cur->isLeaf;
    }
    bool isPref(string &w) {
        Trie *cur = this;
        for(char i : w) {
            if(cur->child[ i - 'a' ] == NULL) return false;
            cur = cur -> child[ i - 'a' ];
        }
        return true;
    }
};
class Solution {
public:
    vector<vector<bool>> vis;
    int r4[4] = {1, -1, 0, 0};
    int c4[4] = {0, 0, 1, -1};
    int n, m;
    set< string > res;
    void dfs(int r, int c,string &cur, vector<vector<char>> &b, Trie *root) {
        if(root == NULL || root->child[ b[r][c]-'a' ] == NULL) return;
        cur += b[r][c];
        if(root->child[ b[r][c]-'a' ]->isLeaf) res.insert(cur);
        
        for(int i = 0; i < 4; ++i) {
            int tr = r + r4[i];
            int tc = c + c4[i];
            if(tr>=0 && tr < n && tc>=0 && tc< m && vis[tr][tc] == 0) {
                vis[tr][tc] = 1;
                dfs(tr, tc, cur, b, root->child[ b[r][c]-'a' ]);
                vis[tr][tc] = 0;
            }
        }
        cur.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& b, vector<string>& words) {
        n = b.size();
        m = b[0].size();
        vector<string> ans;
        
        Trie *root = new Trie();
        for(string w : words) root->insert(w);
        vis.assign(n, vector<bool>(m, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                vis[i][j] = 1;
                string cur = "";
                dfs(i, j, cur, b, root);
                vis[i][j] = 0;
            }
        }
        for(auto &i : res)ans.push_back(i);
        return ans;
    }
};
