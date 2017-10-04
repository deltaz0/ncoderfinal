#pragma once
#include "Constants.h"
#include "PacketImport.h"
extern const int PACKBUF;

class DecodedPacket {
public:
	DecodedPacket(char* myFile);
	~DecodedPacket();
	/*
	DATABUF from PacketImport allocates 256 chars to hold data
	this is 2048 bits
	*/
	struct decPacket {
		//336 bits for UDP header
		char udp[42];
		//96 bits of tf2 protocol header info (431)
		char protoheader[12];
		//8 bits of flag info (may be excluded) (439)
		char protoheaderflag;
		//6 bits of a net-message indicating tick (2 bit overlap) (445)
		char tickmsg;
		//48 bits of the tick message (493)
		char tick[6];
		//6 bits of the usrcmd msg (499)
		char usrcmdmsg;
		//1 bit of messageA present (500)
		char msgApresent;
		//55 bits of messageA (555)
		char msgA[7];
		//so far read in up to 556 bits
		//with DATABUF = 2048 bits, 1492 left
		char extra[187];
	} decpacks[PACKBUF];
	char byteSplitter(char inByte, int startBit, int numBits);
	char bytePuller(int bitStart, PacketImport* mypacks, int packpos, int offset);
};