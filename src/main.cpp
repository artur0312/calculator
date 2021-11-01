//This is the main loop of the program
#include "decls.h"
#include "token.h"
#include "variables.h"
#include "evaluate.h"
#include "error.h"
//Global variable denoting the token stream
Token_stream ts;
//Global variable that will store the table of variables
std::vector<Variable> var_table;

void calculate(){	//expression evaluation loop
	//The input and output prompts
	const std::string prompt=">>";
	const std::string result="=";	
	while(std::cin){
		try{
			std::cout<<prompt;
			Token t=ts.get();
			while(t.type==t_semicolon)
				t=ts.get();
			if(t.type==t_exit_char) return;
			ts.putback(t);
			std::cout<<result<<statement()<<'\n';


		}
		catch(std::exception& e){
			std::cerr<<e.what()<<'\n';
			//skip until the next expression
			ts.ignore(';');
		}
	}
}


int main(){
	try{
		define_name("pi",3.1415926535);
		define_name("e",2.71828459045);
		calculate();
		return 0;
	}
	catch(std::runtime_error &e){
		std::cerr<<e.what()<<'\n';
		return 1;
	}
}


