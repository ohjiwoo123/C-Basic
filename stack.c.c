#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{
	FILE* fp1;
	FILE* fp2;
	int c;
	int i = 0;

	if (argc == 1)
	{
		while ((c = getchar()) != EOF)
			putchar(c);
	}
	else if (argc == 2)
	{
		fp1 = fopen(*(argv + 1), "r");
		if (fp1 == NULL)
		{
			printf("File error\n");
			exit(1);
		}
		else
		{
			while ((c = getc(fp1)) != EOF)
				putchar(c);
			fclose(fp1);
		}
	}

	else if (argc == 3)
	{
		if (strcmp(*(argv + 1), "@") == 0)
		{
			fp1 = fopen(*(argv + 2), "w");
			if (fp1 == NULL)
			{
				printf("File Error\n");
				exit(1);
			}
			else
			{
				while ((c = getchar()) != EOF)
					putc(c, fp1);
				fclose(fp1);
			}
		}
		else
		{
			fp1 = fopen(*(argv + 1), "r");
			fp2 = fopen(*(argv + 2), "w");
			if (fp1 == NULL)
			{
				printf("File error\n");
				exit(1);
			}
			else
			{
				while ((c = getc(fp1)) != EOF)
					putc(c, fp2);
				fclose(fp2);
			}
		}
	}
	else
	{
		printf("Wrong input\n");
		exit(1);
	}
	return 0;
}

