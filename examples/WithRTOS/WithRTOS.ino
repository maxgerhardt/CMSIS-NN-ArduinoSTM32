#include <Arduino.h>
#include <cmsis_os2.h> /* needs RTOS2 */
#include <arm_math.h> /* needs DSP functions */
#include <arm_nnfunctions.h> /* CMSIS-NN */

void blinky_led_thread(void *startArg) {
	(void) startArg;
	while (true) {
		digitalWrite(LED_BUILTIN, HIGH);
		osDelay(500);
		digitalWrite(LED_BUILTIN, LOW);
		osDelay(500);
	}
}

void do_nn_computations(void* args) {
	while (true) {
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

		osDelay(1000);
	}
}

void setup() {
	Serial.begin(115200);
	pinMode(LED_BUILTIN, OUTPUT);

	osKernelInitialize();
	osThreadNew(blinky_led_thread, NULL, NULL);
	osThreadNew(do_nn_computations, NULL, NULL);

	if (osKernelGetState() == osKernelReady) {
		Serial.println("Starting CMSIS-RTOS2 kernel.");
		osKernelStart();
	}
	while (true) {
		Serial.println("Should never reach!");
		Serial.println("Kernel state is " + String((int) osKernelGetState()));
		Serial.flush();
		delay(500);
	}
}

void loop() { /* never reached */ }
