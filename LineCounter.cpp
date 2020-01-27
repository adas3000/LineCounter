#include <iostream>
#include <string>
//#include "FileScanner.h"
#include "FileChecker.h"

int main()
{
	std::string path;

	std::cout << "Write path to project:";

	std::cin >> path;
	
	/*
	FileScanner fs = FileScanner(path);
	for (auto& i : fs.getFile_List()) {
		std::cout << i << "\n";
	}
	*/
	try{

	FileChecker fc = FileChecker(path);

	int lineCount = fc.getTotalLineCount();

	std::cout << "Total line count is:" << lineCount << "\n";

	}
	catch (std::exception e) {
		std::cout << "Error:" << e.what() << "\n";
	}
	
	return 0;
}

