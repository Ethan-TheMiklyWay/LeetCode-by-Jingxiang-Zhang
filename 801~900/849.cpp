Maximize Distance to Closest Person - Medium

You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to the closest person.

 

Example 1:
Input: seats = [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.


class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int max_space = 0;
        int first_person = -1;
        int pointer = 0;
        while(true){
            if(seats[pointer]){
                first_person = pointer;
                max_space = pointer;
                break;
            }
            pointer++;
        }
        int last_person = pointer;
        while(pointer++ < seats.size()-1){
            if(seats[pointer]){
                int len = (pointer-last_person)>>1;
                max_space = max_space>len?
                            max_space:len;
                last_person = pointer;
            }
        }
        
        max_space = max_space>seats.size() - 1 -last_person?
                    max_space:seats.size() - 1 -last_person;
        
        return max_space;
    }
};