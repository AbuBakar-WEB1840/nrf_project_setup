cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV(ZEPHYR BASE))
project(led_blink)
target_sources(app PRIVATE src/main.c)

# to include the file in build
# target_sources(app PRIVATE src/modul1.c)

# for conditional inlcusion in build (as mentioned in Kconfig)
target_sources_ifdef(CONFIG_MODULE_1 app PRIVATE src/modul1.c)