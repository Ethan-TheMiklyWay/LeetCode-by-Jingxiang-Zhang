Minimum Domino Rotations For Equal Row - Medium

In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.

If it cannot be done, return -1.

 

Example 1:


Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
Example 2:

Input: tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]
Output: -1
Explanation: 
In this case, it is not possible to rotate the dominoes to make one row of values equal.



class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int size = tops.size();
        int top0_top = 0;
        int top0_bottom = 0;
        int bottom0_top = 0;
        int bottom0_bottom = 0;
        int same_pair = 0;
        for(int i=0;i<size;i++){
            top0_top += tops[0] == tops[i];
            top0_bottom += tops[0] == bottoms[i];
            bottom0_top += bottoms[0] == tops[i];
            bottom0_bottom += bottoms[0] == bottoms[i];
            same_pair += tops[i] == bottoms[i];
        }
        int ans = size + 1;
        if(top0_top+top0_bottom-same_pair>=size){
            ans = size - top0_top;
            ans = ans<size - top0_bottom?
                    ans:size - top0_bottom;
        }
        else if(bottom0_top+bottom0_bottom-same_pair>=size){
            ans = size - bottom0_top;
            ans = ans<size - bottom0_bottom?
                    ans:size - bottom0_bottom;
        }
        else ans = -1;
        return ans;
    }
};