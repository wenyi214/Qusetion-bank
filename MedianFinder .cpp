class MedianFinder {
public:
	priority_queue<int, vector<int>, less<int>> maxheap;//最大堆，保存数值小的一半
	priority_queue<int, vector<int>, greater<int>> minheap;//最小堆，保存数值大的一半
	//最大堆的最大值小于最小堆的最小值。

	/** initialize your data structure here. */
	MedianFinder() {

	}
	/*
	最大堆数据个数大于或者等于最小堆数据个数，多只多一个
	加入数据时，如果最大堆数据个数等于最小堆数据个数
	要将数据加到最大堆中
	先将数据加到最小堆中，调整出最小值，在加到最大堆中
	如果不相等，说明最大堆数据个数大于最小堆一个
	将数据加到最小堆中
	先将数据加到最大堆中，调整除最大值，在加到最小堆中
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