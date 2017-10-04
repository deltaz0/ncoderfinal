#include "DecodedNewPacket.h"
#include "BitImport.h"
#include "Constants.h"
#include <math.h>
#include <iostream>
extern const int PACKBUF;
extern const int DATABUF;
using namespace std;

DecodedNewPacket::DecodedNewPacket(char* myFile) {
	BitImport* mypacks = new BitImport(myFile);
	//int packNum = 0;
	for (int packNum = 0; packNum < PACKBUF; packNum++) {
	int bitNum = 0;
	int readNum = 0;
		for (int msgNum = 0; msgNum < msgList.size(); msgNum++) {
			switch (msgList[msgNum].type) {
			case 0:
				if (mypacks->packs[packNum].data[readNum] == false) {
					loopAssigner(decpacks[packNum], msgList[msgNum].length, mypacks->packs[packNum].data, bitNum, readNum);
				}
				else {
					zeroAssigner(decpacks[packNum], msgList[msgNum].length, mypacks->packs[packNum].data, bitNum, readNum);
				}
				break;
			case 1:
				if (mypacks->packs[packNum].data[readNum] == true) {
					loopAssigner(decpacks[packNum], msgList[msgNum].length, mypacks->packs[packNum].data, bitNum, readNum);
				}
				else {
					zeroAssigner(decpacks[packNum], msgList[msgNum].length, mypacks->packs[packNum].data, bitNum, readNum);
				}
				break;
			case 2:
				loopAssigner(decpacks[packNum], msgList[msgNum].length, mypacks->packs[packNum].data, bitNum, readNum);
				break;
			case 3:
				if ((byteMerger(mypacks, packNum, 400) == 32) || (byteMerger(mypacks, packNum, 400) == 33)) {
					zeroAssignerNoIter(decpacks[packNum], msgList[msgNum].length, mypacks->packs[packNum].data, bitNum, readNum);
				}
				else {
					loopAssigner(decpacks[packNum], msgList[msgNum].length, mypacks->packs[packNum].data, bitNum, readNum);
				}
				break;
			case 4:
				if (decpacks[packNum][bitNum-6] == true && decpacks[packNum][bitNum-2] == true) {
					loopAssigner(decpacks[packNum], msgList[msgNum].length, mypacks->packs[packNum].data, bitNum, readNum);
				}
				else {
					zeroAssignerNoIter(decpacks[packNum], msgList[msgNum].length, mypacks->packs[packNum].data, bitNum, readNum);
				}
				break;
			case 5:
				if ((((decpacks[packNum][bitNum - 1] == false && decpacks[packNum][bitNum - 2] == false) && (decpacks[packNum][bitNum-3] == true && decpacks[packNum][bitNum-4] == true)) && (decpacks[packNum][bitNum-5] == false && decpacks[packNum][bitNum-6] == false)) && (((decpacks[packNum][bitNum - 7] == false && decpacks[packNum][bitNum - 8] == false) && (decpacks[packNum][bitNum - 9] == false && decpacks[packNum][bitNum - 10] == false)) && (decpacks[packNum][bitNum - 11] == false && decpacks[packNum][bitNum - 12] == false))) {
					loopAssigner(decpacks[packNum], msgList[msgNum].length, mypacks->packs[packNum].data, bitNum, readNum);
				}
				else {
					zeroAssignerNoIter(decpacks[packNum], msgList[msgNum].length, mypacks->packs[packNum].data, bitNum, readNum);
				}
				break;
			case 6:
				if (decpacks[packNum][bitNum - 548] == true) {
					loopAssigner(decpacks[packNum], msgList[msgNum].length, mypacks->packs[packNum].data, bitNum, readNum);
				}
				else {
					zeroAssignerNoIter(decpacks[packNum], msgList[msgNum].length, mypacks->packs[packNum].data, bitNum, readNum);
				}
				break;
			default:
				break;
			}
		}
		loopAssigner(decpacks[packNum], PACKBUF-readNum, mypacks->packs[packNum].data, bitNum, readNum);
	}
}

DecodedNewPacket::~DecodedNewPacket() {
	delete[] decpacks;
}

void DecodedNewPacket::loopAssigner(bool* rcvArr, int len, bool* sndArr, int &bitNum, int &readNum) {
	for (int i = 0; i < len; i++) {
		rcvArr[i + bitNum] = sndArr[i + readNum];
	}
	bitNum += len;
	readNum += len;
}

void DecodedNewPacket::zeroAssigner(bool* rcvArr, int len, bool* sndArr, int &bitNum, int &readNum) {
	rcvArr[bitNum] = sndArr[readNum];
	for (int i = 1; i < len; i++) {
		rcvArr[i + bitNum] = false;
	}
	bitNum += len;
	readNum++;
}

void DecodedNewPacket::zeroAssignerNoIter(bool* rcvArr, int len, bool* sndArr, int &bitNum, int &readNum) {
	for (int i = 0; i < len; i++) {
		rcvArr[i + bitNum] = false;
	}
	bitNum += len;
}

char DecodedNewPacket::byteMerger(BitImport* mypacks, int packIndex, int bitIndex) {
	//read the next 8 bits of mypacks[packIndex] starting at bitIndex and return a byte
	char ret = 0;
	for (int i = 0; i < 8; i++) {
		ret += mypacks->packs[packIndex].data[bitIndex + i] * pow(2, i);
	}
	return ret;
}