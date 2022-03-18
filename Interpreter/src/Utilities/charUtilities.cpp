#include "charUtilities.h"
#include <limits>
#include <iostream>

namespace Utilities
{
	charUtilities& charUtilities::get()
	{
		static charUtilities instance;
		return instance;
	}

	bool charUtilities::isDigit(char c)
	{
		return get().IisDigit(c);
	}

	bool charUtilities::IisDigit(char c)
	{
		return (c >= '0') && (c <= '9');
	}
}
