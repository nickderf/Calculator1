

#ifndef CALC_H
#define CALC_H


#include <iostream>
#include "Stack_Command_Factory.h"
#include <string>
#include <sstream>
#include "Array.h"
#include "Stack.h"
#include "Expr_Iterator.h"
#include "variable.h"
#include <ctype.h>


class Calc
{
public:

	Calc(Stack<int> &result, std::string infix);
	
	~Calc();
	
	void handle_cmd();
	
	//This sorts the variables in alphabetical order using ASCII values
	void get_var_values(int amt);
	
	//Create number commands for variable's after we know the values of these variables
	void switchout_variables(int amt);
	
	//Delete all the variable's created because they were allocated on the heap
	void delete_variables(int amt);
	
	//Take an infix math expression and convert it to postfix
	bool infix_to_postfix();
	
	//Take an expression iterator and evaluate it the postfix array of expression commands
	void eval_postfix(Expr_Iterator &iter);

	//Retrieve postfix array
	Array<Expr_Command *>& getPostfix();
	
	void empty_operator_stack(Stack<Expr_Command *>& s);
	
	//This will swap variable positions in the variable array
	void swap_var(int i);
	
	//This will get the the input the correct amount of times for each different variable
	void var_input(int amt);

private:

	//An array containing expression commands in postfix order
	Array<Expr_Command*> postfix;
	
	//An array of variable commands
	Array<variable *> var;
	
	//Factory that creates commands
	Stack_Command_Factory factory;
	
	//Token used to represent 
	std::string token;
	
	//Global stack of operators that is worked on when not inside of any parenthesis
	//Numbers immediately go to the postfix array while operators are manipulated on the stack
	//I don't want it to be called temp anymore, but as of right now I do not want to change it
	Stack<Expr_Command*> temp;
	
	//A pointer to an individual expression command
	Expr_Command *cmd;
	
	//Current position in the postfix array
	int arr_pos;
	
	//Current position in the array storing the variables
	int var_array_pos;
	
	//String of infix
	const std::string infix;
	
	//String Stream used to parse infix expression
	std::istringstream input;
	
	//Parenthesis count: How many open parenthesis we have
	int par_count;
	//Array of Expr_Command* stacks. Need a stack per open parenthesis
	Array<Stack<Expr_Command *>> operator_array;
	
};


#endif //!defined CALC_H