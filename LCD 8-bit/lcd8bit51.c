#include "lcd8bit51.h"

void lcdDelay(int x){
	int i,j;
	for(i = 0; i < 120; i++){
		for(j = 0; j < x; j++){
		}
	}
}

void lcdInit(){
	int i;
	for(i = 0; i < 3; i++){
		lcdCommand(0x30);
		lcdDelay(100);
	}
	lcdCommand(0x38);
	lcdDispClear();
	lcdCommand(0x0E);
	lcdCommand(0x06);
}

void lcdData(char x){
	DB0 = x & 1;
	DB1 = x & 2;
	DB2 = x & 4;
	DB3 = x & 8;
	DB4 = x & 16;
	DB5 = x & 32;
	DB6 = x & 64;
	DB7 = x & 128;
}

void lcdCommand(char x){
	RS = 0;
	RW = 0;
	lcdData(x);
	E = 1;
	lcdDelay(10);
	E = 0;
	lcdDelay(10);
}

void lcdString(char x){
	int i;
	RS = 1;
	RW = 0;
	for(i = 0; i < sizeof(x); i++){
		lcdData(x);
		E = 1;
		lcdDelay(10);
		E = 0;
		lcdDelay(10);
	}
}

void lcdDispClear(){
	lcdCommand(0x01);
}

void lcdCursorLeft(int x){
	int i;
	for(i = 0; i < x; i++){
		lcdCommand(0x10);
	}
}

void lcdCursorRight(int x){
	int i;
	for(i = 0; i < x; i++){
		lcdCommand(0x14);
	}
}

void lcdDispLeft(int x){
	int i;
	for(i = 0; i < x; i++){
		lcdCommand(0x18);
	}
}

void lcdDispRight(int x){
	int i;
	for(i = 0; i < x; i++){
		lcdCommand(0x1C);
	}
}

void lcdCursorPos(unsigned char row, unsigned char col){
	if(row < 2){
		char pos = 0x80;
		pos += (row*0x40) + col;
		lcdCommand(pos);
	}
}

void lcdCursorReset(){
	lcdCommand(0x02);
}

void lcdCursorOff(){
	lcdCommand(0x0C);
}

void lcdDispOff(){
	lcdCommand(0x08);
}

void lcdCursorOn(){
	lcdCommand(0x0E);
}

void lcdCursorBlink(){
	lcdCommand(0x0F);
}

void lcdDispOn(){
	lcdCommand(0x0E);
}

char lcdBusy(){
	RS = 0;
	RW = 1;
	if(DB7){
		return 1;
	}
	else{
		return 0;
	}
}

void lcdCreateChar(char mem, char row, unsigned char x){
	char pos;
	if(mem < 8){
		pos = 0x40 + (mem * 8)
		lcdCommand(pos + row);
		lcdData(char);
	}
}

void lcdCustomChar(char mem){
	lcdString(0x00 + mem);
}
