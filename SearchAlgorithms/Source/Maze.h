#ifndef MAZE_H
#define MAZE_H

#include "Vector3D.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Maze
{
public:
	class Tile
	{
	public:
		enum class Type
		{
			Standart,
			Explored,
			Path,
			Wall,
			Start,
			End
		};

	public:
		Tile();
		Tile(const Type type, const Vector3D& color);

		Type GetType() const;
		const Vector3D& GetColor() const;

	private:
		Type m_type;
		Vector3D m_color;
	};

public:
	Maze(const std::string& filename);

	void WriteMaze();

private:
	void InitializeMaze(const std::string& filename);
	void WritePixel(std::ostream& out, const Vector3D& color);

private:
	std::vector<Tile> m_maze;

	int m_mazeWidth;
	int m_mazeHeight;

	static constexpr int m_tileWidth{ 100 };
	static constexpr int m_tileHeight{ 100 };
};

#endif