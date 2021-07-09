#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int *a;
	int front;
	int rear;
	int *b;
	int begin;
	int end;

} MaxQueue;


MaxQueue* maxQueueCreate() {
	MaxQueue *queue = (MaxQueue *)malloc(sizeof(MaxQueue));
	queue->a = (int *)malloc(sizeof(int)* 10001);
	queue->front = 0;
	queue->rear = 0;
	queue->b = (int *)malloc(sizeof(int)* 10001);
	queue->begin = 0;
	queue->end = 0;
	return queue;
}

int maxQueueMax_value(MaxQueue* obj) {
	if (obj->front == obj->rear){
		return -1;
	}
	return obj->b[obj->begin + 1];

}

void maxQueuePush_back(MaxQueue* obj, int value) {
	obj->a[++obj->rear] = value;
	//���ʱ����Ϊ�ղ������ֵ�󣬽��������ж�βԪ�س���
	while (obj->begin != obj->end&&value>obj->b[obj->end]){
		obj->end--;
	}
	obj->b[++obj->end] = value;
}

int maxQueuePop_front(MaxQueue* obj) {
	if (obj->front == obj->rear){
		return -1;
	}
	obj->front++;
	//������ӵ�ֵ�뵥�����е�ֵ��ȣ�һ����ӡ�
	int x = obj->a[obj->front];
	if (x == obj->b[obj->begin + 1]){
		obj->begin++;
	}
	return x;
}

void maxQueueFree(MaxQueue* obj) {
	free(obj->a);
	free(obj->b);
	free(obj);
}

int main(){
	return 0;
}