#include "ansi.h"

void clearScreen(){
	printf("%c[2J", ESC);
}

void clearLine(){
	printf("%c[K", ESC);
}

void setCursor(int x, int y){
	printf("%c[%d;%dH", ESC,y,x);
}

void underline(char on){
	if (on == '1')
		printf("%c[4m",ESC);
	else if(on == '0')
		printf("%c[24m",ESC);
}

void blink(char on){
	if(on == '1')
		printf("%c[5m",ESC);
	else if(on == '0')
		printf("%c[25m",ESC);
}

void reverseBackground(){
	printf("%c[7m",ESC);
}

void window(int x1, int y1, int x2, int y2, char str[], int size, char style){
	int n = (x2-x1) - size - 3; // lenght of white spaces after window title string
	int i;
	setCursor(x1,y1);
	if(style == 'a'){
		printf("%c",218);
		printf("%c",180);
		setColor(37,40);
		printf(" %s",str);
		for(i=0; i<n; i++){
			printf(" ");
		}
		setColor(30,47);
		underline('0');
		printf("%c",195);
		printf("%c",191);
		for(i=1; i<(y2-y1)-1; i++) {
			setCursor(x1, y1+i);
 		    printf("%c", 179);
			setCursor(x2, y1+i);
			printf("%c", 179);
		}
		setCursor(x1, y2);
		printf("%c", 192);
		for (i=1; i<(x2-x1); i++){
			printf("%c", 196);
		}
		printf("%c", 217);
	 }
}

void printEscapeChar(char a){
	printf("%c[%c", ESC,a);
}

void setColor(short fg, short bg){
	printf("%c[%u;%um", ESC,fg,bg);
}
