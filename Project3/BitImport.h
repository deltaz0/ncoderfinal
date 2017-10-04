#pragma once
#include "Constants.h"
extern const int PACKBUF;
extern const int DATABUF;

class BitImport {
public:
	BitImport(char* myFile);
	~BitImport();
	static const int INFOBUF = 512;
	struct packet {
		char info[INFOBUF];
		bool data[8092];
	} packs[PACKBUF];
};