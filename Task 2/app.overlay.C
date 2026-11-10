/* read a switch and control a light*/ 
/*app.overlay*/ 
 /{    external_leds //create node to group external leds
        { 
            compatible = "gpio-leds"; //identify node as gpio-controlled led device
            external_led: led_4 { //node label reffered by c programme and name of led node
            gpios = <&gpio0 29 GPIO_ACTIVE_HIGH>; //selects gpio controller 0, and selects gpio pin 29 //active high part - led turns on when gpio output high
            label = "External LED";  //led get descript name
        };
    }; 

    external_switches { 
    compatible = "gpio-keys"; 
    external_switch: switch_0 { 
        gpios = <&gpio1 23 (GPIO_PULL_UP | GPIO_ACTIVE_LOW)>; //enables internal pull up resistors, switch active when gpio reads low
        label = "External Switch"; 
        }; 
    };
};

//devicetree overlay file specifies application-specific
//changes applied to base devicetree for
//board you build .purpose of devicetree overlays
//configure something about hardware used by application.
//allows zephyr to identify which pins are
// connected to led and switch