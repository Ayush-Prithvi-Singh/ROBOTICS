int S0 = A5, S1 = A4, S2 = A3, S3 = A2, S4 = A1 , S5 = A0, S6 = 4, S7 = 7;
int v1, v2, v3, v4, v5, v6, v7, v8;
int L1 = 3, L2 = 5;
int R1 = 9, R2 =10;
int max_speed = 100;
void setup() {
  // put your setup code here, to run once:
   pinMode(L1,OUTPUT);
   pinMode(L2,OUTPUT);
   pinMode(R1,OUTPUT);
   pinMode(R2,OUTPUT);  
  
   pinMode(S0,INPUT);
   pinMode(S1,INPUT);
   pinMode(S2,INPUT);
   pinMode(S3,INPUT);
   pinMode(S4,INPUT);
   pinMode(S5,INPUT);
   pinMode(S6,INPUT);
   pinMode(S7,INPUT);
 
   Serial.begin(9600);
}
   
void readline()
 {
  v1=digitalRead(S0);
  v2=digitalRead(S1);
  v3=digitalRead(S2);
  v4=digitalRead(S3); 
  v5=digitalRead(S4);
  v6=digitalRead(S5);
  v7=digitalRead(S6);
  v8=digitalRead(S7);
  Serial.print(v1);
    Serial.print(v2);
    Serial.print(v3);
    Serial.print(v4);
    Serial.print(v5);
    Serial.print(v6);
    Serial.print(v7);
    Serial.print(v8);
    Serial.println();
 }
    

    
void forward()
{
  analogWrite(L1,max_speed);
  analogWrite(L2,0);
  analogWrite(R1,max_speed);
  analogWrite(R2,0);
}

void hardleft()
{
  analogWrite(L1,0);
  analogWrite(L2,max_speed);
  analogWrite(R1,max_speed);
  analogWrite(R2,0);
}

void hardright()
{
  analogWrite(L1,max_speed);
  analogWrite(L2,0);
  analogWrite(R1,0);
  analogWrite(R2,max_speed);
}

void stp()
{
  analogWrite(L1,0);
  analogWrite(L2,0);
  analogWrite(R1,0);
  analogWrite(R2,0);
}

void backward()
{
  analogWrite(L1,0);
  analogWrite(L2,max_speed);
  analogWrite(R1,0);
  analogWrite(R2,max_speed);
}

void left()
{
  analogWrite(L1,0);
  analogWrite(L2,0);
  analogWrite(R1,max_speed);
  analogWrite(R2,0);
}

void softleft()
{
  analogWrite(L1,20);
  analogWrite(L2,0);
  analogWrite(R1,max_speed);
  analogWrite(R2,0);
}

void right()
{
  analogWrite(L1,max_speed);
  analogWrite(L2,0);
  analogWrite(R1,0);
  analogWrite(R2,0);
}

void softright()
{
  analogWrite(L1,max_speed);
  analogWrite(L2,0);
  analogWrite(R1,20);
  analogWrite(R2,0);
}
void loop() {
  // put your main code here, to run repeatedly:


  if(v1==0&&v2==0&&v3==0&&v4==0&&v5==0&&v6==0&&v7==0&&v8==0)
  {
    forward();
    delay(100);
    hardleft();
    delay(300);
  }
   else if(v1==0&&v2==0&&v3==0&&v4==0&&v5==0&&v6==1&&v7==1&&v8==1) 
  {
    forward();
    delay(100);
    hardleft();
    delay(300);
  }
  else if(v1==1&&v2==1&&v3==1&&v4==0&&v5==0&&v6==0&&v7==0&&v8==0)
  {
    forward();
    delay(100);
    readline();
    if(v1==1&&v2==1&&v3==1&&v4==1&&v5==1&&v6==1&&v7==1&&v8==1)
    {
      hardright();
      delay(300);
    }
    else
    {
      forward();
    }
  }
  else if(v1==1&&v2==1&&v3==1&&v4==1&&v5==1&&v6==1&&v7==1&&v8==1)
  {  
    hardleft();
    delay(600);
    readline();
  }
  else if(v1==1&&v2==1&&v3==1&&v4==0&&v5==0&&v6==0&&v7==1&&v8==1)
  softright();
  else if(v1==1&&v2==1&&v3==0&&v4==0&&v5==0&&v6==1&&v7==1&&v8==1)
  softleft();
  else if(v1==1&&v2==1&&v3==0&&v4==0&&v5==1&&v6==1&&v7==1&&v8==1)
  softleft();
  else if(v1==1&&v2==1&&v3==1&&v4==1&&v5==0&&v6==0&&v7==1&&v8==1)
  softright();
  else if(v1==1&&v2==0&&v3==0&&v4==0&&v5==0&&v6==1&&v7==1&&v8==1)
  left();
  else if(v1==1&&v2==1&&v3==1&&v4==0&&v5==0&&v6==0&&v7==0&&v8==1)
  right();
  else if(v1==1&&v2==1&&v3==1&&v4==1&&v5==1&&v6==1&&v7==0&&v8==0)
  {
    forward();
    delay(100);
    readline();
    if(v1==1&&v2==1&&v3==1&&v4==1&&v5==1&&v6==1&&v7==1&&v8==1)
    {
      hardright();
      delay(300);
    }
    else
    {
      forward();
    }
  }
  else if(v1==0&&v2==0&&v3==1&&v4==1&&v5==1&&v6==1&&v7==1&&v8==1)
  {
  hardleft();
  delay(300);
  }
}
