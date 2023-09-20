#define button1 11 // this button use for only buzzer1 mode
#define button2 5 // this button use for buzzer1 & buzzer2 mode

#define buzzer1 12 // this pin use for buzzer1
#define buzzer2  6 // this pin use for buzzer2

#define echopin 3 // echo pin
#define trigpin 2 // Trigger pin

int alarm1=1, alarm2=1; 
int cm; // Duration used to calculate distance


void setup(){ // put your setup code here, to run once 
Serial.begin(9600);// initialize serial communication at 9600 bits per second:

pinMode(button1, INPUT_PULLUP);
pinMode(button2, INPUT_PULLUP);

pinMode(buzzer1, OUTPUT); //declare buzzer1 as output
pinMode(buzzer2, OUTPUT); //declare buzzer2 as output

pinMode(trigpin, OUTPUT); // declare ultrasonic sensor Echo pin as input
pinMode(echopin, INPUT);  // declare ultrasonic sensor Trigger pin as Output 

delay(100);
}
 
void loop(){  

if(digitalRead(button1)==0) alarm1=1, alarm2=0; //only buzzer1 mode
if(digitalRead(button2)==0) alarm1=1, alarm2=1; //buzzer1 & buzzer2 mode

digitalWrite(trigpin, LOW);
delayMicroseconds(2);
digitalWrite(trigpin, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin, LOW);


// Measure the response from the HC-SR04 Echo Pin
long ultra_time = pulseIn (echopin, HIGH);
  // Determine distance from duration
  // Use 343 metres per second as speed of sound
cm =  (ultra_time/ 2)*0.0343; ; 

Serial.print("cm:");Serial.println(cm);

if(cm>=30 && cm<=100){
int d = map(cm, 30, 100, 30, 1000); 
if(alarm1==1)digitalWrite(buzzer1, HIGH);   // Turn on Buzzer1 
if(alarm2==1)digitalWrite(buzzer2, HIGH); // Turn on Buzzer2
delay(100);  
digitalWrite(buzzer1, LOW); // Turn off Buzzer1 
digitalWrite(buzzer2, LOW);  // Turn off Buzzer2 
delay(d);    
}
if(cm<30){
if(alarm1==1)digitalWrite(buzzer1, HIGH);   // Turn on Buzzer 
if(alarm2==1)digitalWrite(buzzer2, HIGH); // Turn on Vibrator 
}



if(cm>170){
digitalWrite(buzzer1, LOW); // Turn off Buzzer 1
digitalWrite(buzzer2, LOW);  // Turn off buzzer2 
}

delay(10); 
}
