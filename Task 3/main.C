/* waveform generation-Method 1*/ 
/*main.c*/

#include <zephyr/kernel.h> 
#include <zephyr/drivers/gpio.h> 

#define LSB_NODE DT_NODELABEL(bus_lsb) // identify lsb output
#define MSB_NODE DT_NODELABEL(bus_msb) //identify msb output
//most and least significant

static const struct gpio_dt_spec lsb = GPIO_DT_SPEC_GET(LSB_NODE, gpios); //lsb controls LSB gpio
static const struct gpio_dt_spec msb = GPIO_DT_SPEC_GET(MSB_NODE, gpios); 

static void write_bus(uint8_t value) //take numb and split into two bits
{      
    gpio_pin_set_dt(&lsb, (value >> 0) & 1); //don't shift numb, extract rightmost bit
    gpio_pin_set_dt(&msb, (value >> 1) & 1);  //same thing but does shift position right by 1
} 


int main(void) 
{   
    int count; 
    uint8_t values[10] = { 0x0, 0x2, 0x0, 0x0, 0x0, 0x1, 0x3, 0x1, 0x0, 0x0 }; //creates array contains 10 numbers, written hexidecimal
    
    gpio_pin_configure_dt(&lsb, GPIO_OUTPUT_INACTIVE); 
    gpio_pin_configure_dt(&msb, GPIO_OUTPUT_INACTIVE); 
    //both pins outputs, both set low

    while (1) 
    { 
        for (count = 0; count < 10; count++) //starts 0, increase 1, stop at 10
        { 
            write_bus(values[count]); //sends array value to two gpio pins
            k_sleep(K_MSEC(10)); //10ms delay
        } 
    } 
return 0; 
}

//1 sequence = 100ms
//flash repeating pattern display 2 bit nonbinary numbers
