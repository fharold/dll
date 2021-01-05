#define PWM_OUTPUT_PIN 3
#define ON_OFF_BUTTON_PIN 2
#define DOWN_BUTTON_PIN 4
#define UP_BUTTON_PIN 7
#define STATUS_LED_0_PIN 5
#define STATUS_LED_1_PIN 6
#define STATUS_LED_2_PIN 9
#define STATUS_LED_3_PIN 10
#define STATUS_LED_4_PIN 11

#define MAX_DUTY_CYCLE 255
#define MIN_DUTY_CYCLE 1
#define OFF_LED_DUTY_CYCLE 5

int enabled = false;
int dutyCycle = MIN_DUTY_CYCLE;

void setup() {
  // put your setup code here, to run once:
  TCCR2B = TCCR2B & B11111000 | B00000001; // for PWM frequency of 31372.55 Hz
  pinMode(PWM_OUTPUT_PIN, OUTPUT);         //PWM output
  pinMode(ON_OFF_BUTTON_PIN, INPUT_PULLUP);   //On off button
  pinMode(DOWN_BUTTON_PIN, INPUT_PULLUP);   //Down button
  pinMode(UP_BUTTON_PIN, INPUT_PULLUP);   //Up button
  pinMode(STATUS_LED_0_PIN, OUTPUT);        //ON OFF LED
  pinMode(STATUS_LED_1_PIN, OUTPUT);        //ON OFF LED
  pinMode(STATUS_LED_2_PIN, OUTPUT);        //ON OFF LED
  pinMode(STATUS_LED_3_PIN, OUTPUT);        //ON OFF LED
  pinMode(STATUS_LED_4_PIN, OUTPUT);        //ON OFF LED
}

bool isOnOffButtonPressed() {
  return digitalRead(ON_OFF_BUTTON_PIN) == LOW;
}

void setStatusLedDutyCycle(int pin, int ledDutyCycle) {
  
  if (enabled) {
    if (ledDutyCycle < 0) {
      ledDutyCycle = 0;
    }
    analogWrite(pin, min(ledDutyCycle, 255));
  } else {
    analogWrite(pin, OFF_LED_DUTY_CYCLE);
  }
}


void loop() {  
  int upBtnStatus = digitalRead(UP_BUTTON_PIN);
  int downBtnStatus = digitalRead(DOWN_BUTTON_PIN);
  
  if (isOnOffButtonPressed()) {
    enabled = !enabled;
    while (isOnOffButtonPressed()) {};
    return;
  }
  
  if (upBtnStatus == LOW) {
    enabled = true;
    dutyCycle = dutyCycle < MAX_DUTY_CYCLE - 1 ? dutyCycle + 1 : MAX_DUTY_CYCLE - 1;
  }

  if (downBtnStatus == LOW) {
    enabled = true;
    dutyCycle = dutyCycle > MIN_DUTY_CYCLE ? dutyCycle - 1 : MIN_DUTY_CYCLE;
  }

  analogWrite(3, enabled ? dutyCycle : 0);
  setStatusLedDutyCycle(STATUS_LED_0_PIN, min(dutyCycle - 204, 51) * 5);
  setStatusLedDutyCycle(STATUS_LED_1_PIN, min(dutyCycle - 153, 51) * 5);
  setStatusLedDutyCycle(STATUS_LED_2_PIN, min(dutyCycle - 102, 51) * 5);
  setStatusLedDutyCycle(STATUS_LED_3_PIN, min(dutyCycle - 51, 51) * 5);
  setStatusLedDutyCycle(STATUS_LED_4_PIN, max(min(dutyCycle, 51) * 5, OFF_LED_DUTY_CYCLE));

  delay(10);
}
