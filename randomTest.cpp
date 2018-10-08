#include <iostream>
#include <vector>

using namespace std;

void vectorAppend(vector<int> &arr, int size) {		
	int temp;
	for (int i = 0; i < size; i++) {
		temp = rand() % 100 + 1;
		arr.push_back(temp);
	}
}

int interpolationSearch(vector<int> arr, int x) {
	int m, l = 0, h = arr.size() - 1;
	while (x >= arr[l] && x <= arr[h]) {
		m = l + ((x - arr[l]) * (h-l) / (arr[h] - arr[l])); 
		if (arr[m] < x) l = m + 1;
		else if (x < arr[m]) h = m - 1;
		else return m;
	}
	if (x == arr[l]) return l;
	else return -1;
}

int main() {
	vector<int> arr;

	vectorAppend(arr, 100);
	sort(arr.begin(), arr.end());

	int x;
	int result;
	
	cout << "Enter number that you want to search: " << endl;
	cin >> x;

	result = interpolationSearch(arr, x);
	cout << result << endl;
	return 0;	

}
