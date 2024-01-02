#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        vector<int> lettercount_s(26, 0);
        vector<int> lettercount_t(26, 0);
        for (int i = 0; i < s.length(); i++)
        { // get the frequencies of all letters in s and t
            lettercount_s[s[i] % 97] += 1;
            lettercount_t[t[i] % 97] += 1;
        }
        for (int j = 0; j < lettercount_s.size(); j++)
        {
            if (lettercount_s[j] != lettercount_t[j])
            {
                return false;
            }
        }
        return true;
    }
};