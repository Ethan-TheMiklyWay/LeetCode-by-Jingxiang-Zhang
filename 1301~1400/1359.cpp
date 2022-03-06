Count All Valid Pickup and Delivery Options - Hard


Given n orders, each order consist in pickup and delivery services. 

Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i). 

Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: n = 1
Output: 1
Explanation: Unique order (P1, D1), Delivery 1 always is after of Pickup 1.
Example 2:

Input: n = 2
Output: 6
Explanation: All possible orders: 
(P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and (P2,D2,P1,D1).
This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.


https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/discuss/1823403/C%2B%2B-oror-Easy-To-Understand-oror-Full-Explanation-oror-Coimbanotrics


class Solution {
public:
    int countOrders(int n) {
        long res = 1;
        long mod = 1000000007;
        for(int i=1;i<=n;i++){
            res = res * i;
            res = res%mod;
            res = res * (2*i-1);
            res = res%mod;
        }
        return res%mod;
    }
};