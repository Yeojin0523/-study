// 20220803 ��ǻ���а� ������
// 2023-03-30
// ����
#include<stdio.h>
void pick(int n, int* bucket, int bucketSize, int k) {

	int i, lastIndex, smallest, item, count = 0;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++) {
			printf("%d", bucket[i]);
		}
		printf("\n");
		return;
	}
	
	lastIndex = bucketSize - k - 1;
	
	smallest = 0; // �ߺ����� base���� ���� �ٸ� �� n�� ��� ������ ���� => �տ� �Ȱ��� �� ������ �װ� �ߺ��������� ������ �ƴ�

	int flag = 0;

	for (item = smallest; item < n; item++) {
		flag = 0; // �Ź� �ٽ�
		for (int j = 0; j <= lastIndex; j++) {
			if (bucket[j] == item)
				flag = 1;
		}
		if (flag == 1)
			continue;  // flag = 1�϶��� �Ѿ�� ȿ���� �ִ�.

		bucket[lastIndex + 1] = item;
		pick(n, bucket, bucketSize, k - 1);
	}
}
main() {

	int n = 3;
	int bucket[3];
	pick(n, bucket, 3, 3);

	return 0;
}
