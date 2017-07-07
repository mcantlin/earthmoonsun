#include <LiquidCrystal.h>

#include <AccelStepper.h>
#include <MultiStepper.h>


AccelStepper stepper1(AccelStepper::DRIVER, 18, 19); 
AccelStepper stepper2(AccelStepper::DRIVER, 16, 17); 
AccelStepper stepper3(AccelStepper::DRIVER, 14, 15);


int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int sDay=1;
int count=1;
long yr = 2017;
long steps;

LiquidCrystal lcd(8,9,4,5,6,7);


void setup() {
  lcd.begin(16,2);  
  

  stepper1.setMaxSpeed(5000);
  stepper2.setMaxSpeed(7000);
  stepper3.setMaxSpeed(7000);
  
  stepper1.setSpeed(65);// ==> ~5 second moon cycle
  stepper2.setSpeed(55);// ==> ~62 second year
  stepper3.setSpeed(3000);// ==> ~0.168 second day


  
 
}

void loop() {

  stepper1.runSpeed();
  stepper2.runSpeed();
  stepper3.runSpeed();


  if (stepper3.currentPosition()%300==0) 
  { 
     date();
  }
  

  
 
}

//jan, march, may, july, august,october, december == 31
//april, june, september, november == 30
//feb == 28 (29 leap year)
void date()
{

   
     if (sDay<=days[count-1])
      {
        lcd.setCursor(0,0);
        if (sDay < 10) lcd.print('0');
        lcd.print(sDay);
        lcd.print(" / ");
        if (count < 10) lcd.print('0');
        lcd.print(count);
        lcd.print(" / ");
        lcd.print(yr);
        sDay++;
        // for 11.8 rps needs to break for .085 seconds
      }
      if (sDay > days[count-1])
      {
        count++;
        sDay=1;
      }
      if (count > 12)
      {
        yr++;
        count=1;
      }
}





/*void printDate()
{
  lcd.setCursor(0,0);
  lcd.print(sDay);
  lcd.print(" / ");
  lcd.print(count);
  lcd.print(" / ");
  lcd.print(yr);

}*/


/*
 * 20 steps per day
 * 560 to 620 steps per month
 * 7300 to 7320 steps per year
  */
