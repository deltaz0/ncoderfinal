#pragma once
#include "Constants.h"
#include "BitImport.h"
#include <vector>
using namespace std;
extern const int PACKBUF;

class DecodedNewPacket {
public:
	DecodedNewPacket(char* myFile);
	~DecodedNewPacket();

	struct msg {
		//0 = msg present if false
		//1 = msg present if true
		//2 = msg always present
		//3 = special protoheader condition
		int type;
		//length of the message portion
		int length;
	};

	vector<msg> msgList = {
		{ 2,336 },
		{ 2,96 },
		{ 3,8 },
		{ 2,6 },
		{ 2,35 },
		{ 1,16 },
		{ 1,34 },
		//{ 2,3 },
		//{ 1,56 },
		//{ 2,7 },
		{ 2,11 },
		{ 2,6 },
		{ 5,26 },
		{ 1,56 },
		{ 0,56 },
		{ 4,520 },
		{ 6,64 },
		//{ 5,1565 },
		{ 2,17 },
		//{ 5,16 },
		{ 1,16 },
		{ 1,411 },
		{ 1,33 },
		{ 2,1 },
		{ 1,41 },
		{ 2,2 },
		//{ 2,6 },
		{ 1,451 },
		{ 1,58 },
		//{ 1,475 },
		{ 1,434 },
		{ 1,519 },
		{ 1,32 },
		//{ 1,42 },
		{ 2,1 },
		{ 0,3 },
		{ 2,13 },
		{ 2,19 },
		{ 1,33 },
		{ 2,34 },
		{ 1,65 },
		{ 2,1 },
		{ 2,1 },
		{ 1,33 },
		{ 2,1 },
		{ 1,24 },//this can be corrected with above
		{ 1,354 },
		{ 1,2 },
		{ 2,2 },
		{ 1,65 },
		{ 2,2 },
		{ 1,52 },
		{ 2,2 },
		{ 1,33 },
		{ 2,6 },
		{ 1,58 },//
		{ 2,1 },
		{ 1,2 },
		{ 1,84 },
		{ 2,2 },
		{ 1,20 },
		{ 2,4 },
		{ 0,14 },
		{ 0,14 },
		{ 1,52 },
		//{ 0,34 },
		//{ 1,11 },
		//{ 1,65 },
		//{ 2,45 },
		//{ 0,14 },
		//{ 0,14 },
		//{ 0,14 }
		/*
		{2,336},
		{2,96},
		{3,8},
		{4,2},
		{2,4},
		{2,48},
		{2,6},
		{1,56},
		{0,56},
		{2,17},
		{1,16},
		{2,6},
		{1,449},
		{1,58},
		{1,56},
		{1,411},
		{1,32},
		{1,2},
		{0,3},
		{2,13},
		{0,34},
		{1,11},
		{0,73},
		{1,65},
		{2,45},
		{0,14},
		{0,14},
		{0,14}
		*/
	};

	bool decpacks[PACKBUF][8092];

	void loopAssigner(bool* rcvArr, int len, bool* sndArr, int &bitNum, int &readNum);

	void zeroAssigner(bool* rcvArr, int len, bool* sndArr, int &bitNum, int &readNum);

	void zeroAssignerNoIter(bool* rcvArr, int len, bool* sndArr, int &bitNum, int &readNum);

	char byteMerger(BitImport* mypacks, int packIndex, int bitIndex);
};