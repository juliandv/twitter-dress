// do something when a tweet comes in

void newTweet(){

  tone(buzzer, 1000); // Send 1KHz sound signal...
    digitalWrite(led, 1);
    delay(50);
    digitalWrite(led, 0);
   noTone(buzzer);     // Stop sound..


  // and resets the go variable to 0
  // Keep this line!
  Bridge.put("go", String(0));
}
