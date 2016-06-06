/************************************************************

	 Created By Dongho Lim, korea.devsec@gmail.com

*************************************************************/

#include <stdio.h>
#include "ShellCodeMaker.h"

int main(int argc, char** argv){

	char* InputFile = "C:\\input.txt";
	char* OutFile = "C:\\output.txt";

	ShellCodeMaker *mFile = new ShellCodeMaker( InputFile, OutFile );

	return 0;
}