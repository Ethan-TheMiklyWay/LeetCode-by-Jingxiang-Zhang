67. Add Binary - Easy

Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"


class Solution {
public:
    string addBinary(string a, string b) {
        int a_point = a.length();
        int b_point = b.length();
        int c_point = a_point > b_point ? a_point : b_point;
        c_point += 1;
        char *c = new char[c_point + 1];
        for(int i=0;i<c_point;i++){
            c[i] = '0';
        }
        c[c_point] = 0;
        while(a_point > 0 || b_point > 0){
            a_point -= 1;
            b_point -= 1;
            c_point -= 1;
            int a_temp = 0;
            int b_temp = 0;
            int c_temp = 0;
            cout << c[c_point] << endl;
            if(a_point >= 0){
                a_temp = a[a_point] == '1' ? 1 : 0;
            }
            if(b_point >= 0){
                b_temp = b[b_point] == '1' ? 1 : 0;
            }
            c_temp = c[c_point] == '1' ? 1 : 0;
            
            int total = a_temp + b_temp + c_temp;
            if(total == 2 || total == 3){
                c[c_point - 1] = '1';
            }
                
            if(total == 1 || total == 3)
                c[c_point] = '1';
            else
                c[c_point] = '0';
        }
        
        string ret = c;
        if(c[0] == '0')
            ret = ret.substr(1,ret.length()-1);
        delete [] c;
        
        return ret;
    }
};
