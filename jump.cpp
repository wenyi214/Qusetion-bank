//也需要要看最大的范围。
//要定义两个变量，一个确认当前的最大范围(curmaccover)，来确认现在能走的区间。一个是nextmaxcover，来记录curmaxcover范围里能往后走的最大范围。
//如果curmaxcover的区间没有到数组最后，需要跳跃一次，再将nextmaxcover赋值给curmaxcover，更新区间。如果nextmaxcover已经到达数组最后位置，也不需要跳跃。
//如果curmaxcover到达最后，不需要跳跃，直接返回。
class Solution {
public:
	int jump(vector<int>& nums) {
		int len = nums.size() - 1;
		int count = 0;

		int curmaxcover = 0;//现在的最大值范围
		int nextmaxcover = 0;//下一次的最大值范围
		for (int i = 0; i<len; i++){
			nextmaxcover = max(i + nums[i], nextmaxcover);//收集现在区间的最大范围
			if (i == curmaxcover){//走到现在最大范围

				if (curmaxcover<len){//如果小于len
					count++;//需要跳一步
					curmaxcover = nextmaxcover;//范围更新
					if (nextmaxcover >= len){//如果下一次的范围已经超过len，不同跳了
						break;
					}
				}
				else{//现在的最大值已经大于len，到最后了
					break;
				}

			}
		}
		return count;

	}
};