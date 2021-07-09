#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int *a;
	int front;
	int rear;


} MaxQueue;


MaxQueue* maxQueueCreate() {
	MaxQueue *queue = (MaxQueue *)malloc(sizeof(MaxQueue));
	queue->a = (int *)malloc(sizeof(int)* 10001);
	queue->front = 0;
	queue->rear = 0;

	return queue;
}
//找队列最大值
int maxQueueMax_value(MaxQueue* obj) {
	if (obj->front == obj->rear){
		return -1;
	}
	int max = obj->a[obj->front + 1];
	int p = obj->front + 1;
	for (; p <= obj->rear; p++){
		if (obj->a[p]>max){
			max = obj->a[p];
		}
	}
	return max;
}

void maxQueuePush_back(MaxQueue* obj, int value) {
	obj->a[++obj->rear] = value;

}

int maxQueuePop_front(MaxQueue* obj) {
	if (obj->front == obj->rear){
		return -1;
	}
	return obj->a[++obj->front];

}

void maxQueueFree(MaxQueue* obj) {
	free(obj->a);
	obj->a = NULL;
	free(obj);
}
int main(){
	return 0;
}