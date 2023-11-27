%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern char * yytext;
extern int yyleng;
extern int copyInputFlag;
extern int currentLine;

char * inputFormat = "--------------------------------------------------------\n                     Input program:\n--------------------------------------------------------\n\n\n";
char * outputFormat = "\n\n\n--------------------------------------------------------\n                         Output:\n--------------------------------------------------------\n\n\n";

void yyerror(char const *);

void myErrorPrint(int messageCode);

void pushStack();
void popStack();
void compTags();

void checkAttribute();
void storeAttribute();
void necessaryAttributes();
int assignTagNumber();
void attributeValueCheck(int type);
void idCheck();
void radioGroupCheck();
void progressBarCheck();

int linearContentFlag = 0;

char ** stack;
int stackElements = 0;

char ** attributeList;
int attributeCount = 0;

char ** idList;
int idCount = 0;

char * currentCheckedButton;
char ** buttonIds;
int buttonCount = 0;
int currentButtonQuantity = 0;

int currentProgress = 0;
int currentMax = 100;
%}

%token '<' '>' '/' ':' '!' '=' '"'
%token ELEMENT_NAME ATTRIBUTE_START ATTRIBUTE_NAME
%token INTEGER STRING

%%

program:
	%empty {printf("%sThe input file is empty.\n\n", outputFormat);}
	| element_start {if(copyInputFlag == 0) printf("%sCOMPILED_SUCCESSFULLY\n\n", outputFormat);} 
	;
		
element_start:
	'<' ELEMENT_NAME {pushStack();} element_middle
	;

element_middle:
	attributes {necessaryAttributes(); free(attributeList); attributeCount = 0;} element_end
	;

element_end:
	'>' content '<' '/' ELEMENT_NAME {compTags();} '>'
	| '>' '<' '/' ELEMENT_NAME {compTags();} '>'
	| '/' '>' {popStack();}
	;

content:
	content element_start 
	| element_start
	;

attributes:
	attributes attribute
	| attribute
	;
	
attribute:
	ATTRIBUTE_START ':' ATTRIBUTE_NAME {checkAttribute(); storeAttribute();} attribute_value
	;
	
attribute_value:
	'=' '"' INTEGER {attributeValueCheck(0);} '"'
	| '=' '"' STRING {attributeValueCheck(1); idCheck();} '"'
	;

%%
void attributeValueCheck(int type)
{
	if(type == 0)
	{
		if(strcmp(attributeList[attributeCount - 1], "layout_height") != 0
			&& strcmp(attributeList[attributeCount - 1], "layout_width") != 0
			&& strcmp(attributeList[attributeCount - 1], "padding") != 0
			&& strcmp(attributeList[attributeCount - 1], "progress") != 0
			&& strcmp(attributeList[attributeCount - 1], "max") != 0
			&& strcmp(attributeList[attributeCount - 1], "button_quantity") != 0)
		{
			myErrorPrint(5);
		}
		
		if(strcmp(attributeList[attributeCount - 1], "progress") == 0)
			currentProgress = atoi(yytext);
			
		if(strcmp(attributeList[attributeCount - 1], "max") == 0)
			currentMax = atoi(yytext);
			
		if(strcmp(attributeList[attributeCount - 1], "button_quantity") == 0)
			currentButtonQuantity = atoi(yytext);
	}
	else
	{
		if(strcmp(attributeList[attributeCount - 1],"layout_width") == 0 || strcmp(attributeList[attributeCount - 1],"layout_height") == 0)
		{
			if(strcmp(yytext,"wrap_content") != 0 && strcmp(yytext,"match_parent") != 0)
			{
				myErrorPrint(5);
			}
			return;
		}
		else if(strcmp(attributeList[attributeCount - 1], "padding") == 0
			|| strcmp(attributeList[attributeCount - 1], "progress") == 0
			|| strcmp(attributeList[attributeCount - 1], "max") == 0
			|| strcmp(attributeList[attributeCount - 1], "button_quantity") == 0)
		{
			myErrorPrint(5);
		}
		
		if(strcmp(attributeList[attributeCount - 1], "checkedButton") == 0)
		{
			char * temp = (char *) malloc(sizeof(yytext));
			strcpy(temp, yytext);
			currentCheckedButton = temp;
		}
	}
}

void idCheck()
{
	if(strcmp(attributeList[attributeCount - 1], "id") != 0)
		return;
	
	char * temp = (char *) malloc(sizeof(yytext));
	strcpy(temp, yytext);
	
	if(idCount == 0)
	{
		idList = (char **) malloc(sizeof(char *));
		idList[0] = temp;
	}
	else
	{
		for(int i = 0; i < idCount; i++)
		{
			if(strcmp(idList[i], temp) == 0)
			{
				myErrorPrint(6);
				return;
			}
		}
		
		char ** newList = (char **) malloc(sizeof(char *) * (idCount + 1));
		
		for(int i = 0; i < idCount; i++)
			newList[i] = idList[i];
	
		newList[idCount] = temp;
		
		free(idList);
		idList = newList;
	}
	idCount++;
	
	if(strcmp(stack[stackElements - 1], "RadioButton") == 0)
	{
		if(buttonCount == 0)
		{
			buttonIds = (char **) malloc(sizeof(char *));
			buttonIds[0] = temp;
		}
		else
		{
			for(int i = 0; i < buttonCount; i++)
			{
				if(strcmp(buttonIds[i], temp) == 0)
				{
					myErrorPrint(6);
					return;
				}
			}
			
			char ** newList = (char **) malloc(sizeof(char *) * (buttonCount + 1));

			for(int i = 0; i < buttonCount; i++)
				newList[i] = buttonIds[i];
		
			newList[buttonCount] = temp;
			
			free(buttonIds);
			buttonIds = newList;
		}
		buttonCount++;
	}
}

void checkAttribute()
{
	int tagNumber = assignTagNumber();
	
	if(strcmp(yytext, "layout_width") != 0 && strcmp(yytext, "layout_height") != 0 && strcmp(yytext, "id") != 0)
	{
		switch(tagNumber)
		{
			case 0:
				myErrorPrint(2);
				break;
			case 1:
				if(strcmp(yytext, "orientation") != 0)
					myErrorPrint(2);
				break;
			case 2:
				if(strcmp(yytext, "text") != 0 && strcmp(yytext, "textColor") != 0)
					myErrorPrint(2);
				break;
			case 3:
				if(strcmp(yytext, "src") != 0 && strcmp(yytext, "padding") != 0)
					myErrorPrint(2);
				break;
			case 4:
				if(strcmp(yytext, "text") != 0 && strcmp(yytext, "padding") != 0)
					myErrorPrint(2);
				break;
			case 5:
				if(strcmp(yytext, "checkedButton") != 0 && strcmp(yytext, "button_quantity") != 0)
					myErrorPrint(2);
				break;
			case 6:
				if(strcmp(yytext, "text") != 0)
					myErrorPrint(2);
				break;
			case 7:
				if(strcmp(yytext, "max") != 0 && strcmp(yytext, "progress") != 0)
					myErrorPrint(2);
				break;
		}

	}
}

void storeAttribute()
{
	char * temp = (char *) malloc(sizeof(yytext));
	strcpy(temp, yytext);

	if(attributeCount == 0)
	{
		attributeList = (char **) malloc(sizeof(char *));
		attributeList[0] = temp;
	}
	else
	{
		for(int i = 0; i < attributeCount; i++)
		{
			if(strcmp(attributeList[i],temp) == 0)
			{
				myErrorPrint(3);
				return;
			}
		}
		
		char ** newList = (char **) malloc(sizeof(char *) * (attributeCount + 1));
		
		for(int i = 0; i < attributeCount; i++)
			newList[i] = attributeList[i];
	
		newList[attributeCount] = temp;
		
		free(attributeList);
		attributeList = newList;
	}
	attributeCount++;
}

void necessaryAttributes()
{	
	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;
	
	int tagNumber = assignTagNumber();
	
	if(attributeCount < 2)
	{
		myErrorPrint(4);
		return;
	}
	
	for(int i = 0; i < attributeCount; i++)
	{
		if(strcmp(attributeList[i], "layout_width") == 0)
		{
			flag1 = 1;
			break;
		}
	}
	
	for(int i = 0; i < attributeCount; i++)
	{
		if(strcmp(attributeList[i], "layout_height") == 0)
		{
			flag2 = 1;
			break;
		}
	}
	
	if(tagNumber == 3)
	{
		for(int i = 0; i < attributeCount; i++)
		{
			if(strcmp(attributeList[i], "src") == 0)
			{
				flag3 = 1;
				break;
			}
		}

	}
	else if(tagNumber == 5)
	{
		for(int i = 0; i < attributeCount; i++)
		{
			if(strcmp(attributeList[i], "button_quantity") == 0)
			{
				flag3 = 1;
				break;
			}
		}
	}
	else if(tagNumber == 2 || tagNumber == 4 || tagNumber == 6)
	{
		for(int i = 0; i < attributeCount; i++)
		{
			if(strcmp(attributeList[i], "text") == 0)
			{
				flag3 = 1;
				break;
			}
		}
	}
	else flag3 = 1;
	
	if(flag1 == 0 || flag2 == 0 || flag3 == 0)
		myErrorPrint(4);
}

int assignTagNumber()
{
	if(strcmp(stack[stackElements - 1], "RelativeLayout") == 0)
		return 0;
	else if(strcmp(stack[stackElements - 1], "LinearLayout") == 0)
		return 1;
	else if(strcmp(stack[stackElements - 1], "TextView") == 0)
		return 2;
	else if(strcmp(stack[stackElements - 1], "ImageView") == 0)
		return 3;
	else if(strcmp(stack[stackElements - 1], "Button") == 0)
		return 4;
	else if(strcmp(stack[stackElements - 1], "RadioGroup") == 0)
		return 5;
	else if(strcmp(stack[stackElements - 1], "RadioButton") == 0)
		return 6;
	else if(strcmp(stack[stackElements - 1], "ProgressBar") == 0)
		return 7;
}

void pushStack()
{
	char * temp = (char *) malloc(sizeof(yytext));
	strcpy(temp, yytext);

	if(strcmp(temp, "LinearLayout") == 0)
		linearContentFlag = 1;
	else
		linearContentFlag = 0;

	if(stackElements == 0)
	{
		if(strcmp("LinearLayout", temp) != 0 && strcmp("RelativeLayout", temp) != 0)
			myErrorPrint(7);
	
		stack = (char **) malloc(sizeof(char *));
		stack[0] = temp;
	}
	else
	{
		if(strcmp("RadioButton",temp) == 0 && strcmp("RadioGroup",stack[stackElements - 1]) != 0)
			myErrorPrint(9);
			
		if(strcmp("RadioButton",temp) != 0 && strcmp("RadioGroup",stack[stackElements - 1]) == 0)
			myErrorPrint(10);
	
		char ** newStack = (char **) malloc(sizeof(char *) * (stackElements + 1));
		
		for(int i = 0; i < stackElements; i++)
			newStack[i] = stack[i];
			
		newStack[stackElements] = temp;
		
		free(stack);
		stack = newStack;
	}
	stackElements++;
}

void popStack(){
	if(strcmp("LinearLayout", stack[stackElements - 1]) == 0 && linearContentFlag == 1)
		myErrorPrint(8);

	if(strcmp(stack[stackElements - 1], "RadioGroup") == 0)
	{
		radioGroupCheck();
		free(buttonIds);
		free(currentCheckedButton);
		buttonCount = 0;
		currentButtonQuantity = 0;
	}
		
	if(strcmp(stack[stackElements - 1], "ProgressBar") == 0)
	{
		progressBarCheck();
		currentProgress = 0;
		currentMax = 100;
	}
		
	char ** newStack = (char **) malloc(sizeof(char *) * (stackElements - 1));
		
	for(int i = 0; i < stackElements - 1; i++)
		newStack[i] = stack[i];
	
	free(stack);
	stack = newStack;
	stackElements--;
}

void radioGroupCheck()
{
	if(currentButtonQuantity != buttonCount)
		myErrorPrint(14);

	if(currentCheckedButton)
	{
		if(buttonCount == 0)
		{
			myErrorPrint(12);
			return;
		}
		
		for(int i = 0; i < buttonCount; i++)
		{
			if(strcmp(currentCheckedButton, buttonIds[i]) == 0)
				return;
		}
		myErrorPrint(13);
	}
}

void progressBarCheck()
{
	if(currentProgress < 0 || currentProgress > currentMax)
		myErrorPrint(11);
}

void compTags()
{
	if(strcmp(stack[stackElements - 1], yytext) == 0) 
		popStack();
	else
		myErrorPrint(1);
}

void myErrorPrint(int messageCode)
{
	if(copyInputFlag == 0)
	{
		char * errorText = (char *) malloc(sizeof(char *));
	
		switch(messageCode)
		{
			case 1:
				errorText = "START AND END TAGS DONT MATCH";
				break;
			case 2:
				errorText = "TAG CONTAINS IMPROPER ATTRIBUTE";
				break;
			case 3:
				errorText = "MULTIPLE INSTANCES OF ATTRIBUTE ARE NOT ALLOWED";
				break;
			case 4:
				errorText = "TAG DOES NOT CONTAIN NECESSARY ATTRIBUTES";
				break;
			case 5:
				errorText = "WRONG DATA TYPE IN ATTRIBUTE VALUE";
				break;
			case 6:
				errorText = "ID VALUES MUST BE UNIQUE";
				break;
			case 7:
				errorText = "ROOT TAG MUST BE EITHER LINEARLAYOUT OR RELATIVELAYOUT";
				break;
			case 8:
				errorText = "LINEAR LAYOUT TAG CANNOT BE EMPTY";
				break;
			case 9:
				errorText = "RADIO BUTTON TAGS CAN APPEAR ONLY INSIDE RADIO GROUP TAGS";
				break;
			case 10:
				errorText = "RADIO GROUP TAGS CAN CONTAIN ONLY RADIO BUTTON TAGS";
				break;
			case 11:
				errorText = "PROGRESS ATTRIBUTE VALUE MUST BETWEEN 0 AND MAX";
				break;
			case 12:
				errorText = "RADIO GROUP MUST CONTAIN AT LEAST ONE RADIO BUTTON WITH DEFINED ID FOR THE CHECKED BUTTON ATTRIBUTE TO BE USED";
				break;
			case 13:
				errorText = "CHECKED BUTTON NEEDS TO MATCH THE ID OF A RADIO BUTTON INSIDE THE RADIO GROUP";
				break;
			case 14:
				errorText = "RADIO GROUP MUST CONTAIN AS MANY RADIO BUTTONS AS INDICATED BY THE BUTTON QUANTITY ATTRIBUTE";
				break;
			case 15:
				errorText = "IMPROPER CHARACTER";
				break;
			case 16:
				errorText = "COMMENT CANNOT CONTAIN TWO OR MORE HYPHENS IN A ROW";
				break;
		}
		
		printf("%sLine %d: %s\n\n", outputFormat, currentLine, errorText);

		copyInputFlag = 1;
	}
}

void yyerror(char const *msg)
{
	printf("%sLine %d: UNDEFINED SYNTAX ERROR\n\n", outputFormat, currentLine);
}

int main()
{
	printf("%s", inputFormat);
	yyparse();
	return 0;
}