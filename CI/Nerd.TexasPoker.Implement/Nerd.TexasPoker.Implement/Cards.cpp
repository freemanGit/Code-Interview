#include "stdafx.h"
#include "Cards.h"


Cards::Cards(void)
{
	InitialCardList();
	//shuffle 10 times
	for(int i = 0; i<10;++i)
		Shuffle();
}

Cards::~Cards(void)
{
}

void Cards::InitialCardList()
{
	//initial 52 cards;
	for (int i = 0; i< 52; ++i)
	{
		card *c = new card;
		if (i<13)
			c->suit = Suit::Spades;
		else if (i>=13&&i<26)
		    c->suit = Suit::Clubs;
		else if (i>=26&&i<39)
		    c->suit = Suit::Hearts;
		else if (i>=39&&i<52)
		    c->suit = Suit::Diamonds;

		i < 52/2 ? c->color = Colors::Black : c->color = Colors::Red;
		
		c->number = Numbers::Ace;
		card_list.push_back(c);
	}

	for (int i = 0; i<4; ++i)
	{
		card_list[0+13*i]->number = Numbers::Ace;
		card_list[1+13*i]->number = Numbers::Two;
		card_list[2+13*i]->number = Numbers::Three;
		card_list[3+13*i]->number = Numbers::Four;
		card_list[4+13*i]->number = Numbers::Five;
		card_list[5+13*i]->number = Numbers::Six;
		card_list[6+13*i]->number = Numbers::Seven;
		card_list[7+13*i]->number = Numbers::Eight;
		card_list[8+13*i]->number = Numbers::Nigh;
		card_list[9+13*i]->number = Numbers::Ten;
		card_list[10+13*i]->number = Numbers::Jack;
		card_list[11+13*i]->number = Numbers::Queen;
		card_list[12+13*i]->number = Numbers::King;
	}

}

//52! fully shuffled algorithem
void Cards::Shuffle()
{
	int size = card_list.size();
	for (int i = 0; i<size; ++i)
	{
		int index = get_random_index(i);
		card* temp = card_list[i];
		card_list[i] = card_list[index];
		card_list[index] = temp;
	}
}

int Cards::get_random_index(int range)
{
	int size = card_list.size();
	return std::rand()%(size-range) + range;
}