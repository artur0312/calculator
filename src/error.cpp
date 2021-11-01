//The basic error function used throughout this program
#include "decls.h"
void error(const std::string &s){
	throw std::runtime_error(s);
}
