// do something when a tweet comes in

void newTweet(){

  tone(buzzer, 1000); // Send 1KHz sound signal...
    digitalWrite(led, 1);
    delay(50);
    digitalWrite(led, 0);
   noTone(buzzer);     // Stop sound..





// Yay pretty colours!

  colorWipe(strip.Color(155, 0, 0), 50); // Red
  colorWipe(strip.Color(0, 155, 0), 50); // Green
  colorWipe(strip.Color(0, 0, 155), 50); // Blue
  colorWipe(strip.Color(0, 0, 0, 155), 50); // White

strip.show();





  // and resets the go variable to 0
  // Keep this line!
  Bridge.put("go", String(0));
}






void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
