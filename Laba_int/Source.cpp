#include <iostream>
#include "time.h"
using namespace std;


int conv_NAF(long long num, long long *mas) {
	int i = 0;
	long long d = num;
	while (d)
	{
		if (d & 1)
		{
			if ((d & 3) == 3) {
				mas[i] = -1;
				d++;
			}
			else //d&3==1
				mas[i] = 1;
		}
		else
			mas[i] = 0;
		d=d >> 1;
		i++;
	}

	return i;
}
void print_NAF(long long  *mas, int count_of_bit)
{
	cout << "NAF=";
	for (int i= count_of_bit-1; i >=0 ; i--)
	{
		cout <<dec<<mas[i];
	}
	cout << endl;
}
int decod_NAF(long long *mas, int count_of_bit)
{
	int res = 0;
	for (int i = 0; i < count_of_bit; i++)
	{
		if (mas[i] == 1 || mas[i] == -1)
		{
			res = res + (mas[i] * (pow(2, i)));
		}
	}
	return res;
}
int count_of_NAN_zero_elements_f(long long *mas, int count_of_bit)
{
	int count_of_NAN_zero_elements = 0;
	for (int i = 0; i <= count_of_bit; i++)
	{
		if (mas[i] == 1 || mas[i] == -1)
		{
			count_of_NAN_zero_elements = count_of_NAN_zero_elements + 1;
		}
	}
	return count_of_NAN_zero_elements;
}
void density_f(int count_of_NAN_zero_elements, int count_of_bit)
{
	double density = (double)count_of_NAN_zero_elements / (double)count_of_bit;
	cout << "Density_NAF: " << dec << density << endl;
}
int count_of_bit_for_num_f(long long num) 
{
	long long copy_num = num;
	int res = 0;
	while (copy_num)
	{
		copy_num = copy_num >> 1;
		res = res + 1;
	}
	return res;
}
int Num_1_elements(long long num, int count_of_bit_for_num)
{
	long long copy_num = num;
	int bit = 0;
	while (copy_num)
	{
		if (copy_num & 1)
		{
			bit = bit + 1;
		}
		copy_num = copy_num >> 1;
	}
	cout << "Weight_NUM: " << dec << bit<<endl;
	return bit;
}
void density_for_num(int count_of_bit_for_num,int num_1_elements)
{
	double density = (double)num_1_elements / (double)count_of_bit_for_num;
	cout << "Density_NUM: " << dec << density << endl;
}

int main() {
	srand(time(NULL));
	long long res_1, res_2, res_3;
	int count_of_bit_for_num_1, count_of_bit_for_num_2, count_of_bit_for_num_3;
	int count_of_NAN_zero_elements_1, count_of_NAN_zero_elements_2, count_of_NAN_zero_elements_3;
	int  Num_1_elements_1, Num_1_elements_2, Num_1_elements_3;
	int count_of_bit_1, count_of_bit_2, count_of_bit_3 ;
	long long *mas = new long long[32];
	long long num1 = 121;
	long long num2 = (rand() % 32500) + 32498;
	long long num3 = (rand() % 32500) + 32498;
	
	//////////////////////////////////////////////////
	cout << "num: "<<dec << num1 << endl;
	count_of_bit_for_num_1 = count_of_bit_for_num_f(num1);
	cout << "Bit count of num: " << dec << count_of_bit_for_num_1<<endl;
	Num_1_elements_1 = Num_1_elements(num1, count_of_bit_for_num_1);
	density_for_num(count_of_bit_for_num_1, Num_1_elements_1);
	count_of_bit_1 = conv_NAF(num1, mas);
	print_NAF(mas, count_of_bit_1);
	cout << "bit count of NAF: " << dec << count_of_bit_1 << endl;
	count_of_NAN_zero_elements_1 = count_of_NAN_zero_elements_f(mas, count_of_bit_1);
	cout << "Weight_NAF: " << count_of_NAN_zero_elements_1 << endl;
	density_f(count_of_NAN_zero_elements_1, count_of_bit_1);
	res_1= decod_NAF(mas, count_of_bit_1);
	cout << "Decoded: " << res_1 << endl<<endl;

	//////////////////////////////////////////////////////////////////////////////////////////////////
	cout << "num: "<<hex << num2 << endl;
	count_of_bit_for_num_2 = count_of_bit_for_num_f(num2);
	cout << "Bit count of num: " << dec << count_of_bit_for_num_2 << endl;
	Num_1_elements_2 = Num_1_elements(num2, count_of_bit_for_num_2);
	density_for_num(count_of_bit_for_num_2, Num_1_elements_2);
	count_of_bit_2 = conv_NAF(num2, mas);
	print_NAF(mas, count_of_bit_2);
	cout << "bit count of NAF: " << dec << count_of_bit_2 << endl;
	count_of_NAN_zero_elements_2 = count_of_NAN_zero_elements_f(mas, count_of_bit_2);
	cout << "Weight_NAF: " << count_of_NAN_zero_elements_2 << endl;
	density_f(count_of_NAN_zero_elements_2, count_of_bit_2);
	res_2 = decod_NAF(mas, count_of_bit_2);
	cout << "Decoded = " << hex << res_2 << endl<<endl;
	//////////////////////////////////////////////////////////////////////////////////////////////////


	cout << "num: " << hex << num3 << endl;
	count_of_bit_for_num_3 = count_of_bit_for_num_f(num3);
	cout << "Bit count of num: " << dec << count_of_bit_for_num_3 << endl;
	Num_1_elements_3 = Num_1_elements(num3, count_of_bit_for_num_3);
	density_for_num(count_of_bit_for_num_3, Num_1_elements_3);
	count_of_bit_3 = conv_NAF(num3, mas);
	print_NAF(mas, count_of_bit_3);
	cout << "bit count of NAF: " << dec << count_of_bit_3 << endl;
	count_of_NAN_zero_elements_3 = count_of_NAN_zero_elements_f(mas, count_of_bit_3);
	cout << "Weight_NAF: " << count_of_NAN_zero_elements_3 << endl;
	density_f(count_of_NAN_zero_elements_3, count_of_bit_3);
	res_3 = decod_NAF(mas, count_of_bit_3);
	cout << "Decoded = " << hex << res_3 << endl<<endl;
	//////////////////////////////////////////////////////////////////////////////////////////////////


	delete []mas;
	system("pause");
	return 0;
}