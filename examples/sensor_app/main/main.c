#include "esp_log.h"
#include "si7021.h"

#define TAG "SENSOR_APP"

void app_main(void) {
  int i2c_init_result;

  if ((i2c_init_result =
           si7021_init(I2C_NUM_0, GPIO_NUM_21, GPIO_NUM_22, GPIO_PULLUP_ENABLE,
                       GPIO_PULLUP_ENABLE) == 0)) {
    float temperature = si7021_read_temperature();
    ESP_LOGI(TAG, "[APP] read temperature %f", temperature);
  } else {
    ESP_LOGE(TAG, "[APP] init i2c error %d", i2c_init_result);
  }
}
