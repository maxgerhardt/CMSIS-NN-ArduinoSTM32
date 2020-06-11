#include <Arduino.h>
#include <arm_math.h> /* needs DSP functions */
#include <arm_nnfunctions.h> /* CMSIS-NN */

void setup() {
	Serial.begin(115200);
}

void loop() {
	/* do some example computations */
	q7_t in_vec[4] = { -1, 0, 1, 2 };

	Serial.print("Input vector: ");
	for (auto& num : in_vec) {
		Serial.print(num);
		Serial.print(" ");
	}
	Serial.println();

	/*
	 * ReLU(x) = { x   if x >= 0
	 *             0   else
	 *            }
	 */
	arm_relu_q7(in_vec, 4);

	Serial.print("Transformed vector: ");
	for (auto& num : in_vec) {
		Serial.print(num);
		Serial.print(" ");
	}
	Serial.println();

	delay(1000);
}
