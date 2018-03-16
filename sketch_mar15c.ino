
int buzzerPin = 4; // the alarm buzzer pin

int x = 0; // variable used for counting
void setup() {

Serial.begin(9600);
pinMode(11,OUTPUT);

pinMode(12,INPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);

pinMode(buzzerPin, OUTPUT);


//pinMode activates the pin so the arduino can use it


}

void soundAlarm(int cnt) { 
for (x=0 ; x<cnt; x++) { //This controls the number of times it sounds

tone(buzzerPin, 1000, 1000); // High tone (arduino pin, the tone, how long)

delay(1000); // delay for 1 second

tone(buzzerPin, 800, 1000); // Low tone (arduino pin, the tone, how long)

delay(1000); //delay for 1 second


}
}

void loop() { // This is the main program loop
  long duration, inches;

digitalWrite(11,LOW);

//digitalWrite gives the arduino a command. LOW means off, and HIGH means on

delayMicroseconds(2);

//delay makes the arduino wait before doing the next command

digitalWrite(11,HIGH);

delayMicroseconds(5);

digitalWrite(11,LOW);

duration = pulseIn(12,HIGH);

//this part is telling pin 11 to read the sensor

inches = duration / 74/ 2;

Serial.println(inches);

delay(10);

if(inches < 5){

digitalWrite(7,LOW);
digitalWrite(8,HIGH);

}

if(inches > 5){

digitalWrite(7,HIGH);
digitalWrite(8,LOW);


//soundAlarm(3); // Sound alarm (n) times






}}
