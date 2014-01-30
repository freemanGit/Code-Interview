#pragma once
#include <vector>
#include "Common.h"

class Cards
{
public:
	Cards(void);
	~Cards(void);
	void InitialCardList();
	void Shuffle();

private:

    std::vector<card*> card_list;

	int get_random_index(int range);
};
