#pragma once
#include "Constants.h"
extern const int PACKBUF;
extern const int DATABUF;

class BitImport {
public:
	BitImport(char* myFile);
	~BitImport();
	static const int INFOBUF = 256;
	struct packet {
		char info[INFOBUF];
		bool data[DATABUF*8];
	} packs[PACKBUF];
};