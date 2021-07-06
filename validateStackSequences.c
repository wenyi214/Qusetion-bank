//给定 pushed 和 popped 两个序列，每个序列中的 值都不重复，
//只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，
//返回 true；否则，返回 false 。

#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
	//生成一个栈
	int *stack = (int *)malloc(sizeof(int)*pushedSize);
	int top = -1;

	int j = 0;
	for (int i = 0; i<pushedSize; i++){
		//在push数组中将一个元素入栈
		stack[++top] = pushed[i];
		//当pop数组元素与入栈元素相等连续出栈
		while (top != -1 && j<poppedSize&&popped[j] == stack[top]){
			top--;
			j++;
		}

	}
	//释放申请空间
	free(stack);
	stack = NULL;
	//栈里为空时说明序列正确
	if (top == -1){
		return true;
	}
	return false;

}
int main(){

	return 0;
}