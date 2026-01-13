class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {

        double low = 1e18, high = -1e18;

        // Determine search boundaries
        for(auto &sq : squares) {
            double y = sq[1];
            double len = sq[2];
            low = min(low, y);
            high = max(high, y + len);
        }

        // Binary search for y
        for(int iter = 0; iter < 80; iter++) {
            double mid = (low + high) / 2.0;

            double areaBelow = 0.0;
            double areaAbove = 0.0;

            for(auto &sq : squares) {
                double y = sq[1];
                double len = sq[2];

                if(y + len <= mid) {
                    areaBelow += len * len;
                }
                else if(y >= mid) {
                    areaAbove += len * len;
                }
                else {
                    double belowHeight = mid - y;
                    double aboveHeight = (y + len) - mid;

                    areaBelow += belowHeight * len;
                    areaAbove += aboveHeight * len;
                }
            }

            if(areaBelow >= areaAbove)
                high = mid;
            else
                low = mid;
        }

        return low;
    }
};
