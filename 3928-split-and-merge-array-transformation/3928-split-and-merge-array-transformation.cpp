class Solution {
public: 

    int n;
    vector<vector<int>> getAdjNode(vector<int> &node){
        //selecting a particular length so i can generate all possible neighbours
        vector<vector<int>> neighbours;
        for(int len = 1; len<=n; len++){
            
            for(int i=0; i<n; i++){
                if (i + len > n) continue;

                // this subPart can be placed at any position , resulting in a new neighbour
                vector<int> subPart(node.begin() + i, node.begin()+i+len);

                //now select the remaining part from the node
                vector<int> remPart(node.begin(), node.begin() + i);
                remPart.insert(remPart.end(), node.begin() + i + len, node.end());

                //now put the subPart at all possible positions in remPart
                // to generate adjNode
                for(int k = 0; k<=remPart.size(); k++){
                    vector<int> adjNode(remPart.begin(), remPart.begin() + k);
                    adjNode.insert(adjNode.end(), subPart.begin(), subPart.end());
                    adjNode.insert(adjNode.end(), remPart.begin() + k, remPart.end());
                    if(node != adjNode)
                        neighbours.push_back(adjNode);
                        
                }
            }
        }
        return neighbours;
    }
    int minSplitMerge(vector<int>& node1, vector<int>& node2) {
        
        n = node1.size();
        set<vector<int>> visited;
        queue<vector<int>> q;

        q.push(node1);
        visited.insert(node1);

        int level = 0;
        while(!q.empty()){
            int N = q.size();

            for(int i=0; i<N; i++){
                auto node = q.front();
                q.pop();

                if(node == node2) return level;

                for(vector<int> adjNode : getAdjNode(node)){
                    if(visited.count(adjNode) == 0){
                        q.push(adjNode);
                        visited.insert(adjNode);
                    } 
                } 
            }
            level++;
        }
        return 0;
    }
};