#include <iostream>
#include <math.h>
#include <string>

const size_t MOD = 1000000007;
const long long MAX = pow(2, 62);

std::string Sum(std::string num1, std::string num2);
std::string D_n(const long long& n);
bool isNum(const std::string& str);
std::string Reverse(const std::string& str);
inline size_t Min(const size_t& num1, const size_t& num2);
inline const std::string& Long_str(const std::string& str1, const std::string& str2);

int main()
{
	long long k = 0;
	std::cin >> k;
	while (k <= 0 || k >= MAX)
	{
		std::cout << "Incorrect input. Try again: ";
		std::cin >> k;
	}
	std::string S_k = "0";
	for (long long i = 1; i < k; i++)
	{
		S_k = Sum(S_k, D_n(i));
		if (S_k == "0")
		{
			std::cout << "Error!" << std::endl;
			return 1;
		}
	}
	std::cout << S_k << std::endl; //TODO: mod(%)

	return 0;
}

std::string Sum(std::string num1, std::string num2)
{
	if (!isNum(num1) || !isNum(num2))
	{
		return "0";
	}
	std::string sum = "";
	int temp = 0;
	bool in_mind = false;
	size_t min_len = Min(num1.length(), num2.length());
	num1 = Reverse(num1);
	num2 = Reverse(num2);
	for (size_t i = 0; i < min_len; i++)
	{
		temp = (num1[i] - '0') + (num2[i] - '0');
		if (in_mind)
		{
			temp++;
			in_mind = false;
		}
		if (temp / 10 != 0) in_mind = true;
		sum.push_back((char)((temp % 10) + '0'));
	}
	size_t i = 0;
	std::string lstr = Long_str(num1, num2);
	while (in_mind)
	{
		temp = lstr[min_len + i++] + 1 - '0';// +1 because of in_mind
		if (temp / 10 == 0) in_mind = false;
		sum.push_back((char)(temp % 10) + '0');
	}
	sum.append(lstr.begin() + min_len + i, lstr.end());
	return Reverse(sum);
}
std::string D_n(const long long& n)
{
	std::string num = "";
	num.push_back((char)(n % 9 + '0'));
	num.append(n / 9, '9');
	return num;
}
bool isNum(const std::string& str)
{
	if (str.length() == 0)
	{
		return false;
	}
	size_t length = str.length();
	for (size_t i = 0; i < length; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return false;
		}
	}
	return true;
}
std::string Reverse(const std::string& str)
{
	size_t length = str.length(), half_len = length / 2;
	std::string temp = str;
	for (size_t i = 0; i < half_len; i++)
	{
		std::swap(temp[i], temp[length - 1 - i]);
	}
	return temp;
}
inline size_t Min(const size_t& num1, const size_t& num2)
{
	return num1 < num2 ? num1 : num2;
}
inline const std::string& Long_str(const std::string& str1, const std::string& str2)
{
	return str1.length() < str2.length() ? str2 : str1;
}