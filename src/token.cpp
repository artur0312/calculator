#include "decls.h"
#include "token.h"
#include "error.h"


//Put the token we just read on a buffer to be read on the next call of get()
void Token_stream::putback(Token t){
	if(full){
		error("Cannot invoke putback without emptying it first\n");
	}
	else{
		full=true;
		buffer=t;
	}
}

//Read the next token
Token Token_stream::get(){
	char c;
	if(full){
		full=false;
		return buffer;
	}
	std::cin>>c;
	switch(c){
		case '+':
			return Token{t_plus};
		case '-':
			return Token{t_minus};
		case '*':
			return Token{t_star};
		case '/':
			return Token{t_slash};
		case '(':
			return Token{t_open_par};
		case ')':
			return Token{t_close_par};
		case ';':
			return Token{t_semicolon};
		case '%':
			return Token{t_percentage};
		case quit:
			return Token{t_exit_char};
		case '=':
			return Token{t_equal};
		case '.': case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
			{
				std::cin.putback(c);
				double val;
				std::cin>>val;
				return Token{t_num_val,val};
			}
		default:
			if(isalpha(c)){
				std::string s;
				s+=c;
				while(std::cin.get(c) && isalpha(c)||isdigit(c))
					s+=c;
				std::cin.putback(c);
				if(s==declkey)
					return Token{t_let};
				return Token{t_name,s};
			}
			error("Bad Token");
			return Token(t_exit_char);
	}
}

void Token_stream::ignore(char c){
	//First look in the buffer
	if(full && c==buffer.type){
		full=false;
		return;
	}
	full=false;

	char ch=0;
	while(std::cin>>ch){
		if(ch==c)
			return;
	}
}

