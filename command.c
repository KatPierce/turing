#include "tur.h"
/* меняет 3 на 0 и добавляет 6 после 5
> < . - влево, вправо, на месте
_ - дырка
0>1 - пишем 0, сдвиг вправо, состояние q1
# - пустая ячейка

Файл:

12345_   2       (алфавит  и количество состояний)

	q1		q2
1	1>1		#
2	2>1		#
3	0>1		#
4	4>1		#
5	5>1		#
_	6>2		_.0

*/
struct COMMAND **com; // com[N][M]
int N, M;
char alf[21]; // алфавит

void clearCom()
{
	for(int i=0; i<N; i++ )
	{
		for(int j=0; j<M; j++ )
		{
			com[i][j].set = com[i][j].com = '#';
			com[i][j].q=-1;
		}
	}
}

void loadCom()
{
	FILE *in = fopen("fcom.txt", "rt");
	fscanf(in, " %s %d", alf, &M);
	N = strlen(alf);
	// com[len][q]
	com = (struct COMMAND **)calloc(N, sizeof(struct COMMAND *) );
	for( int i=0; i<N; i++ )
	{
		com[i] = (struct COMMAND *)calloc( M, sizeof(struct COMMAND) );
	}
	clearCom();

	char str[101];
	fscanf(in," %*s"); // пропуск пробелов и пустых строк и q1
	fgets(str,100,in); // пропуск q2 (и далее, если есть еще q)
	for(int i=0; i<N; i++ )
	{
		fscanf(in, " %*s"); // пропуск символа алфавита
		for(int j=0; j<M; j++ )
		{
			fscanf(in, " %s", str);
			if( !strcmp(str, "#") ) // str=="#" (пустая ячейка)
			{
				continue;
			}
			com[i][j].set = str[0];
			com[i][j].com = str[1];
			com[i][j].q = atoi(str+2);
		}
	}
	fclose(in);
}

void printCom()
{
	printf("%3c", ' ');
	for( int i=0; i<M; i++ )
		printf( "%7c%d", 'q',i+1);
	printf("\n");

	for(int i=0; i<N; i++ )
	{
		printf("%3c",alf[i]);
		for(int j=0; j<M; j++ )
		{
			if( com[i][j].q != -1 )
				printf("%7c%c%d", com[i][j].set, com[i][j].com, com[i][j].q);
			else
				printf("%9c", ' ');
		}
		printf("\n");
	}

	printf("\n\n");
}

void printCom1(int i, int j)
{
	printf("%cq%d ", alf[i], j+1);
	if( com[i][j].q != -1 )
		printf("%c%c%d\n", com[i][j].set, com[i][j].com, com[i][j].q);
	else
		printf("%c\n", '#');
}

