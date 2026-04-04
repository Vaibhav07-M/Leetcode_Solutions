class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int len = encodedText.size();
        
        if(rows == 1) return encodedText; // edge case
        
        int cols = len / rows;
        
        string result = "";
        
        // Traverse diagonals
        for(int j = 0; j < cols; j++) {
            int i = 0, col = j;
            
            while(i < rows && col < cols) {
                result += encodedText[i * cols + col];
                i++;
                col++;
            }
        }
        
        // Remove trailing spaces
        while(!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        
        return result;
    }
};