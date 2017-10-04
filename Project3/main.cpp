#pragma once
#include <iostream>
#include <bitset>
#include "DecodedBitPacket.h"
#include "DecodedNewPacket.h"
#include "Constants.h"
extern const int PACKBUF;
using namespace std;

int ival(bool bitval) {
	if (bitval == true)	return 255;
	else return 50;
}

int main(int argc, const char* argv[]) {
	char* filei = "nr40xx.txt";
	char* fileo = "nr40xxNew.bmp";
	DecodedBitPacket* mydecpacks = new DecodedBitPacket(filei);
	DecodedNewPacket* mydecnew = new DecodedNewPacket(filei);
	const int w = PACKBUF;
	const int h = 8092;
	int(*red)[h] = new int[w][h];
	int(*green)[h] = new int[w][h];
	int(*blue)[h] = new int[w][h];
	int x; int y; int r; int g; int b;
	FILE *f;
	errno_t ferr;
	unsigned char *img = NULL;
	int filesize = 54 + 3 * w*h;  //w is your image width, h is image height, both int
	if (img)
		free(img);
	img = (unsigned char *)malloc(3 * w*h);
	memset(img, 0, sizeof(img));
	int rval = 0, gval = 0, bval = 0, q = 0;

	/*
	int s1 = sizeof(mydecpacks->decpacks[0].udp);
	int s2 = sizeof(mydecpacks->decpacks[0].protoheader) + s1;
	int s3 = sizeof(mydecpacks->decpacks[0].protoheaderflag) + s2;
	int s4 = sizeof(mydecpacks->decpacks[0].tickmsg) + s3;
	int s5 = sizeof(mydecpacks->decpacks[0].tick) + s4;
	int s6 = sizeof(mydecpacks->decpacks[0].usrcmdmsg) + s5;
	int s7 = sizeof(mydecpacks->decpacks[0].msgApresent) + s6;
	int s8 = sizeof(mydecpacks->decpacks[0].msgA) + s7;
	int s9 = sizeof(mydecpacks->decpacks[0].msgBpresent) + s8;
	int s10 = sizeof(mydecpacks->decpacks[0].msgB) + s9;
	int s11 = sizeof(mydecpacks->decpacks[0].msgCpresent) + s10;
	int s12 = sizeof(mydecpacks->decpacks[0].msgC) + s11;
	int s13 = sizeof(mydecpacks->decpacks[0].msgDpresent) + s12;
	int s14 = sizeof(mydecpacks->decpacks[0].msgD) + s13;
	int s15 = sizeof(mydecpacks->decpacks[0].msgEpresent) + s14;
	int s16 = sizeof(mydecpacks->decpacks[0].msgE) + s15;
	int s17 = sizeof(mydecpacks->decpacks[0].msgFpresent) + s16;
	int s18 = sizeof(mydecpacks->decpacks[0].msgF) + s17;
	int s19 = sizeof(mydecpacks->decpacks[0].msgGpresent) + s18;
	int s20 = sizeof(mydecpacks->decpacks[0].msgG) + s19;
	int s21 = sizeof(mydecpacks->decpacks[0].msgHpresent) + s20;
	int s22 = sizeof(mydecpacks->decpacks[0].msgH) + s21;
	int s23 = sizeof(mydecpacks->decpacks[0].msgIpresent) + s22;
	int s24 = sizeof(mydecpacks->decpacks[0].msgI) + s23;
	int s25 = sizeof(mydecpacks->decpacks[0].msgJpresent) + s24;
	int s26 = sizeof(mydecpacks->decpacks[0].msgJ) + s25;
	int s27 = sizeof(mydecpacks->decpacks[0].msgKpresent) + s26;
	int s28 = sizeof(mydecpacks->decpacks[0].msgK) + s27;
	int s29 = sizeof(mydecpacks->decpacks[0].msgLpresent) + s28;
	int s30 = sizeof(mydecpacks->decpacks[0].msgL) + s29;
	int s31 = sizeof(mydecpacks->decpacks[0].msgMpresent) + s30;
	int s32 = sizeof(mydecpacks->decpacks[0].msgM) + s31;
	int s33 = sizeof(mydecpacks->decpacks[0].msgNpresent) + s32;
	int s34 = sizeof(mydecpacks->decpacks[0].msgN) + s33;
	int s35 = sizeof(mydecpacks->decpacks[0].msgOpresent) + s34;
	int s36 = sizeof(mydecpacks->decpacks[0].msgO) + s35;
	int s37 = sizeof(mydecpacks->decpacks[0].msgPpresent) + s36;
	int s38 = sizeof(mydecpacks->decpacks[0].msgP) + s37;
	int s39 = sizeof(mydecpacks->decpacks[0].msgQpresent) + s38;
	int s40 = sizeof(mydecpacks->decpacks[0].msgQ) + s39;
	int s41 = sizeof(mydecpacks->decpacks[0].msgRpresent) + s40;
	int s42 = sizeof(mydecpacks->decpacks[0].msgR) + s41;
	int s43 = sizeof(mydecpacks->decpacks[0].msgSpresent) + s42;
	int s44 = sizeof(mydecpacks->decpacks[0].msgS) + s43;
	int s45 = sizeof(mydecpacks->decpacks[0].msgTpresent) + s44;
	int s46 = sizeof(mydecpacks->decpacks[0].msgT) + s45;
	int s47 = sizeof(mydecpacks->decpacks[0].msgUpresent) + s46;
	int s48 = sizeof(mydecpacks->decpacks[0].msgU) + s47;

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			rval = 0; gval = 0;	bval = 0; q = 0;
			if (j < s1) {
				q = j - 0;
				rval = ival(mydecpacks->decpacks[i].udp[q]);
			}
			else if (j < s2) {
				q = j - s1;
				gval = ival(mydecpacks->decpacks[i].protoheader[q]);
			}
			else if (j < s3) {
				q = j - s2;
				bval = ival(mydecpacks->decpacks[i].protoheaderflag[q]);
			}
			else if (j < s4) {
				q = j - s3;
				rval = ival(mydecpacks->decpacks[i].tickmsg[q]);
			}
			else if (j < s5) {
				q = j - s4;
				gval = ival(mydecpacks->decpacks[i].tick[q]);
			}
			else if (j < s6 ) {
				q = j - s5;
				bval = ival(mydecpacks->decpacks[i].usrcmdmsg[q]);
			}
			else if (j < s7) {
				q = j - s6;
				rval = ival(mydecpacks->decpacks[i].msgApresent);
			}
			else if (j < s8) {
				q = j - s7;
				gval = ival(mydecpacks->decpacks[i].msgA[q]);
			}
			else if (j < s9) {
				q = j - s8;
				bval = ival(mydecpacks->decpacks[i].msgBpresent);
			}
			else if (j < s10) {
				q = j - s9;
				rval = ival(mydecpacks->decpacks[i].msgB[q]);
			}
			else if (j < s11) {
				q = j - s10;
				gval = ival(mydecpacks->decpacks[i].msgCpresent);
			}
			else if (j < s12) {
				q = j - s11;
				bval = ival(mydecpacks->decpacks[i].msgC[q]);
			}
			else if (j < s13) {
				q = j - s12;
				rval = ival(mydecpacks->decpacks[i].msgDpresent);
			}
			else if (j < s14) {
				q = j - s13;
				gval = ival(mydecpacks->decpacks[i].msgD[q]);
			}
			else if (j < s15) {
				q = j - s14;
				bval = ival(mydecpacks->decpacks[i].msgEpresent);
			}
			else if (j < s16) {
				q = j - s15;
				rval = ival(mydecpacks->decpacks[i].msgE[q]);
			}
			else if (j < s17) {
				q = j - s16;
				gval = ival(mydecpacks->decpacks[i].msgFpresent);
			}
			else if (j < s18) {
				q = j - s17;
				bval = ival(mydecpacks->decpacks[i].msgF[q]);
			}
			else if (j < s19) {
				q = j - s18;
				rval = ival(mydecpacks->decpacks[i].msgGpresent);
			}
			else if (j < s20) {
				q = j - s19;
				gval = ival(mydecpacks->decpacks[i].msgG[q]);
			}
			else if (j < s21) {
				q = j - s20;
				bval = ival(mydecpacks->decpacks[i].msgHpresent);
			}
			else if (j < s22) {
				q = j - s21;
				rval = ival(mydecpacks->decpacks[i].msgH[q]);
			}
			else if (j < s23) {
				q = j - s22;
				gval = ival(mydecpacks->decpacks[i].msgIpresent);
			}
			else if (j < s24) {
				q = j - s23;
				bval = ival(mydecpacks->decpacks[i].msgI[q]);
			}
			else if (j < s25) {
				q = j - s24;
				rval = ival(mydecpacks->decpacks[i].msgJpresent);
			}
			else if (j < s26) {
				q = j - s25;
				gval = ival(mydecpacks->decpacks[i].msgJ[q]);
			}
			else if (j < s27) {
				q = j - s26;
				bval = ival(mydecpacks->decpacks[i].msgKpresent);
			}
			else if (j < s28) {
				q = j - s27;
				rval = ival(mydecpacks->decpacks[i].msgK[q]);
			}
			else if (j < s29) {
				q = j - s28;
				gval = ival(mydecpacks->decpacks[i].msgLpresent);
			}
			else if (j < s30) {
				q = j - s29;
				bval = ival(mydecpacks->decpacks[i].msgL[q]);
			}
			else if (j < s31) {
				q = j - s30;
				rval = ival(mydecpacks->decpacks[i].msgMpresent);
			}
			else if (j < s32) {
				q = j - s31;
				gval = ival(mydecpacks->decpacks[i].msgM[q]);
			}
			else if (j < s33) {
				q = j - s32;
				bval = ival(mydecpacks->decpacks[i].msgNpresent);
			}
			else if (j < s34) {
				q = j - s33;
				rval = ival(mydecpacks->decpacks[i].msgN[q]);
			}
			else if (j < s35) {
				q = j - s34;
				gval = ival(mydecpacks->decpacks[i].msgOpresent);
			}
			else if (j < s36) {
				q = j - s35;
				bval = ival(mydecpacks->decpacks[i].msgO[q]);
			}
			else if (j < s37) {
				q = j - s36;
				rval = ival(mydecpacks->decpacks[i].msgPpresent);
			}
			else if (j < s38) {
				q = j - s37;
				gval = ival(mydecpacks->decpacks[i].msgP[q]);
			}
			else if (j < s39) {
				q = j - s38;
				bval = ival(mydecpacks->decpacks[i].msgQpresent);
			}
			else if (j < s40) {
				q = j - s39;
				rval = ival(mydecpacks->decpacks[i].msgQ[q]);
			}
			else if (j < s41) {
				q = j - s40;
				gval = ival(mydecpacks->decpacks[i].msgRpresent);
			}
			else if (j < s42) {
				q = j - s41;
				bval = ival(mydecpacks->decpacks[i].msgR[q]);
			}
			else if (j < s43) {
				q = j - s42;
				rval = ival(mydecpacks->decpacks[i].msgSpresent);
			}
			else if (j < s44) {
				q = j - s43;
				gval = ival(mydecpacks->decpacks[i].msgS[q]);
			}
			else if (j < s45) {
				q = j - s44;
				bval = ival(mydecpacks->decpacks[i].msgTpresent);
			}
			else if (j < s46) {
				q = j - s45;
				rval = ival(mydecpacks->decpacks[i].msgT[q]);
			}
			else if (j < s47) {
				q = j - s46;
				gval = ival(mydecpacks->decpacks[i].msgUpresent);
			}
			else if (j < s48) {
				q = j - s47;
				bval = ival(mydecpacks->decpacks[i].msgU[q]);
			}
			else {
				q = j - s48;
				rval = ival(mydecpacks->decpacks[i].extra[q]);
			}
			red[i][j] = rval + gval/2 + bval /2;
			green[i][j] = gval + rval/2 + bval/2;
			blue[i][j] = bval + rval/2 + gval/2;
			x = i; y = (h - 1) - j;
			r = red[i][j];
			g = green[i][j];
			b = blue[i][j];
			if (r > 255) r = 255;
			if (g > 255) g = 255;
			if (b > 255) b = 255;
			img[(x + y*w) * 3 + 2] = (unsigned char)(r);
			img[(x + y*w) * 3 + 1] = (unsigned char)(g);
			img[(x + y*w) * 3 + 0] = (unsigned char)(b);
		}
	}
	*/

	for (int i = 0; i < w; i++) {
		int j = 0;
		for (int msgNum = 0; msgNum < mydecnew->msgList.size(); msgNum++) {
			for (int k = 0; k < mydecnew->msgList[msgNum].length; k++) {
				rval = 0, gval = 0, bval = 0;
				if (msgNum % 3 == 0) {
					rval = ival(mydecnew->decpacks[i][j]);
				}
				else if (msgNum % 3 == 1) {
					gval = ival(mydecnew->decpacks[i][j]);
				}
				else {
					bval = ival(mydecnew->decpacks[i][j]);
				}
				if (mydecnew->msgList[msgNum].type == 2) {
					rval = gval = bval = ival(mydecnew->decpacks[i][j]);
				}
				red[i][j] = rval + gval / 2 + bval / 2;
				green[i][j] = gval + rval / 2 + bval / 2;
				blue[i][j] = bval + rval / 2 + gval / 2;
				x = i; y = (h - 1) - j;
				r = red[i][j];
				g = green[i][j];
				b = blue[i][j];
				if (r > 255) r = 255;
				if (g > 255) g = 255;
				if (b > 255) b = 255;
				img[(x + y*w) * 3 + 2] = (unsigned char)(r);
				img[(x + y*w) * 3 + 1] = (unsigned char)(g);
				img[(x + y*w) * 3 + 0] = (unsigned char)(b);
				j++;
			}	
		}
		while (j < h) {
			rval = ival(mydecnew->decpacks[i][j]);
			gval = ival(mydecnew->decpacks[i][j]);
			bval = ival(mydecnew->decpacks[i][j]);
			red[i][j] = rval + gval / 2 + bval / 2;
			green[i][j] = gval + rval / 2 + bval / 2;
			blue[i][j] = bval + rval / 2 + gval / 2;
			x = i; y = (h - 1) - j;
			r = red[i][j];
			g = green[i][j];
			b = blue[i][j];
			if (r > 255) r = 255;
			if (g > 255) g = 255;
			if (b > 255) b = 255;
			img[(x + y*w) * 3 + 2] = (unsigned char)(r);
			img[(x + y*w) * 3 + 1] = (unsigned char)(g);
			img[(x + y*w) * 3 + 0] = (unsigned char)(b);
			j++;
		}
	}
	
	unsigned char bmpfileheader[14] = { 'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0 };
	unsigned char bmpinfoheader[40] = { 40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0 };
	unsigned char bmppad[3] = { 0,0,0 };

	bmpfileheader[2] = (unsigned char)(filesize);
	bmpfileheader[3] = (unsigned char)(filesize >> 8);
	bmpfileheader[4] = (unsigned char)(filesize >> 16);
	bmpfileheader[5] = (unsigned char)(filesize >> 24);

	bmpinfoheader[4] = (unsigned char)(w);
	bmpinfoheader[5] = (unsigned char)(w >> 8);
	bmpinfoheader[6] = (unsigned char)(w >> 16);
	bmpinfoheader[7] = (unsigned char)(w >> 24);
	bmpinfoheader[8] = (unsigned char)(h);
	bmpinfoheader[9] = (unsigned char)(h >> 8);
	bmpinfoheader[10] = (unsigned char)(h >> 16);
	bmpinfoheader[11] = (unsigned char)(h >> 24);

	ferr = fopen_s(&f, fileo, "wb");
	fwrite(bmpfileheader, 1, 14, f);
	fwrite(bmpinfoheader, 1, 40, f);
	for (int i = 0; i<h; i++) {
		fwrite(img + (w*(h - i - 1) * 3), 3, w, f);
		fwrite(bmppad, 1, (4 - (w * 3) % 4) % 4, f);
	}
	fclose(f);
	
	delete[] red;
	delete[] green;
	delete[] blue;
	//system("Pause");
	return 0;
}