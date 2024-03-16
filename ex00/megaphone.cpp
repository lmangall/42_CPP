#include<iostream>

int main(int argc, char **argv)
{
	if(argc == 1)
	{
        // std::cout is the C++ way of outputting to the console.
        // It is part of the std namespace, which contains standard library functions.
        // The << operator is used to send the data to the output stream (console here).
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else
	{
        // toupper is wrapped in a (char) cast to ensure the result is treated as a char
        // because toupper returns an int which can cause unwanted implicit conversions.
		for(int i = 1; argv[i]; i++)
		{
			for(int j = 0; argv[i][j]; j++)
			{
			std::cout << (char) toupper(argv[i][j]);
			}
		if(argv[i + 1])
			std::cout << " ";
		}
	}

	std::cout << std::endl;
	return(0);
}
