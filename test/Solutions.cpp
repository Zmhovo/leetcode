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

/*  1.����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ target �����������������������ǵ������±ꡣ
	����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�  */
/*
vector<int> Solutions::TwoSum(vector<int>& nums, int target)
{
	std::unordered_map <int, int> map;          //ʹ������ӳ��
	for (int i = 0; i < nums.size(); i++)
	{
		auto iter = map.find(target - nums[i]);          //find()���ؼ�Ϊtarget - nums[i]�ĵ����������޶�Ӧֵ������end()
		if (iter != map.end())
		{
			return { i,iter->second };          //->second ����ֵ�Ĳ���
		}
		map[nums[i]] = i;          //����Ϊnums[i]��ֵΪi�ļ�ֵ�Բ�������ӳ����
	}
	return {};
}
*/


/*  2.���������ǿյ�������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ�������ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢һλ���֡�
	���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����
	����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ�� */
/*
ListNode* Solutions::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* head = nullptr, * tail = nullptr;
	int carry = 0;          //��λֵcarry
	while (l1 || l2)          //ѭ������l1��l2
	{
		int i1 = l1 ? l1->val : 0;          //���l1��Ϊ�գ�i1 = l1->val������i1 = 0
		int i2 = l2 ? l2->val : 0;
		int sum = i1 + i2 + carry;          //��Ӧλ���
		if (!head)
		{
			head = tail = new ListNode(sum % 10);          //��ǰ�ڵ��ǽ���б�ͷ�ڵ㣬ͷ�ڵ��β�ڵ㶼ָ���´����Ľڵ�
		}
		else
		{
			tail->next = new ListNode(sum % 10);          //��ǰ�ڵ㲻�ǽ���б�ͷ�ڵ㣬β�ڵ�ָ���´����Ľڵ�
			tail = tail->next;          //����β�ڵ�
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
		tail->next = new ListNode(carry);          //�������һ����λֵ
	}
	return head;
}
*/

/*  3.����һ���ַ���s�������ҳ����в������ظ��ַ�����Ӵ��ĳ��ȡ�*/
/*
int Solutions::lengthOfLongestSubstring(string s)
{
	std::unordered_map<char, int> map;
	auto length = s.size();
	int res = 0, border = -1;          //resΪ���󳤶ȣ�borderΪ�����ظ��ַ��Ӵ���߽�
	for (int i = 0; i < length; i++)
	{
		if (map.find(s[i]) != map.end())
		{
			border = std::max(border, map.find(s[i])->second);          //������߽�
		}
		map[s[i]] = i;          //�������¹�ϣ��
		res = std::max(res, i - border);
	}
	return res;
}
*/



/*  4.����������С�ֱ�Ϊm��n�����򣨴�С��������nums1��nums2�������ҳ������������������������λ����
	�㷨��ʱ�临�Ӷ�Ӧ��ΪO(log(m+n))��*/
/*
int Solutions::getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k)
{
	int m = nums1.size(), n = nums2.size();
	int index1 = 0, index2 = 0;          //�߽��±�
	while (true)
	{
		if (index1 == m)          //num1����Ϊ�գ�num2[index2 + k - 1]Ϊ��λ��
		{
			return nums2[index2 + k - 1];
		}
		if (index2 == n)          //num2����Ϊ�գ�num1[index1 + k - 1]Ϊ��λ��
		{
			return nums1[index1 + k - 1];
		}
		if (k == 1)          //���k == 1��ֻҪ��������������Ԫ�ص���Сֵ���ɡ�
		{
			return std::min(nums1[index1], nums2[index2]);
		}

		int newIndex1 = std::min(index1 + k / 2 - 1, m - 1), newIndex2 = std::min(index2 + k / 2 - 1, n - 1);
		if (nums1[newIndex1] <= nums2[newIndex2]) 
		{
			k -= newIndex1 - index1 + 1;          //newIndex1 - index1 + 1����Ҫ�ų��ĸ���
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
	if (totalLength % 2 == 1)          //�ж��ܳ�������������ż��
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

/*  5.����һ���ַ���s���ҵ�s����Ļ����Ӵ���
	����ַ����ķ�����ԭʼ�ַ�����ͬ������ַ�����Ϊ�����ַ�����*/
string Solutions::longestPalindrome(std::string s)
{
	int length = s.length();
	int maxStart = 0;
	int maxLength = 0;
	//cbbd
	for (int i = 0; i < length; i++)          //����ÿ���ַ���Ϊ�����ַ�
	{
		for (int j = 0; j <= 1; j++)          //j = 0��ʾ���Ľڵ�ֻ��һ��;j = 1��ʾ���Ľڵ�������; 
		{
			int l = i;
			int r = i + j;

			while (l >= 0 && r < length && s[l] == s[r])          //�жϵ�ǰ�Ӵ��Ƿ�Ϊ���Ĵ�
			{
				//��չ��ǰ�����Ӵ�
				l--;
				r++;
			}

			//���ݵ������Ӵ�����ʼ�ͽ���λ��
			l++;
			r--;

			//�Ƚϲ���������ַ�����ʼλ�úͳ���
			if (maxLength < r - l + 1) 
			{
				maxLength = r - l + 1;
				maxStart = l;
			}
		}
	}

	return s.substr(maxStart, maxLength);
}
