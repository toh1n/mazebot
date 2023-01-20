#define portOfPin(P) \
  (((P) >= 0 && (P) < 8) ? &PORTD : (((P) > 7 && (P) < 14) ? &PORTB : &PORTC))
#define ddrOfPin(P) \
  (((P) >= 0 && (P) < 8) ? &DDRD : (((P) > 7 && (P) < 14) ? &DDRB : &DDRC))
#define pinOfPin(P) \
  (((P) >= 0 && (P) < 8) ? &PIND : (((P) > 7 && (P) < 14) ? &PINB : &PINC))
#define pinIndex(P) ((uint8_t)(P > 13 ? P - 14 : P & 7))
#define pinMask(P) ((uint8_t)(1 << pinIndex(P)))
#define pinAsInput(P) *(ddrOfPin(P)) &= ~pinMask(P)
#define pinAsInputPullUp(P) \
  *(ddrOfPin(P)) &= ~pinMask(P); \
  digitalHigh(P)
#define pinAsOutput(P) *(ddrOfPin(P)) |= pinMask(P)
#define digitalLow(P) *(portOfPin(P)) &= ~pinMask(P)
#define digitalHigh(P) *(portOfPin(P)) |= pinMask(P)
#define isHigh(P) ((*(pinOfPin(P)) & pinMask(P)) > 0)
#define isLow(P) ((*(pinOfPin(P)) & pinMask(P)) == 0)
#define digitalState(P) ((uint8_t)isHigh(P))

#define rightMotor1 3
#define rightMotor2 2
#define rightMotorPWM 9
#define leftMotor1 4
#define leftMotor2 5
#define leftMotorPWM 10
#define threshold 700
#define led 13
#define buzzer 11
#define button 12

#define Kp 0.1
#define Kd 0.5
#define Ki .01
#define MaxSpeed 145
int leftMaxSpeed = 115;
int rightMaxSpeed = 200;
int speedturnL = 60;
int speedturnR = 100;
#define speedturn 100  // edit this to determine the speed during taking turns
int lastError = 0;

#define N_SENS 8
int sensor_values[N_SENS];
int sens_max[N_SENS] = { 869, 780, 984, 985, 953, 998, 937, 888 }; // Maximum value from each sensor
int sens_min[N_SENS] = { 34, 32, 38, 52, 45, 52, 37, 35 }; // Minimum value from each sensor
int sensor[N_SENS] = { 7, 6, 5, 4, 3, 2, 1, 0 }; // Sensor pins on arduino
int lastPosition = 0;
unsigned int line_position = 0;

char path[100] = "";
char reversePath[100] = "";
unsigned char dir;
unsigned char path_length = 0;
unsigned char found_left = 0;
unsigned char found_straight = 0;
unsigned char found_right = 0;
