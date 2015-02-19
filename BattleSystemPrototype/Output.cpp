#include "Output.h"


Output::Output()
{
}


Output::~Output()
{
}


void Output::message( std::string message )
{
	std::cout << message;
}


void Output::messageLine( std::string message )
{
	std::cout << message << std::endl;
}