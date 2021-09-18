//考虑好所有的情况
//用三个变量记录手里5块，10块，20块钱的数量
//首先一开始没有零钱，如果bills[0]>5，直接返回false；
//如果遇到5，增加5块的数量，直接获取，不需要找零
//如果遇到10，增加10块的数量，需要找零5块，如果没有5块，直接返回false
//如果遇到20，增加20块的数量，需要先考虑找零10 + 找零5块的情况，再考虑找三张5块的情况，因为5块既能找零10，也能找零20，先将10块用来比较好。
class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		if (bills[0]>5){
			return false;
		}
		int fivecount = 0;
		int tencount = 0;
		int twetycount = 0;

		for (int i = 0; i<bills.size(); i++){
			if (bills[i] == 5){//5块直接获取
				fivecount++;
			}
			else if (bills[i] == 10){//10块
				tencount++;
				if (fivecount == 0){//没有5块直接返回false
					return false;
				}
				else{//有5块，5块数量减1
					fivecount--;
				}
			}
			else{//20
				twetycount++;
				if (tencount == 0){//没有10块
					if (fivecount<3){
						return false;
					}
					else{
						fivecount -= 3;
					}
				}
				else{//有10块
					if (fivecount == 0){//没有5块
						return false;
					}
					else{
						tencount--;
						fivecount--;
					}
				}
			}

		}
		return true;

	}
};