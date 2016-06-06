/************************************************************

	 Created By Dongho Lim, korea.devsec@gmail.com

*************************************************************/

#include "MyFileProcess.h"

class ShellCodeMaker : public MyFileProcess {
protected:
	char *outputData;
public:
	ShellCodeMaker();
	ShellCodeMaker(char* szInputFilePath, char* szOutputFilePath);
};