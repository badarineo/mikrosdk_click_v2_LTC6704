/*!
 * @file main.c
 * @brief Accel 21 Click example
 *
 * # Description
 * This library contains API for Accel 21 Click driver.
 * The library initializes and defines the I2C or SPI bus drivers 
 * to write and read data from registers. 
 * The library also includes a function for reading X-axis, Y-axis, and Z-axis data. 
 *
 * The demo application is composed of two sections :
 *
 * ## Application Init
 * The initialization of I2C or SPI module, log UART, and additional pins. 
 * After the driver init, the app executes a default configuration,
 * checks communication and device ID. 
 *
 * ## Application Task
 * This example demonstrates the use of the Accel 21 Click board™.
 * Measures and displays acceleration data for X-axis, Y-axis, and Z-axis. 
 * Results are being sent to the UART Terminal, where you can track their changes.
 *
 * @author Nenad Filipovic
 *
 */

#include "board.h"
#include "log.h"
#include "accel21.h"

static accel21_t accel21;
static log_t logger;

void application_init ( void )
{
    log_cfg_t log_cfg;          /**< Logger config object. */
    accel21_cfg_t accel21_cfg;  /**< Click config object. */

    /** 
     * Logger initialization.
     * Default baud rate: 115200
     * Default log level: LOG_LEVEL_DEBUG
     * @note If USB_UART_RX and USB_UART_TX 
     * are defined as HAL_PIN_NC, you will 
     * need to define them manually for log to work. 
     * See @b LOG_MAP_USB_UART macro definition for detailed explanation.
     */
    LOG_MAP_USB_UART( log_cfg );
    log_init( &logger, &log_cfg );
    log_info( &logger, " Application Init " );

    // Click initialization.
    accel21_cfg_setup( &accel21_cfg );
    ACCEL21_MAP_MIKROBUS( accel21_cfg, MIKROBUS_1 );
    err_t init_flag = accel21_init( &accel21, &accel21_cfg );
    if ( ( I2C_MASTER_ERROR == init_flag ) || ( SPI_MASTER_ERROR == init_flag ) )
    {
        log_error( &logger, " Communication init." );
        for ( ; ; );
    }

    if ( ACCEL21_ERROR == accel21_default_cfg ( &accel21 ) )
    {
        log_error( &logger, " Default configuration." );
        for ( ; ; );
    }
    
    if ( ACCEL21_ERROR == accel21_check_id ( &accel21 ) )
    {
        log_printf( &logger, " Communication ERROR \r\n" );
        for ( ; ; );
    }

    log_info( &logger, " Application Task " );
    log_printf( &logger, "------------------------\r\n" );
    log_printf( &logger, "       Accel Data       \r\n" );
    log_printf( &logger, "------------------------\r\n" );
    Delay_ms( 100 ); 
}

void application_task ( void )
{
    static accel21_axis_t axis;
    accel21_get_axis( &accel21, &axis );
    log_printf( &logger, "\tX : %d \r\n\tY : %d \r\n\tZ : %d \r\n", axis.x, axis.y, axis.z );
    log_printf( &logger, "------------------------\r\n" );
    Delay_ms( 1000 );
}

void main ( void )
{
    application_init( );

    for ( ; ; )
    {
        application_task( );
    }
}

// ------------------------------------------------------------------------ END
