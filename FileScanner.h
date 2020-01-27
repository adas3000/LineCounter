#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <filesystem>

class FileScanner
{
public:
	enum FileTypes{java,cpp,c,kt,h};
private:
	bool directoryOk;
	std::string path;
	std::vector<std::string> file_List;
public:
	FileScanner(std::string path);
	~FileScanner();
	inline bool getDirectoryOk() { return directoryOk; }
	inline std::vector<std::string> getFile_List() { return file_List; }
private:
	void doFindFiles(std::string path);
};
