#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int deck_size = 52;
int num_deal = 0;
int high_cards = 0;
int low_cards = 0;
int middle_cards = 0;
int bet_count = 0;

int deck[52] = {2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,
			7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,11,11,11,11};

void shuffle(int *A, int num_elements){
	int i = 0;
	int temp;

	for (i = num_elements - 1; i > 0; i--){

		int swapindex = (rand() % (i + 1));
		temp = A[swapindex];
		A[swapindex] = A[i];
		A[i] = temp;
	}
}

int deal_1(int *B)
{
	
	if (deck_size == 0)
	{
		deck_size = 52;
		shuffle(B, 52);
	}
	
	deck_size--;
	num_deal++;

	return B[deck_size];
}

int deal_2(int *C)
{
	if (deck_size == 0)
	{
		deck_size = 52;
		shuffle(C, 52);

		bet_count = 0;
		high_cards = 0;
		low_cards = 0;
		middle_cards = 0;
	}
	
	deck_size--;
	int dealt_card = C[deck_size];
	if (dealt_card == 10 || dealt_card == 11)
	{
		high_cards++;
	}
	else if (dealt_card == 2 || dealt_card == 3 || dealt_card == 4 || dealt_card == 5 || dealt_card == 6)
	{
		low_cards++;
	}
	else
	{
		middle_cards++;
	}
	num_deal++;

	return C[deck_size];
}

int remainingCards(num_deal)
{
	return (52 - num_deal);
}

int participant_hand(int participant, int threshold)
{
	int a = 0;
	int current_card = 0;
	bool flag1 = 1;
	bool flag2 = 1;
	bool flag3 = 1;
	bool flag4 = 1;
	int ace_drawn = 0;
	participant = 0;

	while (participant < threshold)
	{
		current_card = deal_2(deck);
		if (current_card == 11)
		{
			ace_drawn++;
		}
				
		if (ace_drawn == 0)
		{
			participant += current_card;
		}
				
		else if (ace_drawn == 1 && flag1 == 1)
		{
			flag1 = 0;
			if (participant < 10)
			{
				participant += 11;
			}
			else
			{
				participant += 1;
			}
		}
				
		else if (ace_drawn == 2 && flag2 == 1)
		{
			flag2 = 0;
			if (participant > 21)
			{
				participant = participant - 9;
			}
			else
			{
				participant += 1;
			}
		}
				
		else if (ace_drawn == 3 && flag3 == 1)
		{
			flag3 = 0;
			if (participant > 21)
			{
				participant = participant - 19;
			}
			else
			{
			participant += 1;
			}
		}
				
		else if (ace_drawn == 4 && flag4 == 1)
		{
			flag4 = 0;
			if (participant > 21)
			{
				participant = participant - 29;
			}
			else
			{
				participant += 1;
			}
				  
		}
				
		else
		{
			participant += current_card;
		}

	}
			
		a = participant;
		participant = 0;
		return a;
}

int main()
{
	srand((unsigned int)time(NULL));
	
	int player = 0;
	int count = 0;
	int card = 0;
	int ace_drawn = 0;
	int i, j = 0;

	shuffle(deck, 52);

printf("Chance of Bust at Threshold:\n");

	for (i = 10; i < 21; ++i)
	{

		for (j = 0; j < 10000; ++j)
		{
		    bool flag1 = 1;
			bool flag2 = 1;
			bool flag3 = 1;
			bool flag4 = 1;
			ace_drawn = 0;
			player = 0;

			while (player < i)
			{
				card = deal_1(deck);
				if (card == 11)
				{
					ace_drawn++;
				}
				
				if (ace_drawn == 0)
				{
					player += card;
				}
				
				else if (ace_drawn == 1 && flag1 == 1)
				{
					flag1 = 0;
					if (player < 10)
					{
						player += 11;
					}
					else
					{
						player += 1;
					}
				}
				
				else if (ace_drawn == 2 && flag2 == 1)
				{
					flag2 = 0;
					if (player > 21)
					{
						player = player - 9;
					}
					else
					{
					player += 1;
					}
				}
				
				else if (ace_drawn == 3 && flag3 == 1)
				{
					flag3 = 0;
					if (player > 21)
					{
						player = player - 19;
					}
					else
					{
					player += 1;
					}
				}
				
				else if (ace_drawn == 4 && flag4 == 1)
				{
					flag4 = 0;
					if (player > 21)
					{
						player = player - 29;
					}
					else
					{
					player += 1;
					}
				}
				
				else
				{
					player += card;
				}
			}
			
			if (player > 21)
			{
				count++;
			}
			
		}
		
		float bust = (float)count / 10000;
		printf("%d", i);
		printf(": ");
		printf("%.6f\n", bust);
		bust = 0;
		count = 0;
	}
	
printf("Card Counting Result:\n");

	int dealer, player1, player2, player3 = 0;
	player = 0;
	int tie = 0; 
	int player_result = 0;
	int dealer_result = 0;
	int num_hands = 10000;
	int bet_high, bet_low, bet_mid = 0;
	int result_win = 0; 
	int result_lost = 0; 
	int k, l, m, n = 0;
	int correct = 0;
	float bet_correct = 0;

	for (i = 0; i < num_hands; ++i)
	{

		if (bet_count >= 1)
		{
			bet_high = 1;
		}
		else if (bet_count <= -1)
		{
			bet_low = 1;
		}
		else
		{
			bet_mid = 1;
		}
		
		bet_count = 0;

		dealer = deal_2(deck);

		for (k = 0; k < 2; ++k)
		{
			player1 += deal_2(deck);
		}

		for (l = 0; l < 2; ++l)
		{
			player2 += deal_2(deck);
		}

		for (m = 0; m < 2; ++m)
		{
			player3 += deal_2(deck);
		}

		player_result = participant_hand(player, 18);

		if (player_result > 21)
		{
			result_lost = 1;
		}

		else if (player_result == 21)
		{
			result_win = 1;
		}

		else
		{
			dealer_result = participant_hand(dealer, 17);

			if (dealer_result > 21 || player_result > dealer_result)
			{
				result_win = 1;
			}

			if (dealer_result > player_result)
			{
				result_lost = 1;
			}

		}
		
		bet_count += (low_cards - high_cards);
		
		if ((bet_high == 1 && result_win == 1) || (bet_low == 1 && result_lost == 1) || (bet_mid == 1 && result_win == 1))
		{
			correct++;
		}

		result_win = 0;
		result_lost = 0;
		bet_high = 0;
		bet_low = 0;
		bet_mid = 0;
	}
	
	bet_correct = (float)correct / 10000;
	
	printf("%.6f\n", bet_correct);

	return 0;
}