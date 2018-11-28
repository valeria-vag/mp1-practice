#include <stdio.h>
#define N 20 
#define K 16

int InputCode(int CODE[], int n) //ввод кода с проверкой на принадлежность базе данных кодов
{
	int i, f = 0, code;
	printf("Enter code: \n");
	scanf("%d", &code);
	for (i = 0; i < N; i++)
	{
		if (CODE[i] == code)
		{
			f = 1;
			break;
		}
	}
	if (f == 1)
		return i; //если удачно, то номер в массиве 
	else return -1; //если нет, то -1 - для вывода ошибки
}

void Choose()
{
	printf("\n");
	printf("                 Select the action:                   \n");
	printf("        1. Scan product and add to check.             \n");
	printf("     2. Finish scanning. Make a cash voucher.         \n");
	printf("                                                      \n");
}

void product(char product[][K], int price[], float discount[], int  pos_of_code)
{
	int i;
	printf("   Name        Price    Discount  \n");
	for (i = 0; i < K; i++)
	printf("%c", product[pos_of_code][i]);
	printf("%d rub.       ", price[pos_of_code]);
	printf("%0.0f%% \n", discount[pos_of_code]);
}

float SUM(int price[], float discount[], int  pos_of_code)
{
	int i;
	float sum = 0;
	for (i = 0; i < N; i++)
		sum = price[pos_of_code] * (1 - discount[pos_of_code] * 0.01);
	return sum;

}

void OutputCheck(char product[][K], int price[], float discount[], int k[], float sum)
{
	int i, j;
	printf("______________________________________________________\n");
	printf("______________________________________________________\n");
	printf("    Name               Price      Discount      Cost \n");
	for (i = 0; i < N; i++)
	{
		if (k[i] != 0) //проверка на скан хотя бы 1го продукта
		{ 
			for (j = 0; j < K; j++)
				printf("%c", product[i][j]);
			printf("*%d       %d rub.      %0.0f%%       %.2f rub. \n", k[i], price[i],  discount[i], price[i] * (1 - discount[i] * 0.01));
		}
			
	}
	printf("______________________________________________________\n");
	printf("   TOTAL: %.2f \n", sum);
}

void main()
{
	char PRODUCTS[N][K] = { "White bread", "Rye bread", "Baguette", "   Milk",
		"  Yogurt", "Cottage cheese ", "Cheese", "Ice cream", "Cookie", "   Cake",
		"Lemonade", "Candys 0.5kg", "Chocolate", "Potato chip", "Sausages",
		"Potatoes 1kg", "Cucumbers 1kg", "Tomatoes 1kg", "Sugar 1kg", "   Egg" };
	int CODE[N] = { 1000, 1001, 1002, 1003, 1004, 1005,
	1006, 1007, 1008, 1009, 1010, 1011, 1012, 1013,
	1014, 1015, 1016, 1017, 1018, 1019 }; //"1111" - для вывода чека
	int PRICE[N] = { 28, 32, 25, 49, 30, 45, 120, 40, 60, 250, 60, 75,
		80, 43, 65, 50, 150, 85, 55, 47 }; //цена каждого продукта
	int pos_of_code, i, n, ch_action, fl = 0, f;
	int arr_of_code[100] = { 0 }; //массив под сканированные коды
	float DISCOUNT[N], fin_sum = 0, cost;
	for (i = 0; i < N; i++)
		DISCOUNT[i] = rand() % 50 + 1; //независимая генерация скидок на каждый товар
	printf("\n");
	printf("           Welcome to our store 'Delicious'!\n");
	printf("                  We glad to see you!\n");
	printf("\n");
	printf("                      CASHBOX\n");
	printf("\n");
	do
	{
		Choose();
		do
		{
			f = 0;
			scanf("%d", &ch_action);
			if (ch_action != 1 && ch_action != 2)
			{ 
				printf("ERROR. SELECT THE ACTION (1 or 2)\n");
				f = 1;
			}
				
		} while (f == 1);
		switch (ch_action)
		{
		case 1:
		{
			fl = 1;
			pos_of_code = InputCode(CODE, N);
			if (pos_of_code == -1)
			{
				printf("                             ERROR!\n");
				printf("Check the code belonging to the interval from 1000 to 1019 inclusive\n");
				printf("\n");
				break;
			}
			arr_of_code[pos_of_code] ++; //счетчик сканированных кодов
			product(PRODUCTS, PRICE, DISCOUNT, pos_of_code);
			cost = SUM(PRICE, DISCOUNT, pos_of_code);
			fin_sum += cost;
			break;
		case 2:
			if (fl != 1)
			{
				printf("          ERROR! The check cannot be empty\n");
				printf("         (Need to scan at least one product)\n");
				break;
			}
			OutputCheck(PRODUCTS, PRICE, DISCOUNT, arr_of_code, fin_sum);
			break;
		}
		}
	} while (ch_action != 2 || fl != 1);
	system("pause");
	//return;
}