#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int atoi(const char *str) {
		int nResult = 0;
		if (!str)
		{
			return nResult;
		}
		while (*str == ' ')
		{
			++str;
		}
		if (!CheckIsValid(str))
		{

			return nResult;
		}

		if (*str == '+')
		{
			++str;
		}

		bool bNegtiv = false;

		if (*str == '-')
		{
			++str;
			bNegtiv = true;
		}

		// need to check the str is 0x ??
		while (*str != '\0')
		{
			if (!CheckIsNumber(*str))
			{
				break;
			}
			
			int tmpValue = nResult;
			bool outWhile = false;
			for (int i = 0; i < 3; ++i)
			{
				nResult <<= 1;

				if (nResult & 0x80000000)
				{
					outWhile = true;
					break;
				}
			}

			if (outWhile)
			{
				break;
			}

			nResult += 2 * tmpValue;
			char c = *str;
			nResult += c - 48;
			++str;

			if (!bNegtiv && (nResult & 0x80000000))
			{
				break;
			}
		}

		if (!bNegtiv && (nResult & 0x80000000))
		{
			nResult = 0x7fffffff;
		}
		if (bNegtiv)
		{
			if (nResult < 0)
			{
				nResult = 0x80000000;
			}
			else if (nResult > 0)
			{
				nResult *= -1;
			}
		}
		return nResult;
	}

	bool CheckIsValid(const char* str)
	{
		
		if (CheckIsSign(*str))
		{
			if (CheckIsSign(*(str + 1)) )
			{
				return false;
			}
			else
			{

				if (CheckIsNumber(*(str + 1)))
				{
					return true;
				}
			}
		}

		if (CheckIsNumber(*str))
		{
			return true;
		}

		return false;
	}
	bool CheckIsNumber(char c)
	{
		return c >= 48 && c <= 57;
	}

	bool CheckIsSign(char c)
	{
		return c == '+' || c == '-'; 
	}
};
int main()
{
	Solution s;
	cout << s.atoi("    -10326662300y") << endl;
	return 0;
}