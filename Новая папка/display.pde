/*#define lenght 16.0

double percent=100.0;
unsigned char b;
unsigned int peace;

// custom charaters

*/



/*void ap()
{

lcd.setCursor(0, 0);

//ADC conversion

int value = i;

percent = value/1024.0*100.0;

lcd.print(value);

lcd.print(" - ");

lcd.print(percent);
lcd.print(" % ");

lcd.setCursor(0,1);

double a=lenght/100*percent;

// drawing black rectangles on LCD

if (a>=1) {

for (int i=1;i<a;i++) {

lcd.write(4);

b=i;
}

a=a-b;

}

peace=a*5;

// drawing charater's colums

switch (peace) {

case 0:

break;

case 1:
lcd.write(0);

break;

case 2:
lcd.write(1);
break;

case 3:
lcd.write(2);
break;

case 4:
lcd.write(3);
break;

}

//clearing line
for (int i =0;i<(lenght-b);i++) {

lcd.print(" ");
}

;
}*/

void loading() {
	for(int i=0; i=15; i++){
	    lcd.setCursor(i,1);
	    for(int j=0; j<4; j++){
	        lcd.write(j);
	        delay(100);
	    }
	}
}

void NP() {
	lcd.setCursor(0,1);
	lcd.print("123");
}

