class Solution {
public:
    int bestClosingTime(string customers) {
        int size = customers.size();
        int penalty = 0;

        for (char it : customers) {
            if (it == 'Y') penalty++;
        }

        int minpenalty = penalty;
        int hr = 0;

        for (int i = 0; i < size; i++) {
            if (customers[i] == 'Y') penalty--;
            else penalty++;
            if (penalty < minpenalty) {
                minpenalty = penalty;
                hr = i+1;
            }
        }
        return hr;
    }
};
