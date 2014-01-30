#pragma once
#include <vector>
#include "Common.h"

class Players
{
public:
	Players(void);
	~Players(void);
	void ReceiveNextCard(card* singleCard);
	int SumOnHand();


private:
	std::vector<card*> cards_on_hand;
	
};

