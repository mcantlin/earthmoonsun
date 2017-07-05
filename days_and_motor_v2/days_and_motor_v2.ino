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
 date();
  
}

void date()
{

dy = steps/320;

mont = 1;
  
  while (mont < 12)
  { 
     
       if (mont == 1 ||mont == 3 || mont == 5 || mont == 7 || mont == 8 || mont == 10)
       {
          while (dy < 31) 
          {
            dy++;
          }
          dy=1;
          mont++;
       }
      else if (mont == 4 || mont == 6 || mont == 9 || mont == 11)
      {
          while (dy < 30)
          {
            dy++;
          }
          dy=1;
          mont++;
      }
      else // mont==2
      {
          while (dy < 29)
          {
            dy++;
          }
          dy=1;
          mont++;
      }
      
  }
 /* yr++;
  mont=1;
  dy=1;*/

printDate(dy, mont, yr);

}

void printDate(int days, int months, long years)
{
  lcd.setCursor(0,0);
  lcd.print(days);
  lcd.print(" / ");
  lcd.print(months);
  lcd.print(" / ");
  lcd.print(years);

}

