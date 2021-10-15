/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int match(string &a, string &b) {
        int ans = 0;
        for(int i = 0; i < a.length(); ++i) if(a[i] == b[i]) ++ans;
        return ans;
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int n = wordlist.size();
        for(int g = 0; g < 10; ++g) {
            int guessidx = rand() % n;
            string guess = wordlist[guessidx];
            int input = master.guess(guess);
            int j = -1;
            for(int i = 0; i < n; ++i) {
                if(match(wordlist[i], guess) == input) {
                    ++j;
                    swap(wordlist[i], wordlist[j]);
                }
            }
            n = j + 1;
        }
    }
};
