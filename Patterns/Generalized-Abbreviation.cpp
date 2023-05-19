#include <iostream>
#include <vector>
#include <string>

using namespace std;

// https://protegejj.gitbook.io/algorithm-practice/leetcode/backtracking/320-generalized-abbreviation
// https://baihuqian.github.io/2018-07-31-generalized-abbreviation/#backtracking-solution
class Solution {
public:
    vector<string> generateAbbreviations(string &word) {
        vector<string> result;
        generateAbbreviationsHelper(word, 0, 0, "", result);
        return result;
    }
private:
void generateAbbreviationsHelper(const string& word, int index, int count, string current, vector<string>& result){
        const string countStr = count > 0 ? to_string(count) : "";
        if(index == word.size()){
            result.push_back(current + countStr);
            return;
        }
        // Abbreviate
        generateAbbreviationsHelper(word, index + 1, count + 1, current, result);
        // Add curr char
        generateAbbreviationsHelper(word, index + 1, 0, current + countStr + word[index], result);
    }
};

void printResult(const vector<string>& result){
    cout << "Result size = " << result.size() << endl;
    for(const auto& abbv : result){
        cout << abbv << ", ";
    }
    cout << endl;
}

int main(){
    Solution solution;
    string input = "word";
    vector<string> result;
    result = solution.generateAbbreviations(input);
    printResult(result);
    input = "today";
    result = solution.generateAbbreviations(input);
    printResult(result);
}
