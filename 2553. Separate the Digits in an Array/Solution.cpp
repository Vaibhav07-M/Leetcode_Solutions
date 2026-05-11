class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        vector<int> ans;
        
        for(int num : nums) {
            
            vector<int> temp;
            
            // extract digits
            while(num > 0) {
                temp.push_back(num % 10);
                num /= 10;
            }
            
            // reverse to maintain order
            reverse(temp.begin(), temp.end());
            
            // add to answer
            for(int d : temp) {
                ans.push_back(d);
            }
        }
        
        return ans;
    }
};