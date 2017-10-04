#include "BitImport.h"
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <bitset>
#include "Constants.h"
extern const int PACKBUF;
extern const int DATABUF;
using namespace std;

BitImport::BitImport(char* myFile) {
	string myString;
	string subBytes;
	char cBytes[16];
	ifstream infile;
	infile.open(myFile);
	int ctr = 0;
	int pkpos;
	while (!infile.eof() && ctr < PACKBUF) {
		getline(infile, myString);
		if (myString.empty()) {
			continue;
		}
		else if (myString[0] == '0') {
			pkpos = 0;
			for (int cctr = 0; cctr < 16; cctr++) {
				cBytes[cctr] = 0;
			}
			while (!myString.empty()) {
				subBytes = myString.substr(6, 47);
				subBytes.erase(remove_if(subBytes.begin(), subBytes.end(), isspace), subBytes.end());
				for (int i = 0; i < (subBytes.length() / 2); i++) {
					cBytes[i] = strtol(subBytes.substr(i * 2, 2).c_str(), NULL, 16);
				}
				for (int cctr = 0; cctr < 16; cctr++) {
					for (int i = 0; i < 8; i++) {
						packs[ctr].data[pkpos] = bitset<8>(cBytes[cctr])[i];
						pkpos++;
					}
				}
				getline(infile, myString);
			}
			ctr++;
		}
		else {
			strncpy_s(packs[ctr].info, myString.c_str(), INFOBUF);
		}
	}
	infile.close();
}

BitImport::~BitImport() {
	delete[] packs;
}