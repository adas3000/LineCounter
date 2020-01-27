#include "FileScanner.h"

FileScanner::FileScanner(std::string path) {
	this->path = path;
	this->directoryOk = std::experimental::filesystem::exists(path);
	if (directoryOk) {
		doFindFiles(path);
	}
}

FileScanner::~FileScanner() {

}

void FileScanner::doFindFiles(std::string path) {


	for (const auto& entry : std::experimental::filesystem::directory_iterator(path)) {

		if (std::experimental::filesystem::is_directory(entry.path())) {
			doFindFiles(entry.path().string());
		}
		else {
			file_List.push_back(entry.path().string());
		}

	}

}