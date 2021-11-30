class Solution {
public:
    int maxAreaInHistogram(vector<int> &hist){
        /*	
    Use a stack to find the first smaller element to left and right of every element and find width of rectangle with ith element as height 
        */
        stack<int> Stack;
        int maxArea = 0;
        int idx = 0;
        while(idx < hist.size()) {
            if(Stack.empty() || hist[Stack.top()] <= hist[idx]) 
                Stack.push(idx++);
            else {
                int cur = Stack.top(); // cur element for height of rect
                Stack.pop();
                int curArea;
                if(Stack.empty()) // no smaller element to left exists
                    curArea = hist[cur] * idx;
                else  // smaller element to left = Stack.top()
                    curArea = hist[cur] * (idx - Stack.top()-1);
                maxArea = max(maxArea, curArea);
    }
    }
    while(!Stack.empty()) {
        int cur = Stack.top(); // cur element for height of rect
            Stack.pop();
            int curArea;
            if(Stack.empty()) // no smaller element to left exists
                curArea = hist[cur] * idx;
            else  // smaller element to left = Stack.top()
                curArea = hist[cur] * (idx - Stack.top()-1);
            maxArea = max(maxArea, curArea);
    }
    return maxArea;
    }
    int maximalRectangle(vector<vector<char>> &mat) {
        
    int Rows = mat.size();
    if(Rows == 0) return 0; // empty matrix

    int Cols = mat[0].size();
    vector<vector<int>> matrix(Rows, vector<int> (Cols));
    for(int row = 0; row < Rows; ++row)
        for(int col = 0; col < Cols; ++col) 
            matrix[row][col] = mat[row][col] - '0';
        // transform matrix rows to histograms 
    for(int row = 1; row < Rows; ++row)
            for(int col = 0; col < Cols; ++col) 
                matrix[row][col] *= (1 + matrix[row-1][col]);

    int maxArea = 0;
    // find maxArea in each histogram row
    for(int row = 0; row < Rows; ++row)
        maxArea = max(maxArea, maxAreaInHistogram(matrix[row]));
    return maxArea;
    }

};
