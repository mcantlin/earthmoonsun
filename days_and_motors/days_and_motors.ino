#include <LiquidCrystal.h>

#include <AccelStepper.h>
#include <MultiStepper.h>

int dy=1;
int mont =1;
long yr = 2017;
long steps;

AccelStepper stepper1(AccelStepper::DRIVER, 18, 19); 
AccelStepper stepper2(AccelStepper::DRIVER, 16, 17); 
AccelStepper stepper3(AccelStepper::DRIVER, 14, 15);


LiquidCrystal lcd(8,9,4,5,6,7);


void setup() {
  lcd.begin(16,2);  
  
  stepper1.setMaxSpeed(5000);
  stepper2.setMaxSpeed(7000);
  stepper3.setMaxSpeed(7000);
  
  stepper1.setSpeed(130);//0.44rps ==> ~2.27 second moon cycle
  stepper2.setSpeed(110);//0.032rps ==> ~31 second year
  stepper3.setSpeed(500);//11.8rps ==> ~0.084 second day -->6000


  
 
}

void loop() {
  

  stepper1.runSpeed();
  stepper2.runSpeed();
  stepper3.runSpeed();


 steps=stepper3.currentPosition();
 
 printDate();

  // need to fix makes day motor not run too well
 
}

//jan, march, may, july, august,october, december == 31
//april, june, september, november == 30
//feb == 28 (29 leap year)
int days()
{
 mont = 1;
 dy = steps/320;
 
  
  if (dy < 31)
  {
    if (mont == 2 && dy == 28)
    {
      dy=1;
      months();
     
    }
    else if (mont == 4 || mont == 6 || mont == 9 || mont == 11 && dy==30)
    {
      months();
      dy=1;
      
    }
    else
    {
       dy++;
    }
  }
  else// (mont == 1 ||mont == 3 || mont == 5 || mont == 7 || mont == 8 || mont == 10 && dy==31)
  {
     months();
     dy=1;
 
  }
 

  
  
return dy;
}

void months()
{
  mont++;
  dy=1;
  years();
}

int getMonth()
{
  return mont;
}

int getYear()
{
  return yr;
}

void years()
{
  yr++;
  mont=1;
}

int getDay()
{
  return dy;
}

void printDate()
{
  lcd.setCursor(0,0);
  lcd.print(days());
  lcd.print(" / ");
  lcd.print(getMonth());
  lcd.print(" / ");
  lcd.print(getYear());

}


/*
 * 20 steps per day
 * 560 to 620 steps per month
 * 7300 to 7320 steps per year
  */
