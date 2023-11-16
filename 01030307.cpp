#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include <string>
#include <map>

using std::cout;
using std::cin;

class Solution
{
public:
	int findLucky(std::vector<int>& arr)
	{
		int res = -1;
		//code
		std::map<int, int> counter;
		std::map<int, int>::iterator it;
		int temp = 0;

		for (int i = 0; i < arr.size(); ++i) // ��������� � ����� ������ ���������� �����, ������ �������� ���������� � ���� ��������
		{
			if (counter.find(arr[i]) == counter.end())
			{
				counter.emplace(arr[i], 1);
			}
			else if (counter.find(arr[i]) != counter.end()) //���� �������� ����� ��� ���� � ����� ������ �������� ������������� �� 1
			{
				it = counter.find(arr[i]);
				temp = it->second;
				++temp;
				it->second = temp;
			}
		}

		std::vector<int> maxLuck;
		for (auto j = counter.begin(); j != counter.end(); ++j) // ��� ����� ��� ����� ������ �������� ��������� � ������
		{
			if (j->first == j->second)
			{
				maxLuck.push_back(j->first);
			}

		}

		int tempMax = 0;
		for (int v = 0; v < maxLuck.size(); ++v) //����� ������� ����� ������� ������������� � res
		{
			if (maxLuck[v] > tempMax) tempMax = maxLuck[v];
		}

		if (tempMax != 0) res = tempMax;

		return res;
	}
};

int main()
{
	std::vector<int> items;
	int item;
	std::string line;
	std::getline(cin, line);
	std::istringstream is(line);
	while (is >> item)
	{
		items.push_back(item);
	}

	Solution sol;
	cout << sol.findLucky(items);

	return 0;
}
