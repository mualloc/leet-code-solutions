// https://www.lintcode.com/problem/907/

#include <array>
#include <iostream>
#include <limits.h>

using namespace std;


class Solution {
public:
    /**
     * @param s: a string
     * @param k: an integer
     * @return: a string such that the same characters are at least distance k from each other
     */
    string rearrangeString(string &s, int k) {
        std::array<char, 128> freqs{{0}};
        int maxFreq = INT_MIN;
        char maxChar = '\0';
        for(const auto& c: s) {
            if(++freqs[c] > maxFreq){
                maxFreq = freqs[c];
                maxChar = c;
            }
        }
        const int ssize = s.size();
        if(maxFreq > ssize / k + (0 != ssize % k)) return "";
        
        string result(ssize, '\0');
        int index = 0;
        while(freqs[maxChar]--){
            result[index] = maxChar;
            index += k;
        }
        int start_index = 0;
        for(int c = 0; c < freqs.size(); ++c){
            while(freqs[c]-- > 0){
                if(index >= ssize) index = ++start_index;
                result[index] = c;
                index += k;
            }
        }
        
        return result;
    }
};


int main()
{
    Solution s;

    int test_index = 1;
    string input_s = "aabbcc";
    string actual = s.rearrangeString(input_s, 3);
    if("abcabc" == actual) cout << "SUCCESS" << test_index++ << endl;
    else cerr << "FAIL" << test_index++ << ", ACTUAL[" << actual << "]" << endl;
    input_s = "aaabc";
    actual = s.rearrangeString(input_s, 3);
    if("" == actual) cout << "SUCCESS" << test_index++ << endl;
    else cerr << "FAIL" << test_index++ << ", ACTUAL[" << actual << "]" << endl;
    input_s = "aaadbbcc";
    actual = s.rearrangeString(input_s, 2);
    if("abacacbd" == actual) cout << "SUCCESS" << test_index++ << endl;
    else cerr << "FAIL" << test_index++ << ", ACTUAL[" << actual << "]" << endl;
    input_s = "abb";
    actual = s.rearrangeString(input_s, 2);
    if("bab" == actual) cout << "SUCCESS" << test_index++ << endl;
    else cerr << "FAIL" << test_index++ << ", ACTUAL[" << actual << "]" << endl;
    input_s = "aacbbc";
    actual = s.rearrangeString(input_s, 3);
    if("abcabc" == actual) cout << "SUCCESS" << test_index++ << endl;
    else cerr << "FAIL" << test_index++ << ", ACTUAL[" << actual << "]" << endl;
    input_s = "geeksforgeeks";
    actual = s.rearrangeString(input_s, 3);
    if("egoegrekseksf" == actual) cout << "SUCCESS" << test_index++ << endl;
    else cerr << "FAIL" << test_index++ << ", ACTUAL[" << actual << "]" << endl;
    input_s = "aaa";
    actual = s.rearrangeString(input_s, 2);
    if("" == actual) cout << "SUCCESS" << test_index++ << endl;
    else cerr << "FAIL" << test_index++ << ", ACTUAL[" << actual << "]" << endl;
    
    return 0;
}
