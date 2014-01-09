#ifndef ZodziuDaznis_H
#define ZodziuDaznis_H

#include <string>

using namespace std;

class ZodziuDaznis {
private:
	string zodis;
	int kiek;
public:
	// Populate words list
	ZodziuDaznis(string i, int k) { zodis = i; kiek = k; };
	// Get word
	string ImtiZodi() { return zodis; };
	// Get number of words
	int ImtiKiek() { return kiek; };
	// Set number of words
	void DetiKiek(int k) { kiek = k; };
	// Operator overlay
	friend bool operator== (const ZodziuDaznis zod1, const ZodziuDaznis zod2) { return zod1.zodis == zod2.zodis; };
};

#endif