class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

        sort(asteroids.begin(), asteroids.end());

        long long curMass = mass;

        for (int asteroid : asteroids) {

            if (curMass < asteroid)
                return false;

            curMass += asteroid;
        }

        return true;
    }
};