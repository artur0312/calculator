#include "decls.h"
#include "variables.h"
#include "error.h"
extern std::vector<Variable> var_table;
double get_value(std::string s){
	for(Variable v:var_table){
		if(v.name==s){
			return v.value;
		}
	}
	error("undefined variable: "+s);
	return 0;
}

void set_value(std::string s,double d){
	for(Variable v:var_table){
		if(v.name==s){
			v.value=d;
			return;
		}
	}
	error("undefined variable: "+s);
}

bool is_declared(std::string var){
	for(Variable v:var_table){
		if(v.name==var){
			return true;
		}
	}
	return false;
}

double define_name(std::string var, double val){
	if(is_declared(var)){
		error("This variable is already declared");
	}
	Variable temp{var,val};
	var_table.push_back(temp);
	return val;
}
