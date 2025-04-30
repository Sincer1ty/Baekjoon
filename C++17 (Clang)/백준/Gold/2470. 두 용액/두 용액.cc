#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	int count_liquid;
	
	cin >> count_liquid;
	
	int nums[count_liquid];

    for (int i = 0; i < count_liquid; i++) {
        cin >> nums[i];
    }

	sort(nums, nums + count_liquid);

	int left = 0, right = count_liquid - 1;
	int sum;
	int min = 2000000000;
	int a, b;

	while (left < right) {
		sum = nums[left] + nums[right];
		if (min > abs(sum)) {
			min = abs(sum);
			a = nums[left];
			b = nums[right];
		}

		if (sum > 0) right -= 1;
		else if (sum < 0) left += 1;
		else break;
	}

	if (sum > 0) right += 1;
	else if (sum < 0) left -= 1;

	cout << a << " " << b;
	
	return 0;
}