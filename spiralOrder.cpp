class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {

		vector<int> res;
		int x = matrix.size();
		int y = matrix[0].size();//计算函数和列数
		if (x == 0 && y == 0){
			return res;
		}
		int count = x*y;//算出一共有多少元素
		int k = 0;//记录入到结果数组里的元素个数
		res.resize(count);//开辟空间

		int startx = 0;//螺旋数组开始位置
		int starty = 0;

		int len = 1;//区间前闭后开，要间的元素个数，前闭后开，搜易初始值1
		int i, j;

		while (k<count){
			//所有判断条件都要k的个数小于元素总个数
			for (i = startx; k<count&&i<starty + y - len; i++){//starty+y，要从starty下标开始所以加y
				res[k++] = matrix[startx][i];//减掉已经遍历了的个数  
			}

			for (j = starty; k<count&&j<startx + x - len; j++){
				res[k++] = matrix[j][i];
			}

			for (; k<count&&i>startx; i--){
				res[k++] = matrix[j][i];
			}

			for (; k<count&&j>starty; j--){
				res[k++] = matrix[j][i];
			}
			if (k == count - 1){//如果为n*n矩阵，上面都不会进入，最后一个不会加上，此时退出，外面加上
				break;
			}
			startx++;
			starty++;
			len += 2;
		}
		if (k == count - 1){//加上中间位置
			int mid = x / 2;
			res[k] = matrix[mid][mid];
		}
		return res;

	}
};