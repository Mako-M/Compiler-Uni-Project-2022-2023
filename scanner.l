%option noyywrap
%s COMMENT
%{
#include "parser.tab.h"
#include <stdio.h>
#include <string.h>

extern void myErrorPrint(int messageCode);

int copyInputFlag = 0;
int currentLine = 1;
int firstLinePrint = 0;
int hyphensInARow = 0;

void checkCharacters();
void printProgram();
void printLineNumbers();
%}

%%

<INITIAL>"<!--" {BEGIN(COMMENT); printProgram();}

<COMMENT>{
    "-->" {BEGIN(INITIAL); hyphensInARow = 0; printProgram();}
    . {checkCharacters();}
	"\n" {printProgram(); currentLine++; printLineNumbers();}
}

<INITIAL>{
	"\n" {printProgram(); currentLine++; printLineNumbers();}
	" "	{printProgram();}
	"\t" {printProgram();}

	"<" {printProgram(); return '<';}
	">" {printProgram(); return '>';}
	"/" {printProgram(); return '/';}
	":" {printProgram(); return ':';}
	"!" {printProgram(); return '!';}
	"=" {printProgram(); return '=';}
	\" {printProgram(); return '"';}

	"LinearLayout" {printProgram(); return ELEMENT_NAME;}
	"RelativeLayout" {printProgram(); return ELEMENT_NAME;}
	"TextView" {printProgram(); return ELEMENT_NAME;}
	"ImageView" {printProgram(); return ELEMENT_NAME;}
	"Button" {printProgram(); return ELEMENT_NAME;}
	"RadioButton" {printProgram(); return ELEMENT_NAME;}
	"RadioGroup" {printProgram(); return ELEMENT_NAME;}
	"ProgressBar" {printProgram(); return ELEMENT_NAME;}

	"android" {printProgram(); return ATTRIBUTE_START;}

	"layout_width" {printProgram(); return ATTRIBUTE_NAME;}
	"layout_height" {printProgram(); return ATTRIBUTE_NAME;}
	"orientation" {printProgram(); return ATTRIBUTE_NAME;}
	"id" {printProgram(); return ATTRIBUTE_NAME;}
	"text" {printProgram(); return ATTRIBUTE_NAME;}
	"textColor" {printProgram(); return ATTRIBUTE_NAME;}
	"src" {printProgram(); return ATTRIBUTE_NAME;}
	"padding" {printProgram(); return ATTRIBUTE_NAME;}
	"checkedButton" {printProgram(); return ATTRIBUTE_NAME;}
	"max" {printProgram(); return ATTRIBUTE_NAME;}
	"progress" {printProgram(); return ATTRIBUTE_NAME;}
	"button_quantity" {printProgram(); return ATTRIBUTE_NAME;}

	[0-9]+ {printProgram(); return INTEGER;}
	[0-9A-Za-z_ ]+ {printProgram(); return STRING;}
	. {myErrorPrint(15);}
}
%%

void checkCharacters()
{
	if(yytext[0] == '-')
	{
		hyphensInARow++;
		printProgram();
	}
	else
	{
		hyphensInARow = 0;
		printProgram();
	}
		
	if(hyphensInARow >= 2)
		myErrorPrint(16);
}

void printProgram()
{
	if(firstLinePrint == 0)
	{
		printf("  1.|");
		firstLinePrint = 1;
	}

	if(copyInputFlag == 0)
		printf(yytext);
}

void printLineNumbers()
{
	if(copyInputFlag == 0)
	{
		if(currentLine < 10)
			printf("  %d.|", currentLine);
		else if(currentLine >=10 && currentLine < 100)
			printf(" %d.|", currentLine);
		else
			printf("%d.|", currentLine);
	}
}