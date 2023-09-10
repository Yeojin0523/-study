#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// #include<stdlib.h>
#include<string.h> // strlen�� ���
void makeCode(char code[], int dist) {
	int i;

	for (i = 0; i < 26; i++) {
		code[i] = 'A' + ((i + dist) % 26);
	}
}
void printCode(char code[]) {
	int i;

	for (i = 0; i < 26; i++)
		printf("%c", 'A' + i);
	printf("\n");

	for (i = 0; i < 26; i++)
		printf("%c", code[i]);
	printf("\n");
}
void encode(char code[], char s[], char e[]) {
	int i = 0;

	for (i = 0; i < strlen(s); i++) {
		char ch = s[i];

		if ('A' <= ch && ch <= 'Z') {
			int relative_pos = ch - 'A';
			e[i] = code[relative_pos];
		}
		else {
			printf("%d\n", ch);
			e[i] = ch;
		}
	}
	e[i] = '\0';
}
int main(void) {

	char code[26];
	int distance;
	char sentence[80], encodedSentence[80];
	char* buf;
	char ch;
	
	FILE *fp1, *fp2;
	fp1 = fopen("original.txt", "rt");
	if (fp1 == NULL) {
		printf("���� ������ �� �� �����ϴ�.");
		exit(1);
	}

	fp2 = fopen("encoded.txt", "wt");
	if (fp2 == NULL) {
		printf("��ȣȭ�� ������ �� �� �����ϴ�.");
		fclose(fp1);
		exit(1);
	}
	
	printf("��ȣȭ�� �Ÿ� �Է�: ");
	scanf("%d", &distance);
	makeCode(code, distance);
	printf("��ȣȭ �ڵ�:\n");
	printCode(code);

	fgets(sentence, sizeof(sentence), fp1);

	encode(code, sentence, encodedSentence);
	fputs(encodedSentence, fp2);

	fclose(fp1);
	fclose(fp2);

	return 0;
}