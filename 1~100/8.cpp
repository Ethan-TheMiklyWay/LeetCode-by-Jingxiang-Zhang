String to Integer (atoi) - Medium
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
Return the integer as the final result.
Note:

Only the space character ' ' is considered a whitespace character.
Do not ignore any characters other than the leading whitespace or the rest of the string after the digits


class Solution {
public:
    int myAtoi(string s) {
        int length = s.length();
        int pointer = 0;
        int symbol = 1;
        while(pointer<length){
            if(s[pointer]=='-' || s[pointer]=='+') {
                if(!(s[pointer+1]<='9' && s[pointer+1]>='0')) return 0;
                if(s[pointer] == '-') symbol = -1;
            }
            else if(s[pointer]<='9' && s[pointer]>='0') break;
            else if(s[pointer]!=' ') return 0;
            pointer++;
        }
        int result = 0;
        while(pointer<length){
            char c = s[pointer];
            if(!(c<='9' && c>='0')) break;
            if(result > 214748364){
                return symbol == 1 ? 2147483647 : -2147483648;
            }
            int ct = c - '0';
            if(result == 214748364){
                if(symbol == 1){
                    if(ct<7) result = 2147483640+ct;
                    else result = 2147483647;
                }
                else{
                    if(ct<8) return -2147483640-ct;
                    else return -2147483648;
                }
            }
            else{
                result = result * 10 - '0' + c;
            }
            pointer++;
        }
        return result*symbol;
    }
    
};

