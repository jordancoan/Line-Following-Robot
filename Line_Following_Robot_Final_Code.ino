//sensor

int leftSensor = 1;

int midSensor = 2;

int rightSensor = 3;

 

int LEDPin = 2;

 

int leftReading;

int rightReading;

int midReading;

//int initialReading;

int blackThreshold;

 

//Motors

int STBY = 8; //standby

//Motor A

int PWMA = 3; //Speed control

int AIN1 = 6; //Direction

int AIN2 = 5; //Direction

//Motor B

int PWMB = 10; //Speed control

int BIN1 = 11; //Direction

int BIN2 = 12; //Direction

 

void setup() {

 

 //motor setup

 pinMode(STBY, OUTPUT);

 

 pinMode(PWMA, OUTPUT);

 pinMode(AIN1, OUTPUT);

 pinMode(AIN2, OUTPUT);

 

 pinMode(PWMB, OUTPUT);

 pinMode(BIN1, OUTPUT);

 pinMode(BIN2, OUTPUT);

 

 //blackThreshold = analogRead(midSensor);

 

 pinMode(LEDPin, OUTPUT);

 //sensor

 Serial.begin(9600);

 

 //delay(3000);

 

}

void loop() {

 

 rightReading = analogRead(rightSensor);

 leftReading = analogRead(leftSensor);

 midReading = analogRead(midSensor);

 

 Serial.print(“Mid Reading “);

 Serial.print(midReading);

 Serial.print(“\n”);

 

 Serial.print(“Left Reading “);

 Serial.print(leftReading);

 Serial.print(“\n”);

 

 Serial.print(“Right Reading “);

 Serial.print(rightReading);

 Serial.print(“\n”);

 

if (midIsBlack() == true && leftIsBlack() == false && rightIsBlack() == false){

 

   move(1, 80, 1); //motor 1, half speed, right

   move(2, 80, 0); //motor 2, half speed, right

 

 }else if (leftIsBlack() == true && midIsBlack() == false && rightIsBlack() == false){

   //move left, turn on right motor;

   move(2, 00, 1);

   move(1, 70, 1);

 

 }else if(rightIsBlack() == true && midIsBlack() == false && leftIsBlack() == false){

   //move right, turn on left motor;

   move(2, 70, 2);

   move(1, 00, 2);

 }

  else if (rightIsBlack() == true && midIsBlack() == true && leftIsBlack() == true){

   stop();

   digitalWrite(LEDPin, HIGH);

   delay(3000);

   digitalWrite(LEDPin, LOW);

   move(1, 70, 1); //motor 1, half speed, right

   move(2, 70, 0);

   delay(300);

 }

 digitalWrite(LEDPin, LOW);

 

 //delay(2000);

}

 

//sensor methods

bool leftIsBlack(){

 return (leftReading < 900);

}

 

bool rightIsBlack(){

 return (rightReading < 900);

}

 

bool midIsBlack(){

 return (midReading < 900);

}

 

//motor methods

 

void move(int motor, int speed, int direction){

//Move specific motor at speed and direction

//motor: 0 for B 1 for A

//speed: 0 is off, and 255 is full speed

//direction: 0 clockwise, 1 counter-clockwise

 

 digitalWrite(STBY, HIGH); //disable standby

 

 boolean inPin1 = LOW;

 boolean inPin2 = HIGH;

 

 if(direction == 1){

   inPin1 = HIGH;

   inPin2 = LOW;

 }

 

 if(motor == 1){

   digitalWrite(AIN1, inPin1);

   digitalWrite(AIN2, inPin2);

   analogWrite(PWMA, speed);

 }else{

   digitalWrite(BIN1, inPin1);

   digitalWrite(BIN2, inPin2);

   analogWrite(PWMB, speed);

 }

}

 

void stop(){

//enable standby

 digitalWrite(STBY, LOW);

}

 void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
