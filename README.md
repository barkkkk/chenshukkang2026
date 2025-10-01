# Way to solve the led change blinking when pushing the button
## 1.To solve the led blinking without using delay function
Recording the tick_last and tick_now;

Calculate the difference between tick_last and tick_now;

If the difference exceed the threshold, then execute the HAL_GPIO_TogglePin;


## 2.To solve led switch when pushing the button
Recording the PB2_state_now and PB2_state_last;

Determine whether the PB2_state_last is GPIO_PIN_RESET and PB2_state_now is GPIO_PIN_SET;

So that we can know the PB2 is pushed as it have a change;

Then give a bool to switch different color of led.
