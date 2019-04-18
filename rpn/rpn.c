#define N	(10)
#include <stdio.h>
#include <ctype.h>

/* functions */
int isempty();
int isfull();
int has_two_digits();
int peek();
int pop();
int push(int nbr);
void print_result();


/* variables */
int MAXSIZE = 10;
int stack[10];
int my_index = -1;
int line = 1;
int c;
int value = 0;
int processing_digit = -1;
int last_was_sign = -1;
int error = -1;

int main(void)
{
	
	while ((c = getchar()) != EOF) {
		if (isdigit(c)){
			if (processing_digit != 1){
				value = c - '0';
				processing_digit = 1;
			} else {
				value = (value*10) + (c - '0');
			}
			last_was_sign = -1;
		} else {
			if (processing_digit != -1){
				if (!isfull()){
					push(value);
					processing_digit = -1;
				} else {
					error = 2;
				}
			}
			if (error == 2){
				
			} else if (c == ' '){
				
			} else if (c == '+') {
				if (!has_two_digits()){
					error = 1;
				} else {
					int v1 = pop();
					int v2 = pop();
					int new_value = v1 + v2;
					push(new_value);
				}
				last_was_sign = 1;
			} else if (c == '-') {
				if (!has_two_digits()){
					error = 1;
				} else {
					int v1 = pop();
					int v2 = pop();
					int new_value = v2 - v1 ;
					push(new_value);
				}
				last_was_sign = 1;
			} else if (c == '*') {
				if (!has_two_digits()){
					error = 1;
				} else {
					int v1 = pop();
					int v2 = pop();
					int new_value = v1 * v2;
					push(new_value);
				}
				last_was_sign = 1;
			} else if (c == '/') {
				if (!has_two_digits()){
					error = 1;
				} else {
					int v1 = pop();
					int v2 = pop();
					if (v1 != 0){
						int new_value = v2 / v1;
						push(new_value);
					} else {
						error = 1;
					}
				}
				last_was_sign = 1;
			} else if (c == '\n'){
				print_result();
			} else {
				error = 1;
			} 
		}
		if (error > 0){
			print_result();
			while ((c = getchar()) != EOF && c != '\n'){}
		}
	}
	return 0;
}

void print_result(){
	if (error <= 0) { //No error
		if (last_was_sign == -1){
			printf("line %d: error at \\n\n", line);
		} else {
			int tmp = pop();
			printf("line %d: %i\n", line, tmp);
		}
	} else if (error == 2){ //Error
		printf("line %d: error at %i\n", line, value);
	} else {
		printf("line %d: error at %c\n", line, c);
	}
	line +=1;
	error = -1;
	last_was_sign = -1;
	my_index = -1;
	processing_digit = -1;
}

int isempty(){
	if (my_index == -1){
		return 1;
	} else {
		return 0;
	}
}

int isfull(){
	if (my_index == MAXSIZE - 1){
		return 1;
	} else {
		return 0;
	}
}

int has_two_digits(){
	if (my_index >= 1) {
		return 1;
	} else {
		return 0;
	}
}

int peek(){
	return stack[my_index];
}

int pop(){
	if (!isempty()) {
		int rtn = stack[my_index];
		my_index = my_index - 1;
		return rtn;
	}
	return 0;
}

int push(int nbr){
	if (!isfull()){
		my_index = my_index + 1;
		stack[my_index] = nbr;
	}
	return 0;
}