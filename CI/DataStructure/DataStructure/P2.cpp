#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>



//Change digit numbers to string
//e.g. 923,234,251 ->nine hundred twenty three million two hundred thirty four thousand two hundred fifty one

std::string singleBase[] = {"one","two","three"};
std::string tens[]={"ten","eleven","twelve","thirteen","fourteen"};
std::string tenth[]={"twenty","thirty"};
std::string big[]={"","thousand","million"};

std::string make100(int num)
{
	std::string res="";
	int a = num/100;
	if(a!=0)
	{
		res = singleBase[a-1]+" "+"hundred ";
		num = num - a*100;
	}

	if(1<=num<=9)
		res = res + singleBase[num-1];
	else if(10<=num<=19)
		res = res + tenth[num-10];
	else
	{
		int b=num/10;
		res = res + tens[b-2]+ "-";
		num = num - b*10;
		res = res + singleBase[num-1];
	}

	return res;
}

std::string convertDtoS(int number)
{
	if(number == 0)
		return "zero";
	if(number < 0)
		return "negetive" + convertDtoS(-1*number);

	std::string res="";
	int i = 0;

	while (number > 0)
	{
		res = make100(number%1000)+" "+big[i++]+" "+res;
		number = number / 1000;
	}
	return res;
}

//find largest sum
//e.g [6,5,-12,3] return 11 = 6+5
int getMaxSum(int arr[],int size,std::vector<int> &res)
{
	int maxSum = 0;
	int curSum=0;
	for (int i = 0; i < size; i++)
	{
		curSum += arr[i];
		if (maxSum < curSum)
		{
			maxSum = curSum;
			res.push_back(arr[i]);
		}
		else if (curSum < 0 )
		{
			curSum = 0;
			res.clear();
		}
	}	
	return maxSum;
}
