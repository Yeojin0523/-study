#include<stdio.h>
void func(int* a) { // �ּ� return �Ϸ��� pointer ��� ��
	*a = 2;
}
int main(void) {
	int b = 0;

	func(&b);
	printf("%d\n", b); // -> b�� �� x �ּҰ� return
	return 0;
}