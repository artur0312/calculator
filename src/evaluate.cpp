//The function to evaluate an expression
//For a detailed explanation of the grammar that generated this program, see Programming, Principles and Practice with C++
#include "decls.h"
#include "token.h"
#include "evaluate.h"
#include "error.h"
#include "variables.h"
extern Token_stream ts;
double statement(){
	Token t=ts.get();
	switch(t.type){
		case t_let:
			return declaration();
		default:
			ts.putback(t);
			return expression();
	}
}
double declaration(){
	Token t=ts.get();
	if(t.type!=t_name){
		error("Unexpected name for a variable");
	}
	std::string var_name=t.name;
	Token t2=ts.get();
	if(t2.type!= t_equal){
		error("Expected '=' in the declaration of the variable "+var_name);
		}
	double d=expression();
	define_name(var_name,d);
	return d;
}


double expression(){
	double lvalue=term();
	Token t=ts.get();
	while(true){
		switch(t.type){
			case t_plus:
				lvalue+=term();
				t=ts.get();
				break;
			case t_minus:
				lvalue-=term();
				t=ts.get();
				break;
			//If there are no more '+' and '-'
			default:
				ts.putback(t);
				return lvalue;
				break;
		}
	}
}

double term(){
	double lvalue=primary();
	Token t=ts.get();
	while(true){
		switch(t.type){
			case t_star:
				lvalue*=primary();
				t=ts.get();
				break;
			case t_slash:
				{
					double zero_check=primary();
					if(!zero_check)
						error("Division by zero");
					lvalue/=zero_check;
					t=ts.get();
					break;
				}
				//Handles modulo of doubles
			case t_percentage:
				{
					double d=primary();
					if(d==0)
						error("%:divide by zero");
					lvalue=std::fmod(lvalue,d);
					t=ts.get();
					break;
				}
			//If there are no more '*','/',and '%'
			default:
				ts.putback(t);
				return lvalue;
		}
	}
}

//Evaluate a number or an expression in parenthesis
double primary(){
	Token t=ts.get();
	switch(t.type){
		case t_num_val:
			return t.value;
			break;
		case t_open_par:
			{
				double result=expression();
				t=ts.get();
				if(t.type==t_close_par){
					return result;
				}
				else{
					error("Expected ')'");
				}
				break;
			}
		//Allows handling trailing + and - at the beggining of the expression
		case t_minus:
			return -primary();
		case t_plus:
			return primary();
		case t_name:
			return get_value(t.name);

		default:
			error("Primary expected");
	}
	return 1;
}
