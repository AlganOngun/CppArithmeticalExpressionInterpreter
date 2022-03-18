#pragma once

#include <string>
#include <fstream>

namespace Utilities
{
	class charUtilities
	{
	private:
		charUtilities(const charUtilities&) = delete;

		charUtilities() {}

		bool IisDigit(char c);
	public:
		static charUtilities& get();

		static bool isDigit(char c);
	};
}
