
#include <iostream>
#include "Stack_Command_Factory.h"
#include <string>
#include <sstream>
#include "Array.h"
#include "Stack.h"
#include "Expr_Iterator.h"
#include "variable.h"
#include <ctype.h>
#include "Calc.h"

// COMMENT: Instead of using C functions to implement parts of the
// calculator. It would be better suited to use a Wrapper Facade.

//I put the functions I was using in my driver file into their own class


std::string menu()
{
	
	//Take in the math expression that user wants evaluated. Expecting spaces inbetween each character
	std::string infix = "";
	std::cout << "Enter an expression: ";
	std::getline(std::cin, infix);
	return infix;
}
int main()
{
	int go = 0;
	while (go == 0)
	{
		Stack<int> result;
		
		std::string infix = menu();
		
		//Initialize a calculator that will take in a stack result and an infix expression to evaluate
		Calc calculator(result, infix);
	
		//Need to translate that math expression into postfix format, which modifies the postfix array to have each correctly
		//formatted/indexed character in the expression made into a command that will be iterated over and executed
		calculator.infix_to_postfix();

		//Initialize an iterator that will be able to iterate over an array of expr_command's
		//call eval_postfix to execute each command
		Expr_Iterator iter(calculator.getPostfix());
		calculator.eval_postfix(iter);

		//Result stack is what is being manipulated during execution of commands. At the end, the top of the stack has
		//the answer to the math expression
		int ans = result.top();

		
		std::cout << "Your answer is: " << ans << std::endl;

		std::string x;
		std::getline(std::cin, x);
		if (x == "QUIT")
		{
			go = 1;
		}
		
	}
	
	
	return 0;

}
