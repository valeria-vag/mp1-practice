#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int r, ch, ch_pl = 0, k = 0, n1 = 1, n2 = 1000;
	char ssign;

	printf("HELLO! WELCOME TO THE GAME!\n");
	printf("The game has 2 modes\n");
	printf("1 - the player guesses the number \n");
	printf("2 - the computer guesses the number \n");
	do
	{
		printf("Choose the game mode (1 or 2) \n"); //����� ������ � ���������
		scanf("%d", &r);
	} while (r != 1 && r != 2);
	srand((unsigned int)time(0));
	if (r == 1)   //����� 1  
	{
		ch = rand() % (n2 - n1 + 1) + n1;
		printf("The computer made a number from 1 to 1000. Let's guess!\n");
		do
		{
			do 
			{ 
				scanf("%d", &ch_pl);
			} while (ch_pl <= 0 && ch_pl > 1000);
				
			if (ch_pl < ch)
				printf("This number %d is smaller than the number made by the computer. Try again \n", ch_pl);
			else
				printf("This number %d is bigger than the number made by the computer. Try again \n", ch_pl);
				k++; // ������� �������
		} while (ch != ch_pl);
		printf("You guessed the number! It's %d. Number of attempts: %d \n", ch, k);
		return;
	}

	else       //����� 2
	{
		printf("HINT: If the computer has entered a number larger, enter '>' else '<' \n  ");
		printf("    If the computer has entered a number equal to done, enter '=' \n ");
		printf("\n");
		do
		{
			printf("Make a number from 1 to 1000\n");
			scanf("%d", &ch_pl);
		} while (ch_pl <= 0 && ch_pl > 1000);
		do
		{
			ch = rand() % (n2 - n1 + 1) + n1;
			printf("The computer made a number %d\n", ch);

			do 
			{
				printf("Enter the sign\n");
				scanf("%1s", &ssign);
			} while (ssign != '=' && ssign != '<' && ssign != '>');
			if (ssign == '>')
				n2 = ch - 1;      // "����������" �������
			if (ssign == '<')
				n1 = ch + 1;
			k++;
		} while (ssign != '=');
			printf("Computer guessed the number! It's %d. Number of attempts: %d \n", ch, k);
		return;
	}
}
