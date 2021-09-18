#include <iostream>
#include <string>
#include <numeric>

/** @brief: Demonstrates the concept of folding ,
 *          To achieve right folding, reverse the iterators.
 *          Folding means inserting an operator between successive elements pointed to by the iterator
 *          **/

int f(int previous_count, char c)
{
    return (c != '\n') ? previous_count : previous_count + 1;
}

int count_lines(const std::string& s)
{
    return std::accumulate(s.cbegin(), s.cend(),  // Folds the entire string
                           0,                     // Starts the count with 0
                           f);                    // Returns updated count
}
int main(int argc, char const *argv[])
{
    std::string s ( "My name is Jibran. \nI am 25 years old.\nI live in Worcester, MA\n");

    std::cout << "Count of lines : " << count_lines(s) << std::endl;
    return 0;
}
