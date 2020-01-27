#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include "FileScanner.h"

class FileChecker
{
private:
	FileScanner fileScanner;
	std::vector<std::string> files;
	unsigned int totalLineCount;
public:
	FileChecker(std::string path);
	~FileChecker();
	inline unsigned int getTotalLineCount() { return totalLineCount; }
private:
	void doFileCheck();


};

