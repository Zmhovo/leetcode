#include "Solutions.h"


using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

Solutions::Solutions()
{
}

Solutions::~Solutions()
{
}

/*  1.给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出和为目标值 target 的那两个整数，并返回它们的数组下标。
	你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。  */
/*
vector<int> Solutions::TwoSum(vector<int>& nums, int target)
{
	std::unordered_map <int, int> map;          //使用无序映射
	for (int i = 0; i < nums.size(); i++)
	{
		auto iter = map.find(target - nums[i]);          //find()返回键为target - nums[i]的迭代器，若无对应值，返回end()
		if (iter != map.end())
		{
			return { i,iter->second };          //->second 返回值的部分
		}
		map[nums[i]] = i;          //将键为nums[i]，值为i的键值对插入无序映射中
	}
	return {};
}
*/


/*  2.给你两个非空的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。
	请你将两个数相加，并以相同形式返回一个表示和的链表。
	你可以假设除了数字 0 之外，这两个数都不会以 0 开头。 */
/*
ListNode* Solutions::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* head = nullptr, * tail = nullptr;
	int carry = 0;          //进位值carry
	while (l1 || l2)          //循环遍历l1和l2
	{
		int i1 = l1 ? l1->val : 0;          //如果l1不为空，i1 = l1->val；否则i1 = 0
		int i2 = l2 ? l2->val : 0;
		int sum = i1 + i2 + carry;          //对应位求和
		if (!head)
		{
			head = tail = new ListNode(sum % 10);          //当前节点是结果列表头节点，头节点和尾节点都指向新创建的节点
		}
		else
		{
			tail->next = new ListNode(sum % 10);          //当前节点不是结果列表头节点，尾节点指向新创建的节点
			tail = tail->next;          //更新尾节点
		}
		carry = sum / 10;
		if (l1)
		{
			l1 = l1->next;
		}
		if (l2)
		{
			l2 = l2->next;
		}
	}
	if (carry > 0)
	{
		tail->next = new ListNode(carry);          //处理最后一个进位值
	}
	return head;
}
*/

/*  3.给定一个字符串s，请你找出其中不含有重复字符的最长子串的长度。*/
/*
int Solutions::lengthOfLongestSubstring(string s)
{
	std::unordered_map<char, int> map;
	auto length = s.size();
	int res = 0, border = -1;          //res为所求长度，border为不含重复字符子串左边界
	for (int i = 0; i < length; i++)
	{
		if (map.find(s[i]) != map.end())
		{
			border = std::max(border, map.find(s[i])->second);          //更新左边界
		}
		map[s[i]] = i;          //插入或更新哈希表
		res = std::max(res, i - border);
	}
	return res;
}
*/



/*  4.给定两个大小分别为m和n的正序（从小到大）数组nums1和nums2。请你找出并返回这两个正序数组的中位数。
	算法的时间复杂度应该为O(log(m+n))。*/
/*
int Solutions::getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k)
{
	int m = nums1.size(), n = nums2.size();
	int index1 = 0, index2 = 0;          //边界下标
	while (true)
	{
		if (index1 == m)          //num1数组为空，num2[index2 + k - 1]为中位数
		{
			return nums2[index2 + k - 1];
		}
		if (index2 == n)          //num2数组为空，num1[index1 + k - 1]为中位数
		{
			return nums1[index1 + k - 1];
		}
		if (k == 1)          //如果k == 1，只要返回两个数组首元素的最小值即可。
		{
			return std::min(nums1[index1], nums2[index2]);
		}

		int newIndex1 = std::min(index1 + k / 2 - 1, m - 1), newIndex2 = std::min(index2 + k / 2 - 1, n - 1);
		if (nums1[newIndex1] <= nums2[newIndex2]) 
		{
			k -= newIndex1 - index1 + 1;          //newIndex1 - index1 + 1即需要排除的个数
			index1 = newIndex1 + 1;
		}
		else 
		{

			k -= newIndex2 - index2 + 1;
			index2 = newIndex2 + 1;
		}
	}
	return 0;
}

double Solutions::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int totalLength = nums1.size() + nums2.size();
	if (totalLength % 2 == 1)          //判断总长度是奇数还是偶数
	{
		return getKthElement(nums1, nums2, (totalLength + 1) / 2);
	}
	else 
	{
		return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
	}
	return 0.0;
}
*/

/*  5.给你一个字符串s，找到s中最长的回文子串。
	如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。*/
string Solutions::longestPalindrome(std::string s)
{
	int length = s.length();
	int maxStart = 0;
	int maxLength = 0;
	//cbbd
	for (int i = 0; i < length; i++)          //遍历每个字符作为中心字符
	{
		for (int j = 0; j <= 1; j++)          //j = 0表示中心节点只有一个;j = 1表示中心节点有两个; 
		{
			int l = i;
			int r = i + j;

			while (l >= 0 && r < length && s[l] == s[r])          //判断当前子串是否为回文串
			{
				//扩展当前回文子串
				l--;
				r++;
			}

			//回溯到回文子串的起始和结束位置
			l++;
			r--;

			//比较并保存最长的字符串起始位置和长度
			if (maxLength < r - l + 1) 
			{
				maxLength = r - l + 1;
				maxStart = l;
			}
		}
	}

	return s.substr(maxStart, maxLength);
}
