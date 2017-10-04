#pragma once
#include "Constants.h"
#include "BitImport.h"
extern const int PACKBUF;

class DecodedBitPacket {
public:
	DecodedBitPacket(char* myFile);
	~DecodedBitPacket();
	/*
	DATABUF from PacketImport allocates 256 chars to hold data
	this is 2048 bits
	*/
	struct decPacket {
		//336 bits for UDP header
		bool udp[336] = { 0 };
		//96 bits of tf2 protocol header info (431)
		bool protoheader[96] = { 0 };
		//8 bits of flag info (may be excluded) (439)
		bool protoheaderflag[8] = { 0 };
		//6 bits of a net-message indicating tick (2 bit overlap) (445)
		bool tickmsg[6] = { 0 };
		//48 bits of the tick message (493)
		bool tick[48] = { 0 };
		//6 bits of the usrcmd msg (499)
		bool usrcmdmsg[6] = { 0 };
		//1 bit of messageA present (500)
		bool msgApresent = false;
		//55 bits of messageA (555)
		bool msgA[55] = { 0 };
		//1 bit of messageB present (556)
		bool msgBpresent = false;
		//55 bits of messageB (611)
		bool msgB[55] = { 0 };
		//1 bit of msgCpresent
		bool msgCpresent = false;
		//18 bits of mystery bits before C (629)
		bool msgC[17] = { 0 };
		//1 bit of messageC present (630)
		bool msgDpresent = false;
		//88 bits of messageB (718)
		bool msgD[15] = { 0 };
		//1 bit of messageC present (719)
		bool msgEpresent = false;
		//372 bits of messageB (1111)
		bool msgE[6] = { 0 };
		bool msgFpresent = false;
		//372 bits of messageB (1111)
		bool msgF[448] = { 0 };
		bool msgGpresent = false;
		//372 bits of messageB (1111)
		bool msgG[57] = { 0 };
		bool msgHpresent = false;
		//372 bits of messageB (1111)
		bool msgH[55] = { 0 };
		bool msgIpresent = false;
		//372 bits of messageB (1111)
		bool msgI[410] = { 0 };
		bool msgJpresent = false;
		//372 bits of messageB (1111)
		bool msgJ[31] = { 0 };
		bool msgKpresent = false;
		//372 bits of messageB (1111)
		bool msgK[1] = { 0 };
		bool msgLpresent = false;
		//372 bits of messageB (1111)
		bool msgL[2] = { 0 };
		bool msgMpresent = false;
		//372 bits of messageB (1111)
		bool msgM[13] = { 0 };
		//msg
		bool msgNpresent = false;
		bool msgN[33] = { 0 };
		//msg
		bool msgOpresent = false;
		bool msgO[10] = { 0 };
		//msg
		bool msgPpresent = false;
		bool msgP[72] = { 0 };
		//msg
		bool msgQpresent = false;
		bool msgQ[64] = { 0 };
		bool msgRpresent = false;
		bool msgR[45] = { 0 };
		bool msgSpresent = false;
		bool msgS[13] = { 0 };
		bool msgTpresent = false;
		bool msgT[13] = { 0 };
		bool msgUpresent = false;
		bool msgU[13] = { 0 };
		/*
		bool msgPpresent = false;
		bool msgP[29] = { 0 };
		//msg
		bool msgQpresent = false;
		bool msgQ[14] = { 0 };
		//extra
		*/
		bool extra[3072] = { 0 };
	} decpacks[PACKBUF];
	int enableA = 1;
	int enableB = 1; //reversed
	int enableC = 0;
	int enableD = 1;
	int enableE = 0;
	int enableF = 1;
	int enableG = 1;
	int enableH = 1;
	int enableI = 1;
	int enableJ = 1;
	int enableK = 1;
	int enableL = 1; //reversed
	int enableM = 0;
	int enableN = 1; //reversed
	int enableO = 1;
	int enableP = 1; //reversed
	int enableQ = 1;
	int enableR = 0;
	int enableS = 1;
	int enableT = 1;
	int enableU = 1;
	char DecodedBitPacket::byteMerger(BitImport* mypacks, int packIndex, int bitIndex);
};