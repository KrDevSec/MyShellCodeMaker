/************************************************************

	 Created By Dongho Lim, korea.devsec@gmail.com

*************************************************************/

#include "ShellCodeMaker.h"

ShellCodeMaker::ShellCodeMaker(){
	/* 생성자 사용을 잘못한 경우(인자를 넘기지 않은 경우) */
	printf(" [!] ShellCodeMaker() Constructor Syntax Error...\n");
}

ShellCodeMaker::ShellCodeMaker(char* szInputFilePath, char* szOutputFilePath){
	/* 정상 생성자 및 초기화 작업 */
	FILE *oFile = NULL;

	MyFileProcess *mfc = new MyFileProcess(szInputFilePath);
		
	oFile = fopen(szOutputFilePath, "w");			/* 파일을 쓰기모드로 열고 */

	if ( oFile == NULL )							/* 파일 열기에 실패한 경우 */
	{
		printf(" [!] ShellCodeMaker() File Open Failed...\n");		/* 오류를 알린다. */
		return;
	}

	int nSize = mfc->GetFileSize();
	if ( nSize == 0 ){
		printf(" [!] Not Found File...\n");
		return;	
	}


	fprintf(oFile, "\"");							/* 처음의 " 를 기록 */
	
	char item[3];
	item[2] = NULL;
	for(int i=0; i<nSize; i++){
		item[0] = mfc->GetDataAtIndex(i);
		if( item[0] == ' ' || item[0] == '\n' || item[0] == '\t' ) /* 공백 문자일 경우 */
			continue;
		else 
		{
			item[1] = mfc->GetDataAtIndex(++i);
			fprintf(oFile, "\\x%s", item);
		}
	}

	fprintf(oFile, "\"");							/* 끝의 " 를 기록 */
	
	fclose(oFile);
	
	printf(" [*] Done. \n");
	
	delete mfc;

};
