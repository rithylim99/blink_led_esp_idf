#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/gpio.h"

#define LED_PIN (GPIO_NUM_15)

void gpio_init(void){
    gpio_config_t io_conf = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = 1ULL << LED_PIN,
        .intr_type = GPIO_INTR_DISABLE,
        .pull_down_en = 0x0,
        .pull_up_en = 0x0
    };
    gpio_config(&io_conf);
}

void app_main(void)
{
    gpio_init();
    for(;;){
        gpio_set_level(LED_PIN, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        gpio_set_level(LED_PIN, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }

}
