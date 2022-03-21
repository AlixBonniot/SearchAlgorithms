#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <fstream>
#include <string>

class FileManager
{
public:
	FileManager() = default;

	static bool OpenFile(std::fstream& file, const std::string& filename);
	static void ReadFile(std::fstream& file);	
};

#endif