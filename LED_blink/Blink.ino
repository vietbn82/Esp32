// /*
//   Blink

//   Turns an LED on for one second, then off for one second, repeatedly.

//   Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
//   it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
//   the correct LED pin independent of which board is used.
//   If you want to know what pin the on-board LED is connected to on your Arduino
//   model, check the Technical Specs of your board at:
//   https://www.arduino.cc/en/Main/Products

//   modified 8 May 2014
//   by Scott Fitzgerald
//   modified 2 Sep 2016
//   by Arturo Guadalupi
//   modified 8 Sep 2016
//   by Colby Newman

//   This example code is in the public domain.

//   http://www.arduino.cc/en/Tutorial/Blink
// */

// // the setup function runs once when you press reset or power the board
// void setup() {
//   // initialize digital pin LED_BUILTIN as an output.
//   pinMode(LED_BUILTIN, OUTPUT);
// }

// // the loop function runs over and over again forever
// void loop() {
//   // digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
//   // delay(1000);                       // wait for a second
//   // digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
//   // delay(10000);                       // wait for a second
// }
int led = 6;           // cổng digital mà LED được nối vào
int brightness = 0;    // mặc định độ sáng của đèn là
int fadeAmount = 2;    // mỗi lần thay đổi độ sáng thì thay đổi với giá trị là bao nhiêu


void setup()  {
  // ​pinMode đèn led là OUTPU
  pinMode(led, OUTPUT);
}

void loop()  {
  // ​ xuất giá trị độ sáng đèn LE
  analogWrite(led, brightness);

  // ​thay đổi giá trị là đèn LE
  brightness = brightness + fadeAmount;

   // ​Đoạn code này có nghĩa nếu độ sáng == 0 hoặc bằng == 255 thì sẽ đổi chiều của biến thay đổi độ sáng. Ví dụ, nếu đèn từ sáng yếu --> sáng mạnh thì fadeAmount dương. Còn nếu đèn sáng mạnh --> sáng yếu thì fadeAmmount lúc này sẽ có giá trị âm
  if ( ( brightness +fadeAmount) <= 0 || ( brightness +fadeAmount) >= 255 )
  {
        fadeAmount = -fadeAmount ;
        delay(100);
  }
  
  // ​đợi 30 mili giây để thấy sự thay đổi của đèn
  delay(30);
}