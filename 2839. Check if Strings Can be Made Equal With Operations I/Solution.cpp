class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        
        // Group 1: index 0, 2
        vector<char> a = {s1[0], s1[2]};
        vector<char> b = {s2[0], s2[2]};
        
        // Group 2: index 1, 3
        vector<char> c = {s1[1], s1[3]};
        vector<char> d = {s2[1], s2[3]};
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        sort(d.begin(), d.end());
        
        return (a == b && c == d);
    }
};