#pragma once

#include <string>
#include <fstream>

namespace Utilities
{
	class fileReader
	{
	private:
		fileReader(const fileReader&) = delete;

		fileReader() {}

		std::string IreadFile(std::string filePath);
	public:
		static fileReader& get();

		static std::string readFile(std::string filePath);
	};
}
