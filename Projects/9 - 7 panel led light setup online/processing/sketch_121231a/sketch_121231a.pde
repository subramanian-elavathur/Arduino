 import processing.serial.*;
 Serial port;
 
 void setup()  {
 
   /* This part must be altered to fit your local settings. The number in brackets after "Serial.list()" is where you declare what COM port your Arduino is connected to.
      If you get error messages, try a different number starting from 0 (e.g. 0, 1, 2, 3...) . */
    port = new Serial(this, Serial.list()[0], 9600);  // Open the port that the Arduino board is connected to, at 9600 baud
 
}
 void draw() {
 
  String onoroff[] = loadStrings("http://arduino.mitfiles.COM/ledstat.txt"); // Insert the location of your .txt file
  print(onoroff[0]);  // Prints whatever is in the file ("1" or "0")
 
  if (onoroff[0].equals("1") == true) {
    println(" - TELLING ARDUINO TO TURN LED ON");
    port.write('H'); // Send "H" over serial to set LED to HIGH
 
  } else {
 
    println(" - TELLING ARDUINO TO TURN LED OFF");
    port.write('L');  // Send "L" over serial to set LED to LOW
 }
 
  delay(500); // Set your desired interval here, in milliseconds
 }
