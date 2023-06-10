#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// https://www.lintcode.com/problem/605/
// https://www.youtube.com/watch?v=wggaoezAR34
class Solution {
public:
    /**
     * @param org: a permutation of the integers from 1 to n
     * @param seqs: a list of sequences
     * @return: true if it can be reconstructed only one or false
     */
    bool sequenceReconstruction(const vector<int> &org, const vector<vector<int>> &seqs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> indegrees;
        for(const auto& seq : seqs){
            for(int i = 0; i < seq.size() - 1; ++i){
                graph[seq[i]].push_back(seq[i + 1]);
                ++indegrees[seq[i + 1]];
                // Register to indegrees as 0 if not already exists
                indegrees[seq[i]];
            }
        }
        queue<int> todo;
        for (auto indegree : indegrees) if(0 == indegree.second) todo.push(indegree.first);
        vector<int> candidateSequence;
        while(false == todo.empty()){
            if(todo.size() > 1) return false;       // Check uniqueness
            auto node = todo.front(); todo.pop();
            candidateSequence.push_back(node);
            const vector<int>& adjancencies = graph[node];
            for(int adjacent : adjancencies) if(0 == --indegrees[adjacent]) todo.push(adjacent);
        }
        return candidateSequence == org;
    }
};

void TEST(const vector<int> &org, const vector<vector<int>> &seqs, bool expected){
    static int i = 0;
    Solution solution;
    cout << "TEST" << ++i << ":\t";
    if(expected == solution.sequenceReconstruction(org, seqs))	cout << "SUCCESS!" << endl;
	else cerr << "FAIL!" << endl;
}

int main()
{
	TEST({1,2,3},{{1,2},{1,3}}, false);
	TEST({1,2,3},{{1,2}}, false);
	TEST({1,2,3},{{1,2},{1,3},{2,3}}, true);
	TEST({4,1,5,2,6,3},{{5,2,6,3},{4,1,5,2}}, true);
	TEST({4,1,5,2,6},{{5,2,6,3},{4,1,5,2}}, false);
	TEST({4,1,5,2,6,3},{{5,2,6},{4,1,5,2}}, false);
    return 0;
}
