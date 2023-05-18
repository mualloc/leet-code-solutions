class Solution {
public:
    vector<string> generateAbbreviations(string &word) {
        vector<string> result;
        string current;
        generateAbbreviationsHelper(word, 0,, 0 current, result);
        return result;
    }

private:
    void generateAbbreviationsHelper(const string& word, int index, int count, string& current, vector<string>& result){
        if(index == word.size()){
            result.push_back(current);
        }
        for(int i = index; i < word.size(); ++i){
            
        }
    }
};