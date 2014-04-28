#include <stdio.h>
#include "stack.h"

int command_line();

int main(void)
{
   int command = command_line();
   TYPE val;
   TYPE result;
   Stack *stack = NULL;
   while(command != 6)
   {	
   		switch(command)
   		{
   			case 1:
   				stack = initStack();
   				printf("Stack create successful!\n"); 
   				break;
   			case 2:
	   			printf("Please enter the value: ");
	   			scanf("%d", &val);
	   			push(stack, val);
	   			printf("\npush successful!\n");
	   			break;
   			case 3:
	   			result = pop(stack);
	   			printf("\n%d\n",result);
	   			break;
   			case 4:
		   		result = top(stack);
		   		printf("%d\n", result); 
	   			break;
   			case 5:
	   			destroy(stack);
	   			printf("List delete successful!"); 
	   			break;
   			case 6:
   				break;
   			default:
   				printf("Wrong Comand! Enter Again!\n");
   		}

   		command = command_line();

   }

 return 0;
}


int command_line()
{
	int command;
	printf("1. Create queue\n2. Add\n3. Remove\n4. Get\n5. Delete\n6. Exit");
	scanf("%d", &command);
	return command;
}