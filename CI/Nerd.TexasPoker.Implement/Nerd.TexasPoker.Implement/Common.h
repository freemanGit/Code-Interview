#pragma once
struct card
{
	enum Suit suit;
	enum Colors color;
	enum Numbers number;
};	

enum Suit
{
	Diamonds, Hearts, Clubs, Spades
};

enum Colors
{
	Black, Red
};

enum Numbers
{
	Ace = 1,Two,Three,Four,Five,Six,Seven,Eight,Nigh,Ten,Jack,Queen,King
};
