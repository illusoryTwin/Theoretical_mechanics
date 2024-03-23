
#define encoderPole1 2
#define encoderPole2 4 // Only use one interrupt in this example

#define encoderCart1 3
#define encoderCart2 5

volatile int count;
volatile int count2;

void setup()
{
  Serial.begin(115200);
  count=0; 
  count2 = 0;
  pinMode(encoderPole1, INPUT);
  pinMode(encoderPole2, INPUT);
  pinMode(encoderCart1, INPUT);
  pinMode(encoderCart2, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(2), handleEncoder1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), handleEncoder2, CHANGE);

  
}

void loop()
{
//  Serial.print(count);
//  Serial.print(" ");
//  Serial.println(count2);
//  delay(10);

  Serial.print(count2*428.0/11976.0);
  Serial.print(" ");
  Serial.println(count*360.0/8308.0);
  delay(10);
}

void handleEncoder1()
{
  
  if(digitalRead(encoderPole1) == digitalRead(encoderPole2))
  {
    count++;
  }
  else
  {
    count--;
  }
  
}

void handleEncoder2()
{
  
  if(digitalRead(encoderCart1) == digitalRead(encoderCart2))
  {
    count2++;
  }
  else
  {
    count2--;
  }
  
}