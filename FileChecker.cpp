#include "FileChecker.h"

FileChecker::FileChecker(std::string path)
	:fileScanner(path)
{
	this->totalLineCount = 0;
	if (!fileScanner.getDirectoryOk()) {
		throw "No Such Directory";
	}
	files = fileScanner.getFile_List();
	doFileCheck();
}

FileChecker::~FileChecker()
{
}

void FileChecker::doFileCheck() {
	
	std::fstream fileOpener;
	std::string line;
	for (auto& path : files) {
		fileOpener.open(path, std::fstream::in);
		if (!fileOpener.is_open()) {
			throw "Cannot open file";
		}
		
		while (!fileOpener.eof()) {
			std::getline(fileOpener, line);
			totalLineCount++;
		}
			
		fileOpener.flush();
		fileOpener.close();
	}
}