/************************************************************

	 Created By Dongho Lim, korea.devsec@gmail.com

*************************************************************/

#include "ShellCodeMaker.h"

ShellCodeMaker::ShellCodeMaker(){
	/* ������ ����� �߸��� ���(���ڸ� �ѱ��� ���� ���) */
	printf(" [!] ShellCodeMaker() Constructor Syntax Error...\n");
}

ShellCodeMaker::ShellCodeMaker(char* szInputFilePath, char* szOutputFilePath){
	/* ���� ������ �� �ʱ�ȭ �۾� */
	FILE *oFile = NULL;

	MyFileProcess *mfc = new MyFileProcess(szInputFilePath);
		
	oFile = fopen(szOutputFilePath, "w");			/* ������ ������� ���� */

	if ( oFile == NULL )							/* ���� ���⿡ ������ ��� */
	{
		printf(" [!] ShellCodeMaker() File Open Failed...\n");		/* ������ �˸���. */
		return;
	}

	int nSize = mfc->GetFileSize();
	if ( nSize == 0 ){
		printf(" [!] Not Found File...\n");
		return;	
	}


	fprintf(oFile, "\"");							/* ó���� " �� ��� */
	
	char item[3];
	item[2] = NULL;
	for(int i=0; i<nSize; i++){
		item[0] = mfc->GetDataAtIndex(i);
		if( item[0] == ' ' || item[0] == '\n' || item[0] == '\t' ) /* ���� ������ ��� */
			continue;
		else 
		{
			item[1] = mfc->GetDataAtIndex(++i);
			fprintf(oFile, "\\x%s", item);
		}
	}

	fprintf(oFile, "\"");							/* ���� " �� ��� */
	
	fclose(oFile);
	
	printf(" [*] Done. \n");

};