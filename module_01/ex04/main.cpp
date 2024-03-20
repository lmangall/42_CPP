#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::string readFileContent(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) return "";
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();

    return content;
}


// Function to write content to a file
bool writeToFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename.c_str());
    if (!file.is_open()) return false;
    file << content;
    return true;
}


// Function to replace all occurrences of 'from' with 'to' in 'original'
std::string customReplace(const std::string& original, const std::string& from, const std::string& to) {
    if (from.empty()) return original; // Prevent infinite loop

    std::string result;
    size_t start = 0, pos;

    while ((pos = original.find(from, start)) != std::string::npos) {
        // Append everything before the occurrence of 'from'
        result.append(original.substr(start, pos - start));
        // Append the replacement string 'to'
        result.append(to);
        // Update starting position to search after the replaced string
        start = pos + from.length();
    }

    // Append the remaining part of the original string after all replacements
    result.append(original.substr(start));
    return result;
}

bool parse(const std::string& filename, const std::string& s1, const std::string& s2) {
	// std::string content = readFileContent(filename);
	// if (content.empty()) {
	// 	std::cerr << "Failed to read from file: " << filename << std::endl;
	// 	return false;
	// }

	// std::string modifiedContent = customReplace(content, s1, s2);

	// if (!writeToFile(filename, modifiedContent)) {
	// 	std::cerr << "Failed to write to file: " << filename << std::endl;
	// 	return false;
	// }

	// return true;

	if (filename.empty() || s1.empty() || s2.empty()) {
		std::cerr << "Error: Invalid input: filename, string1 or string2 is empty" << std::endl;
		return false;
	}

	if(s1 == s2) {
		std::cerr << "Error: string1 and string2 are identic" << std::endl;
		return false;
	}

	return true;
}

int main(int argc, char* argv[]) {

	// std::cout << std::endl;

	if(argc != 4) {
		std::cerr << "Error: Invalid input (wrong number of arguments)" << std::endl;
        std::cout << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
		return 1;
	}

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string outputName = filename + ".replace";

	if(!parse(filename, s1, s2)) {
		return 1;
	}

    std::string content = readFileContent(filename);
    if (content.empty()) {
        std::cerr << "Failed to read from file: " << filename << std::endl;
        return 1;
    }

    std::string modifiedContent = customReplace(content, s1, s2);

    if (!writeToFile(outputName, modifiedContent)) {
        std::cerr << "Failed to write to file: " << outputName << std::endl;
        return 1;
    }

    return 0;
}
