# Key experiment principle

 

# how to compile

    cd $STM32_SDK_DIR/projects/stm32f407zgt-pro/key/gcc
    make

# Experimental phenomena
Only key1 is supported:

* led0 & led1 will toggle while the key1 was pressed

# How to debug

* if you have a jlink, you can use **Ozone** to make life easier. Using Ozone and config you Ozone project as follow:
1. create a new project

2. choose the target device

3. setting the debug interface

4. select you program file

5. the finally page will shown as follow:

* if you are familiar with gdb, it would be a good choise dubug the program with openocd

