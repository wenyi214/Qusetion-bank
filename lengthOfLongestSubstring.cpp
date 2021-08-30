//不用hashmap，滑动窗口
//用一个数组key记录这s[j]是否在[i, j)区域的子串里。0书名不在子串里，1说明在子串里。
//因为是字符，key的个数最多为256个。初始化为0，用过置为1
//如果key[s[j]] == 0，j++，将滑动窗口后端向前走，扩大滑动窗口的大小。并且将key[s[j]]++，说明包含在子串里。
//如果key[s[j]] == 1，i++，将滑动窗口前端向前走，缩小滑动窗口的大小。并且将key[s[i]]--，说明不包含在子串里。
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int len = s.size();
		if (len == 0){
			return 0;
		}
		if (len == 1){
			return 1;
		}
		//数组记录是否包含在子串里
		int *key = new int[256];
		memset(key, 0, sizeof(int)* 256);

		int i = 0;
		int j = i + 1;
		int max = 0;
		key[s[i]]++;

		while (j<len){
			//扩大滑动窗口大小
			while (j<len&&key[s[j]] == 0){
				key[s[j]]++;
				j++;
			}
			//记录子串长度最大值
			if (max<j - i){
				max = j - i;
			}
			if (j == len){
				break;
			}
			//缩小滑动窗口大小
			while (i<j&&key[s[j]] != 0){
				key[s[i]]--;
				i++;
			}
		}
		delete[] key;
		return max;

	}
};