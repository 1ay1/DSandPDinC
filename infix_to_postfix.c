#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXCOLS 100

#define TRUE 1
#define FALSE 0

int isalp(char ch)
{
  if(ch == '/') return TRUE;
  if(ch == '*') return TRUE;
  if(ch == '-') return TRUE;
  if(ch == '+') return TRUE;
  if(ch == '^') return TRUE;

  return 0;
}

int prdnce(char op1, char op2)
{
  int plus = 0;
  int minus = 0;
  int product = 1;
  int divide = 1;
  int exp = 2;

  int op1num, op2num;

  switch(op1)
    {
    case '-':
      {
	op1num = minus;
	break;
      }
    case '+':
      {
	op1num = plus;
	break;
      }
    case '*':
      {
	op1num = product;
	break;
      }
    case '/':
      {
	op1num = divide;
	break;
      }
    case '^':
      {
	op1num = exp;
	break;
      }
    default: break;
    }
  
  switch(op2)
    {
    case '-':
      {
	op2num = minus;
	break;
      }
    case '+':
      {
	op2num = plus;
	break;
      }
    case '*':
      {
	op2num = product;
	break;
      }
    case '/':
      {
	op2num = divide;
	break;
      }
    case '^':
      {
	op2num = exp;
	break;
      }
    default: break;
    }

  if( op1num > op2num || op1num == op2num)
    {
      return TRUE;
    }
  else
    {
      return FALSE;
    }
}


struct stack_ds
{
  int top;
  char items[MAXCOLS];
};

void push(struct stack_ds *stack, char item)
{
  if(stack->top == MAXCOLS -1) exit(0);
  stack->items[++(stack->top)] = item;
}

char pop(struct stack_ds *stack)
{
  if(stack->top == -1) exit(1);
  return stack->items[stack->top--];
}

void in_to_post(char *in, char *post)
{
  struct stack_ds *stack = malloc(sizeof(struct stack_ds));
  stack->top = -1;
  
  int position_in, position_post = 0;
  for(position_in = 0; in[position_in] != '\0'; position_in++)
    {
      if(isdigit(in[position_in]))
	{
	  post[position_post++] = in[position_in];
	}
      if(in[position_in] == '(')
	{
	  push(stack, '(');
	}
      if(in[position_in] == ')')
	{
	  while(stack->top != '(' && stack->top != -1)
	    {
	      post[position_post++] = pop(stack);
	    }
	  /*mothefuck ->  stack->top--;  <- motherfuck*/
	}
      if(in[position_in] != '(' && in[position_in] != ')' && isalp(in[position_in]))
	{
	  while( stack->top != -1 && prdnce(stack->items[stack->top], in[position_in]) && stack->items[stack->top] != '(')
	    {
	      post[position_post++] = pop(stack);
	    }
	  if(stack->items[stack->top] == '(') pop(stack);
	  push(stack, in[position_in]);
	}
    }

  while(stack->top != -1)
    {
      /*motherfuck->*/      post[position_post++] = pop(stack);  //<-motherfuck
    }

  post[position_post] = '\0';
}	


int main()
{
  char ch1[MAXCOLS];
  char ch2[MAXCOLS];

  fgets(ch1, 100, stdin);

  in_to_post(ch1, ch2);

  puts(ch2);
  
  getchar();
  return 0;
}
