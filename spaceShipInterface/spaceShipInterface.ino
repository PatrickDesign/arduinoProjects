int switchState = 0;
bool firstPress = false,
     systemReady = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, INPUT);

}


//Red = 6
//Yellow = 3
//Green = 4
//Blue = 5

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);


    if(switchState == LOW){
      digitalWrite(3, LOW);
      digitalWrite(6, LOW);
      if(firstPress && systemReady){
        digitalWrite(4, HIGH);
      }
    }else{
      if(!firstPress)
        firstPress = true;

      if(systemReady){
        
          //system is ready... display blue for 2 seconds!!
          digitalWrite(4, 0);
          digitalWrite(5, HIGH);
          delay(2000);
          digitalWrite(5, LOW);
          systemReady = false;
  
      }else{

  
        digitalWrite(6, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(5, LOW);
    
        delay(250);
    
        digitalWrite(6, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(5, LOW);
    
        delay(250);
        digitalWrite(3, LOW);
    
        systemReady = true;

      }
    
    }
  

}
