#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

union n{
	int i;
	char a;
};

int main(){
	union n b;
	b.i = 1;
	if (b.a){
		printf("Ð¡¶Ë\n");
	}
	else{
		printf("´ó¶Ë\n");
	}
	system("pause");
	return 0;
}