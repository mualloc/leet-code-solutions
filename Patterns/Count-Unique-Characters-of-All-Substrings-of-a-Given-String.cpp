// https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/solutions/1651064/1d-dp-approach/
// https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/solutions/423812/python-detailed-explanation/
class Solution {
public:
    // TC: O(N)
    // SC: O(1)
    int uniqueLetterString(string s) {
        array<pair<int, int>, 26> last_indexes;
        last_indexes.fill({-1, -1});
        int result = 0;
        for(int i = 0, prev_step = 0; i < s.size(); ++i){
            const char ci = s[i] - 'A';
            auto& first = last_indexes[ci].first;
            auto& second = last_indexes[ci].second;
            prev_step += i - second - (second - first);
            result += prev_step;
            first = second;
            second = i;
        }
        return result;
        /*1
        1 2
        1 2 3*/


        /*xyyyx

        x xy*/


        /* 
        // leelle
        l
        e le
        e ee lee
        l el eel leel
        l ll ell eell leell
        e le lle elle eelle leelle

        // ele
        e
        l el
        e le ele
        */
    }
};
