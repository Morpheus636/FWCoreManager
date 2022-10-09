#include <list>
#include <string>
#include <fstream>

namespace data_utils {

// Public function.
std::string FindLine(std::string file_path, std::string substring) {
    // Open the file as an input string.
    std::ifstream file(file_path);
    // Loop through the file line-by-line and check it for the substring.
	for (std::string line; std::getline(file, line);) {
		if (line.find(substring) != std::string::npos) {
            // Close the file and return the line if the substring is found.
            file.close();
            return line;
        }
	}
    // Close the file and return an empty string if the substring isn't found.
    file.close();
    std::string line = "";
    return line;
}


// Public function.
std::list<std::string> SplitString(std::string original_string, std::string delimiter) {
    std::list<std::string> split_strings;
    // TODO - Write split_string function
    return split_strings;
}


} // namespace data_utils
