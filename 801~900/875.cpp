Koko Eating Bananas - Medium


Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int result_min = 1;
        int result_max = 1;
        for(int i=0;i<piles.size();i++)
            result_max = result_max>piles[i]?result_max:piles[i];
        
        while(result_min != result_max){
            int result_medium = (result_min + result_max) / 2;
            cout<<result_min<<" "<<result_max <<" " << result_medium<<" "<<endl;
            int temp = h;
            for(int i=0;i<piles.size();i++){
                temp -= piles[i] / (result_medium);
                if(piles[i]%result_medium!=0)
                    temp--;
                if(temp<0){
                    break;
                }
            }
            if(temp<0){
                if(result_min == result_medium)
                    result_min++;
                else
                    result_min = result_medium;
            }
            else{
                result_max = result_medium;
            }
            
        }
        
        return result_max;
    }
};