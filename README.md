# sample_ADC
## 概要

| 項目         | 仕様                      |
| ------------ | ------------------------- |
| 使用マイコン | NUCLEO_F446RE             |
| 使用IDE      | CubeIDE,VSCode,PlatformIO |
| 使用言語等   | C++,STM32CubeHAL          |

## ピン設定
| ピン     | 設定        | ラベル      | 備考           |
| -------- | ----------- | ----------- | -------------- |
| PA5      | GPIO_Output | DebugLED    | ラベルのみ変更 |
| PC13     | GPIO_EXTI13 | DebugButton | ラベルのみ変更 |
| PA0-WKUP | ADC1_IN0    |             |                |
| PA1      | ADC1_IN1    |             |                |
| PA4      | ADC1_IN4    |             |                |

## クロック設定
| 項目 | 内容 | 備考 |
| ---- | ---- | ---- |
|      |      |      |

## 変更した設定
### Project Manager
Code Generator, Generated files\
✅Generate peripheral initialization as a pair of '.c/.h' files per peripheral

### ADC1
✅IN0\
✅IN1\
✅IN4
#### Parameter Settings
##### ADC_Settings
✅Scan Conversion Mode\
✅Continuous Conversion Mode\
✅DMA Continuous Requests
##### ADC_Regular_Conversion_Mode
Number of Conversion: 3
- Rank 1
- - Channel 0
- - Sampling Time: 480 Cycles
- Rank 2
- - Channel 1
- - Sampling Time: 480 Cycles
- Rank 3
- - Channel 4
- - Sampling Time: 480 Cycles
#### DMA Settings
Add→ADC1\
Mode: Circular\
Data Width: Word\
Increment Address Memory: ✅

### USART2
✅USART2 global interrupt

## memo
サンプリングタイムはできるだけ長い方がいい気がする\
サンプル&ホールド型
