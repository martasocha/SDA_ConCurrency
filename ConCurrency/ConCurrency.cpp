#include "MainManager.hpp"

int main()
{
	try
	{
		MainManager m;
		m.mainFunction();
	}
	catch (const std::exception& error)
	{
		std::cout << "Błąd! " << error.what() << std::endl;
	}
}
