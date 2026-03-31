class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        
        int len = n + m - 1;
        vector<char> word(len, '?');
        
        // STEP 1: Apply 'T' constraints
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'T') {
                for(int j = 0; j < m; j++) {
                    if(word[i + j] == '?' || word[i + j] == str2[j]) {
                        word[i + j] = str2[j];
                    } else {
                        return ""; // conflict
                    }
                }
            }
        }
        
        // STEP 2: Fill remaining with 'a'
        for(int i = 0; i < len; i++) {
            if(word[i] == '?') word[i] = 'a';
        }
        
        // STEP 3: Fix 'F' constraints
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'F') {
                
                bool match = true;
                for(int j = 0; j < m; j++) {
                    if(word[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }
                
                if(match) {
                    // break it → change last char
                    bool fixed = false;
                    
                    for(int j = m - 1; j >= 0; j--) {
                        int idx = i + j;
                        
                        for(char c = 'a'; c <= 'z'; c++) {
                            if(c != word[idx]) {
                                char old = word[idx];
                                word[idx] = c;
                                
                                // check if still valid for T constraints
                                bool ok = true;
                                for(int k = 0; k < n; k++) {
                                    if(str1[k] == 'T') {
                                        for(int x = 0; x < m; x++) {
                                            if(word[k + x] != str2[x]) {
                                                ok = false;
                                                break;
                                            }
                                        }
                                        if(!ok) break;
                                    }
                                }
                                
                                if(ok) {
                                    fixed = true;
                                    break;
                                }
                                
                                word[idx] = old;
                            }
                        }
                        
                        if(fixed) break;
                    }
                    
                    if(!fixed) return "";
                }
            }
        }
        
        return string(word.begin(), word.end());
    }
};