cmake_minimum_required(VERSION 3.21)
if (${TOOLCHAIN_LANGUAGE} MATCHES "MikroC")
    project(lib_accel28 LANGUAGES MikroC)
else()
    project(lib_accel28 LANGUAGES C ASM)
endif()

if (NOT PROJECT_TYPE)
    set(PROJECT_TYPE "mikrosdk" CACHE STRING "" FORCE)
endif()

add_library(lib_accel28 STATIC
        src/accel28.c
        include/accel28.h
)
add_library(Click.Accel28  ALIAS lib_accel28)

if (${MCU_NAME} MATCHES "(^PIC18F(.+)[KQ]4[23]$)|(^PIC32(.+)$)")
    set(sample_mode_reg_case "SAMPLE_REG_CASE_1")
else()
    set(sample_mode_reg_case "SAMPLE_REG_CASE_2")
endif()

target_compile_definitions(lib_accel28 PUBLIC ${sample_mode_reg_case})


target_include_directories(lib_accel28 PUBLIC 
        include
)

find_package(MikroC.Core REQUIRED)
target_link_libraries(lib_accel28 PUBLIC MikroC.Core)
find_package(MikroSDK.Driver REQUIRED)
target_link_libraries(lib_accel28 PUBLIC MikroSDK.Driver)

