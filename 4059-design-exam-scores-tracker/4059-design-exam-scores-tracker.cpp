class ExamTracker {
private:
    map<int, long long> m;
    long long total_score;

public:
    ExamTracker() { 
        m[0] = 0;   
        total_score = 0; 
    }
    
    void record(int time, int score) {
        total_score += score;

        m[time] = total_score;

    }
    
    long long totalScore(int startTime, int endTime) {
        long long score = 0;
        auto endIt = prev(m.upper_bound(endTime));
        auto startIt = m.lower_bound(startTime);

        score += endIt->second;
        if(startIt != m.end()){
            startIt = prev(startIt);
            score -= startIt->second;
        }


        return score;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */