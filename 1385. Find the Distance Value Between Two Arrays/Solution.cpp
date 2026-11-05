class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1,
                             vector<int>& arr2, int d) {

        int count = 0;

        // Check every element of arr1
        for (int i = 0; i < arr1.size(); i++) {

            bool valid = true;

            // Compare with every element of arr2
            for (int j = 0; j < arr2.size(); j++) {

                if (abs(arr1[i] - arr2[j]) <= d) {
                    valid = false;
                    break;
                }
            }

            // Count only valid elements
            if (valid) {
                count++;
            }
        }

        return count;
    }
};
