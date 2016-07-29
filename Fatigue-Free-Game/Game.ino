//Variable declarations
//Pin assignments
//Inputs
const int trigger1Pin = 3;
const int trigger2Pin = 4;
const int trigger3Pin = 5;
const int buttonPin = 6;

//Outputs
const int buzzerPin = 13;
const int ledPin = 12;
const int stillFatiguedPin = 14;

//Input variables
int triggerState1 = LOW;
int triggerState2 = LOW;
int triggerState3 = LOW;
int buttonState = LOW;

//Output Variables
int buzzerState = LOW;
int ledState = LOW;

//Time constants, in milliseconds
//Song 1
long songLength = 0;
long time1 = 0;
long time2 = 0;
long time3 = 0;
long time4 = 0;
long time5 = 0;
long time6 = 0;
long time7 = 0;
long time8 = 0;

//Time control variables
long startTime = 0;
long curTime = 0;

//Scorekeeping variables
int mispresses = 0;
double scoreTracker = 0;
double total = 0;
double score = 0;
int scoreInt = 0;
int stillFatiguedTracker = 0;
//tracking mispresses
bool pressed1 = false;
//tracking word presses
bool pressed2 = false;
int test = 200;

void setup() {
  //Pin setup
  pinMode(trigger1Pin, INPUT);
  pinMode(trigger2Pin, INPUT);
  pinMode(trigger3Pin, INPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(stillFatiguedPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {

  //Starting the System
  if (buttonPin == HIGH) {
    Serial.println("900");
  }

  //Reading triggers
  triggerState1 = digitalRead(trigger1Pin);
  triggerState2 = digitalRead(trigger2Pin);
  triggerState3 = digitalRead(trigger3Pin);

  Serial.println(test); 
  
  if (triggerState1 == HIGH) {
    //Initialization
    songLength = 76000;
    time1 = 13000;
    time2 = 17500;
    time3 = 36750;
    time4 = 53400;
    time5 = 59500;
    time6 = 65750;
    time7 = 68500;
    time8 = 71500;

    buzzerState = LOW;

    mispresses = 0;
    scoreTracker = 0;
    total = 8;
    score = 0;
    scoreInt = 0;
    stillFatiguedTracker = 0;
    pressed1 = false;
    pressed2 = false;

    startTime = millis();
    songOne();
  }
  
  if (triggerState2 == HIGH) {
    //Initialization
    songLength = 75000;
    time1 = 33500;//3
    time2 = 43500;//3
    time3 = 49500;//2
    time4 = 53000;//3
    time5 = 57750;//3
    time6 = 62500;//3
    time7 = 68500;//2

    mispresses = 0;
    scoreTracker = 0;
    total = 7;
    score = 0;
    scoreInt = 0;
    stillFatiguedTracker = 0;
    pressed1 = false;
    pressed2 = false;

    startTime = millis();
    songTwo();
  }

  if (triggerState3 == HIGH) {
    //Initialization
    songLength = 100000;
    time1 = 35500;//3-3.5
    time2 = 42500;//
    time3 = 60000;//
    time4 = 66500;//
    time5 = 73750;//
    time6 = 80500;//
    time7 = 98000;//

    mispresses = 0;
    scoreTracker = 0;
    total = 7;
    score = 0;
    scoreInt = 0;
    stillFatiguedTracker = 0;
    pressed1 = false;
    pressed2 = false;

    startTime = millis();
    songThree();
  }
}

//SONG ONE/////////////////////////////////////////////////////////////////////////////////////
void songOne() {
  //Don't Stop Me Now
  //Driver pushes whenever "Stop" comes up 
  Serial.println("500");

  curTime = millis()-startTime;

  //Game:
  while (curTime < songLength){
    curTime = millis()-startTime;
    
    buzzerState = LOW;
    ledState = LOW;

    buttonState = digitalRead(buttonPin);

    //matching conditions

    //WORD 1
    //mispress
    if (curTime < (time1-500)) {
      ifmispress();
    }
    //DING
    else if (((time1-500) <= curTime) && (curTime < (time1+2000))){
      ifcorrect();
    }
    //check for mistake
    else if (((time1+2000) <= curTime) && (curTime < (time2-500))){
      if (pressed2 == false){
        if (curTime < (time1+2250)){
          ifmissed();
        }
        else {
          ifmispress();
        }
      }
      else {
        pressed2 = false;
      }  
    }
    
    //WORD 2
    //DING
    else if (((time2-500) <= curTime) && (curTime < (time2+2000))){
      ifcorrect();
    }
    //check for mistake
    else if (((time2+2000) <= curTime) && (curTime < (time3-500))){
      if (pressed2 == false){
        if (curTime < (time2+2250)){
          ifmissed();
        }
        else {
          ifmispress();
        }
      }
      else {
        pressed2 = false;
      }  
    }

    //WORD 3
    //DING
    else if (((time3-500) <= curTime) && (curTime < (time3+2000))){
      ifcorrect();
    }
    //check for mistake
    else if (((time3+2000) <= curTime) && (curTime < (time4-500))){
      if (pressed2 == false){
        if (curTime < (time3+2250)){
          ifmissed();
        }
        else {
          ifmispress();
        }
      }
      else {
        pressed2 = false;
      }  
    }

    //WORD 4
    //DING
    else if (((time4-500) <= curTime) && (curTime < (time4+2000))){
      ifcorrect();
    }
    //check for mistake
    else if (((time4+2000) <= curTime) && (curTime < (time5-500))){
      if (pressed2 == false){
        if (curTime < (time4+2250)){
          ifmissed();
        }
        else {
          ifmispress();
        }
      }
      else {
        pressed2 = false;
      }  
    }

    //WORD 5
    //correct once if button is pressed within 3 seconds of the word
    else if (((time5-500) <= curTime) && (curTime < (time5+2000))){
      ifcorrect();
    }
    //check for mistake
    else if (((time5+2000) <= curTime) && (curTime < (time6-500))){
      if (pressed2 == false){
        if (curTime < (time5+2250)){
          ifmissed();
        }
        else {
          ifmispress();
        }
      }
      else {
        pressed2 = false;
      } 
    }

    //WORD 6
    //DING
    else if (((time6-500) <= curTime) && (curTime < (time6+2000))){
      ifcorrect();
    }
    //check for mistake
    else if (((time6+2000) <= curTime) && (curTime < (time7-500))){
      if (pressed2 == false){
        if (curTime < (time6+2250)){
          ifmissed();
        }
        else {
          pressed2 = false;
          ifmispress();
        }
      }
      else {
        pressed2 = false;
        Serial.println(pressed2);
      } 
    }

    //WORD 7
    //correct once if button is pressed within 3 seconds of the word
    else if (((time7-500) <= curTime) && (curTime < (time7+2000))){
      ifcorrect();
    }
    //check for mistake
    else if (((time7+2000) <= curTime) && (curTime < (time8-500))){
      if (pressed2 == false){
        if (curTime < (time7+2250)){
          ifmissed();
        }
        else {
          ifmispress();
        }
      }
      else {
        pressed2 = false;
      }  
    }

    //LAST WORD
    //correct once if button is pressed within 3 seconds of the word
    else if (((time8-500) <= curTime) && (curTime < (time8+2000))){
      ifcorrect();
    }
    //check for mistake
    else if (((time8+2000) <= curTime)){
      if (pressed2 == false){
        if (curTime < (time8+2250)){
          ifmissed();
        }
        else {
          ifmispress();
        }
      }
      else {
        pressed2 = false;
      }  
    }

    //Serial print to processing
    if (ledState == HIGH){
      Serial.println("800");
    }
    if (buzzerState == HIGH){
     //vibration code 
    }

    //Outputs
    if (stillFatiguedTracker > 4){
      digitalWrite(stillFatiguedPin, HIGH);
    }
    digitalWrite(buzzerPin, buzzerState);
    digitalWrite(ledPin, ledState);
    
    delay(250);
  }

  buzzerState = LOW;
  ledState = LOW;

  digitalWrite(buzzerPin, buzzerState);
  digitalWrite(ledPin, ledState);

  score = (scoreTracker/total)*100;
  scoreInt = (int)score;
  Serial.println(scoreInt); 
  delay(1000);

  digitalWrite(stillFatiguedPin, LOW);
}

//SONG TWO/////////////////////////////////////////////////////////////////////////////////////
void songTwo() {
  //Beat It
  //Driver pushes whenever "Beat" comes up 
  Serial.println("600");

  curTime = millis()-startTime;

  //Game:
  while (curTime < songLength){
    curTime = millis()-startTime;
    
    buzzerState = LOW;
    ledState = LOW;

    buttonState = digitalRead(buttonPin);

    //matching conditions

    //WORD 1
    //mispress
    if (curTime < (time1-500)) {
      ifmispress();
    }
    //DING
    else if (((time1-500) <= curTime) && (curTime < (time1+3000))){
      ifcorrect();
    }
    //check for mistake
    else if (((time1+3000) <= curTime) && (curTime < (time2-500))){
      if (pressed2 == false){
        if (curTime < (time1+3250)){
          ifmissed();
        }
        else {
          ifmispress();
        }
      }
      else {
        pressed2 = false;
      }  
    }
    
    //WORD 2
    //DING
    else if (((time2-500) <= curTime) && (curTime < (time2+3000))){
      ifcorrect();
    }
    //check for mistake
    else if (((time2+3000) <= curTime) && (curTime < (time3-500))){
      if (pressed2 == false){
        if (curTime < (time2+3250)){
          ifmissed();
        }
        else {
          ifmispress();
        }
      }
      else {
        pressed2 = false;
      }  
    }

    //WORD 3
    //DING
    else if (((time3-500) <= curTime) && (curTime < (time3+2000))){
      ifcorrect();
    }
    //check for mistake
    else if (((time3+2000) <= curTime) && (curTime < (time4-500))){
      if (pressed2 == false){
        if (curTime < (time3+2250)){
          ifmissed();
        }
        else {
          ifmispress();
        }
      }
      else {
        pressed2 = false;
      }  
    }

    //WORD 4
    //DING
    else if (((time4-500) <= curTime) && (curTime < (time4+3000))){
      ifcorrect();
    }
    //check for mistake
    else if (((time4+3000) <= curTime) && (curTime < (time5-500))){
      if (pressed2 == false){
        if (curTime < (time4+3250)){
          ifmissed();
        }
        else {
          ifmispress();
        }
      }
      else {
        pressed2 = false;
      }  
    }

    //WORD 5
    //correct once if button is pressed within 3 seconds of the word
    else if (((time5-500) <= curTime) && (curTime < (time5+3000))){
      ifcorrect();
    }
    //check for mistake
    else if (((time5+3000) <= curTime) && (curTime < (time6-500))){
      if (pressed2 == false){
        if (curTime < (time5+3250)){
          ifmissed();
        }
        else {
          ifmispress();
        }
      }
      else {
        pressed2 = false;
      } 
    }

    //WORD 6
    //DING
    else if (((time6-500) <= curTime) && (curTime < (time6+3000))){
      ifcorrect();
    }
    //check for mistake
    else if (((time6+3000) <= curTime) && (curTime < (time7-500))){
      if (pressed2 == false){
        if (curTime < (time6+3250)){
          ifmissed();
        }
        else {
          pressed2 = false;
          ifmispress();
        }
      }
      else {
        pressed2 = false;
        Serial.println(pressed2);
      } 
    }

    //WORD 7 (LAST WORD)
    //correct once if button is pressed within 3 seconds of the word
    else if (((time7-500) <= curTime) && (curTime < (time7+2000))){
      ifcorrect();
    }
    //check for mistake
    else if (((time7+2000) <= curTime)){
      if (pressed2 == false){
        if (curTime < (time7+2250)){
          ifmissed();
        }
        else {
          ifmispress();
        }
      }
      else {
        pressed2 = false;
      }  
    }

    //Serial print to processing
    if (ledState == HIGH){
      Serial.println("800");
    }
    if (buzzerState == HIGH){
     //vibration code 
    }

    //Outputs
    if (stillFatiguedTracker > 4){
      digitalWrite(stillFatiguedPin, HIGH);
    }
    digitalWrite(buzzerPin, buzzerState);
    digitalWrite(ledPin, ledState);
    
    delay(250);
  }

  buzzerState = LOW;
  ledState = LOW;

  digitalWrite(buzzerPin, buzzerState);
  digitalWrite(ledPin, ledState);

  score = (scoreTracker/total)*100;
  scoreInt = (int)score;
  Serial.println(scoreInt); 
  delay(1000);

  digitalWrite(stillFatiguedPin, LOW);
}

//SONG THREE/////////////////////////////////////////////////////////////////////////////////////
void songThree() {
  //Mama Mia
  //Driver pushes whenever "Mama Mia" comes up 
  Serial.println("700");

  curTime = millis()-startTime;

  //Game:
  while (curTime < songLength){
    curTime = millis()-startTime;
    
    buzzerState = LOW;
    ledState = LOW;

    buttonState = digitalRead(buttonPin);

    //matching conditions

    //WORD 1
    //mispress
    if (curTime < (time1-500)) {
      ifmispress();
    }
    //DING
    else if (((time1-500) <= curTime) && (curTime < (time1+3000))){
      ifcorrect();
    }
    //check for mistake
    else if (((time1+3000) <= curTime) && (curTime < (time2-500))){
      if (pressed2 == false){
        if (curTime < (time1+3250)){
          ifmissed();
        }
        else {
          ifmispress();
        }
      }
      else {
        pressed2 = false;
      }  
    }
    
    //WORD 2
    //DING
    else if (((time2-500) <= curTime) && (curTime < (time2+3000))){
      ifcorrect();
    }
    //check for mistake
    else if (((time2+3000) <= curTime) && (curTime < (time3-500))){
      if (pressed2 == false){
        if (curTime < (time2+3250)){
          ifmissed();
        }
        else {
          ifmispress();
        }
      }
      else {
        pressed2 = false;
      }  
    }

    //WORD 3
    //DING
    else if (((time3-500) <= curTime) && (curTime < (time3+3000))){
      ifcorrect();
    }
    //check for mistake
    else if (((time3+3000) <= curTime) && (curTime < (time4-500))){
      if (pressed2 == false){
        if (curTime < (time3+3250)){
          ifmissed();
        }
        else {
          ifmispress();
        }
      }
      else {
        pressed2 = false;
      }  
    }

    //WORD 4
    //DING
    else if (((time4-500) <= curTime) && (curTime < (time4+3000))){
      ifcorrect();
    }
    //check for mistake
    else if (((time4+3000) <= curTime) && (curTime < (time5-500))){
      if (pressed2 == false){
        if (curTime < (time4+3250)){
          ifmissed();
        }
        else {
          ifmispress();
        }
      }
      else {
        pressed2 = false;
      }  
    }

    //WORD 5
    //correct once if button is pressed within 3 seconds of the word
    else if (((time5-500) <= curTime) && (curTime < (time5+3000))){
      ifcorrect();
    }
    //check for mistake
    else if (((time5+3000) <= curTime) && (curTime < (time6-500))){
      if (pressed2 == false){
        if (curTime < (time5+3250)){
          ifmissed();
        }
        else {
          ifmispress();
        }
      }
      else {
        pressed2 = false;
      } 
    }

    //WORD 6
    //DING
    else if (((time6-500) <= curTime) && (curTime < (time6+3000))){
      ifcorrect();
    }
    //check for mistake
    else if (((time6+3000) <= curTime) && (curTime < (time7-500))){
      if (pressed2 == false){
        if (curTime < (time6+3250)){
          ifmissed();
        }
        else {
          pressed2 = false;
          ifmispress();
        }
      }
      else {
        pressed2 = false;
        Serial.println(pressed2);
      } 
    }

    //WORD 7 (LAST WORD)
    //correct once if button is pressed within 3 seconds of the word
    else if (((time7-500) <= curTime) && (curTime < (time7+3000))){
      ifcorrect();
    }
    //check for mistake
    else if (((time7+3000) <= curTime)){
      if (pressed2 == false){
        if (curTime < (time7+3250)){
          ifmissed();
        }
        else {
          ifmispress();
        }
      }
      else {
        pressed2 = false;
      }  
    }


    //Serial print to processing
    if (ledState == HIGH){
      Serial.println("800");
    }
    if (buzzerState == HIGH){
     //vibration code 
    }

    //Outputs
    if (stillFatiguedTracker > 4){
      digitalWrite(stillFatiguedPin, HIGH);
    }
    digitalWrite(buzzerPin, buzzerState);
    digitalWrite(ledPin, ledState);
    
    delay(250);
  }

  buzzerState = LOW;
  ledState = LOW;

  digitalWrite(buzzerPin, buzzerState);
  digitalWrite(ledPin, ledState);

  score = (scoreTracker/total)*100;
  scoreInt = (int)score;
  Serial.println(scoreInt); 
  delay(1000);

  digitalWrite(stillFatiguedPin, LOW);
}

//Functions////////////////////////////////////////////////////////////////////////////////////

void ifmissed(){
  buzzerState = HIGH;
  stillFatiguedTracker++;
}

void ifmispress(){
  if (buttonState == HIGH){
    buzzerState = HIGH;
    if (pressed1 == false){
      mispresses++;
      pressed1 = true;
    }
  }
  else {
    pressed1 = false;
  }
}

void ifcorrect(){
  if (buttonState == HIGH){
    if (pressed2 == false){
      ledState = HIGH;
      scoreTracker++;
      pressed2 = true;
    }
    else {
      buzzerState = HIGH;
      mispresses++;
    }
  }
}

