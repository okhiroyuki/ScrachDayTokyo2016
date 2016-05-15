import ddf.minim.*;
import processing.serial.*;
 
Minim minim;
AudioPlayer player;
 
Serial myPort;
int val;
 
String [] soundfile = new String[8];
 
void setup() {
  size(800, 400, P3D);
  soundfile[0] = "drum1_cymbal.mp3";
  soundfile[1] = "drum1_snare.mp3";
  soundfile[2] = "drum1_tom1.mp3";
  soundfile[3] = "drum1_bassdrum1.mp3";
  soundfile[4] = "drum2_hat.mp3";
  soundfile[5] = "drum1_tom2.mp3";
  soundfile[6] = "drum1_tom3.mp3";
  soundfile[7] = "drum2_snare.mp3";
  
  println(Serial.list());
  String portName = Serial.list()[1];
  myPort = new Serial(this, portName, 9600);
  minim = new Minim(this);
  player = minim.loadFile(soundfile[int(random(7))], 2048);
}
 
void draw() {
  background(0);
  stroke(0,255,0);
  for(int i = 0; i < player.bufferSize() - 1; i++) {
    float x = map(i, 0, player.bufferSize(), 0, width);
    point(x,  height / 2 + player.left.get(i) * height*5);
  }
  //for(int i = 0; i < player.bufferSize() - 1; i++) {
  // float x = map(i, 0, player.bufferSize(), 0, width);
  // point(x,  height / 4 * 2 + player.right.get(i) * height*2);
  //}
  //  for(int i = 0; i < player.bufferSize() - 1; i++) {
  // float x = map(i, 0, player.bufferSize(), 0, width);
  // point(x,  height / 4 * 3 + player.right.get(i) * height*2);
  //}
}
 
void serialEvent(Serial p) {
  if(p.available() > 1) {
    val = p.read();
    //println(val);
  }
  //if(val > 0 && player.isPlaying() == false){
  if(val > 0){
    player = minim.loadFile(soundfile[val-47], 2048);
    player.rewind();
    player.play();
  }
}
 
void stop() {
  player.close();
  minim.stop();
  super.stop();
}