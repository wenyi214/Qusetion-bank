class MedianFinder {
public:
	priority_queue<int, vector<int>, less<int>> maxheap;//���ѣ�������ֵС��һ��
	priority_queue<int, vector<int>, greater<int>> minheap;//��С�ѣ�������ֵ���һ��
	//���ѵ����ֵС����С�ѵ���Сֵ��

	/** initialize your data structure here. */
	MedianFinder() {

	}
	/*
	�������ݸ������ڻ��ߵ�����С�����ݸ�������ֻ��һ��
	��������ʱ������������ݸ���������С�����ݸ���
	Ҫ�����ݼӵ�������
	�Ƚ����ݼӵ���С���У���������Сֵ���ڼӵ�������
	�������ȣ�˵���������ݸ���������С��һ��
	�����ݼӵ���С����
	�Ƚ����ݼӵ������У����������ֵ���ڼӵ���С����
	*/
	void addNum(int num) {

		if (maxheap.size() == minheap.size()){
			minheap.push(num);
			int top = minheap.top();
			minheap.pop();
			maxheap.push(top);
		}
		else{
			maxheap.push(num);
			int top = maxheap.top();
			maxheap.pop();
			minheap.push(top);
		}
	}

	double findMedian() {
		if (maxheap.size() == minheap.size()){
			return (maxheap.top() + minheap.top()) / 2.0;
		}
		return maxheap.top()*1.0;

	}
};