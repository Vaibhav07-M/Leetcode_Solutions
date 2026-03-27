class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        k = k % n; // important optimization
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                int original = mat[i][j];
                int shifted;
                
                if(i % 2 == 0) {
                    // even row → left shift
                    shifted = mat[i][(j + k) % n];
                } 
                else {
                    // odd row → right shift
                    shifted = mat[i][(j - k + n) % n];
                }
                
                if(original != shifted)
                    return false;
            }
        }
        
        return true;
    }
};