#include <Wire.h>
#include <Adafruit_MCP4725.h>

#define MPU_ADDR 0x68

Adafruit_MCP4725 dac;

int16_t accY;
float tiltRaw;
float tiltFiltered = 0;

// ---- TUNING (SAFE VALUES) ----
const float DEADZONE_DEG  = 6.0;
const float MAX_TILT_DEG  = 20.0;

// DAC values:
// MCP4725 = 12-bit (0–4095)
// Typical throttle:
// ~0.9V = idle
// ~1.2–1.4V = very slow
const int DAC_IDLE = 750;   // ~0.9V
const int DAC_MAX  = 1150;  // ~1.35V (VERY SLOW)

const float FILTER_ALPHA = 0.15;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // MPU wake
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  // DAC init
  dac.begin(0x60);   // default MCP4725 address
  dac.setVoltage(DAC_IDLE, false); // SAFE idle output
}

void loop() {
  // ---- Read MPU Y accel ----
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3D);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 2, true);
  accY = Wire.read() << 8 | Wire.read();

  // Rough tilt
  tiltRaw = accY / 16384.0 * 90.0;

  // Low-pass filter
  tiltFiltered = FILTER_ALPHA * tiltRaw +
                 (1.0 - FILTER_ALPHA) * tiltFiltered;

  float tiltUse = tiltFiltered;

  // Deadzone + clamp
  if (tiltUse < DEADZONE_DEG) tiltUse = 0;
  if (tiltUse > MAX_TILT_DEG) tiltUse = MAX_TILT_DEG;

  int dacValue;

  if (tiltUse == 0) {
    dacValue = DAC_IDLE;
  } else {
    dacValue = map((int)tiltUse,
                   (int)DEADZONE_DEG,
                   (int)MAX_TILT_DEG,
                   DAC_IDLE,
                   DAC_MAX);
  }

  dacValue = constrain(dacValue, DAC_IDLE, DAC_MAX);
  dac.setVoltage(dacValue, false);

  // Debug
  Serial.print("TiltRaw: ");
  Serial.print(tiltRaw);
  Serial.print(" | TiltFilt: ");
  Serial.print(tiltFiltered);
  Serial.print(" | DAC: ");
  Serial.println(dacValue);

  delay(20);
}