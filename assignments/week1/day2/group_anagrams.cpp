#include <vector>
using namespace std;
#include <string>
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> sln;
        if (strs.size() < 2)
        {
            sln.push_back(strs);
            return sln;
        }
        // idea: copy the frequency of letters of each string into n int vectors
        vector<int> count(26, 0);
        vector<vector<int>> lettercount; // contains frequency of each string n x 26.
        for (int i = 0; i < strs.size(); i++)
        {
            count.clear();
            for (int j = 0; j < strs[i].size(); j++)
            {
                count[strs[i][j] % 97] += 1;
            }
            lettercount.push_back(count);
        }
        // then compare each vector; the vectors with the same frequency of letters are grouped together within one string vector.
        vector<bool> grouped(strs.size()); // makes sure that strings that are already grouped will not be duplicated
        for (int k = 0; k < lettercount.size(); k++)
        {
            vector<string> anagrams = {};
            if (grouped[k] == 0)
            {
                anagrams.push_back(strs[k]);
                grouped[k] = 1;
                for (int l = k + 1; l < lettercount.size(); l++)
                {
                    if (lettercount[k] == lettercount[l] && grouped[l] == 0)
                    {
                        anagrams.push_back(strs[l]);
                        grouped[l] = 1;
                    }
                }
                // after finding all anagrams belonging to the same group, push it back into sln.
                sln.push_back(anagrams);
            }
        }
        return sln;
    }
};