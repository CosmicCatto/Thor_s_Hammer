int relay1ControlPin = 13;  // Green
int lightPin = 12;
int relay1Status = 0; 
int lightStatus = 0;

int remoteButtonA_pin = 5;
int remoteButtonB_pin = 4;
int remoteButtonC_pin = 3;
int remoteButtonD_pin = 2;

bool remoteButtonA_state = 0;  
bool remoteButtonB_state = 0; 
bool remoteButtonC_state = 0; 
bool remoteButtonD_state = 0;

void setup() {
  Serial.begin(9600);
  pinMode(relay1ControlPin, OUTPUT);
  pinMode(lightPin, OUTPUT);
   
  pinMode(remoteButtonA_pin, INPUT);
  pinMode(remoteButtonB_pin, INPUT);
  pinMode(remoteButtonC_pin, INPUT);
  pinMode(remoteButtonD_pin, INPUT);
  
  delay(1000);
}

void loop() {
  readRemoteButtonStates();
  
  if (remoteButtonA_state) {
    relay1Status = 1;
    lightStatus = 1;
    Serial.println("Button A Pressed");
  }
  
  if (remoteButtonB_state) {
    relay1Status = 0;
    lightStatus = 0;
    Serial.println("Button B Pressed");
  }
    
  digitalWrite(relay1ControlPin, relay1Status);
  digitalWrite(lightPin, lightStatus);
}
