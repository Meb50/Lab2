/* waveform generation-Method 1*/ 
/* app.overlay*/ 
/ { 
    bus_outputs { //parent node, contain 2 led
            compatible = "gpio-leds"; //tells zephyr they gpio controlled

            bus_lsb: led_1 { 
                gpios = <&gpio0 29 GPIO_ACTIVE_HIGH>; //gpio controller at 0, gpio pin 29, turns led on
                label = "Bus LSB"; 
            }; 

            bus_msb: led_2 { 
                gpios = <&gpio1 23 GPIO_ACTIVE_HIGH>; 
                label = "Bus MSB"; 
                }; 
            }; 
    };