求两数组数的中位数，如果两数组总数为偶数，为两个中间数和的一半，如果是奇数，直接等于中间这个数的值。
在两个数组中找两个分割线，两分割线左边所有值比分割线右边的所有值小。并且分割线左边数的个数和右边数的个数差不多
由于两数组也是有序的，数组1分割线左边值小于右边，同理数组2左边值小于右边。

如果两数组元素个数总和为偶数，我们让分割线左边元素个数等于右边元素个数。此时中位数为靠近分割线左边最大值，靠近分割线右边最小值和的一半。

如果两数组元素个数总和为奇数，我们让分割线左边元素个数等于右边元素个数加1。此时中位数为靠近分割线左边的最大值。


当两数组元素个数总和为偶数，数组1元素个数m，数组2元素个数n。
左边元素个数为（m + n） / 2
当两数组元素个数总和为奇数数，数组1元素个数m，数组2元素个数n。
左边元素个数为（m + n + 1） / 2
由于整数做除法得到的还是整数，偶数加1除2和偶数除2值相同，所以有，不论奇数偶数，左边元素个数都是（m + n + 1） / 2

定义分割线：
第一个数组下标为i，表示分割线左边元素的个数，第二个数组下标为j，表示分割线左边元素的个数。

找分割线：实际我们是要找到符合条件的值
确定在哪个数组找分割线。
首先我们只要在一个数组里找分割线，下一个数组的分割线用左边元素个数减去一个数组的左边元素个数(分割线右边元素下标)就能得到
确定在较短的数组里找分割线。
因为如果在长的数组中找分割线，当在找的时候，数组下标很小时，另一个数组的下标是由左边元素个数减大数组下标得到，此时可能是一个很大值，超过小数组的长度了，越界了。

要使分割线左边元素值都小于分割线右边元素的值，一个数组中因为有序，肯定满足。
所以要满足条件：nums1[i - 1] <= nums2[j] && nums1[j - 1] <= nums1[i]
如果不满足就需要调整，
用二分查找来找分割线。当一个条件不满足，重新确定查找区间。
//确认分割线
//方法1：
int left = 0;
int right = nums1.size();
while (left < right)//不要等于，right = len1，不是len1 - 1
{
	//int i = left + (right - left)/2;//nums1分割线右边元素位置
	int i = left + (right - left + 1) / 2;//向上取整
	int j = leftnum - i;//nums2分割线右边元素位置
	//[0,len1]向上取整,i取不到0,i-1不会越界
	if (nums1[i - 1] > nums2[j]){//nums[i -1]nums1分割线左边元素位置
		//往[left,i-1]找
		right = i - 1;
	}
	else{
		//往[i，right]找
		//当只有两个元素时，由i = left + (right - left)/2(right != left),i=left不会更新left
		//死循环，在更新i时，向上取整
		left = i;
	}
}
//方法二：
//[0,len1)
while (left < right)//不要等于，right = len1，不是len1 - 1
{
	int i = left + (right - left) / 2;//nums1分割线右边元素位置
	int j = leftnum - i;//nums2分割线右边元素位置
	//i取不到len，由于nums1个数小于nums2，nums2左边一定有元素，j-1一定不会越界
	if (nums1[i] < nums2[j - 1]){//nums2[j -1]nums2分割线左边元素位置
		//往[i+1,right]找
		left = i + 1;
	}
	else{

		right = i;
	}
}

总代码：
class Solution {
private:
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		//从小的数组确定分割线
		if (nums2.size() < nums1.size()){
			vector<int> temp = nums1;
			nums1 = nums2;
			nums2 = temp;
		}
		int len1 = nums1.size();
		int len2 = nums2.size();

		//左边元素个数，默认左边多一个元素
		int leftnum = (len1 + len2 + 1) / 2;
		//nums[i-1] <= nums[j] && nums[j-1] <= nums[i]
		//确认分割线
		int left = 0;
		int right = len1;
		while (left < right)//不要等于，right = len1，不是len1 - 1
		{
			//int i = left + (right - left)/2;//nums1分割线右边元素位置
			int i = left + (right - left + 1) / 2;//向上取整
			int j = leftnum - i;//nums2分割线右边元素位置
			//[0,len1]向上取整取不到0,i-1不会越界
			if (nums1[i - 1] > nums2[j]){//nums[i -1]nums1分割线左边元素位置
				//往[left,i-1]找
				right = i - 1;
			}
			else{
				//往[i，right]找
				//当只有两个元素时，由i = left + (right - left)/2(right != left),i=left不会更新left
				//死循环，在更新i时，向上取整
				left = i;
			}
		}
		//当left = right时退出 找到分割线
		int i = left;
		int j = leftnum - i;
		//取两数组左右两边的值，防止越界
		int left1max = i == 0 ? INT_MIN : nums1[i - 1];
		int left2max = j == 0 ? INT_MIN : nums2[j - 1];
		int right1min = i == len1 ? INT_MAX : nums1[i];
		int right2min = j == len2 ? INT_MAX : nums2[j];
		//默认左边多一个元素
		//奇数
		if ((len1 + len2) % 2 == 1){
			return max(left1max, left2max);
		}
		//偶数
		else{
			return (double)((max(left1max, left2max) + min(right1min, right2min)) / 2.0);
		}

	}
};