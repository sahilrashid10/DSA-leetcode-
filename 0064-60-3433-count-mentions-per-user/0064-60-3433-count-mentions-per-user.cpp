class Solution {
public:

    static bool cmp(vector<string>e1, vector<string>e2){
        int a = stoi(e1[1]);
        int b = stoi(e2[1]);
        return a==b?e1[0]>e2[0]:a<b;
    }

    void handleMessage(vector<string>&event, vector<int>&mentions, vector<int>&offlineTime){ 
        vector<string>ids;
        stringstream ss(event[2]);
        string s;
        while(ss >> s)
            ids.push_back(s);

        int n=mentions.size();
        for(auto id:ids){
            if(id=="ALL"){
                for(int i=0; i<n; i++)
                    mentions[i]++;
            }else if(id=="HERE"){
                for(int i=0; i<n; i++){
                    if(offlineTime[i] <= stoi(event[1]) || offlineTime[i]==0)
                    mentions[i]++;
                }
            }else{
                int ID = stoi(id.substr(2));
                mentions[ID]++;
            }
        }
    }  

    void handleOffline(vector<string>&event, vector<int>&offlineTime){
        int ID = stoi(event[2]);
        offlineTime[ID] = stoi(event[1])+60;
    }
    
    vector<int> countMentions(int numberOfUsers,vector<vector<string>>& events)     {
        sort(events.begin(), events.end(), cmp);   
        vector<int>mentions(numberOfUsers);
        vector<int>offlineTime(numberOfUsers);

        for(auto &event:events){
            if(event[0]=="MESSAGE")
                handleMessage(event, mentions, offlineTime);
                
            else if(event[0]=="OFFLINE")
                handleOffline(event, offlineTime);
        }
        return mentions;
    }
};