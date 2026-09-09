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
特に変更せず
