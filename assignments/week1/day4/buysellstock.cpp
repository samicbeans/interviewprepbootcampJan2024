#include <vector>
using namespace std;
class Solution
{
public:
    /*notes:
    prices is a list of prices of given stock on ith day
    find the lowest price to buy and highest pric to sell
    max and min must be different days, and max must be after min
    return max - min. if max =< min return 0
    */
    int maxProfit(vector<int> &prices)
    {
        int min = 99999999;
        int profit = 0;
        if (prices.size() == 1)
        {
            return 0;
        }
        else if (prices.size() == 2)
        {
            if (prices[1] - prices[0] > 0)
            {
                return prices[1] - prices[0];
            }
            else
                return 0;
        }
        else
        {
            for (auto i = 0; i < prices.size(); ++i)
            {
                if (prices[i] < min)
                {
                    min = prices[i];
                }
                int max = 0;
                for (auto j = i + 1; j < prices.size(); ++j)
                {
                    if (prices[j] > max)
                    {
                        max = prices[j];
                    }
                    if (max - min > profit)
                    {
                        profit = max - min;
                    }
                }
            }
        }
        return profit;
    }
};