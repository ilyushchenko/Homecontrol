/*------------------------------------ Воключение или выключение света ------------------------------*/
void ligth() {
  if (lightValue)
  {
    digitalWrite(relay1, HIGH);
  } else {
    digitalWrite(relay1, LOW);
  }
  displayStat();
  lightDisplay(0);
}