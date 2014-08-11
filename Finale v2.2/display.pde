void displayStat() {
	lcd.clear();
	lcd.setCursor(0,0);
	if(curtainValue){
	   lcd.print("Curtain");
	   lcd.print(" - ");
	   lcd.print("CLOSE");
	} else {
		lcd.print("Curtain");
	    lcd.print(" - ");
	    lcd.print("OPEN");
	}
	lcd.setCursor(0,1);
	if(lightValue){
	    lcd.print("Light");
	    lcd.print(" - ");
	    lcd.print("ON");
	} else {
		lcd.print("Light");
	    lcd.print(" - ");
	    lcd.print("OFF");
	}
}
void lightDisplay(int li) {
	switch (li) {
		case 0:
			for(int i=3; i>=0; i--){
				lcd.setCursor(15,1);
				delay(1000);
				lcd.print(i);	    
			}
			displayStat();
			digitalWrite(DispPin, LOW);
			break;
		case 1:
			digitalWrite(DispPin, HIGH);
			break;
	}
}
void lightCountPrint() {
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("Counter: "); lcd.print(count);
}
