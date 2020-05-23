/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, 
return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0
*/


class Solution {
private:
    int msb_pos(int num) {
        int pos = -1;
        while(num) {
            num /= 2;
            pos++;
        }
        return pos;
    }
public:
    int rangeBitwiseAnd(int m, int n) {
        long long res = 0;
        while(m && n) {
            int msb_p1 = msb_pos(m);
            int msb_p2 = msb_pos(n);
            
            if(msb_p1 != msb_p2)
                break;
            
            long long adder = pow(2, msb_p1);
            res += adder;
            
            m -= adder;
            n -= adder;
        }
        return res;
    }
};

// Simple implementation
int rangeBitwiseAnd(int m, int n) {
	int c = 0;
	while(m != n){
		m >>= 1;
		n >>= 1;
		++c;
	}
	return n << c;
}