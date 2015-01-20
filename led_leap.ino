
#define NL 10
#define BOTTOM 14
#define MIDDLE 15
#define TOP    16

char str[256];
void setup(){
  int i;
  
  Serial.begin(38400);
  //cube
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  //layer
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  
  for(i = 2; i<= 16; i++){
    digitalWrite(i, LOW);
  }
  

  Serial.println("---setup done."); 

  while(1){
    if(Serial.available() ){
      Serial_gets(str, NL);
      Serial.print("str:"); Serial.println(str);
      break;
    }
  }
}

void loop() {  
  int i,j;
  unsigned long start;
    
  if( !strcmp(str, "u") ){
    Serial.println("front up");
    front_up();
  }else if( !strcmp(str, "d") ){
    front_down();
  }else if( !strcmp(str, "r") ){
    right_tilt();
  }else if( !strcmp(str, "l") ){
    left_tilt();
  }else if( !strcmp(str, "dr") ){
    front_down_right();
  }else if( !strcmp(str, "ur") ){
    front_up_right();
  }else if( !strcmp(str, "dl") ){
    front_down_left();
  }else if( !strcmp(str, "ul") ){
    front_up_left();
  }else if( !strcmp(str, "h") ){
    horizon(MIDDLE);
  }else{
    all_off();
    
    while(1){
    if(Serial.available() ){
      Serial_gets(str, NL);
      Serial.print("str:"); Serial.println(str);
      return;
    }
  }
    
  }
  
  Serial_gets(str, NL);
  //Serial.print("str2:"); Serial.println(str);
  
}

void front_up(){
  int k;
  do{
    //Serial.println("hogehoge ");
    for( k = BOTTOM; k<=TOP; k++){
      //Serial.println("hogehoge2 ");
      all_off();
      switch( k ){
         case BOTTOM:
          digitalWrite(TOP, LOW);
          digitalWrite(8, HIGH);digitalWrite(9, HIGH);digitalWrite(10, HIGH);
          delay(5);
         break;
         case MIDDLE:
          digitalWrite(MIDDLE, LOW);
          digitalWrite(5, HIGH);digitalWrite(6, HIGH);digitalWrite(7, HIGH);
          delay(5);
           break;
  
         case TOP:
          digitalWrite(BOTTOM, LOW);
         digitalWrite(2, HIGH);digitalWrite(3, HIGH);digitalWrite(4, HIGH);
          delay(5);
           break;
        }
    }//end for
  }while(Serial.available() == 0 );
  
}
void front_down(){
  int k;
  do{
    for( k = BOTTOM; k<=TOP; k++){
      all_off();
      switch( k ){
         case BOTTOM:
          digitalWrite(TOP, LOW);
          digitalWrite(2, HIGH);digitalWrite(3, HIGH);digitalWrite(4, HIGH);
          delay(5);
         break;
         case MIDDLE:
          digitalWrite(MIDDLE, LOW);
          digitalWrite(5, HIGH);digitalWrite(6, HIGH);digitalWrite(7, HIGH);
          delay(5);
           break;
  
         case TOP:
          digitalWrite(BOTTOM, LOW);
          digitalWrite(8, HIGH);digitalWrite(9, HIGH);digitalWrite(10, HIGH);
          delay(5);
           break;
        }
    } //loop k
  }while(Serial.available() == 0 );
}

void horizon(int k){
  //int i, j, k;
  do{
    //all_off();
    all_on();
    switch( k ){
      case BOTTOM:
       digitalWrite(MIDDLE, HIGH);
       digitalWrite(TOP, HIGH);
       //digitalWrite(8, HIGH);digitalWrite(9, HIGH);digitalWrite(10, HIGH);
       delay(5);
       break;
       
      case MIDDLE:
       digitalWrite(BOTTOM, HIGH);
       digitalWrite(TOP, HIGH);
       //digitalWrite(5, HIGH);digitalWrite(6, HIGH);digitalWrite(7, HIGH);
       delay(5);
       break;
  
      case TOP:
       digitalWrite(BOTTOM, HIGH);
       digitalWrite(MIDDLE, HIGH);
       //digitalWrite(2, HIGH);digitalWrite(3, HIGH);digitalWrite(4, HIGH);
       delay(5);
       break;
    }
  }while(Serial.available() == 0 );
}

void left_tilt(){
  int k;
  do{
    for( k = BOTTOM; k<=TOP; k++){
      all_off();
      switch( k ){
         case BOTTOM:
          digitalWrite(BOTTOM, LOW);
          digitalWrite(4, HIGH);digitalWrite(7, HIGH);digitalWrite(10, HIGH);
          delay(5);
         break;
         case MIDDLE:
          digitalWrite(MIDDLE, LOW);
          digitalWrite(3, HIGH);digitalWrite(6, HIGH);digitalWrite(9, HIGH);
          delay(5);
           break;
         case TOP:
          digitalWrite(TOP, LOW);
         digitalWrite(2, HIGH);digitalWrite(5, HIGH);digitalWrite(8, HIGH);
          delay(5);
           break;
        }
    } //loop k
  }while(Serial.available() == 0 );
}

void right_tilt(){
  int k;
  do{
    for( k = BOTTOM; k<=TOP; k++){
      all_off();
      switch( k ){
         case BOTTOM:
          digitalWrite(BOTTOM, LOW);
          digitalWrite(2, HIGH);digitalWrite(5, HIGH);digitalWrite(8, HIGH);
          delay(5);
         break;
         case MIDDLE:
          digitalWrite(MIDDLE, LOW);
          digitalWrite(3, HIGH);digitalWrite(6, HIGH);digitalWrite(9, HIGH);
          delay(5);
           break;
         case TOP:
          digitalWrite(TOP, LOW);
         digitalWrite(4, HIGH);digitalWrite(7, HIGH);digitalWrite(10, HIGH);
          delay(5);
           break;
        }
    } //loop k
  }while(Serial.available() == 0 );
}

void front_down_left(){
  int k;
  do{
    for( k = BOTTOM; k<=TOP; k++){
      all_off();
      switch( k ){
         case BOTTOM:
          digitalWrite(BOTTOM, LOW);
          digitalWrite(10, HIGH);
          delay(5);
         break;
         case MIDDLE:
          digitalWrite(MIDDLE, LOW);
          digitalWrite(4, HIGH);digitalWrite(6, HIGH);digitalWrite(8, HIGH);
          delay(5);
           break;
         case TOP:
          digitalWrite(TOP, LOW);
         digitalWrite(2, HIGH);
          delay(5);
           break;
        }
    } //loop k
  }while(Serial.available() == 0 );
}

void front_down_right(){
  int k;
  do{
    for( k = BOTTOM; k<=TOP; k++){
      all_off();
      switch( k ){
         case BOTTOM:
          digitalWrite(BOTTOM, LOW);
          digitalWrite(8, HIGH);
          delay(5);
         break;
         case MIDDLE:
          digitalWrite(MIDDLE, LOW);
          digitalWrite(2, HIGH);digitalWrite(6, HIGH);digitalWrite(10, HIGH);
          delay(5);
           break;
         case TOP:
          digitalWrite(TOP, LOW);
         digitalWrite(4, HIGH);
          delay(5);
           break;
        }
    } //loop k
  }while(Serial.available() == 0 );
}

void front_up_right(){
  int k;
  do{
    for( k = BOTTOM; k<=TOP; k++){
      all_off();
      switch( k ){
         case BOTTOM:
          digitalWrite(BOTTOM, LOW);
          digitalWrite(2, HIGH);
          delay(5);
         break;
         case MIDDLE:
          digitalWrite(MIDDLE, LOW);
          digitalWrite(4, HIGH);digitalWrite(6, HIGH);digitalWrite(8, HIGH);
          delay(5);
           break;
         case TOP:
          digitalWrite(TOP, LOW);
         digitalWrite(10, HIGH);
          delay(5);
           break;
        }
    } //loop k
  }while(Serial.available() == 0 );
}

void front_up_left(){
  int k;
  do{
    for( k = BOTTOM; k<=TOP; k++){
      all_off();
      switch( k ){
         case BOTTOM:
          digitalWrite(BOTTOM, LOW);
          digitalWrite(4, HIGH);
          delay(5);
         break;
         case MIDDLE:
          digitalWrite(MIDDLE, LOW);
          digitalWrite(2, HIGH);digitalWrite(6, HIGH);digitalWrite(10, HIGH);
          delay(5);
           break;
         case TOP:
          digitalWrite(TOP, LOW);
         digitalWrite(8, HIGH);
          delay(5);
           break;
        }
    } //loop k
  }while(Serial.available() == 0 );
}

//get strings from serial port
void Serial_gets(char *buf, char sw){
  int i = 0;
  char c;
  unsigned long time = millis();
  while(1){
    //loopが始まって1sec 経ったら強制終了させる
    if( millis() > time + 1000 ){
         break;
    }
    
    if(Serial.available()){
      c = Serial.read();
      //Serial.print("read->");
      //Serial.println(c, DEC);
      buf[i] = c;
      if(c == sw){
          buf[i] = 0; // null terminate
          //Serial.println("---break");
          //return;
          break;
      }
      i++;
      if( i == 255 ){
        break; //fool safe
      }
    }
  }
}
//all off
void all_off(){
  int i;
    for(i=2; i<=10; i++){
      digitalWrite(i, LOW);
    }
    for(i=14; i<=16; i++){
      digitalWrite(i, HIGH);
    }
}
void all_on(){
  int i;
    for(i=2; i<=10; i++){
      digitalWrite(i, HIGH);
    }
    for(i=14; i<=16; i++){
      digitalWrite(i, LOW);
    }
}
