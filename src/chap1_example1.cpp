#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>

using namespace std::filesystem; 

/** @brief: Counts the number of lines in a file by creating ifstream objects from the filenames passed to it **/
std::vector<int> count_lines_in_files(const std::vector<std::string>& files)
{
    std::vector<int> results;
    char c = 0;
     for(const auto& file : files) {
         int line_count = 0;

         std::ifstream in(file);
         while(in.get(c)) {
            if(c == '\n') 
                line_count++;
         }
         results.push_back(line_count);
     }
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
