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

#define rightMotor1 5
#define rightMotor2 4
#define rightMotorPWM 10
#define leftMotor1 3
#define leftMotor2 2
#define leftMotorPWM 9

int threshold = 500;
int turnThreshold = 450;
#define led 13
#define buzzer 11
#define button 12

#define getBackToStartDelay 80

#define Kp 0.13
#define Kd 0.65
#define Ki .01
int MaxSpeed = 145;
int leftMaxSpeed = 200;
int rightMaxSpeed = 200;
int speedturnL = 60;
int speedturnR = 60;
int lastError = 0;

#define N_SENS 8
int sensor_values[N_SENS];
int sensorValueCal[N_SENS];
int sens_max[N_SENS] = { 992, 989, 988, 994, 996, 997, 988, 987 };
int sens_min[N_SENS] = { 614, 681, 653, 550, 516, 638, 630, 621 };
int sensor[N_SENS] = { 7, 6, 5, 4, 3, 2, 1, 0 };
int lastPosition = 0;
unsigned int line_position = 0;

char path[100] = "";
char reversePath[100] = "";
unsigned char dir;
unsigned char path_length = 0;
