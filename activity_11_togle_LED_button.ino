#define RED_LED 8
#define YELLOW_LED 3
#define GREEN_LED 7
#define BUTTON_PIN 2

unsigned long redStart = millis();
unsigned long lastTimeButtonChanged = millis();

long buttonDelay = 50;

long redDelay = 1000;

boolean redOn = false;

byte buttonState = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned long currTime = millis();
  byte currButtonState = digitalRead(BUTTON_PIN);

// make the red led blink on and off for 1 sec
  if(currTime - redStart > redDelay){
    if(redOn){
      digitalWrite(RED_LED, HIGH);
      redOn = false;
    } else{
      digitalWrite(RED_LED, LOW);
      redOn = true;
    }
    redStart += redDelay;
  }

  //tolge green and yellow when button is pressed
  //when low yellow on green off
  //when high
  if (currTime - lastTimeButtonChanged > buttonDelay){
    if(buttonState != currButtonState){
      lastTimeButtonChanged = currTime;
      buttonState = currButtonState;

      if (buttonState == LOW){
        digitalWrite(YELLOW_LED, HIGH);
        digitalWrite(GREEN_LED, LOW);

      } else{
        digitalWrite(YELLOW_LED, LOW);
        digitalWrite(GREEN_LED, HIGH);
      }

    }



  }


  

}
