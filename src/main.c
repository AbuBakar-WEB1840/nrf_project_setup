#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/drivers/gpio.h>
// #include "modul1.h"

#ifdef CONFIG_MODULE_1
    #include "modul1.h"
#endif

// led
#define led_1 DT_ALIAS(led0)
static struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET(led_1, gpios);

// button
#define btn_1 DT_ALIAS(sw0)
static struct gpio_dt_spec sw0 = GPIO_DT_SPEC_GET(btn_1, gpios);


int main(void){
    if (!gpio_is_ready_dt(&led1)){
        return 0;
    }
    if (!gpio_is_ready_dt(&sw0)){
        return 0;
    }

    // led configuration
    gpio_pin_configure_dt(&led1, GPIO_OUTPUT);
    gpio_pin_set_dt(&led1, 0);

    // button configuration
    gpio_pin_configure_dt(&sw0, GPIO_INPUT);

    int a = 12; int b = 13;

    while (1)
    {   
        int val = gpio_pin_get_dt(&sw0);

        if (val == 1){
            // gpio_pin_toggle_dt(&led1);
            gpio_pin_set_dt(&led1, 1);
            k_msleep(2000);
        }
        gpio_pin_set_dt(&led1, 0);

        // using modu1 function
        #ifdef CONFIG_MODULE_1
            printk("%d + %d: %d\n", a, b, add(a, b));
        #endif
    }
    
}