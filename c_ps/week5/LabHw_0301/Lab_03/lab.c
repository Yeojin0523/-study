// // ������ ����
// lab(�̱� - �����)
// �� ���� ���, �� ���� �ֿ�� => ���� �߿�, �ߺ� x => ����
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void pick(int n, int* bucket, int bucketSize, int k, char actors[][10]) {
	
	int i, smallest, lastIndex, item, j, count = 0, flag = 0;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++) {
			printf("%10s", actors[bucket[i]]);
		}
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;
	smallest = 0;

	for (item = smallest; item < n; item++) {
		flag = 0;
		for (j = 0; j <= lastIndex; j++) {
			if (bucket[j] == item) {
				flag = 1;
			}
		}
		if (flag == 1)
			continue; // flag = 1�϶��� �Ѿ�� ȿ���� �ִ�.

		bucket[lastIndex + 1] = item;
		pick(n, bucket, bucketSize, k - 1, actors);
	}
}
int main(void) {

	int n, i;
	int* bucket;
	char actors[5][10] = { "����", "�����", "���߱�", "����", "����" };

	scanf("%d", &n);

	if (n <= 0)
		return 0;

	bucket = (int*)malloc(sizeof(int) * n);

	if (!bucket) {
		printf("�޸𸮸� �Ҵ��� �� �����ϴ�.");
		return 0;
	}

	for (i = 0; i < n; i++) {
		bucket[i] = 0;
	} // �ʱ�ȭ
	
	pick(5, bucket, n, n, actors);

	free(bucket);
	return 0;

}
