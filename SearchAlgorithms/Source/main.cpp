#include "Maze.h"

int main()
{
	Maze maze{ "../../../SearchAlgorithms/Assets/maze3.txt" };
	maze.WriteMaze();

	return 0;
}