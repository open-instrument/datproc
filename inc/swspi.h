/* 
 * File:   alspi.h
 * Author: apleilx
 */

#ifndef SPI_SW_HALL_H
#define SPI_SW_HALL_H

#include "stdint.h"

#ifdef __cplusplus
extern "C"
{
#endif

  typedef struct
  {
    uint8_t speed;
    uint8_t bits; //0-31 位数=bits+1
  } spi_info_type;

  typedef const struct
  {
    void (*cs_out_high)(void);
    void (*cs_out_low)(void);

    void (*sck_out_high)(void);
    void (*sck_out_low)(void);

    void (*mosi_out_high)(void);
    void (*mosi_out_low)(void);

    uint8_t (*miso_st_get)(void);

    void (*insert_clks)(void); //低速模式时时钟时钟宽度

    spi_info_type *info;
  } spi_cfg_type;

  void sw_spi_init(spi_cfg_type *spi);
  
  //MSB
  uint32_t sw_spi_rw(spi_cfg_type *spi, uint32_t wdata);
  //LSB
  uint32_t sw_lsbspi_rw(spi_cfg_type *spi, uint32_t wdata);

  
  void sw_spi_cs(spi_cfg_type *spi, uint8_t cs);
  void sw_spi_speed(spi_cfg_type *spi, uint8_t high1_or_low0);

#ifdef __cplusplus
}
#endif

#endif /* SPI_SW_HALL_H */
