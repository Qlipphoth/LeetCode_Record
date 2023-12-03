#include "header.h"

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int size = cardPoints.size();
        int windowSize = size - k;
        int sum = accumulate(cardPoints.begin(), cardPoints.begin() + windowSize, 0);
        int minSum = sum;
        for (int i = windowSize; i < size; i++) {
            sum += cardPoints[i] - cardPoints[i - windowSize];
            minSum = min(minSum, sum);
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - minSum;
    }

    int maxScore(vector<int>& cardPoints, int k, bool) {
        int size = cardPoints.size();
        int sum = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        int maxSum = sum;
        for (int i = 1; i < k + 1; i++)
        {
            sum += cardPoints[size - i] - cardPoints[k - i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};