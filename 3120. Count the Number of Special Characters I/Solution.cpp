class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        unordered_set<char> lower;
        unordered_set<char> upper;
        
        for(char c : word) {
            
            if(islower(c))
                lower.insert(c);
            else
                upper.insert(c);
        }
        
        int count = 0;
        
        for(char c = 'a'; c <= 'z'; c++) {
            
            if(lower.count(c) && upper.count(c - 'a' + 'A')) {
                count++;
            }
        }
        
        return count;
    }
};