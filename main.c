#include <stdio.h>

int checkData(FILE* fp);
void saveData(FILE* fp);
void printData(FILE* fp);

int main()
{
	FILE* dt;

	if ((fopen_s(&dt, "dt.txt", "a+")) != 0)
	{
		printf("File Error\n");
		exit(1);
	}

	// check if data file is empty
	if ((checkData(dt)) == 0)
	{
		printf("Empty.\n");
	}
	else
	{
		printf("Found data.\n");
		printData(dt);
	}



	saveData(dt);
	
	//fclose(dt);
	// this is fun lol
	int numclosed = _fcloseall();
	printf("Number of files closed by _fcloseall: %u\n", numclosed);


	return 0;
}


int checkData(FILE* fp)
{
	
	fseek(fp, 0L, 2);	//to end
	if ((ftell(fp)) == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void saveData(FILE* fp)
{
	char buffer[50];
	printf("Enter text to save.\n");

	fgets(buffer, 50, stdin);
	fputs(buffer, fp);
}

void printData(FILE* fp)
{
	int c;
	fseek(fp, 0L, 0);	//to start
	while ((c = fgetc(fp)) != EOF)
	{
		putchar(c);
	}
}