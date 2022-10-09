#ifndef FWCOREMANAGER_COREMGR_data_utils_H_
#define FWCOREMANAGER_COREMGR_data_utils_H_

#include <string>
#include <list>

namespace data_utils {

// Private function.
// Iterates over the contents of `file_path` line-by-line until it finds a line
// containing the substring `substring`. Returns the entire line.
//
// If there are multiple lines containing the substring, it will always
// return the first one. If it reaches the end of the file and does not find
// the substring, it will return an empty string.
std::string FindLine(std::string file_path, std::string substring);


// Splits the `original_string` on the `delimiter` and returns them in a list.
std::list<std::string> SplitString(std::string original_string, std::string delimiter);


} // namespace data_utils
#endif
