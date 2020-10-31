#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//int main(void) {
//	setlocale(LC_ALL, "Rus");
//	int Str, StrNum;
//	char** ARRCHNUM = { 0 };
//	char Line[21] = { 0 }; //Сюда изначально вводим строку.
//	printf("Введите число строк:");
//	scanf_s("%d", &StrNum); //Вводим количество строк.
//	ARRCHNUM = (char**)calloc(StrNum, sizeof(char*));
//	for (Str = 0; Str < StrNum; Str++) {
//		printf("Введите %d-е целое число, не более чем из 20 знаков:", Str + 1);
//		fgets(Line, 21, stdin);
//		fflush(stdin);
//		if (Line != NULL) {
//			ARRCHNUM[Str] = (char*)calloc(strlen(Line) + 1, sizeof(char));
//			strcpy_s(ARRCHNUM[Str], strlen(Line), Line);
//			free(Line);
//		}
//	}
//	//free();
//	return 0;
//}
int main(void) {
	setlocale(LC_ALL, "Rus");
	int Str, StrNum, StrLenght, *FloatToIntNums, StrBubble, BubbleTmp;
	char** ARRCHNUM=NULL;
	printf("Введите число строк:");
	scanf_s("%d", &StrNum); //Вводим количество строк.
	ARRCHNUM = (char**)calloc(StrNum, sizeof(char*)); //Память под строки.
	printf("Введите максимальный размер строки:");
	scanf_s("%d", &StrLenght); //Максимальную длину числа, включая \0.
	for (Str = 0; Str < StrNum; Str++) {
		ARRCHNUM[Str] = (char*)calloc(StrLenght, sizeof(char)); //Память под числа.
	}
	fflush(stdin); //Чистим ввод.
	getchar(); // Убираем из stdin 10.
	for (Str = 0; Str < StrNum; ++Str) {
		printf("Введите %d-е целое число, не более чем из %d цифр:", Str+1, StrLenght - 1);
		fgets(ARRCHNUM[Str], StrLenght, stdin);
		fflush(stdin);
	}
	FloatToIntNums = (int*)calloc(StrNum, sizeof(int)); //Выделение памяти для int массива.
	for (Str = 0; Str < StrNum; Str++) {
		FloatToIntNums[Str] = atoi(ARRCHNUM[Str]); //Перевод из char в int.
	}
	for (Str = 0; Str < StrNum - 1; Str++) { //Сортируем "пузырьком" введенные числа.
		for (StrBubble = 0; StrBubble < StrNum - Str - 1; StrBubble++) {
			if (FloatToIntNums[StrBubble] > FloatToIntNums[StrBubble + 1]) {
				BubbleTmp = FloatToIntNums[StrBubble];
				FloatToIntNums[StrBubble] = FloatToIntNums[StrBubble + 1];
				FloatToIntNums[StrBubble + 1] = BubbleTmp;
			}
		}
	}
	for (Str = 0; Str < StrNum; Str++) {  //Выводим результаты сортировки.
		printf("\n%d-й элемент: %d", Str + 1, FloatToIntNums[Str]);
	}
	for (Str = StrNum; Str >= 0; Str--) {  //Освобождаем память.
		free(ARRCHNUM[Str]);
	}
	free(ARRCHNUM);
	free(FloatToIntNums);
	return 0;
}