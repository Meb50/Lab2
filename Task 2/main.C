/* read a switch and control a light*/ 
/* main.c */ 

#include <zephyr/kernel.h> //provides kernel functions - allows use of k_sleep
#include <zephyr/drivers/gpio.h> //provides GPIO functions to control pins

#define SWITCH_NODE DT_NODELABEL(external_switch) //define switch and led refferences     
#define LED_NODE DT_NODELABEL(external_led) //device tree must contain nodes labelled external_switch etc //takes info from app overlay

static const struct gpio_dt_spec switchinput = GPIO_DT_SPEC_GET(SWITCH_NODE, gpios);  //switchinput stores switch gpio info //retrieves and stores info from overlay
//identifies what component to retrieve info from
static const struct gpio_dt_spec light = GPIO_DT_SPEC_GET(LED_NODE, gpios); // light stores gpio info for led //pointer to gpio device controlling pin, gets pin number and flags from device tree


int main(void) 
    {  
        gpio_pin_configure_dt(&switchinput, GPIO_INPUT); //configures switch pin as input
        gpio_pin_configure_dt(&light, GPIO_OUTPUT_INACTIVE); //end part of this configures led pin as output, off
        while (1) { //continuous execution of code in loop
            int switch_value = gpio_pin_get_dt(&switchinput); //reads current switch state
            if (switch_value == 1) //active gpio when 1
            { 
                gpio_pin_set_dt(&light, 1); 
            }
         
            else 
            { 
                gpio_pin_set_dt(&light, 0); //inactive gpio when 0
            } 
        k_sleep(K_MSEC(10)); //adds 10 ms delay to pause programme before checking switch again
    } 
return 0; 
}
//A source code file.
//tree-like data structure used to describe the hardware of a computer or embedded system
//Each node in the tree represents a device or a logical grouping of devices, and properties within nodes provide key-value information about the device