#include <algorithm>
#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        std::vector<int> rowStarts;
        auto itr = std::lower_bound(
            matrix.begin(), 
            matrix.end(), 
            target, 
            [](const std::vector<int>& row, int value) {
                return row[0] < value;
            }
        );
        if (itr == matrix.begin())
            return itr->at(0) == target;
        else if (itr != matrix.end() && itr->at(0) == target)
            return true;
        itr--;
        auto itr2 = std::lower_bound(itr->begin(), itr->end(), target);
        return itr2 != itr->end() && *itr2 == target;
    }
};