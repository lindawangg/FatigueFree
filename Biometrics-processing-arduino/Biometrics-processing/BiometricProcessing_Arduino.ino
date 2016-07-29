
/*  Pulse Sensor Amped 1.4    by Joel Murphy and Yury Gitman   http://www.pulsesensor.com

----------------------  Notes ----------------------  ---------------------- 
This code:
1) Blinks an LED to User's Live Heartbeat   PIN 13
2) Fades an LED to User's Live HeartBeat
3) Determines BPM
4) Prints All of the Above to Serial

Read Me:
https://github.com/WorldFamousElectronics/PulseSensor_Amped_Arduino/blob/master/README.md   
 ----------------------       ----------------------  ----------------------
*/

//  Variables
int pulsePin = 0;                 // Pulse Sensor purple wire connected to analog pin 0
//int blinkPin = 13;                // pin to blink led at each beat
int fadePin = 5;                  // pin to do fancy classy fading blink at each beat
int fadeRate = 0;                 // used to fade LED on with PWM on fadePin
int FSR_Pin = A5;                 //analog pin 1
int Act_Pin = 8;
int game_Pin = 13;

// Volatile Variables, used in the interrupt service routine!
volatile int BPM;                   // int that holds raw Analog in 0. updated every 2mS
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // int that holds the time interval between beats! Must be seeded! 
volatile boolean Pulse = false;     // "True" when User's live heartbeat is detected. "False" when not a "live beat". 
volatile boolean QS = false;        // becomes true when Arduino finds a beat.
volatile int FSRReading;
volatile int runningBPM;
volatile int runningGrip;
volatile int SDBPM;
volatile boolean restDetect = false;
unsigned long startTime;
unsigned long runningTime;
volatile int restingBPM = 0;
boolean actRest = false;
int w1 = 1000;
int w2 = 100;
int score = 0;
int threshold1 = 10000;

// Regards Serial OutPut  -- Set This Up to your needs
static boolean serialVisual = false;   // Set to 'false' by Default.  Re-set to 'true' to see Arduino Serial Monitor ASCII Visual Pulse 


void setup(){
  //pinMode(blinkPin,OUTPUT);         // pin that will blink to your heartbeat!
  pinMode(fadePin,OUTPUT);          // pin that will fade to your heartbeat!
  pinMode(FSR_Pin, INPUT);
  pinMode(Act_Pin, OUTPUT);
  pinMode(game_Pin, INPUT);
  Serial.begin(115200);             // we agree to talk fast!
  //Serial.begin(9600);
  interruptSetup();                 // sets up to read Pulse Sensor signal every 2mS 
   // IF YOU ARE POWERING The Pulse Sensor AT VOLTAGE LESS THAN THE BOARD VOLTAGE, 
   // UN-COMMENT THE NEXT LINE AND APPLY THAT VOLTAGE TO THE A-REF PIN
//   analogReference(EXTERNAL);   
   startTime = millis();
}


void loop(){
  if (!actRest) {
     runningTime = millis() - startTime;
    if (runningTime > 30000) {
      actRest = true; 
    }
  }
  
  serialOutput() ;       
    
  if (QS == true){     // A Heartbeat Was Found
                       // BPM and IBI have been Determined
                       // Quantified Self "QS" true when arduino finds a heartbeat
        fadeRate = 255;         // Makes the LED Fade Effect Happen
                                // Set 'fadeRate' Variable to 255 to fade LED with pulse
        serialOutputWhenBeatHappens();   // A Beat Happened, Output that to serial.     
        QS = false;                      // reset the Quantified Self flag for next time    
  }

  if (actRest)
  {
    if (digitalRead(game_Pin) == HIGH) {
       score = 1000;
    }
    else {
      score = 0;
    }
    if (((restingBPM - BPM)*w1 + (1023-FSRReading)*w2 + score) > threshold1) {
      digitalWrite(Act_Pin, HIGH); 
    }
    else {
      digitalWrite(Act_Pin, LOW);
    }
  }
  else
  {
    digitalWrite(Act_Pin, LOW);
  }
  ledFadeToBeat();                      // Makes the LED Fade Effect Happen 
  delay(20);                             //  take a break
}





void ledFadeToBeat(){
    fadeRate -= 15;                         //  set LED fade value
    fadeRate = constrain(fadeRate,0,255);   //  keep LED fade value from going into negative numbers!
    analogWrite(fadePin,fadeRate);          //  fade LED
  }




