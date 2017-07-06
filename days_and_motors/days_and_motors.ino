#include <LiquidCrystal.h>

#include <AccelStepper.h>
#include <MultiStepper.h>


AccelStepper stepper1(AccelStepper::DRIVER, 18, 19); 
AccelStepper stepper2(AccelStepper::DRIVER, 16, 17); 
AccelStepper stepper3(AccelStepper::DRIVER, 14, 15);



//int sDay=1;
//int count=1;
//long yr = 2017;
long steps;

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


 
  date(); // when this is enabled it makes it so the motors do not run at the same time
          // possibly could use interupts()??

 
}

//jan, march, may, july, august,october, december == 31
//april, june, september, november == 30
//feb == 28 (29 leap year)
void date()
{
int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int count=1;
long yr = 2017;



while (1)
{
   int sDay=1;
    for (; sDay<=days[count-1]; sDay++)
    {
        lcd.setCursor(0,0);
        if (sDay < 10) lcd.print('0');
        lcd.print(sDay);
        lcd.print(" / ");
        if (count < 10) lcd.print('0');
        lcd.print(count);
        lcd.print(" / ");
        lcd.print(yr);
        delay(1000); // for 11.8 rps needs to break for .085 seconds
    }
    count++;
    if (count > 12)
    {
      yr++;
      count=1;
    }
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
