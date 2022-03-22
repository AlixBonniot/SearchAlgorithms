#include "Maze.h"

#include <cassert>

Maze::Maze(const std::string& filename)
: m_maze{}
, m_mazeWidth{ 0 }
, m_mazeHeight{ 0 }
{
	assert(!filename.empty() && "Maze::Maze() - filename is empty");

	// We compute the maze width and height for later use
	InitializeMaze(filename);
}

void Maze::WriteMaze()
{
	// This function will read the file and output in
	// a more graphical way, in a .ppm image format
	const int imageWidth{ m_mazeWidth * m_tileWidth };
	const int imageHeight{ m_mazeHeight * m_tileHeight };

	std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

	Tile tile{};
	for (int y{ 0 }; y < imageHeight; ++y)
	{
		std::cerr << "\rScanline remaining: " << (imageHeight - y) << ' ' << std::flush;

		for (int x{ 0 }; x < imageWidth; ++x)
		{
			if ((x % m_tileWidth) == 0)
			{
				const int index{ (m_mazeWidth * (y / 100)) + (x / 100) };
				tile = m_maze[index];
			}

			WritePixel(std::cout, tile.GetColor());
		}
	}

	std::cerr << "\nDone\n";
}

void Maze::InitializeMaze(const std::string& filename)
{
	// We try to open the fstream and trigger a warning
	// if we didn't succedeed
	std::fstream file{ filename, std::ios::in | std::ios::out | std::ios::binary };
	if (!file.is_open())
	{
		std::cerr << "FileManager::OpenFile() - File didn't open properly\n";
	}

	const Vector3D green{ 0.0f, 255.0f, 0.0f };
	const Vector3D red{ 255.0f, 0.0f, 0.0f };
	const Vector3D lightGray{ 172.0f, 172.0f, 172.0f };
	const Vector3D darkGray{ 17.0f, 17.0f, 17.0f };

	// We will read the file, and find the width and height
	// by count reference
	bool bWidthComputed{ false };
	char character{};
	while (!file.eof())
	{
		file.get(character);
		if ((character == '\n'))
		{
			++m_mazeHeight;
			bWidthComputed = true;
		}
		else if ((character != 'n'))
		{
			if (!bWidthComputed)
			{
				++m_mazeWidth;
			}
			
			if (character == 'A')
			{
				m_maze.emplace_back(Tile{ Tile::Type::Start, green });
			}
			else if (character == 'B')
			{
				m_maze.emplace_back(Tile{ Tile::Type::End, red });
			}
			else if (character == ' ')
			{
				m_maze.emplace_back(Tile{ Tile::Type::Standart, lightGray });
			}
			else if (character == '#')
			{
				m_maze.emplace_back(Tile{ Tile::Type::Wall, darkGray });
			}

		}
	}

	--m_mazeHeight;
}

// Function that write a pixel to the stream
// R, G, B varie from 0.0f to 1.0f and we convert them
// to 255 ASCII format
void Maze::WritePixel(std::ostream& out, const Vector3D& color)
{
	// Here X, Y and Z, replace the RGB value
	// because we are using a Vector3D
	// as Color data type
	out << static_cast<int>(color.x) << ' '
		<< static_cast<int>(color.y) << ' '
		<< static_cast<int>(color.z) << '\n';
}

Maze::Tile::Tile()
	: m_type{ Type::Standart }
	, m_color{}
{
}

Maze::Tile::Tile(const Type type, const Vector3D& color)
: m_type{ type }
, m_color{ color }
{
}

Maze::Tile::Type Maze::Tile::GetType() const
{
	return m_type;
}

const Vector3D& Maze::Tile::GetColor() const
{
	return m_color;
}
