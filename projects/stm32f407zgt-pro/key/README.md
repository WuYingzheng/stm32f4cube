# Key experiment principle
1. Circuit diagram 
 ![picture](https://github.com/WuYingzheng/stm32f4cube/blob/master/Documentation/pictures/project/stm32f407/key/key.png)

# how to compile

    cd $STM32_SDK_DIR/projects/stm32f407zgt-pro/key/gcc
    make

# Experimental phenomena
Only key1 is supported:

* led0 & led1 will toggle while the key1 was pressed

# How to debug

* **Ozone**: if you have a jlink, you can use Ozone to make life easier. Using Ozone and config you Ozone project as follow:
 1. create a new project.
![picture](https://github.com/WuYingzheng/stm32f4cube/blob/master/Documentation/pictures/project/stm32f407/key/create_project.png)  
 2. choose the target device.
![picture](https://github.com/WuYingzheng/stm32f4cube/blob/master/Documentation/pictures/project/stm32f407/key/debug_target.png)
 3. setting the debug interface.
![picture](https://github.com/WuYingzheng/stm32f4cube/blob/master/Documentation/pictures/project/stm32f407/key/config_jlink.png)
 4. select you program file.
![picture](https://github.com/WuYingzheng/stm32f4cube/blob/master/Documentation/pictures/project/stm32f407/key/config_jlink.png)
 5. the finally page will shown as follow.
![picture](https://github.com/WuYingzheng/stm32f4cube/blob/master/Documentation/pictures/project/stm32f407/key/dubug_page.png)

* **openocd**: if you are familiar with gdb, it would be a good choise dubug the program with openocd

