#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//int main(void) {
//	setlocale(LC_ALL, "Rus");
//	int Str, StrNum;
//	char** ARRCHNUM = { 0 };
//	char Line[21] = { 0 }; //���� ���������� ������ ������.
//	printf("������� ����� �����:");
//	scanf_s("%d", &StrNum); //������ ���������� �����.
//	ARRCHNUM = (char**)calloc(StrNum, sizeof(char*));
//	for (Str = 0; Str < StrNum; Str++) {
//		printf("������� %d-� ����� �����, �� ����� ��� �� 20 ������:", Str + 1);
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
	printf("������� ����� �����:");
	scanf_s("%d", &StrNum); //������ ���������� �����.
	ARRCHNUM = (char**)calloc(StrNum, sizeof(char*)); //������ ��� ������.
	printf("������� ������������ ������ ������:");
	scanf_s("%d", &StrLenght); //������������ ����� �����, ������� \0.
	for (Str = 0; Str < StrNum; Str++) {
		ARRCHNUM[Str] = (char*)calloc(StrLenght, sizeof(char)); //������ ��� �����.
	}
	fflush(stdin); //������ ����.
	getchar(); // ������� �� stdin 10.
	for (Str = 0; Str < StrNum; ++Str) {
		printf("������� %d-� ����� �����, �� ����� ��� �� %d ����:", Str+1, StrLenght - 1);
		fgets(ARRCHNUM[Str], StrLenght, stdin);
		fflush(stdin);
	}
	FloatToIntNums = (int*)calloc(StrNum, sizeof(int)); //��������� ������ ��� int �������.
	for (Str = 0; Str < StrNum; Str++) {
		FloatToIntNums[Str] = atoi(ARRCHNUM[Str]); //������� �� char � int.
	}
	for (Str = 0; Str < StrNum - 1; Str++) { //��������� "���������" ��������� �����.
		for (StrBubble = 0; StrBubble < StrNum - Str - 1; StrBubble++) {
			if (FloatToIntNums[StrBubble] > FloatToIntNums[StrBubble + 1]) {
				BubbleTmp = FloatToIntNums[StrBubble];
				FloatToIntNums[StrBubble] = FloatToIntNums[StrBubble + 1];
				FloatToIntNums[StrBubble + 1] = BubbleTmp;
			}
		}
	}
	for (Str = 0; Str < StrNum; Str++) {  //������� ���������� ����������.
		printf("\n%d-� �������: %d", Str + 1, FloatToIntNums[Str]);
	}
	for (Str = StrNum; Str >= 0; Str--) {  //����������� ������.
		free(ARRCHNUM[Str]);
	}
	free(ARRCHNUM);
	free(FloatToIntNums);
	return 0;
}