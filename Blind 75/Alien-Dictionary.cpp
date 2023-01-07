#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>


using namespace std;



class Solution {
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    // TC: O(w * n)
    string alienOrder(vector<string> &words) {
        unordered_map<char, unordered_set<char>> edges;

        for(int i = 0; i < words.size() - 1; ++i){
            int minLen = min(words[i].size(), words[i + 1].size());
            if(words[i].size() >= words[i + 1].size() && 0 == strncmp(words[i].c_str(), words[i + 1].c_str(), minLen)) return "";   // Detect case 2 contradiction
            
            for(int j = 0; j < minLen; ++j){
                if(words[i][j] != words[i + 1][j]) {
                    edges[words[i][j]].insert(words[i + 1][j]);
                    break;
                }
            }
        }

        vector<VisitState> visit(26, VisitState::kUnvisited);
        stack<char> path;
        for(const auto & edge: edges){
            const char node = edge.first;
            if(kUnvisited == visit[node - 'a']) {
                if(false == DFS(node, edges, visit, path)) return "";
            }
        }

        string result;
        while(false == path.empty()){
            result.push_back(path.top());
            path.pop();
        }
        return result;
    }

private:
    enum VisitState {
        kUnvisited = 0,
        kVisiting = 1,
        kVisited = 2
    };

    bool DFS(char node,  unordered_map<char, unordered_set<char>> & edges, vector<VisitState> & visit, stack<char> & path){
        visit[node - 'a'] = VisitState::kVisiting;

        for(const char & nei : edges[node]) {
            if(visit[nei - 'a'] == kVisiting) return false;
            else if(visit[nei - 'a'] == kUnvisited) {
                if(false == DFS(nei, edges, visit, path)) return false;
            }
        }

        path.push(node);
        visit[node - 'a'] = VisitState::kVisited;
        return true;
    }
};


/*void TEST1(){
    vector<string> input({"wrt","wrf","er","ett","rftt"});
    Solution solution;
    string output = solution.alienOrder(input);
    if("wertf" == output) cout << "SUCCESS: TEST1" << endl;
    else cerr << "FAIL: TEST1" << endl;
}

void TEST2(){
    vector<string> input({"z", "x"});
    Solution solution;
    string output = solution.alienOrder(input);
    if("zx" == output) cout << "SUCCESS: TEST2" << endl;
    else cerr << "FAIL: TEST2" << endl;
}

void TEST3(){
    vector<string> input({"apple", "app"});
    Solution solution;
    string output = solution.alienOrder(input);
    if("" == output) cout << "SUCCESS: TEST3" << endl;
    else cerr << "FAIL: TEST3" << endl;
}

void TEST4(){
    vector<string> input({"a", "ba", "bc", "c"});
    Solution solution;
    string output = solution.alienOrder(input);
    if("abc" == output) cout << "SUCCESS: TEST4" << endl;
    else cerr << "FAIL: TEST4" << endl;
}


int main() {
    TEST1();
    TEST2();
    TEST3();
    TEST4();

    return 0;
}*/