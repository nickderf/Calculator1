#include "Calc.h"

Calc::Calc(Stack<int>&result, std::string infix_)
	:postfix(Array<Expr_Command *> (50)),
	factory(result),
	infix(infix_),
	var(Array<variable *> (50)),
	token(""),
	cmd(0),
	arr_pos(0),
	var_array_pos(0),
	par_count(0),
	input(infix),
	operator_array(Array<Stack <Expr_Command *>> ())
{
	//Temp (global operator stack) needs to be put on the operator array immediately
	operator_array.set(0, this->temp);
	
}

Calc::~Calc()
{
	
}

//Empty stack, but needs  to have a stack passed to it
void Calc::empty_operator_stack(Stack<Expr_Command*> &s)
{
	//Empty the stack and put the remaining operators into the postfix array.
	while (!s.is_empty())
	{
		Expr_Command* tempCmd = s.pop();
		this->postfix[arr_pos] = tempCmd;
		this->arr_pos++;
		
	}
}
//Convert an infix math expression to postfix form
bool Calc::infix_to_postfix()
{
	
	
	//While iterating through the parsed string we passed..
	while(!input.eof())
	{
		
		//Get the next part of the expression, starting with first character
		this->input >> this->token;
		char c_token = this->token[0];
		
		//Create corresponding command for corresponding operator
		//If open parenthesis, create a new temp stack for current parenthesis to work on and increase parenthesis count
		if(token == "(")
		{
			Stack<Expr_Command*> s;
			this->par_count ++;
			this->operator_array.set(this->par_count, s);
			this->infix_to_postfix();
		}
		else if (token == "+")
		{
			this->cmd = factory.create_add_command();
			this->handle_cmd();
		}
		else if (token == "-")
		{
			this->cmd = factory.create_sub_command();
			this->handle_cmd();
		}
		else if (token == "*")
		{
			this->cmd = factory.create_mult_command();
			this->handle_cmd();
		}
		else if (token == "/")
		{
			this->cmd = factory.create_div_command();
			this->handle_cmd();
		}
		else if (token == "%")
		{
			this->cmd = factory.create_mod_command();
			this->handle_cmd();
		}
		//Check to see if it is a variable
		else if (isalpha(c_token))
		{
			//Create new variable and insert in variable array
			variable *tempVar = new variable(c_token);
			this->var.set(this->var_array_pos, tempVar);
			
			//Create a blank number command to fill in the spot in the postfix array
			this->cmd = factory.create_num_command(tempVar->getNumber());
			this->postfix[arr_pos] = cmd;
			
			//Remember the position this is at in the postfix array to replace it later
			tempVar->setPostfixPos(this->arr_pos);
			
			this->arr_pos++;
			this->var_array_pos++;
			
		}
		//Return and pop current operators in stack, decrease parenthesis count
		else if(token == ")")
		{
			empty_operator_stack(this->operator_array[this->par_count]);
			this->par_count --;
			return true;
		}
		//If none of the above, then it is a number.
		else
		{
			std::istringstream iss(token);
			int number;
			iss>> number;
			this->cmd = factory.create_num_command(number);
			this->postfix[arr_pos] = this->cmd;
			this->arr_pos++;
		
		}
	}
	//After this we need to empty the operator stack
	empty_operator_stack(this->operator_array[this->par_count]);
	
	//Need to resize the array because when we use an iterator to iterate over the array, it relies on the number of elements
	//actually in the array. 
	//Alternatively, I tried to use a member of the array that holds the amount of elements currently in the array
	//but ran into problems with it. Another way to deal with this is initializing the array with the correct amount of space
	this->postfix.resize(this->arr_pos);
	
	//Now we get the values for any variables used in the expression.
	if (this->var_array_pos > 0)
	{
		
		this->get_var_values(this->var_array_pos);
		this->var_input(this->var_array_pos);
		this->switchout_variables(this->var_array_pos);
	}
	this->delete_variables(this->var_array_pos);
	return true;
}

void Calc::handle_cmd()
{
	//Logic for handling command

    // COMMENT Although you are pushing "nullptr" to represent a parenthesis,
    // you are basically saying a parenthesis is a command. Moreover, what
    // happens if you have another "special" token that needs to go onto the
    // stack. You cannot use a nullptr for that one.  Create a design that does
    // not require having parenthesis as as command object since parenthesis are
    // not executed.

		//Reworked parenthesis

	if (this->operator_array[this->par_count].is_empty())
	{
		this->operator_array[this->par_count].push(this->cmd);
	}
	
	//If operator and it has a higher precedence than the top of stack, push the operator onto the stack
	//Lower priority number means higher precedence
	else if (this->operator_array[this->par_count].top() != 0)
	{
		
		if (this->cmd->priority() < this->operator_array[this->par_count].top()->priority())
		{
		
			this->operator_array[this->par_count].push(cmd);
		}
		//Otherwise if it has a lower precedence, pop the stack and place the operators on the postfix array until the operator
		//has a lower or equal precedence to top of stack
		else
		{

			while (!this->operator_array[this->par_count].is_empty() && this->operator_array[this->par_count].top() != 0 && this->cmd->priority() >= this->operator_array[this->par_count].top()->priority())
				{
					
					this->postfix[this->arr_pos] = this->operator_array[this->par_count].pop();
					this->arr_pos++;
				}
			

			//Push the operator we've been working with onto the stack
			this->operator_array[this->par_count].push(this->cmd);

		}
	}

	else
	{
		
		this->operator_array[this->par_count].push(this->cmd);
	}

}


void Calc::swap_var(int i)
{
	variable * temp = this->var[i];
	this->var[i] = var[i + 1];
	this->var[i + 1] = temp;
}

void Calc::var_input(int amt)
{
	//Ask for the user's input for what each variable is
	
	//this array temporarily stores which variables we are using in our current expression
	Array <variable*> var_arr(amt);
	
	//Position in the temp array storing variables and their inputs
	int arr_pos = 0;
	
	for (int i = 0; i < amt; i++)
	{
		//when dont_set is 0 this means that the current variable we are working with is the first iteration of the variable
		int dont_set = 0;
		
		//iterate through temp variable array to see if we have already set a value for this variable
		for(int j = 0; j < arr_pos; j++)
		{
			if(this->var[i]->getLetter() == var_arr[j]->getLetter())
			{
				this->var[i]->setNumber(var_arr[j]->getNumber());
				dont_set++;
			}
		}
		
		if(dont_set == 0 )
		{
			this->var[i]->setNumber();
			var_arr.set(arr_pos,this->var[i]);
			arr_pos++;
		}
		
		
	}
}
void Calc::get_var_values(int amt)
{
	int lett_value;
	int compared_letter_value;
	char lett;
	char compared_letter;
	for (int i = 0; i < amt - 1; i++)
	{
		//Assign temp char to lett, and then convert that char to its ASCII int value
		lett = var[i]->getLetter();
		lett_value = lett;
		
		//Do the same for the next variable in the array
		compared_letter = var[i + 1]->getLetter();
		compared_letter_value = compared_letter;
		
		//Sort variables
		
		if(lett_value>compared_letter_value)
		{
			this->swap_var(i);
		}
	}
	int out_of_order = 0;
	
	for (int i = 0; i < amt - 1; i++)
	{
		//Assign temp char to lett, and then convert that char to its ASCII int value
		lett = var[i]->getLetter();
		lett_value = lett;
		
		//Do the same for the next variable in the array
		compared_letter = var[i + 1]->getLetter();
		compared_letter_value = compared_letter;
		
		//Sort variables
		
		if(lett_value>compared_letter_value)
		{
		
			out_of_order ++;
		}
	}
	
	if(out_of_order > 0)
	{
		get_var_values(amt);
	}


}
//Replace blank number commands with their respective variable values
void Calc::switchout_variables(int amt)
{
	for (int i = 0; i < amt; i++)
	{
		Expr_Command *new_command = factory.create_num_command(var[i]->getNumber());
		
		//Replace the variable command with the number command that represents that variable
		this->postfix[this->var[i]->getPostfixPos()] = new_command;
	}
	
}

void Calc::delete_variables(int amt)
{
	for (int i = 0; i < amt; i++)
	{
		delete this->var[i];
	}
}

void Calc::eval_postfix(Expr_Iterator &iter)
{
	for (; !iter.is_done(); iter.next())
	{
	
		(*iter).execute();
	}
	
}

Array<Expr_Command *>&Calc::getPostfix()
{
	return this->postfix;
}