Search a 2D Matrix - Medium

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int begin = 0;
        int end = m*n-1;
        while(begin!=end){
            int mid = (begin+end) / 2;
            int a = mid/n;
            int b = mid%n;
            int val = matrix[a][b];
            // cout<<mid<<" "<<a<<" "<<b<<endl;
            if(val==target)
                return true;
            if(val>target){
                end = mid;
            }
            else if(val<target){
                if(mid == begin)
                    begin++;
                else
                    begin = mid;
            }
        }
        int a = begin/n;
        int b = begin%n;
        if(matrix[a][b]==target)
            return true;
        return false;
    }
};