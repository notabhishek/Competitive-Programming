pair<int, int> solve(const string& a) {
        int plus = find(a.begin(), a.end(), '+') - a.begin(); // Find Where the plus sign is
        int i = find(a.begin(), a.end(), 'i') - a.begin(); // Find where the imaginary part is
        int real = stoi(a.substr(0, plus)); // Real Part (string to int)
        int img = stoi(a.substr(plus + 1, i - plus)); // Imaginary Part (string to int)
        return {real, img};
    }
string complexNumberMultiply(string a, string b) {
        pair<int, int> av = solve(a);
        pair<int, int> bv = solve(b);
        int re = av.first * bv.first - av.second * bv.second;
        int im = av.first * bv.second + av.second * bv.first;
        return to_string(re) + "+" + to_string(im) + "i" ; // Real + i*(Imaginary)
    }
    
