//ROLL_NO-CSB17024
/*Design a DFA for a regular language L1 and write a program to simulate the DFA. The program should
be able to take any random string as input from the user and determine whether the string belongs to
the language L1=w| the number of 0's in w is the multiple of 3 , alphabets={0,1})*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*Respective Transitions are explained in the function block below*/
enum STATES{Q0_final,Q1,Q2};
/*Declaration of states where
1) Q0_final = start_state and also final state
2) Q1 = only single 0 seen state
3) Q2 = 00 seen state */
enum STATES state = Q0_final; 

/*Function declaration with return type states*/
enum STATES start(char c);
enum STATES qo(char c);
enum STATES q1(char c);

int main(){
	
	int len,i =0;
	printf("ENTER THE  LENGTH OF THE STRING- ");
	scanf("%d",&len);
	char *input_string = (char *)malloc((len+1)*sizeof(char));
	// Dynamic memory of string for variable length.
	printf("ENTER THE STRING WITH 0 AND 1 ONLY:");
	scanf("%s",input_string);
	input_string[len] ='\0';
	//Last character is made null.
	printf("%s\n",input_string);
	printf("length of the string is:%d\n",len);
	while(input_string[i] != '\0'){
		/*For present state =  Start*/
		if(state == Q0_final){
			state = start(input_string[i]);//Function call for trasitions for 0 & 1.
		}
		/*For present state = Q1*/
		else if(state == Q1){
			state = qo(input_string[i]);
		}
		/*For present state = Q2*/
		else if(state == Q2){
			state = q1(input_string[i]);
		}
		i++;
	}
	/*Checking whether the the string has reached final state and if is in the final state then the string is accepted*/
	if(state == Q0_final){
		printf("The string is accepted by the DFA");
	}
	else{
		printf("The string is not accepted by the DFA");
	}
}
enum STATES start(char c){
	//If it sees a 1 then it remains in the same state
	if(c == '1'){
		state = Q0_final;
	}
	//If it sees a 0 then it moves to the Q1 state
	else {
		state = Q1;
	}
	return(state);
}
enum STATES qo(char c){
	//If it sees a 1 then it remains in the same state  
	if(c == '1'){
		state = Q1;
	}
	//If it sees a 0 then it moves to Q2
	else{
		state = Q2;
	}
	return state;
}
enum STATES q1(char c){
	//If it sees a 1 then it remains in the same state
	if(c == '1'){
		state = Q2;
	}
	//If it sees a 0 then it moves to final state
	else {
		state = Q0_final;
	}
	return state;
}