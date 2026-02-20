class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> parts;
        int count = 0;
        int last = 0;

        for(int i=0;i<s.size();i++) {
            if(s[i] == '1') count++;
            else count--;

            if(count == 0) {
                // s[last..i] is a special substring
                // strip outer 1 and 0, solve inside recursively
                string inner = s.substr(last + 1, i - last - 1);
                parts.push_back("1" + makeLargestSpecial(inner) + "0");
                last = i + 1;
            }
        }

        sort(parts.begin(), parts.end(), greater<string>());

        string res;
        for(auto &p : parts) res += p;
        return res;
    }
};