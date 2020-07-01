#include <Arduino.h>

// 用于测试在双核心情况下的任务执行
#define CORE_PRO_DELAY      1000
#define CORE_APP_DELAY      750

void core_pro(void *pvParameters) {
    while(1) {
        Serial.println("P.");
        vTaskDelay(CORE_PRO_DELAY);
    }
}

void core_app(void *pvParameters) {
    while(1) {
        Serial.println("A.");
        vTaskDelay(CORE_APP_DELAY);
    }
}

void setup() {
    Serial.begin(115200);

    xTaskCreatePinnedToCore(core_pro, "ProCoreTask", 1000, NULL, 0, NULL,  CORE_ID_PRO);
    xTaskCreatePinnedToCore(core_app, "AppCoreTask", 1000, NULL, 1, NULL,  CORE_ID_APP);

}

void loop() {
    // 保持空白
}
