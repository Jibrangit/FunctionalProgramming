#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>
#include <algorithm>

using namespace std::filesystem; 

// The return counts newlines from the current position in the stream until the end of the file. 
// The std::count measures the no. of instances of an element/condition in a range, in this case '\n'
int count_lines(const std::string& filename) 
{
    std::ifstream in(filename);

    return std::count(
        std::istreambuf_iterator<char>(in),
        std::istreambuf_iterator<char>(),
        '\n');
}

// Pass the filenames into the count_lines function which will create an ifstream object from the names, whose first iterator will point to first character. 
std::vector<int> count_lines_in_files(const std::vector<std::string>& files)
{
    std::vector<int> results;

    for(const auto& file : files) 
        results.push_back(count_lines(file));
    
    return results;
}
int main(int argc, char const *argv[])
{
    std::vector<std::string> songs;
    std::vector<int> line_counter;
    std::string path = "text/";

/** @brief:  For all files in the given directory (passed as a string), the names of the files in the directory are put into the vector of strings "songs" **/
    for (const auto & file : directory_iterator(path))
        songs.emplace_back(file.path());
    
    line_counter = count_lines_in_files((songs));

// Printing the number of lines in all songs
    for(const auto n : line_counter)
        std::cout << n << std::endl;
    
    
    return 0;
}
