# buildroot_2024_for_LVGL_with_LinuxFB_of_MA35H0

## Intro
This Buildroot can be used to port Embedded Linux with LVGL v9.2(framebuffer-based) to the Nuvoton MA35H0 evaluation board.

## Development environment
### Hardware
|N|Name|Description|Note|
|---|---|---|---|
|1|NuMaker-HMI-MA35H0-A1|MA35H0 Evaluation board|Version 1.0|

### Software
|N|Name|Description|Note|
|---|---|---|---|
|1|Lv_port_linux|LVGL Graphics library|Version 9.2|

## How to build
1) Run 'make numaker_hmi_ma35h04f70_for_lvgl_defconfig'.
2) Run 'make'.
3) Do download output/images/pack-core-image-buildroot-ma35h0-hmi-128m-sdcard.bin file to MA35H0 EVB with NuWriter.

### Results
<img width="975" height="710" alt="image" src="https://github.com/user-attachments/assets/02e34c1d-368f-479b-835a-067beb249ff0" />

## Thanks to
https://github.com/OpenNuvoton/buildroot_2024<br />
https://github.com/lvgl/lv_port_linux
