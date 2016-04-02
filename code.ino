int motoreDestra;
int motoreSinistra;
 
void setup() {
  Serial.begin(9600);
}
 
loop() {
  int x_axis = analogRead(0); // value of X-Axis joystick (0-1023, 512 = centered)
  int y_axis = analogRead(1); // value of Y-Axis joystick (0-1023, 512 = centered)

// Map values from potentiometers to a smaller range for the PWM motor controllers (0-255)


       
        if (x_axis > 500 & x_axis < 524)
         { 
           motoreDestra = map(y_axis, 0, 1023, 0, 255);
           motoreSinistra = map(y_axis, 0, 1023, 0, 255);
         }

        if (x_axis < 500 or x_axis > 524)
         {
                 if (y_axis > 500 & y_axis < 524)
                  {                        
                    motoreDestra = map(x_axis, 1023, 0, 0, 255);
                    motoreSinistra = map(x_axis, 0, 1023, 0, 255);
                  }
                 if (y_axis > 524) 
                  {
                    motoreDestra = (map(x_axis, 1023, 0, 0, 255)) + (map(y_axis, 0, 1023, 0, 255));
                       if (motoreDestra > 255) motoreDestra = 255;
                    motoreSinistra = (map(x_axis, 0, 1023, 0, 255)) + (map(y_axis, 524, 1023, 0, 127));
                       if (motoreSinistra > 255) motoreSinistra = 255;
                  }
                 if (y_axis < 500) 
                  {
                    motoreDestra = (map(x_axis, 1023, 0, 0, 255)) - (map(y_axis, 0, 1023, 0, 255));
                       if (motoreDestra < 0) motoreDestra = 0;
                    motoreSinistra = (map(x_axis, 0, 1023, 0, 255)) + (map(y_axis, 524, 1023, 0, 127));
                       if (motoreSinistra > 255) motoreSinistra = 255;
                  }

         }
       
     
   
}

