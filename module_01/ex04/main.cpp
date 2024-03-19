#include <string>

Files to turn in : Makefile, main.cpp, *.cpp, *.{h, hpp}
Forbidden functions : std::string::replace

// Create a program that takes three parameters in the following order: a filename and
// two strings, s1 and s2.

// It will open the file <filename> and copies its content into a new file
// <filename>.replace, replacing every occurrence of s1 with s2.

// Using C file manipulation functions is forbidden and will be considered cheating. All
// the member functions of the class std::string are allowed, except replace. Use them
// wisely!

// Of course, handle unexpected inputs and errors. You have to create and turn in your
// own tests to ensure your program works as expected.

int main(int argc, char argv)
{
	if (argc != 3)
		std::cout << "please provide 3 args: a filename and two strings" << std::endl;

	std::ifstream	originFS("string inside the filestream")

	std::ofstream outputFS(argv(1));

	std::replace

	StringBuilder sb

	originFS.close();
	
return 0;
}