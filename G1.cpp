/* Question: Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.
 solution :Since we know that XOR operation can be used for testing if 1 bit occurs twice, in other words, for a single bit, if 1 occurs twice, it turns to 0.
Now we need a 3-time criteria for each bit, by utilizing the bit operations.
This 3-time criteria needs every bit turns to 0 if  '1' occurs three times.

If we know on which bits '1' occurs twice, and also know on which bits '1' occurs 1-time, a simple '&' operation would result in the bit where '1' occurs three times. Then we turn these bit to zero, would do well for this problem.

(1). Check bits which have 1-time '1', use the XOR operation.
(2). Check bits which have 2-times '1's, use current 1-time result & current number.
(3). Check bits which have 3-times '1's, use '1-time' result & '2-times' result
(4). To turn 3-times bits into 0:   ~(3-times result) & 1-time result
                                                     ~(3-times result) & 2-times result
                                                     */




 class Solution {
public:
    int singleNumber(int A[], int n) {
        int t1 = 0;
        int t2 = 0;
        int t3 = 0;
        
        for (int i = 0; i < n; i++){
            t1 = t1 ^ A[i];
            t2 = t2 | ((t1^A[i]) & A[i]);
            t3 = ~(t1 & t2);
            t1 = t1 & t3;
            t2 = t2 & t3;
        }
        
        return t1;
        
    }
};
