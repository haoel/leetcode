// num.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define INT_MAX 2147483647
int threeSumClosest(vector<int> &num, int target) {
	//sort the array
	sort(num.begin(), num.end());

	int n = num.size();
	int distance = INT_MAX;
	int result;

	for (int i = 0; i<n - 2; i++) {
		//skip the duplication
		if (i>0 && num[i - 1] == num[i]) continue;
		int a = num[i];
		int low = i + 1;
		int high = n - 1;
		//convert the 3sum to 2sum problem
		while (low < high) {
			int b = num[low];
			int c = num[high];
			int sum = a + b + c;
			if (sum - target == 0) {
				//got the final soultion
				return target;
			}
			else {

				//tracking the minmal distance
				if (abs(sum - target) < distance) {
					distance = abs(sum - target);
					result = sum;
				}

				if (sum - target> 0) {
					//skip the duplication
					while (high>low && num[high] == num[high - 1]) high--;
					//move the `high` pointer
					high--;
				}
				else {
					//skip the duplication
					while (low<high && num[low] == num[low + 1]) low++;
					//move the `low` pointer
					low++;
				}
			}
		}
	}

	return result;
}




int main()
{
	int a[] = { 1, 1, 1 ,-1};
	vector<int> n(a, a + sizeof(a) / sizeof(int));
	int target = 2;
	cout << threeSumClosest(n, target) << endl;
	return 0;
}
