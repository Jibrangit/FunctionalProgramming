#include <iostream>
#include <vector>
#include <algorithm>

/** @brief: String trimming using the concept of higher order functions. 
 *          The string is first copied and moved into a function that uses the std::erase method on string using a predicate (is_not_space) to trim its end whitespace.
 *          Then, the above declaration, is enclosed in another similar trim function to remove the initial whitespace.
 *          This way we have a function (is_not_space) within a function (trim_right) within a function (trim_left)
 * */

bool is_not_space(const char &c) {
    return (c != ' ');
}

std::string trim_left(std::string s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), is_not_space));
    return s;
}

std::string trim_right(std::string s) 
{
    s.erase(std::find_if(s.rbegin(), s.rend(), is_not_space).base(), s.end());
    return s;
}

std::string trim(std::string s) {
    return trim_left(trim_right(std::move(s))); // Moving it since s is a copy anyways
}
int main(int argc, char const *argv[])
{
    std::string s ( " My name is Jibran. \nI am 25 years old.\nI live in Worcester, MA ");
    std::string s2;
    std::cout << s << "." << std::endl;

    
    s2 = trim_left(s);
    std::cout << std::endl << s2 << "." << std::endl;    // Removing initial whitespace

    s2 = trim_right(s);
    std::cout << std::endl << s2 << "." << std::endl;    // REmoving final whitespace

    s2 = trim(s);
    std::cout << std::endl << s2 << "." << std::endl;    // Removing both.
    
    return 0;
}
