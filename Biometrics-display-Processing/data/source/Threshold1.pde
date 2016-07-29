import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;
import ddf.minim.signals.*;
import ddf.minim.spi.*;
import ddf.minim.ugens.*;
Minim m;
AudioPlayer sleepy;

PFont font;

void setup() {
  size(500, 100);
  font = loadFont("Arial-BoldMT-24.vlw");
  textFont(font);
  textAlign(CENTER);
  rectMode(CENTER);
  ellipseMode(CENTER);
  m = new Minim(this);
  sleepy = m.loadFile("3-sleepy.mp3");
}

void draw() {
  background(0);
  noStroke();
  text("Threshold 1 activated", 300, 30);
  sleepy.play();
}