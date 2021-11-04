/**
 * @type of arr: integer array
 * @return type: integer
 */
class Solution {
public:
    // merge sort approach, segment tree approach
    // merge sort 
    int mergeSort(vector<int> &arr, int st, int en) {
    	if(st == en) return 0;
        
        int mid = (st + en) >> 1;
        int inversions = 0;
        inversions += mergeSort(arr, st, mid);
        inversions += mergeSort(arr, mid+1, en);
        // merge here
        vector<int> c;
        int i = st, j = mid+1;
//         cout << "arr: "; for(int i = st; i<=en; ++i) cout <<arr[i] << " " ; cout << endl;
        while(i <= mid && j <= en) {
         	if(arr[i] <= arr[j]) c.push_back(arr[i++]);
            else {
                c.push_back(arr[j++]);
                inversions += mid - i + 1;
            }
        }
        while(i <= mid) c.push_back(arr[i++]);
        while(j <= en) {
            c.push_back(arr[j++]);
        }
        for(int i = 0; i < c.size(); ++i) 
            arr[st+i] = c[i];
//        	cout << st << "  " << en << " " << inversions << endl;
        return inversions;
    }
    int inversionCount(vector<int>& arr) {
    	// write your awesome code here 
        return mergeSort(arr, 0, arr.size()-1);
    }
};
