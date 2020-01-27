#include <iostream>
#include <string>
#include "FileScanner.h"

int main()
{
	std::string path;

	std::cout << "Write path to project:";

	std::cin >> path;

	FileScanner fs = FileScanner(path);
	
	std::vector<std::string> fileList = fs.getFile_List();

	for (auto& str : fileList) {
		std::cout << str << "\n";
	}



	return 0;
}

