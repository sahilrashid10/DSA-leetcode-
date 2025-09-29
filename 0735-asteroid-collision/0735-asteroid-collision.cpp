class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> finalState;

        for(int i=0; i<n; i++){
            int pushFactor = 0;
            while(finalState.size() != 0 && asteroids[i] < 0 && *finalState.rbegin() > 0){
                    if(abs(asteroids[i]) > *finalState.rbegin())
                        finalState.pop_back();
                    else if(abs(asteroids[i]) == *finalState.rbegin()){
                        finalState.pop_back();
                        pushFactor = 1;
                        break;
                    }else{
                        pushFactor = 1;
                        break;
                    } 
            }
            if(pushFactor == 0){
                finalState.push_back(asteroids[i]);
            }
        }
        return finalState;

    }
};