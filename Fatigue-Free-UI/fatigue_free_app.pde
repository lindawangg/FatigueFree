//Define libraries
import processing.sound.*;
import processing.serial.*;

//Define Files
SoundFile[] audio = new SoundFile[10];
PImage braceletOn; 
PImage splashPage;
PImage activate;
PImage normalDriving;
PImage song1; 
PImage song2;
PImage song3;
PImage destination; 
//Define global variables
Serial myPort;  
String data; 
boolean trigger = false;
boolean[] play = new boolean[10];
boolean butHover = false;
boolean printing = false;
int score; 
int butYesX = 250, butYesY = 220;
int butNoX = 575, butNoY = 220;
int butWidth = 200, butHeight = 50; 
  int test =234343;
int positionX, positionY; 
PFont font;

void setup() { 
  size(740,324);
  myPort = new Serial(this, Serial.list()[1], 9600);
  myPort.bufferUntil('\n'); 
  font = loadFont("SegoeUI-20.vlw");
  splashPage = loadImage("splash-page.png");
  braceletOn = loadImage("put-on-bracelet.png");
  activate = loadImage("activate.png");
  song1 = loadImage("song1.png"); 
  song2 = loadImage("song2.png"); 
  song3 = loadImage("song3.png"); 
  normalDriving = loadImage("normal-driving.png"); 
  destination = loadImage("return-bracelet.png"); 
  audio[0] = new SoundFile(this, "2-bracelet.mp3");
  audio[1] = new SoundFile(this, "1-activate.mp3");
  audio[2] = new SoundFile(this, "3-sleepy.mp3");
  audio[3] = new SoundFile(this, "4-stop.mp3");
  audio[4] = new SoundFile(this, "6-destination.mp3");
  audio[5] = new SoundFile(this, "Don't-Stop-Me-Now.mp3"); 
  audio[6] = new SoundFile(this, "8-sorry.mp3");
  audio[7] = new SoundFile(this, "11-mamma mia.mp3");
  audio[8] = new SoundFile(this, "Ding.wav");
  audio[9] = new SoundFile(this, "7-alert.mp3"); 
 for (int i=0; i<play.length; i++)
   play[i] = true;
}

void draw() {
    if (printing) {
        printScore(score);
    } 
}

//Reads keyboard input to change app interface/play audio
void keyPressed()
{
  switch(key) {
    case '0': 
      background(splashPage);
      break; 
    case 'b':
      background(braceletOn);
      playAudio(0);
      break;
    case 'a':
      background(activate);
      playAudio(1);
      break;
    case 'n': { 
      printing = false;
      image(normalDriving, 0, 0);
      printing = false;
      break; }
    case 'r': {
      printing = false;
      background(normalDriving); 
      printing = false;
      playAudio(8);
      break;
    }
    case 'd':
      background(destination);
      playAudio(4);
      break;
  }
}    

//Plays audio recordings
void playAudio(int i) {
  if (play[i]) {
    if( i > 4  && i <= 5) {
      audio[i].play();
    }
    else if (i == 8) {
      audio[i].play();
      audio[i].amp(1.0); 
    }
    else {
      audio[i].play();
      audio[i].rate(0.5);
      play[i] = false;
    }
  }
} 

//changes the Yes button to clicked
void clickYes() {
  stroke(#60D88B);
  fill(#757C78);
  rect(butYesX, butYesY, butWidth, butHeight, 6);
  textFont(font,24);
  fill(255);
  text("Yes", 330, 255); 
} 

//reads input from arduino
void serialEvent(Serial myPort) {
  data = myPort.readStringUntil('\n'); 
  if (data != null) {
    data = trim(data);
    int intData = int(data); 
    //start song if trigger says so
    if (trigger == false) {
        myPort.clear();
        trigger = true;
        println("Connected to Arduino");
      }
    else {
      println(intData); 
      switch(intData) {
        case 500: 
          playAudio(2);
          delay(5000);
          playAudio(5);//plays don't stop me now
          background(song1);  
          break;
        case 600://plays second song
          playAudio(2);
          delay(5000);
          playAudio(6);
          background(song2);
          break;
        case 700://Plays third song
          playAudio(2);
          delay(5000);
          playAudio(7);
          background(song3);
          break; 
        case 800://plays Ding
          playAudio(8);
          break;
        case 900: 
          background(normalDriving); 
        default: 
          if (intData <= 100 && intData > 0) {
            score = intData;
            printing = true;
          }
          break;
        }
     }
  }
}
      
void printScore(int score) { 
  textFont(font,24);
  text("Your score:", 430, 275); 
  text(score, 600, 275);
  text("%", 630, 275); 
}
 
////Draws yes buttons
//void drawYesButton() {
//    stroke(#60D88B);
//    fill(0);
//    rect(butYesX, butYesY, butWidth, butHeight, 6);
//    textFont(font,24);
//    fill(255);
//    text("Yes", 330, 255); 
//}
////Draws no buttons
//void drawNoButton() {
//  stroke(#FA2650);
//  fill(0);
//  rect(butNoX, butNoY, butWidth, butHeight, 6);
//  textFont(font,24);
//  fill(255);
//  text("No", 655, 255); 
//}
////Controls yes button on activation screen
//void mouseClicked() {
//  if ((mouseX > butYesX && mouseX < butYesX+butWidth) && 
//          (mouseY > butYesY && mouseY < butYesY+butWidth))
//     background(normalDriving);
//}