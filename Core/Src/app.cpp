// main code here!!

#include <main.h>
#include <usart.h>
#include <gpio.h>
#include <adc.h>
#include <stdio.h>
#include <ukaikokko/ukaikokko.h>

using namespace ukaikokko;

InterruptBufferedUART<256, 256> pc(&huart2);
GPOutput led(DebugLED_GPIO_Port, DebugLED_Pin);
GPInput button(DebugButton_GPIO_Port, DebugButton_Pin);
uint32_t dma_buf[3];
AnalogInputDMA adc(&hadc1, dma_buf, sizeof(dma_buf) / sizeof(dma_buf[0]));

#ifdef __cplusplus
extern "C"
{
#endif

    // MARK:setup
    void user_setup(void)
    {
        led.write(1);

        setbuf(stdout, NULL);
        printf("sample_ADC\r\n");
        printf(__DATE__ "\r\n");
        printf(__TIME__ "\r\n");

        pc.begin();
        adc.start();

        led.write(0);
    }

    // MARK:loop
    void user_loop(void)
    {
        const uint32_t now = HAL_GetTick();
        static uint32_t pre = now;

        if (now - pre >= 10)
        {
            printf(">adc1:%d\r\n", (int)(adc.read(0) * 1000));
            printf(">adc2:%d\r\n", (int)(adc.read(1) * 1000));
            printf(">adc3:%d\r\n", (int)(adc.read(2) * 1000));

            pc.periodic();
            pre = now;
        }
    }

    // MARK:_write (for printf)
    int _write(int file, char* ptr, int len)
    {
        pc.write((uint8_t*)ptr, len);
        return len;
    }

    // MARK:HAL_UART_RxCpltCallback
    void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart)
    {
        pc.RxCplt(huart);
    }

    // MARK:HAL_UART_TxCpltCallback
    void HAL_UART_TxCpltCallback(UART_HandleTypeDef* huart)
    {
        pc.TxCplt(huart);
    }

#ifdef __cplusplus
}
#endif
