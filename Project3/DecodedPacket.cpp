#include "DecodedPacket.h"
#include <bitset>
#include "PacketImport.h"
#include "Constants.h"
extern const int PACKBUF;
extern const int DATABUF;
using namespace std;

DecodedPacket::DecodedPacket(char* myFile) {
	PacketImport* mypacks = new PacketImport(myFile);
	//i is which packet
	//j is which byte
	//k is which bit in current byte
	//p is which bit overall
	//q is j minus the current byte offset
	//r is the current bit offset
	//o is bit offset due to missing information
	int q = 0;
	int r = 0;
	int o = 0;
	int cbuf[8];
	for (int i = 0; i < PACKBUF; i++) {
		q,r,o = 0;
		for (int j = 0; j < 256; j++) {
			for (int k = 0; k < 8; k++) {
				int p = j * 8 + k;
				if (i > 0 && p > 555) {
					int t = 1;
				}
				if (p < 336) {
					q = j - 0; r = 0;
					if (k == 0) {
						decpacks[i].udp[q] = mypacks->packs[i].data[j+o];
					}
				}
				else if (p < 432) {
					q = j - 42; r = 0;
					if (k == 0) {
						decpacks[i].protoheader[q] = mypacks->packs[i].data[j+o];
					}
				}
				else if (p < 440) {
					q = j - 54; r = 0;
					if (k == 0) {
						if ((int)mypacks->packs[i].data[50] == 32) {
							o = o - 8;
							decpacks[i].protoheaderflag = 0;
						}
						else {
							decpacks[i].protoheaderflag = mypacks->packs[i].data[j + o/8];
						}
					}
				}
				else if (p < 446) {
					q = j - 55; r = 0;
					if (k == 0) {
						decpacks[i].tickmsg = byteSplitter(mypacks->packs[i].data[j + o/8], 0, 6);
					}
				}
				else if (p < 494) {
					q = j - 55; r = 6;
					if (k - r == 0) {
						decpacks[i].tick[q] = bytePuller(p, mypacks, i, o);
					}
				}
				else if (p < 500) {
					q = j - 61; r = 6;
					if (k - r == 0) {
						decpacks[i].usrcmdmsg = byteSplitter(bytePuller(p, mypacks, i, o), 0, 6);
					}
				}
				else if (p < 501) {
					q = j - 62; r = 4;
					if (k - r == 0) {
						decpacks[i].msgApresent = byteSplitter(bytePuller(p, mypacks, i, o), 0, 1);
					}
				}
				else if (p < 556) {
					q = j - 62; r = 5;
					if (decpacks[i].msgApresent != 1) {
						if (q == 0 && k - r == 0) {
							o = o - 55;
						}
						if (k - r == 0) {
							decpacks[i].msgA[q] = 0;
						}
					}
					else if (k - r == 0) {
						if (q != 6) {
							decpacks[i].msgA[q] = bytePuller(p, mypacks, i, o);
						}
						else if (q == 6) {
							decpacks[i].msgA[q] = byteSplitter(bytePuller(p, mypacks, i, o), 0, 7);
						}
					}
				}
				else {
					q = j - 69; r = 4;
					if (k - r == 0) {
						decpacks[i].extra[q] = bytePuller(p, mypacks, i, o);
					}
				}
			}
		}
	}
}

DecodedPacket::~DecodedPacket() {
	delete[] decpacks;
}

char DecodedPacket::byteSplitter(char inByte, int startBit, int numBits) {
	char x = 0;
	for (int i = startBit; i < startBit + numBits; i++) {
		x += bitset<8>(inByte)[i] ^ (2 * (i - startBit));
	}
	return x;
}

char DecodedPacket::bytePuller(int bitStart, PacketImport* mypacks, int packpos, int offset) {
	char x = 0;
	int j = bitStart / 8;
	int o = bitStart % 8;
	if (j + ((-offset)/8) > DATABUF - 3) {
		x = 0;
	}
	else {
		for (int i = 0; i < 8; i++) {
			x += bitset<8>(mypacks->packs[packpos].data[(((j * 8) + ((i + o) % 8)) / 8) + (-offset) / 8])[(i + o + ((-offset) % 8)) % 8] ^ (2 * i);
		}
	}
	return x;
}