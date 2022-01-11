1094. Car Pooling - Medium

There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trip[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.


Example 1:

Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false

Example 2:

Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true


class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int min=1000, max=0;
        for (vector<vector<int>>::const_iterator iter = trips.cbegin(); iter != trips.cend(); iter++) {
            vector<int> temp = *iter;
            vector<int>::const_iterator itert = temp.cbegin();
            itert++;
            min = min < (*itert) ? min : (*itert);
            itert++;
            max = max > (*itert) ? max : (*itert);
        }
        int *length=new int[max+1];
        for(int i=0;i<max;i++) length[i]=0;
        
        for (vector<vector<int>>::const_iterator iter = trips.cbegin(); iter != trips.cend(); iter++) {
            vector<int> temp = *iter;
            vector<int>::const_iterator itert = temp.cbegin();
            int num = *itert;
            itert++;
            length[(*itert)] += num;
            itert++;
            length[(*itert)] -= num;      
        }
        int current = 0;
        for(int i=0;i<max;i++){
            current += length[i];
            if(current > capacity)
                return false;
        }
        return true;
    }
};