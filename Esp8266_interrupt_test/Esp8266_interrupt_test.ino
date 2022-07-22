// This is a test sketch to see how interrupt pins work!
// This sketch was made with the esp8266 in mind but will work with other boards
// if adjusted accordingly
// Just make sure the pins you want to use can work with interrupt!
// This sketch was made by Tatshino, i would appreciate if you don't take credit for making this
// @Tatshino on twitter

const int bt1 = D7;
int yes = 0;

void setup() {
  // You set your pin mode to input for your interrupt pin
  // then you set the pin you want as your interrupt pin as so
  Serial.begin(115200);
  pinMode(bt1, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(bt1),ButtonPressed1,FALLING);
}

void loop() {
  // This code is an example of a hold button(don't know the real name, don't sue me)
  // If yes = 1 then it'll say that the button was pressed
  // if you press the button again then yes = 0 in which case makes it say "waiting" till the button is pressed again 
  if(yes ==  1){
    Serial.println("Button was pressed!");
  }else{
    Serial.println("waiting");
  }
  delay(700);
}

ICACHE_RAM_ATTR void ButtonPressed1(){
  // It was a pain for me to figure out why it didn't work in the beginning
  // till i found out how you can't use a normal void function and can only use
  // a "ICACHE_RAM_ATTR void VoidName(){}" to be sure that your interrupt works
  
  //yes = 1;
  if(yes == 1){
    yes = 0;
  }else if (yes ==  0){
    yes = 1;
  }


  //the code below is a test to make a int go from 0 to 1
  //if it reaches the end then it should go back to the start(which is 0)
  //don't know if this works or not, still have to test out
  /*if(yes == 1){
    yes = 2;
  }else if(yes == 2){
    yes = 3;
  }else if(yes == 3){
    yes = 3;
  }else if (yes ==  0){
    yes = 1;
  }*/
}
