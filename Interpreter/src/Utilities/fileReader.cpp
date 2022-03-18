#include "fileReader.h"
#include <limits>
#include <iostream>

namespace Utilities
{
	fileReader& fileReader::get()
	{
		static fileReader instance;
		return instance;
	}

	std::string fileReader::readFile(std::string filePath)
	{
		return get().IreadFile(filePath);
	}

	std::string fileReader::IreadFile(std::string filePath)
	{
		std::string data;

		std::fstream file;
		file.open(filePath, std::ios::in);
		if(file.is_open())
		{
			std::string line = "";
			while(std::getline(file, line))
			{
				data.append(line+'\n');
			}
		}
		file.close();
		return data;
	}
}
