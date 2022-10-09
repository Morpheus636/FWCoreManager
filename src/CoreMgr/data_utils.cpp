#include <vector>
#include <string>
#include <fstream>

namespace data_utils {

const std::string WHITESPACE = " \n\r\t\f\v";


// Public Function
std::string StringLTrim(const std::string &s) {
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}


// Public Function
std::string StringRTrim(const std::string &s) {
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}


// Public Function
std::string StringTrim(const std::string &s) {
    return StringRTrim(StringLTrim(s));
}


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
std::vector<std::string> StringSplit(std::string original_string, std::string delimiter) {
    std::vector<std::string> split_strings;
    // TODO - Write split_string function
    return split_strings;
}


} // namespace data_utils
