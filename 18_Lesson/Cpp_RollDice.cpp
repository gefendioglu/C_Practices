#include <stdlib.h>
#include <random>

#define NGAMES 100'000'000

// NGAMES 100'000'000 --> kazanma olasiligi : 0.492305970000
// NGAMES 10'000'000  --> kazanma olasiligi : 0.492299200000
// NGAMES 1'000'000   --> kazanma olasiligi : 0.492245000000

int rollDice(void) {

	static std::mt19937 eng; 
	std::uniform_int_distribution<int> dist{ 1,6 };

	int dice1 = dist(eng);
	int dice2 = dist(eng);

	return dice1 + dice2;
}

