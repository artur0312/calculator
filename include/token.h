#ifndef TOKEN_H
#define TOKEN_H

//The enumeration that list the types of tokens of the program
enum Token_types{t_plus,t_minus,t_star,t_slash,t_open_par,t_close_par,t_num_val,t_semicolon,t_exit_char,t_percentage,t_let,t_equal,t_name};

//Class to hold a token
class Token{
	public:
		Token_types type;
		double value;
		std::string name;
		Token(Token_types ch): type{ch} {}
		Token(Token_types ch,double val):type{ch},value{val} {}
		Token(Token_types ch,std::string s):type{ch},name{s} {}
};

//Class to read the tokens
class Token_stream{
	public:
		//Get the next token
		Token get();
		//Put the token on the istream to be read by get
		void putback(Token t);
		//Skip reading tokens until the character c
		void ignore(char c);
		//Default constructor

		Token_stream():full{false},buffer(t_plus){
		}
	private:
		bool full;
		Token buffer;
};

#endif
