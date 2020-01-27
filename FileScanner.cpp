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
			if(fileShouldBeAdded(path))
			file_List.push_back(entry.path().string());
		}

	}

}

bool FileScanner::fileShouldBeAdded(std::string f_path) {

	std::string	comma = f_path.substr(f_path.find_last_of('.'));

	for (auto i : fileTypes) {
		if (comma == i) return true;
	}

	return false;
}