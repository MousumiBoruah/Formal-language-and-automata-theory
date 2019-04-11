//ROLL_NO - CSB17024
/*Design a PDA for a context free language  and write a program to simulate the PDA. Similar to the
previous question, the program should be able to determine whether a random string given as user
input belongs to the language .*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//THE PDA ACCEPTION CRITERIA IS REACHING FINAL STATE 
/*Respective Transitions are explained in the function block below*/
enum STATES{Q0,Q1,Q2,Q3,Final};
/*Declaration of states where
1) Q0 = start_state 
2) Q1 = When a 1 is seen and the top of the stack is 0 so that we can pop 
3) Q2 = It is the dead state where the string is not acepted any how
4) Q3 = It is the state when we get any number of 2 we ignore it and simply stay in that state
5) Final = It is the final state */
enum STATES state = Q0;
//Function declaration
enum STATES q0(char c,char *);
enum STATES q1(char c,char *);
enum STATES q3(char c,char *);

int top = 0;

//Push function for the stack
void push(char c,char *stack)
{
	    top=top+1;
		stack[top]= c;
}
//Pop function for the stack
void pop(char *stack)
{
		top=top-1;
}

int main(){
	int len,i =0;
	printf("ENTER THE  LENGTH OF THE STRING- ");
	scanf("%d",&len);
	char stack[len];//declaration of stack as per the length given by the user
    stack[top] = 'E';//Initializing the Stack top value by 'E'(flag)
	char *input_string = (char *)malloc((len+1)*sizeof(char));
	// Dynamic memory of string for variable length.
	printf("ENTER THE STRING WITH 0 , 1  AND 2 ONLY:");
	scanf("%s",input_string);
	input_string[len] ='\0';
	//Last character is made null.
	printf("%s\n",input_string);
	printf("length of the string is:%d\n",len);
	while(input_string[i] != '\0'){
		/*For present state =  Start*/
		if(state == Q0){
			state = q0(input_string[i],stack);//Function call for trasitions for 0 & 1.
		}
		/*For present state = Q1*/
		else if(state == Q1){
			state = q1(input_string[i],stack);
		}
		/*For present state = Q2*/
		else if(state == Q2){
		break;//The string is any how not accepted that is why break
		}
		/*For present state = Q3*/
		else if(state == Q3){
			state = q3(input_string[i],stack);
		}
		i++;
	}
	//if the state Q3 also it is not in state Q2 and top of the stack is 'E' 
	if(state == Q3 && state != Q2 && stack[top] == 'E'){
		state = Final;
	}
	if(state == Final){
		printf("The string is accepted by the push down automata");
	}
	else{
		printf("The string is not accepted by the push down automata");
	}
} 
enum STATES q0(char c,char *stack){
	//If it sees a 0 and the stack top is 'E' then it remains in the same state and push 0
	if(c == '0' && stack[top] == 'E'){
		state = Q0;
		push(c,stack);
	}
	//If it sees a 0 and and the stack top is 0 then it remains in the same state and push 0
	else if(c == '0' && stack[top] == '0') {
		state = Q0;
		push(c,stack);
	}
	//If it sees a 1 and the stack top is 0 then state is changed to Q1 and 0 is popped out
	else if(c == '1' && stack[top] == '0'){
		state = Q1;
		pop(stack);
	}
	//Else it moves to the dead end i.e.Q2
	else{
		state = Q2;
	}
	return(state);
}
enum STATES q1(char c,char *stack){
	//If it sees a 1 and the satck top is 0 then it remains in the same state and pops out 0 
	if(c == '1' && stack[top] == '0'){
		state = Q1;
		pop(stack);
	}
	//If it sees a 2 then it moves to Q3 and ignores the 2
	else if(c == '2' && stack[top] == 'E'){
		state = Q3;
	}
	//else it moves to the dead end i.e.Q2
	else{
		state = Q2;
	}
	return state;
}
enum STATES q3(char c,char *stack){
	//If it sees a 2 then it remains in the same state
	if(c == '2' && stack[top] == 'E'){
		state = Q3;
	}
	//Else it moves to the dead end i.e.Q2
	else {
		state = Q2;
	}
	return state;
}