#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
	Программа генератор с тремя флагами запуска
	-h справка по использованию программы и завершение работы
	-о задание стандартного имены выходного файла сгенерированных последовательностей
	-с особый режим работы ( количество сгенерированных элеметнов)
*/

int main(int argc, char *argv[]) {
	// Pre-setup
	char *filename = "default_output.txt";
	int amountOfGeneration = 100;
	FILE *filePtr = NULL;
	srand(time(NULL));
	
	// args logic
//	if(argc == 1){
//		printf("Generator program with three run flags\n");
//		printf("-h help on using the program and exit\n");
//		printf("-o set the standard output file name of the generated sequences\n");
//		printf("-c special mode of operation (number of generated elements)\n");
//		return 0;
//	}
	
	char *opts = "ho:c:f:";
	int opt;
	while( (opt = getopt(argc, argv, opts)) != -1 ){
		switch(opt){
			case 'h':{
				printf("Generator program with three run flags\n");
				printf("-h help on using the program and exit\n");
				printf("-o set the standard output file name of the generated sequences\n");
				printf("-c special mode of operation (number of generated elements)\n");
				return 0;
				break;
			}
			case 'o':{
				filename = optarg;
				break;
			}
			case 'c':{
				amountOfGeneration = atoi(optarg);
				break;
			}
			case 'f':{
				printf("Passed filename = %s",optarg);
				break;
			}
		}
	}
	
	// generation and write logic
	filePtr = fopen(filename, "w");
	if(filePtr == NULL){
		printf("File open error!");
		return -1;
	}
	for(int i = 0 ; i < amountOfGeneration ; i++){
		int randomNumber = rand() % 1000;
		fprintf(filePtr,"%d\n", randomNumber);
	}
	return 0;
}