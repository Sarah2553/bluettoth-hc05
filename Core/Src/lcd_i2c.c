#include "lcd_i2c.h"
#include "string.h"

extern I2C_HandleTypeDef hi2c1; // Remplace par hi2c2 si tu utilises un autre

#define SLAVE_ADDRESS_LCD 0x4E // Adresse I2C = 0x27 << 1

I2C_HandleTypeDef *_lcd_i2c;

void lcd_send_cmd(char cmd) {
  char data_u, data_l;
  uint8_t data_t[4];

  data_u = (cmd & 0xf0);
  data_l = ((cmd << 4) & 0xf0);
  data_t[0] = data_u | 0x0C;
  data_t[1] = data_u | 0x08;
  data_t[2] = data_l | 0x0C;
  data_t[3] = data_l | 0x08;

  HAL_I2C_Master_Transmit(_lcd_i2c, SLAVE_ADDRESS_LCD, data_t, 4, 100);
}

void lcd_send_data(char data) {
  char data_u, data_l;
  uint8_t data_t[4];

  data_u = (data & 0xf0);
  data_l = ((data << 4) & 0xf0);
  data_t[0] = data_u | 0x0D;
  data_t[1] = data_u | 0x09;
  data_t[2] = data_l | 0x0D;
  data_t[3] = data_l | 0x09;

  HAL_I2C_Master_Transmit(_lcd_i2c, SLAVE_ADDRESS_LCD, data_t, 4, 100);
}

void lcd_clear(void) {
  lcd_send_cmd(0x01);
  HAL_Delay(2);
}

void lcd_put_cursor(uint8_t row, uint8_t col) {
  switch (row) {
    case 0:
      lcd_send_cmd(0x80 + col);
      break;
    case 1:
      lcd_send_cmd(0xC0 + col);
      break;
  }
}

void lcd_send_string(char *str) {
  while (*str) lcd_send_data(*str++);
}

void lcd_init(I2C_HandleTypeDef *hi2c) {
  _lcd_i2c = hi2c;

  HAL_Delay(50);
  lcd_send_cmd(0x30);
  HAL_Delay(5);
  lcd_send_cmd(0x30);
  HAL_Delay(1);
  lcd_send_cmd(0x30);
  HAL_Delay(10);
  lcd_send_cmd(0x20);  // 4 bit mode

  lcd_send_cmd(0x28);  // 2 lines, 5x7 matrix
  lcd_send_cmd(0x08);  // display off
  lcd_send_cmd(0x01);  // clear display
  HAL_Delay(2);
  lcd_send_cmd(0x06);  // entry mode
  lcd_send_cmd(0x0C);  // display on, cursor off
}
