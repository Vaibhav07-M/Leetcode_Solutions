class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        
        // Process from right to left (LSB to MSB)
        for(int i=s.size()-1;i>0;i--) {
            int bit = (s[i] - '0') + carry;
            
            if(bit % 2 == 0) {
                // even -> divide by 2
                steps += 1;
            } 
            else {
                // odd -> add 1 (then divide by 2)
                steps += 2;
                carry = 1;
            }
        }
        
        // If carry remains at MSB, it adds one more step
        return steps + carry;
    }
};