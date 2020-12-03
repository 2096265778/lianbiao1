#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK      1 
#define ERROR   0
#define TRUE    1
#define FALSE   0
#define MAXSIZE 50

typedef int Status;
typedef int SElemType;
typedef struct
{
	    SElemType data[MAXSIZE];
	        int top;
}SqStack;
Status init_stack(SqStack *s)
{
	    s->top = -1;
	        return OK;
}

Status clear_stack(SqStack *s)
{
	    s->top = -1;
	        return OK;
}

Status stack_empty(SqStack s)
{
	    if(s.top == -1)
		            return TRUE;
	        else
			        return FALSE;
}

int stack_length(SqStack *s)
{
	    return s->top+1;
}

Status push(SqStack *s, SElemType e)
{
	    if(s->top == MAXSIZE-1)
		            return ERROR;
	        s->top++;
		    s->data[s->top] = e;
		        return OK;
}

Status pop(SqStack *s, SElemType *e)
{
	    if(s->top == -1)
		            return ERROR;
	        *e = s->data[s->top];
		    s->top--;
		        return OK;
}
Status infix_to_postfix(char *infix, char *postfix)
{
	    SqStack s;
	        int e = 0;
		    int i = 0, j = 0;
		        int flag = 0;

			    if(init_stack(&s) != OK)
				            return ERROR;
			        
			        while(infix[i]!='\0')
					    {
						            while(infix[i]>='0' && infix[i]<='9')
							    {
								                if(flag)
											            {
													                    flag = 0;
															                    postfix[j++] = '-';
																	                }
										            postfix[j++] = infix[i];
											                i++;
													            if(infix[i]<'0' || infix[i]>'9')
															                    postfix[j++] = ' ';
														            }
							            if(infix[i]==')' || infix[i]==']' || infix[i]=='}')
								    {
									                pop(&s, &e);
											            while(e!='(' && e!='[' && e!='{')
													                {
																                postfix[j++] = e;
																		                postfix[j++] = ' ';
																				                pop(&s, &e);
																						            }
												            }
								            else if(infix[i]=='+' || infix[i]=='-')
										            {
												                if(infix[i] == '-' && (i==0 || (i!=0 && (infix[i-1]<'0' || infix[i-1]>'9'))))
															flag = 1;     
														            else if(stack_empty(s))
																                    push(&s, infix[i]);
															                else
																		            {
																				                    do
																							                    {
																										                        pop(&s, &e);
																													                    if(e=='(' || e=='[' || e== '{')
																																                            push(&s, e);
																															                        else
																																			                    {
																																						                            postfix[j++] = e;
																																									                            postfix[j++] = ' ';
																																												                        }
																																		                }while(!stack_empty(s) && e!='(' && e!='[' && e!='{');
																						                    push(&s, infix[i]);
																						                }
																	        }
									            else if(infix[i]=='*' || infix[i]=='/' || infix[i]=='(' || infix[i]=='[' || infix[i] == '{')
											                push(&s, infix[i]);
										            else if(infix[i] == '\0')
												                break;
											            else
													                return ERROR;
												            i++;
													        }
				    
				    while(!stack_empty(s))
					        {
							        pop(&s,&e);
								        postfix[j++] = e;
									        postfix[j++] = ' ';
										    }

				        clear_stack(&s);
					    return OK;
}
Status calculate(char *postfix, int *result)
{
	    SqStack s;
	        char *op;
		char *buf=postfix;char *saveptr=NULL;
		    int d,e,f;

		        if(init_stack(&s) != OK)
				        return ERROR;
			   
			    while((op = strtok(buf, " ")) != NULL)
				        {
						        buf = NULL;
							        switch(op[0])
									        {
											            case '+':
													                    pop(&s, &d);
															                    pop(&s, &e);
																	                    f = d+e;
																			                    push(&s, f);
																					                    break;
																							                case '-':
																							                    if(op[1]>='0' && op[1]<='9')
																									    {
																										                        d = atoi(op);
																													                    push(&s, d);
																															                        break;
																																		                }
																									                    pop(&s, &d);
																											                    pop(&s, &e);
																													                    f = e-d;
																															                    push(&s, f);
																																	                    break;
																																			                case '*':
																																			                    pop(&s, &d);
																																					                    pop(&s, &e);
																																							                    f = e*d;
																																									                    push(&s, f);
																																											                    break;
																																													                case '/':
																																													                    pop(&s, &d);
																																															                    pop(&s, &e);
																																																	                    f = e/d;
																																																			                    push(&s, f);
																																																					                    break;
																																																							                default:
																																																							                    d = atoi(op);
																																																									                    push(&s, d);
																																																											                    break;
																																																													            }
								    }
			        pop(&s, result);
				    clear_stack(&s);
}

void main()
{
	    char infix[MAXSIZE] = {0};
	        char postfix[MAXSIZE] = {0};
		    int result = 0;
		        
		        scanf("%s", infix);

			    infix_to_postfix(infix, postfix);
			        calculate(postfix, &result);

				    printf("%d\n",result);
}
