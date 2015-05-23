#ifndef LCD_8BIT_51_H_
#define LCD_8BIT_51_H_

extern bit RS; //Register Select
extern bit RW; //Read/Write
extern bit E; //Enable

//Data bit 0-7
extern bit DB0;
extern bit DB1;
extern bit DB2;
extern bit DB3;
extern bit DB4;
extern bit DB5;
extern bit DB6;
extern bit DB7;

void lcdInit();

void lcdData(char x);

void lcdCommand(char x);
void lcdString(char x);

void lcdDispClear();

void lcdCursorReset();
void lcdCursorPos(unsigned char row, unsigned char col);

void lcdCursorLeft(int x);
void lcdCursorRight(int x);
void lcdCursorOff();
void lcdCursorOn();
void lcdCursorBlink();

void lcdDispLeft(int x);
void lcdDispRight(int x);
void lcdDispOff();
void lcdDispOn(); //same as lcdCursorOn

void lcdDelay(int x);

char lcdBusy();

#endif // LCD_8BIT_51_H_