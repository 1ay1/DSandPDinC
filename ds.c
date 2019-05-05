#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void remove_space(char* restrict str_trimmed, char* restrict str_untrimmed)
{
  while(*str_untrimmed != '\0')
    {
      if(!isspace(*str_untrimmed))
	{
	  *str_trimmed = *str_untrimmed;
	  str_trimmed++;
	}
      str_untrimmed++;
    }
  *str_trimmed = '\0';
}

struct stack
{
  int top;
  float items[100];
};

float oper(int sym, float op1, float op2)
{
  switch(sym)
    {
    case '+': return (op1 + op2);
    case '-': return (op1 - op2);
    case '*': return (op1 * op2);
    case '/': return (op1/op2);
    case '$': return (powf(op1, op2));
    default:
      {
	printf("%s", "Illegal Expression!\n");
	exit(1);
      }
    }
}

int is_empty(struct stack *stac)
{
  if(stac->top == -1)
    return 1;
  else
    return 0;
}

float pop(struct stack *sp)
{
  if(is_empty(sp))
    {
      printf("Stack Underflow or wrong postfix Expression\n");
      exit(1);
    }
  return (sp->items[sp->top--]);
}

void push(struct stack *sp, float item)
{
  if(sp->top == 100-1)
    {
      printf("Stack Overflow or Wrong postfix Expression");
      exit(1);
    }

  else
    {
      sp->items[++(sp->top)] = item;
    }
}

float eval(char *string)
{
  int c, position;
  float opd1, opd2, value;

  struct stack *working_stack;

  working_stack->top = -1;

  for(position = 0; (c = string[position]) != '\0'; position++)
    {
      if(isdigit(c))
	{
	  push(working_stack, (float) ( c - '0'));
	}
      else
	{
	  opd2 = pop(working_stack);
	  opd1 = pop(working_stack);
	  value = oper(c, opd1, opd2);
	  push(working_stack, value);
	}

    }

  printf("%d\n", working_stack->top);
  return (pop(working_stack));
}

    
int main()
{
  char string[100];
  fgets(string, 100, stdin);

  char string_trimmed[100];
  remove_space(string_trimmed, string);

  printf("The value if the expression is: %f\n", eval(string_trimmed));
  
  return 0;
}
