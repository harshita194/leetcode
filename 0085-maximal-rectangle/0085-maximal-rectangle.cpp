// class Solution {
// public:
//     vector<int> nextSmallerElement(vector<int> arr, int n){
//         stack<int> s;
//         s.push(-1);
//         vector<int> ans(n);
//         for(int i= n-1; i>=0; i--){
//             int curr = arr[i];
//             while(s.top() != -1 && arr[s.top()] >= curr){
//                 s.pop();
//             }
//             ans[i] = s.top();
//             s.push(i);
//         }
//         return ans;
//     }

//     vector<int> prevSmallerElement(vector<int> arr, int n){
//         stack<int> s;
//         s.push(-1);
//         vector<int> ans(n);
//         for(int i=0; i<n; i++){
//             int curr = arr[i];
//             while(s.top() != -1 && arr[s.top()] >= curr){
//                 s.pop();
//             }
//             ans[i] = s.top();
//             s.push(i);
//         }        
//         return ans;
//     }

//     int largestRectangle(vector<int> heights, int n){
//         vector<int> next(n);
//         next = nextSmallerElement(heights,n);
//         vector<int> prev(n);
//         prev = prevSmallerElement(heights,n);
//         int area = 0;
//         for(int i=0; i<n; i++){
//             int l = heights[i];
//             if(next[i] == -1){
//                 next[i] = n;
//             }
//             int b = next[i] - prev[i] - 1;
//             int newArea = l * b;
//             area = max(area, newArea);
//         }
//         return area;
//     }
//     int maximalRectangle(vector<vector<char>>& matrix) {
//         if (matrix.empty()) return 0;
//         int n = matrix.size();
//         int m = matrix[0].size();

//         vector<int> heights(m, 0);
//         int area = 0;

//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(matrix[i][j] == '1'){
//                      heights[j] += 1;
//                 }
//                 else{
//                     heights[j] = 0;
//                 }
//             }
//             area = max(area, largestRectangle(heights,m));
//         }
//         return area;
//     }
// };






class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);  // Sentinel to flush the stack
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }

        heights.pop_back();  // Restore
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<int> heights(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};
