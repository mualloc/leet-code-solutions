#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        string result;
        for(const auto & str : strs) result += std::to_string(str.size()) + kDelimiter + str;     
        return result;
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        vector<string> result;
		int i = 0;
        while(i < str.size()){
            const size_t delimIndex = str.find(kDelimiter,i);
            const int tokenSize = stoi(str.substr(i, delimIndex - i));     
            i = delimIndex + 1;
            result.push_back(str.substr(i, tokenSize));
            i += tokenSize;
        }
        return result;
    }
	
private:
	const char kDelimiter = '#';
};

void test(vector<string> & strs){
    Solution s;
    string encoded = s.encode(strs);
    cout << "encoded : " << encoded << endl;
    const vector<string> decoded = s.decode(encoded);
    if(strs != decoded) throw -1;
    for(const auto & d : decoded) cout << d << ", ";
    cout << endl;
    cout << "OK!" << endl;
}

int main()
{
    vector<string> strs = {"lint","code","love","you"};
    test(strs);
    cout << endl << "==============================" << "\n" << endl;
    strs = {"we", "say", ":", "yes"};
    test(strs);
    return 0;
}