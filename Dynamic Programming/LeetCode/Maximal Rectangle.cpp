class Solution {
public:
    int histArea(int row , vector<vector<int>> &hist) {
        int maxArea = 0 ;
        stack<int> s;
        int i = 0;
        for(; i < hist[row].size();) {
            //keep pushing bigger elements
            if(s.empty() || hist[row][s.top()] <= hist[row][i] ) {
                s.push(i++);
            } else {
                //pop the top of stack
                int tp = s.top();
                s.pop();
                if(s.empty()) {
                    maxArea = max(maxArea , i * hist[row][tp]);
                }else {
                    maxArea = max(maxArea , (i - s.top() - 1) * hist[row][tp] );
                }
            }
        }
        while(!s.empty()) {
            int tp = s.top();
            s.pop();
            int newArea = hist[row][tp] * (s.empty() ? i : i - s.top() - 1);
            maxArea = max(maxArea  , newArea);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        int rows = matrix.size() , cols = matrix[0].size();
        vector<vector<int>> hist( rows , vector<int>(cols , 0));
        //Fill the first row
        for(int i = 0 ; i < cols;++i)
            hist[0][i] = matrix[0][i]-'0';
        // Fill other rows
        for(int i = 1; i < rows; ++i) 
            for(int j = 0 ;j < cols; ++j) 
                hist[i][j] = ((matrix[i][j]=='1')? (1 + hist[i-1][j]) : 0);
        // Find maximum histogram area
        for(auto &i : hist) {
            for(auto &j : i) cout << j << " "; cout<<"\n";
        } 
        int maxarea = 0;
        for(int i = 0 ; i < rows; ++i) {
            maxarea = max(maxarea , histArea(i  , hist));
        }
        return maxarea;
    
    }
};
