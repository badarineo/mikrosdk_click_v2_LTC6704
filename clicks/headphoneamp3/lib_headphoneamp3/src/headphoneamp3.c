/****************************************************************************
** Copyright (C) 2020 MikroElektronika d.o.o.
** Contact: https://www.mikroe.com/contact
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
** The above copyright notice and this permission notice shall be
** included in all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
** OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
** DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT
** OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
**  USE OR OTHER DEALINGS IN THE SOFTWARE.
****************************************************************************/

/*!
 * @file headphoneamp3.c
 * @brief Headphone AMP 3 Click Driver.
 */

#include "headphoneamp3.h"

void headphoneamp3_cfg_setup ( headphoneamp3_cfg_t *cfg ) 
{
    cfg->enp = HAL_PIN_NC;
    cfg->ena = HAL_PIN_NC;
}

err_t headphoneamp3_init ( headphoneamp3_t *ctx, headphoneamp3_cfg_t *cfg ) 
{
    err_t error_flag = HEADPHONEAMP3_OK;

    error_flag |= digital_out_init( &ctx->enp, cfg->enp );
    error_flag |= digital_out_init( &ctx->ena, cfg->ena );

    return error_flag;
}

void headphoneamp3_default_cfg ( headphoneamp3_t *ctx ) 
{
    headphoneamp3_enable_power( ctx, HEADPHONEAMP3_ENABLE );
    headphoneamp3_enable_amp( ctx, HEADPHONEAMP3_ENABLE );
}

void headphoneamp3_enable_power ( headphoneamp3_t *ctx, uint8_t state ) 
{
    if ( HEADPHONEAMP3_ENABLE == state )
    {
        digital_out_high( &ctx->enp );
    }
    else
    {
        digital_out_low( &ctx->enp );
    }
}

void headphoneamp3_enable_amp ( headphoneamp3_t *ctx, uint8_t state ) 
{
    if ( HEADPHONEAMP3_ENABLE == state )
    {
        digital_out_high( &ctx->ena );
    }
    else
    {
        digital_out_low( &ctx->ena );
    }
}

// ------------------------------------------------------------------------- END
