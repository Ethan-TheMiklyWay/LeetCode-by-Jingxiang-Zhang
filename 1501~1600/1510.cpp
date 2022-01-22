Stone Game IV - Hard

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there are n stones in a pile. On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.

Also, if a player cannot make a move, he/she loses the game.

Given a positive integer n, return true if and only if Alice wins the game otherwise return false, assuming both players play optimally.

 

Example 1:

Input: n = 1
Output: true
Explanation: Alice can remove 1 stone winning the game because Bob doesn't have any moves.
Example 2:

Input: n = 2
Output: false
Explanation: Alice can only remove 1 stone, after that Bob removes the last one winning the game (2 -> 1 -> 0).


class Solution {
public:
    bool winnerSquareGame(int n) {
        /*
        * let success[i] record whether Alice can win or not at the 
        * start of i stones. Suppose when i less than n, all of the 
        * record is determined, then we can calculate when i is equal to
        * n, whether Alice can win or not.
        * when i = n-m*m, and success[i] is false, it means Alice can loose
        * definitely. But when add m*m stones, Alice can pick m*m stones at
        * the first time, then the result will turn, and Alice will win.
        */
        bool *success = new bool[n+1];
        for(int i=0;i<=n;i++)
            success[i] = false;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sqrt(i);j++){
                if(success[i-j*j]==false)
                    success[i]=true;
            }
        }
        bool ret = success[n];
        delete [] success;
        return ret;
    }
};
