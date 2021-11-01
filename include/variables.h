#ifndef VARIABLES_H
#define VARIABLES_H
//Store a variable
class Variable{
	public:
		std::string name;
		double value;
};

//Get the numerical value stored in a variable
double get_value(std::string s);
//Change the value of a variable
void set_value(std::string s,double d);
//See if the variable is declared in var_table
bool is_declared(std::string var);
//Add the variable to var_table
double define_name(std::string var, double val);
#endif

