# 基于ESP32-S3的高安全性宿舍智能门锁设计

编译环境：ESP-IDF v5.3.1

## 主要特性
1. 兼容宿舍门锁：采用串口总线舵机驱动开锁
2. 高安全性：利用ESP32-S3的eFuse、世界控制器等特性实现高安全性
3. 人机交互：利用串口屏、喇叭实现人机交互，针对不同的事件播放不同音效
4. 开锁方式：支持指纹识别和密码识别

## 文档结构

想好再写，又挖了个大坑，不知道什么时候能填完。

```
├── CMakeLists.txt
├── main
│   ├── CMakeLists.txt
│   └── main.c
└── README.md                  This is the file you are currently reading
```
