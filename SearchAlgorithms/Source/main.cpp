#include "FileManager.h"

int main()
{
	std::fstream file{};
	if (FileManager::OpenFile(file, "Assets/maze1.txt"))
	{
		FileManager::ReadFile(file);
	}

	return 0;
}