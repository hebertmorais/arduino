int buzzer = 10;

int rgb_red = 3;
int rgb_green = 5;
int rgb_blue = 6;

int green_light = 7;
int red_light = 8;

int pedestrian_green_light = 12;
int pedestrian_red_light = 13;

void setup() {
  pinMode(green_light, OUTPUT); 
  pinMode(red_light, OUTPUT); 
  pinMode(pedestrian_green_light, OUTPUT); 
  pinMode(pedestrian_red_light, OUTPUT); 

  Serial.begin(9600);
}

void loop() {
  digitalWrite(pedestrian_red_light, HIGH);
  digitalWrite(green_light, HIGH);
  delay(5 * 1000);
  digitalWrite(green_light, LOW);
  yellowLight(3);
  digitalWrite(pedestrian_red_light, LOW);
  digitalWrite(pedestrian_green_light, HIGH);
  digitalWrite(red_light, HIGH);
  delay(5 * 1000);
  tone(buzzer,262,3000); //DO
  for(int i = 0; i < 5; i++){
    digitalWrite(pedestrian_green_light, HIGH);
    delay(300);
    digitalWrite(pedestrian_green_light, LOW);
    delay(300);
  }
  digitalWrite(red_light, LOW);
  digitalWrite(pedestrian_green_light, LOW);
}

void yellowLight(int seconds){
  analogWrite(rgb_red, 255);
  analogWrite(rgb_green, 255);
  delay(seconds * 1000);
  analogWrite(rgb_red, 0);
  analogWrite(rgb_green, 0);
}


