# Calculator

This is a calculator based on the one described in the book "Programming: Principles and Practice Using C++"

## Description

This project is a calculator that handles not only operations, but also expressions. The operations that are handled are addition `+`, subtraction `-`, multiplication `*`, division `/`, and floating-point modulo `%`. All the number literals are floating point numbers. The program follows the traditional order of precedence of operators, but parenthesis can be used to alter this order. Finally, the program has support for variables, to see the details about this features, see [variables](#variables)

## Compiling and running

To compile the program, run the makefile on the source directory. It will produce a file called `calculator` on Linux systems and `calculator.exe` on Windows. Then just run the executable file to start the calculator.

The prompt for input is `>>`. Every expression must terminate with a semicolon and a line will appear with the output prompt `=`, showing the result of the evaluation. Then, it will be possible to enter a new expression and the loop of the program continues like this. When you are done, enter `q` and press `ENTER` to exit the program.

If there is a problem and it is not possible to write an expression after an error, entering a semicolon will open a new input prompt

## Variables

Variables must start with a letter and can contain numbers and letters. To declare a variable `phi` with value `10` for example, enter
    let phi = 10;
The right hand side doesn't need to be a number literal, it can be any expression, which can include other variables. The program already defines two variables, `pi` and `e`, Euleur's number.

**ATTENTION:** The program doesn't support the assignment operator, so it isn't possible to modify the value of a variable after defining it. Trying to redefine will generate an error, as it is understood that this is a typo.

## Grammar

This section describes the formal grammar that this calculator follows.
```
<Calculation>	::= <Declaration> | <Expression>

<Declaration>	::= "let" <Name> "=" <Expression>

<Name>			::= [a-zA-Z][a-zA-Z0-9]*

<Expression>	::= <Term> | <Expression> "+" <Term> | <Expression> "-" <Term>

<Term>			::= <Primary> | <Primary> | <Term> "*" <Primary> | <Term> "/" <Primary> | <Term> "%" <Primary>

<Primary>		::= <Number> | "(" Expression ")" | <Name>

<NUMBER>		::= floating-point-literal

```
