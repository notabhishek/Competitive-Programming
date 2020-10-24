void LGE(vector<int>&h , vector<int>& lge) {
	int n = h.size();
	vector<pair<int, int>>st;
    for (int i = 0; i < n; i++) { // the nearest greater from the left
        while (!st.empty() && st.back().first < h[i]) {
            st.pop_back();
        }
        if (st.empty()) lge[i] = -1;
        else lge[i] = st.back().second;
        st.push_back({h[i], i});
    }
}
void LLE(vector<int>&h , vector<int>& lle) {
	vector<pair<int, int>>st;
	int n = h.size();
	for (int i = 0; i < n; i++) { // the nearest less from the left
        while (!st.empty() && st.back().first > h[i]) {
            st.pop_back();
        }
        if (st.empty()) lle[i] = -1;
        else lle[i] = st.back().second;
        st.push_back({h[i], i});
    }
}
void RGE(vector<int>&h , vector<int>& rge) {
	vector<pair<int, int>>st;
	int n = h.size();
	for (int i = n - 1; i >= 0; i--) { // the nearest greater from the right
        while (!st.empty() && st.back().first < h[i]) {
            st.pop_back();
        }
        if (st.empty()) rge[i] = -1;
        else rge[i] = st.back().second;
        st.push_back({h[i], i});
    }
}
void RLE(vector<int>&h , vector<int>& rle) {
	vector<pair<int, int>>st;
	int n = h.size();
	for (int i = n - 1; i >= 0; i--) { // the nearest less from the right
        while (!st.empty() && st.back().first > h[i]) {
            st.pop_back();
        }
        if (st.empty()) rle[i] = -1;
        else rle[i] = st.back().second;
        st.push_back({h[i], i});
    }
}