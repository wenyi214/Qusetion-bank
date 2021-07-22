class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));
		//旋转开始位置
		int startx = 0;
		int starty = 0;
		//放到数组里的值
		int count = 1;
		//中间这个位置
		int mid = n / 2;
		//圈数
		int number = n / 2;
		//每一圈循环，需要控制每一条边遍历的长度
		int len = 1;
		int i, j;
		while (number--){

			for (i = startx; i<starty + n - len; i++){
				res[startx][i] = count++;
			}
			for (j = starty; j<startx + n - len; j++){
				res[j][i] = count++;
			}
			for (; j>startx; j--){
				res[i][j] = count++;
			}
			for (; i>starty; i--){
				res[i][j] = count++;
			}

			startx++;
			starty++;
			//每次回少两个元素
			len += 2;
		}
		//如果为奇数中间这个数上面循环不会遍历到
		if (n % 2){
			res[mid][mid] = count;
		}
		return res;
	}
};