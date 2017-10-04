#include "DecodedBitPacket.h"
#include <bitset>
#include "BitImport.h"
#include "Constants.h"
#include <math.h>
extern const int PACKBUF;
extern const int DATABUF;
using namespace std;

DecodedBitPacket::DecodedBitPacket(char* myFile) {
	BitImport* mypacks = new BitImport(myFile);
	int s1 = sizeof(decpacks[0].udp);
	int s2 = sizeof(decpacks[0].protoheader) + s1;
	int s3 = sizeof(decpacks[0].protoheaderflag) + s2;
	int s4 = sizeof(decpacks[0].tickmsg) + s3;
	int s5 = sizeof(decpacks[0].tick) + s4;
	int s6 = sizeof(decpacks[0].usrcmdmsg) + s5;
	int s7 = sizeof(decpacks[0].msgApresent) + s6;
	int s8 = sizeof(decpacks[0].msgA) + s7;
	int s9 = sizeof(decpacks[0].msgBpresent) + s8;
	int s10 = sizeof(decpacks[0].msgB) + s9;
	int s11 = sizeof(decpacks[0].msgCpresent) + s10;
	int s12 = sizeof(decpacks[0].msgC) + s11;
	int s13 = sizeof(decpacks[0].msgDpresent) + s12;
	int s14 = sizeof(decpacks[0].msgD) + s13;
	int s15 = sizeof(decpacks[0].msgEpresent) + s14;
	int s16 = sizeof(decpacks[0].msgE) + s15;
	int s17 = sizeof(decpacks[0].msgFpresent) + s16;
	int s18 = sizeof(decpacks[0].msgF) + s17;
	int s19 = sizeof(decpacks[0].msgGpresent) + s18;
	int s20 = sizeof(decpacks[0].msgG) + s19;
	int s21 = sizeof(decpacks[0].msgHpresent) + s20;
	int s22 = sizeof(decpacks[0].msgH) + s21;
	int s23 = sizeof(decpacks[0].msgIpresent) + s22;
	int s24 = sizeof(decpacks[0].msgI) + s23;
	int s25 = sizeof(decpacks[0].msgJpresent) + s24;
	int s26 = sizeof(decpacks[0].msgJ) + s25;
	int s27 = sizeof(decpacks[0].msgKpresent) + s26;
	int s28 = sizeof(decpacks[0].msgK) + s27;
	int s29 = sizeof(decpacks[0].msgLpresent) + s28;
	int s30 = sizeof(decpacks[0].msgL) + s29;
	int s31 = sizeof(decpacks[0].msgMpresent) + s30;
	int s32 = sizeof(decpacks[0].msgM) + s31;
	int s33 = sizeof(decpacks[0].msgNpresent) + s32;
	int s34 = sizeof(decpacks[0].msgN) + s33;
	int s35 = sizeof(decpacks[0].msgOpresent) + s34;
	int s36 = sizeof(decpacks[0].msgO) + s35;
	int s37 = sizeof(decpacks[0].msgPpresent) + s36;
	int s38 = sizeof(decpacks[0].msgP) + s37;
	int s39 = sizeof(decpacks[0].msgQpresent) + s38;
	int s40 = sizeof(decpacks[0].msgQ) + s39;
	int s41 = sizeof(decpacks[0].msgRpresent) + s40;
	int s42 = sizeof(decpacks[0].msgR) + s41;
	int s43 = sizeof(decpacks[0].msgSpresent) + s42;
	int s44 = sizeof(decpacks[0].msgS) + s43;
	int s45 = sizeof(decpacks[0].msgTpresent) + s44;
	int s46 = sizeof(decpacks[0].msgT) + s45;
	int s47 = sizeof(decpacks[0].msgUpresent) + s46;
	int s48 = sizeof(decpacks[0].msgU) + s47;
	//p is which packet
	//b is which bit
	//q is bit index of current section
	//o is bit offset
	for (int p = 0; p < PACKBUF; p++) {
		int q = 0;
		int o = 0;
		for (int b = 0; b < 4096; b++) {
			if (b < s1) {
				q = b - 0;
				decpacks[p].udp[q] = mypacks->packs[p].data[b + o];
			}
			else if (b < s2) {
				q = b - s1;
				decpacks[p].protoheader[q] = mypacks->packs[p].data[b + o];
			}
			else if (b < s3) {
				q = b - s2;
				if (p == 1272) {
					int test = 1;
				}
				if (((byteMerger(mypacks, p, 400) == 32) || (byteMerger(mypacks, p, 400) == 33)) && b == s2) {
					o = o - 8;
					b = b + 7;
					for (int i = 0; i < 8; i++) {
						decpacks[p].protoheaderflag[q] = 0;
					}
				}
				else {
					decpacks[p].protoheaderflag[q] = mypacks->packs[p].data[b + o];
				}
			}
			else if (b < s4) {
				q = b - s3;
				decpacks[p].tickmsg[q] = mypacks->packs[p].data[b + o];
			}
			else if (b < s5) {
				q = b - s4;
				decpacks[p].tick[q] = mypacks->packs[p].data[b + o];
			}
			else if (b < s6) {
				q = b - s5;
				decpacks[p].usrcmdmsg[q] = mypacks->packs[p].data[b + o];
			}
			else if (b < s7) {
				q = b - s6;
				decpacks[p].msgApresent = mypacks->packs[p].data[b + o];
			}
			else if (b < s8) {
				q = b - s7;
				if (decpacks[p].msgApresent == false && b == s7 - (1 - enableA)) {
					o = o - sizeof(decpacks[0].msgA);
					b = b + sizeof(decpacks[0].msgA) - 1;
					for (int i = 0; i < sizeof(decpacks[0].msgA); i++) {
						decpacks[p].msgA[q] = 0;
					}
				}
				else {
					decpacks[p].msgA[q] = mypacks->packs[p].data[b + o];
				}
			}
			else if (b < s9) {
				q = b - s8;
				decpacks[p].msgBpresent = mypacks->packs[p].data[b + o];
			}
			else if (b < s10) {
				q = b - s9;
				if ((decpacks[p].msgBpresent == true) && b == s9 - (1 - enableB)) {
					o = o - sizeof(decpacks[0].msgB);
					b = b + sizeof(decpacks[0].msgB) - 1;
					for (int i = 0; i < sizeof(decpacks[0].msgB); i++) {
						decpacks[p].msgB[q] = 0;
					}
				}
				else {
					decpacks[p].msgB[q] = mypacks->packs[p].data[b + o];
				}
			}
			else if (b < s11) {
				q = b - s10;
				decpacks[p].msgCpresent = mypacks->packs[p].data[b + o];
			}
			else if (b < s12) {
				q = b - s11;
				if (decpacks[p].msgCpresent == true && b == s11 - (1 - enableC)) {
					o = o - sizeof(decpacks[0].msgC);
					b = b + sizeof(decpacks[0].msgC) - 1;
					for (int i = 0; i < sizeof(decpacks[0].msgC); i++) {
						decpacks[p].msgC[q] = 0;
					}
				}
				else {
					decpacks[p].msgC[q] = mypacks->packs[p].data[b + o];
				}
			}
			else if (b < s13) {
				q = b - s12;
				decpacks[p].msgDpresent = mypacks->packs[p].data[b + o];
			}
			else if (b < s14) {
				q = b - s13;
				if (decpacks[p].msgDpresent == false && b == s13 - (1 - enableD)) {
					o = o - sizeof(decpacks[0].msgD);
					b = b + sizeof(decpacks[0].msgD) - 1;
					for (int i = 0; i < sizeof(decpacks[0].msgD); i++) {
						decpacks[p].msgD[q] = 0;
					}
				}
				else {
					decpacks[p].msgD[q] = mypacks->packs[p].data[b + o];
				}
			}
			else if (b < s15) {
				q = b - s14;
				decpacks[p].msgEpresent = mypacks->packs[p].data[b + o];
			}
			else if (b < s16) {
				q = b - s15;
				if (decpacks[p].msgEpresent == false && b == s15 - (1 - enableE)) {
					o = o - sizeof(decpacks[0].msgE);
					b = b + sizeof(decpacks[0].msgE) - 1;
					for (int i = 0; i < sizeof(decpacks[0].msgE); i++) {
						decpacks[p].msgE[q] = 0;
					}
				}
				else {
					decpacks[p].msgE[q] = mypacks->packs[p].data[b + o];
				}
			}
			else if (b < s17) {
				q = b - s16;
				decpacks[p].msgFpresent = mypacks->packs[p].data[b + o];
			}
			else if (b < s18) {
				q = b - s17;
				if (decpacks[p].msgFpresent == false && b == s17 - (1 - enableF)) {
					o = o - sizeof(decpacks[0].msgF);
					b = b + sizeof(decpacks[0].msgF) - 1;
					for (int i = 0; i < sizeof(decpacks[0].msgF); i++) {
						decpacks[p].msgF[q] = 0;
					}
				}
				else {
					decpacks[p].msgF[q] = mypacks->packs[p].data[b + o];
				}
			}
			else if (b < s19) {
				q = b - s18;
				decpacks[p].msgGpresent = mypacks->packs[p].data[b + o];
			}
			else if (b < s20) {
				q = b - s19;
				if (decpacks[p].msgGpresent == false && b == s19 - (1 - enableG)) {
					o = o - sizeof(decpacks[0].msgG);
					b = b + sizeof(decpacks[0].msgG) - 1;
					for (int i = 0; i < sizeof(decpacks[0].msgG); i++) {
						decpacks[p].msgG[q] = 0;
					}
				}
				else {
					decpacks[p].msgG[q] = mypacks->packs[p].data[b + o];
				}
			}
			else if (b < s21) {
				q = b - s20;
				decpacks[p].msgHpresent = mypacks->packs[p].data[b + o];
			}
			else if (b < s22) {
				q = b - s21;
				if (decpacks[p].msgHpresent == false && b == s21 - (1 - enableH)) {
					o = o - sizeof(decpacks[0].msgH);
					b = b + sizeof(decpacks[0].msgH) - 1;
					for (int i = 0; i < sizeof(decpacks[0].msgH); i++) {
						decpacks[p].msgH[q] = 0;
					}
				}
				else {
					decpacks[p].msgH[q] = mypacks->packs[p].data[b + o];
				}
			}
			else if (b < s23) {
				q = b - s22;
				decpacks[p].msgIpresent = mypacks->packs[p].data[b + o];
			}
			else if (b < s24) {
				q = b - s23;
				if (decpacks[p].msgIpresent == false && b == s23 - (1 - enableI)) {
					o = o - sizeof(decpacks[0].msgI);
					b = b + sizeof(decpacks[0].msgI) - 1;
					for (int i = 0; i < sizeof(decpacks[0].msgI); i++) {
						decpacks[p].msgI[q] = 0;
					}
				}
				else {
					decpacks[p].msgI[q] = mypacks->packs[p].data[b + o];
				}
			}
			else if (b < s25) {
				q = b - s24;
				decpacks[p].msgJpresent = mypacks->packs[p].data[b + o];
			}
			else if (b < s26) {
				q = b - s25;
				if (decpacks[p].msgJpresent == false && b == s25 - (1 - enableJ)) {
					o = o - sizeof(decpacks[0].msgJ);
					b = b + sizeof(decpacks[0].msgJ) - 1;
					for (int i = 0; i < sizeof(decpacks[0].msgJ); i++) {
						decpacks[p].msgJ[q] = 0;
					}
				}
				else {
					decpacks[p].msgJ[q] = mypacks->packs[p].data[b + o];
				}
			}
			else if (b < s27) {
				q = b - s26;
				decpacks[p].msgKpresent = mypacks->packs[p].data[b + o];
			}
			else if (b < s28) {
				q = b - s27;
				if (decpacks[p].msgKpresent == false && b == s27 - (1 - enableK)) {
					o = o - sizeof(decpacks[0].msgK);
					b = b + sizeof(decpacks[0].msgK) - 1;
					for (int i = 0; i < sizeof(decpacks[0].msgK); i++) {
						decpacks[p].msgK[q] = 0;
					}
				}
				else {
					decpacks[p].msgK[q] = mypacks->packs[p].data[b + o];
				}
			}
			else if (b < s29) {
				q = b - s28;
				decpacks[p].msgLpresent = mypacks->packs[p].data[b + o];
			}
			else if (b < s30) {
				q = b - s29;
				if (decpacks[p].msgLpresent == true && b == s29 - (1 - enableL)) {
					o = o - sizeof(decpacks[0].msgL);
					b = b + sizeof(decpacks[0].msgL) - 1;
					for (int i = 0; i < sizeof(decpacks[0].msgL); i++) {
						decpacks[p].msgL[q] = 0;
					}
				}
				else {
					decpacks[p].msgL[q] = mypacks->packs[p].data[b + o];
				}
			}
			else if (b < s31) {
				q = b - s30;
				decpacks[p].msgMpresent = mypacks->packs[p].data[b + o];
			}
			else if (b < s32) {
				q = b - s31;
				if (decpacks[p].msgMpresent == false && b == s31 - (1 - enableM)) {
					o = o - sizeof(decpacks[0].msgM);
					b = b + sizeof(decpacks[0].msgM) - 1;
					for (int i = 0; i < sizeof(decpacks[0].msgM); i++) {
						decpacks[p].msgM[q] = 0;
					}
				}
				else {
					decpacks[p].msgM[q] = mypacks->packs[p].data[b + o];
				}
			}
			else if (b < s33) {
				q = b - s32;
				decpacks[p].msgNpresent = mypacks->packs[p].data[b + o];
			}
			else if (b < s34) {
				q = b - s33;
				if (decpacks[p].msgNpresent == true && b == s33 - (1 - enableN)) {
					o = o - sizeof(decpacks[0].msgN);
					b = b + sizeof(decpacks[0].msgN) - 1;
					for (int i = 0; i < sizeof(decpacks[0].msgN); i++) {
						decpacks[p].msgN[q] = 0;
					}
				}
				else {
					decpacks[p].msgN[q] = mypacks->packs[p].data[b + o];
				}
			}
			else if (b < s35) {
				q = b - s34;
				decpacks[p].msgOpresent = mypacks->packs[p].data[b + o];
			}
			else if (b < s36) {
				q = b - s35;
				if (decpacks[p].msgOpresent == false && b == s35 - (1 - enableO)) {
					o = o - sizeof(decpacks[0].msgO);
					b = b + sizeof(decpacks[0].msgO) - 1;
					for (int i = 0; i < sizeof(decpacks[0].msgO); i++) {
						decpacks[p].msgO[q] = 0;
					}
				}
				else {
					decpacks[p].msgO[q] = mypacks->packs[p].data[b + o];
				}
			}
			else if (b < s37) {
				q = b - s36;
				decpacks[p].msgPpresent = mypacks->packs[p].data[b + o];
			}
			else if (b < s38) {
				q = b - s37;
				if (decpacks[p].msgPpresent == true && b == s37 - (1 - enableP)) {
					o = o - sizeof(decpacks[0].msgP);
					b = b + sizeof(decpacks[0].msgP) - 1;
					for (int i = 0; i < sizeof(decpacks[0].msgP); i++) {
						decpacks[p].msgP[q] = 0;
					}
				}
				else {
					decpacks[p].msgP[q] = mypacks->packs[p].data[b + o];
				}
			}
			else if (b < s39) {
				q = b - s38;
				decpacks[p].msgQpresent = mypacks->packs[p].data[b + o];
			}
			else if (b < s40) {
				q = b - s39;
				if (decpacks[p].msgQpresent == false && b == s39 - (1 - enableQ)) {
					o = o - sizeof(decpacks[0].msgQ);
					b = b + sizeof(decpacks[0].msgQ) - 1;
					for (int i = 0; i < sizeof(decpacks[0].msgQ); i++) {
						decpacks[p].msgQ[q] = 0;
					}
				}
				else {
					decpacks[p].msgQ[q] = mypacks->packs[p].data[b + o];
				}
			}
			else if (b < s41) {
				q = b - s40;
				decpacks[p].msgRpresent = mypacks->packs[p].data[b + o];
			}
			else if (b < s42) {
				q = b - s41;
				if (decpacks[p].msgRpresent == true && b == s41 - (1 - enableQ)) {
					o = o - sizeof(decpacks[0].msgR);
					b = b + sizeof(decpacks[0].msgR) - 1;
					for (int i = 0; i < sizeof(decpacks[0].msgR); i++) {
						decpacks[p].msgR[q] = 0;
					}
				}
				else {
					decpacks[p].msgR[q] = mypacks->packs[p].data[b + o];
				}
			}
			else if (b < s43) {
				q = b - s42;
				decpacks[p].msgSpresent = mypacks->packs[p].data[b + o];
			}
			else if (b < s44) {
				q = b - s43;
				if (decpacks[p].msgSpresent == true && b == s43 - (1 - enableS)) {
					o = o - sizeof(decpacks[0].msgS);
					b = b + sizeof(decpacks[0].msgS) - 1;
					for (int i = 0; i < sizeof(decpacks[0].msgS); i++) {
						decpacks[p].msgS[q] = 0;
					}
				}
				else {
					decpacks[p].msgS[q] = mypacks->packs[p].data[b + o];
				}
			}
			else if (b < s45) {
				q = b - s44;
				decpacks[p].msgTpresent = mypacks->packs[p].data[b + o];
			}
			else if (b < s46) {
				q = b - s45;
				if (decpacks[p].msgTpresent == true && b == s45 - (1 - enableT)) {
					o = o - sizeof(decpacks[0].msgT);
					b = b + sizeof(decpacks[0].msgT) - 1;
					for (int i = 0; i < sizeof(decpacks[0].msgT); i++) {
						decpacks[p].msgT[q] = 0;
					}
				}
				else {
					decpacks[p].msgT[q] = mypacks->packs[p].data[b + o];
				}
			}
			else if (b < s47) {
				q = b - s46;
				decpacks[p].msgUpresent = mypacks->packs[p].data[b + o];
			}
			else if (b < s48) {
				q = b - s47;
				if (decpacks[p].msgUpresent == true && b == s47 - (1 - enableU)) {
					o = o - sizeof(decpacks[0].msgU);
					b = b + sizeof(decpacks[0].msgU) - 1;
					for (int i = 0; i < sizeof(decpacks[0].msgU); i++) {
						decpacks[p].msgU[q] = 0;
					}
				}
				else {
					decpacks[p].msgU[q] = mypacks->packs[p].data[b + o];
				}
			}
			else {
				q = b - s48;
				decpacks[p].extra[q] = mypacks->packs[p].data[b + o];
			}
		}
	}
}

DecodedBitPacket::~DecodedBitPacket() {
	delete[] decpacks;
}

char DecodedBitPacket::byteMerger(BitImport* mypacks, int packIndex, int bitIndex) {
	//read the next 8 bits of mypacks[packIndex] starting at bitIndex and return a byte
	char ret = 0;
	for (int i = 0; i < 8; i++) {
		ret += mypacks->packs[packIndex].data[bitIndex + i] * pow(2, i);
	}
	return ret;
}

/*
#include "DecodedBitPacket.h"
#include <bitset>
#include "BitImport.h"
#include "Constants.h"
#include <math.h>
extern const int PACKBUF;
extern const int DATABUF;
using namespace std;

DecodedBitPacket::DecodedBitPacket(char* myFile) {
	BitImport* mypacks = new BitImport(myFile);

	//p is which packet
	//b is which bit
	//q is bit index of current section
	//o is bit offset
	for (int p = 0; p < PACKBUF; p++) {
		int q = 0;
		int o = 0;
		for (int b = 0; b < 2048; b++) {
			if (b < 336) {
				q = b - 0;
				decpacks[p].udp[q] = mypacks->packs[p].data[b + o];
			}
			else if (b < 432) {
				q = b - 336;
				decpacks[p].protoheader[q] = mypacks->packs[p].data[b + o];
			}
			else if (b < 440) {
				q = b - 432;
				if (byteMerger(mypacks, p, 400) == 32 && b == 432) {
					o = o - 8;
					b = b + 7;
					for (int i = 0; i < 8; i++) {
						decpacks[p].protoheaderflag[q] = 0;
					}
				}
				else {
					decpacks[p].protoheaderflag[q] = mypacks->packs[p].data[b + o];
				}
			}
			else if (b < 446) {
				q = b - 440;
				decpacks[p].tickmsg[q] = mypacks->packs[p].data[b + o];
			}
			else if (b < 494) {
				q = b - 446;
				decpacks[p].tick[q] = mypacks->packs[p].data[b + o];
			}
			else if (b < 500) {
				q = b - 494;
				decpacks[p].usrcmdmsg[q] = mypacks->packs[p].data[b + o];
			}
			else if (b < 501) {
				q = b - 500;
				decpacks[p].msgApresent = mypacks->packs[p].data[b + o];
			}
			else if (b < 556) {
				q = b - 501;
				if (decpacks[p].msgApresent == false && b == 501) {
					o = o - 55;
					b = b + 54;
					for (int i = 0; i < 55; i++) {
						decpacks[p].msgA[q] = 0;
					}
				}
				else {
					decpacks[p].msgA[q] = mypacks->packs[p].data[b + o];
				}
			}
			else if (b < 557) {
				q = b - 556;
				decpacks[p].msgBpresent = mypacks->packs[p].data[b + o];
			}
			else if (b < 612) {
				q = b - 557;
				if ((decpacks[p].msgBpresent == true) && b == 557) {
					o = o - 55;
					b = b + 54;
					for (int i = 0; i < 55; i++) {
						decpacks[p].msgB[q] = 0;
					}
				}
				else {
					decpacks[p].msgB[q] = mypacks->packs[p].data[b + o];
				}
			}
			else if (b < 630) {
				q = b - 612;
				decpacks[p].mysteryBeforeC[q] = mypacks->packs[p].data[b + o];
			}
			else if (b < 631) {
				q = b - 630;
				decpacks[p].msgDpresent = mypacks->packs[p].data[b + o];
			}
			else if (b < 719) {
				q = b - 631;
				if (decpacks[p].msgDpresent == false && b == 631) {
					o = o - 88;
					b = b + 87;
					for (int i = 0; i < 88; i++) {
						decpacks[p].msgD[q] = 0;
					}
				}
				else {
					decpacks[p].msgD[q] = mypacks->packs[p].data[b + o];
				}
			}
			else if (b < 720) {
				q = b - 719;
				decpacks[p].msgEpresent = mypacks->packs[p].data[b + o];
			}
			else if (b < 1112) {
				q = b - 720;
				if (decpacks[p].msgEpresent == false && b == 720) {
					o = o - 392;
					b = b + 391;
					for (int i = 0; i < 392; i++) {
						decpacks[p].msgE[q] = 0;
					}
				}
				else {
					decpacks[p].msgE[q] = mypacks->packs[p].data[b + o];
				}
			}
			else {
				q = b - 1112;
				decpacks[p].extra[q] = mypacks->packs[p].data[b + o];
			}
		}
	}
}

DecodedBitPacket::~DecodedBitPacket() {
	delete[] decpacks;
}

char DecodedBitPacket::byteMerger(BitImport* mypacks, int packIndex, int bitIndex) {
	//read the next 8 bits of mypacks[packIndex] starting at bitIndex and return a byte
	char ret = 0;
	for (int i = 0; i < 8; i++) {
		ret += mypacks->packs[packIndex].data[bitIndex + i] * pow(2, i);
	}
	return ret;
}
*/