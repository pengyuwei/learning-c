// extract to string
#include <iostream>
#include <string>

int main ()
{
  std::string cmd;

  std::cout << "Enter u name or press ^D: ";
  std::getline (std::cin, cmd);
  std::cout << "Hello, " << cmd << "!\n";
  std::getline (std::cin, cmd);
  if (std::cin.eof()) {
      std::cout << "eof" << std::endl;
  }
  std::cout << "Hello, " << cmd<< "!\n";
  std::cin.clear();
  std::cin.ignore();

  while ( getline( std::cin, cmd) ) {
    std::cout << " " << cmd<< std::endl ;
    if (cmd == "exit") {
        break;
    }
  }

  return 0;
}
