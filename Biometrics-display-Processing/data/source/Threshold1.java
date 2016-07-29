import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import ddf.minim.*; 
import ddf.minim.analysis.*; 
import ddf.minim.effects.*; 
import ddf.minim.signals.*; 
import ddf.minim.spi.*; 
import ddf.minim.ugens.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class Threshold1 extends PApplet {







Minim m;
AudioPlayer sleepy;

PFont font;

public void setup() {
  
  font = loadFont("Arial-BoldMT-24.vlw");
  textFont(font);
  textAlign(CENTER);
  rectMode(CENTER);
  ellipseMode(CENTER);
  m = new Minim(this);
  sleepy = m.loadFile("3-sleepy.mp3");
}

public void draw() {
  background(0);
  noStroke();
  text("Threshold 1 activated", 300, 30);
  sleepy.play();
}
  public void settings() {  size(500, 100); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "Threshold1" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
