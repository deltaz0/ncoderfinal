#pragma once
#include "Constants.h"
extern const int PACKBUF;
extern const int DATABUF;

class PacketImport {
public:
	PacketImport(char* myFile);
	~PacketImport();
	static const int INFOBUF = 256;
	struct packet {
		char info[INFOBUF];
		char data[DATABUF];
	} packs[PACKBUF];
	int datalen(int packnumber);
};