class Solution {
public:
    unordered_map<string, vector<char>> transitionMap; 
    unordered_set<string> failedRows;

    bool canBuild(const string& baseRow) {
        if (baseRow.size() == 1) return true;
        if (failedRows.count(baseRow)) return false;

        vector<string> upperRows;
        generateNextRows(baseRow, 0, "", upperRows);

        for (const string& nextRow : upperRows)
            if (canBuild(nextRow)) return true;

        failedRows.insert(baseRow);
        return false;
    }

    void generateNextRows(const string& baseRow, int idx, string formedRow, vector<string>& results) {
        if (idx == baseRow.size() - 1) {
            results.push_back(formedRow);
            return;
        }

        string pairKey = baseRow.substr(idx, 2);
        if (!transitionMap.count(pairKey)) return;

        for (char topBlock : transitionMap[pairKey])
            generateNextRows(baseRow, idx + 1, formedRow + topBlock, results);
    }

    bool pyramidTransition(string bottomRow, vector<string>& allowedPatterns) {
        for (const string& pattern : allowedPatterns)
            transitionMap[pattern.substr(0, 2)].push_back(pattern[2]);
        return canBuild(bottomRow);
    }
};
