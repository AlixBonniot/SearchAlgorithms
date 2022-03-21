#include "FileManager.h"

#include <iostream>

bool FileManager::OpenFile(std::fstream& file, const std::string& filename)
{
	// The function tries to open the fstream and triggers a warning
	// if it didn't succedeed
	file.open(filename, std::ios::in | std::ios::out | std::ios::binary);
	if (!file.is_open())
	{
		std::cerr << "FileManager::OpenFile() - File didn't open properly\n";
		return false;
	}

	return true;
}

void FileManager::ReadFile(std::fstream& file)
{
	char character{};
	while (!file.eof())
	{
		file.get(character);
		std::cout << character;
	}
}
