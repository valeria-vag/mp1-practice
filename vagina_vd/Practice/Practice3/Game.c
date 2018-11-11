#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int r, ch, ch_pl, k, n1 = 1, n2 = 1000;
	char ssign;

	printf("HELLO! WELCOME TO THE GAME!\n");
	printf("The game has 2 modes\n");
	printf("1 - the player guesses the number \n");
	printf("2 - the computer guesses the number \n");
	do
	{
		printf("Choose the game mode (1 or 2) \n"); //выбор режима с проверкой
		scanf("%d", &r);
	} while ((r != 1) && (r != 2));
	srand((unsigned int)time(0));
	k = 0;
	if (r == 1)   //режим 1  
	{
		ch = rand() % (n2 - n1 + 1) + n1;
		printf("The computer made a number from 1 to 1000. Let's guess!\n");
		do
		{
			while ((ch_pl > 0) && (ch_pl <= 1000))
				scanf("%d", &ch_pl);
			if (ch_pl < ch)
				printf("This number %d is smaller than the number made by the computer. Try again \n", ch_pl);
			else
				printf("This number %d is bigger than the number made by the computer. Try again \n", ch_pl);
				k++; // счетчик попыток
		} while (ch != ch_pl);
		printf("You guessed the number! It's %d. Number of attempts: %d \n", ch, k);
		return;
	}

	else       //режим 2
	{
		printf("HINT: if the computer has entered a number larger, enter '>' else '<' /n  ");
		printf("If the computer has entered a number equal to done, enter '=' ");
		while ((ch_pl > 0) && (ch_pl <= 1000))
		{
			printf("Make a number from 1 to 1000\n");
			scanf("%d", &ch_pl);
		}
		do
		{
			ch = rand() % (n2 - n1 + 1) + n1;
			printf("The computer made a number %d /n", ch);

			while ((ssign == '=') || (ssign == '<') || (ssign == '>'))
			{
				printf("Enter the sign /n");
				scanf("%с", &ssign);
			}
			if (ssign == '<')
				n2 = ch - 1;      // "сокращение" отрезка
			if (ssign == '>')
				n1 = ch + 1;
			k++;
		} while (ssign != '=');
			printf("Computer guessed the number! It's %d. Number of attempts: %d \n", ch, k);
		return;
	}
}
