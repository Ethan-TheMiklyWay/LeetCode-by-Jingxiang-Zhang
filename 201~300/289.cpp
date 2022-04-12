Game of Life - Medium

According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

 

Example 1:


Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

class Solution {
public:
    int val(vector<vector<int>> &arr, int i, int j) {
        if(i<0 || j<0 || i>=arr.size() || j>=arr[0].size())
            return 0;
        return arr[i][j];
    }
    int next_gen(vector<vector<int>> &arr, int &i, int &j) {
        int nei = val(arr, i + 1, j) + val(arr, i, j - 1 ) +
            val(arr, i + 1, j + 1) + val(arr, i + 1, j - 1) + 
            val(arr, i, j + 1) + val(arr, i - 1, j) + 
            val(arr, i - 1, j + 1) + val(arr, i - 1, j - 1);
        if (arr[i][j] == 0) {
            if (nei == 3)
                return 1;
            else
                return 0;
        }
        else {
            if (nei == 3 || nei == 2)
                return 1;
            else
                return 0;
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> arr = board;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                board[i][j] = next_gen(arr, i, j);
            }
        }
    }
};