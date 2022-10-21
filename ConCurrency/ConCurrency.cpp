#include "MainManager.hpp"

int main()
{
	/*void displayTitle()
	{

	}*/
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\033[97m       $$$$                            $$$$                                                                  \033[0m" << std::endl;
	std::cout << "\033[97m      $    $                          $    $                                                                 \033[0m" << std::endl;
	std::cout << "\033[97m     $           $$$      $$$$$      $          $      $  $   $  $   $   $$$$   $$$$$     $$$$    $    $     \033[0m" << std::endl;
	std::cout << "     $         $     $    $     $    $          $      $  $ $    $ $    $    $  $    $   $    $   $    $     " << std::endl;
	std::cout << "     $        $       $   $     $    $          $      $  $      $      $$$$$   $    $   $        $    $     " << std::endl;
	std::cout << "     $         $     $    $     $    $          $      $  $      $      $       $    $   $    $    $$$$$     " << std::endl;
	std::cout << "\033[90m      $    $     $$$      $     $     $    $      $$$$    $      $       $$$$   $    $    $$$$         $     \033[0m" << std::endl;
	std::cout << "\033[90m       $$$$                            $$$$                                                          $$$     \033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

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
