//其实机器人到一个是从上和左边走过来的。
//会有一种情况，m = 11，n = 11，k = 1 (0，9)不符合，但是(0, 10)符合题意，但是(0，10)并不属于机器人的范围。不能走到说明是障碍。
//要用一个数组来记录该格子是否是机器人的范围。来确定是否可以继续往下走
class Solution {
public:
	//计算位数和
	int BitNums(int s){
		int num = 0;
		while (s){
			int x = s % 10;
			num += x;
			s /= 10;
		}
		return num;
	}

	int movingCount(int m, int n, int k) {

		//记录该格子是否是机器人的范围。
		vector<vector<bool>> dp(m, vector<bool>(n, false));
		dp[0][0] = true;
		//第一个格子循环里未计算，所以num=1
		int num = 1;
		for (int i = 0; i<m; i++){
			int x = BitNums(i);
			for (int j = 0; j<n; j++){
				int y = BitNums(j);
				//一个格子是否是机器人的范围，其实可以简化成只从上面和左边走过来。
				//如果上面和左边没有走过，即使位数和符合条件，也不属于机器人的范围
				//所以要与上dp，由于dp横坐标从i-1开始，纵坐标从j-1开始，所以要i>0,j>0
				if (x + y <= k && ((i >= 1 && dp[i - 1][j]) || (j >= 1 && dp[i][j - 1]))){
					dp[i][j] = true;
					num++;
				}

			}
		}
		return num;


	}
};