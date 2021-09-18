#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// Calculate average score using std::accumulate
double average_score(const std::vector<int>& scores)
{
    return std::accumulate(scores.cbegin(), scores.cend(), 0)
            / (double)scores.size();
}

// Treating std::accumulate as a higher order function by passing function std::multiplies<T> to it
double scores_product(const std::vector<int>& scores)
{
    return std::accumulate(scores.cbegin(), scores.cend(), 
                           1,
                           std::multiplies<int>());
}

int main(int argc, char const *argv[])
{
    std::vector<int> scores{2, 3, 5, 1, 6, 4, 7, 4, 1, 9};

    std::cout << "Average score = " << average_score(scores) << std::endl;
 
    std::cout << "Product of scores = " << scores_product(scores) << std::endl;
    return 0;
}
