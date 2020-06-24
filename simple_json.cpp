#include "simple_json.h"
#include <stdint.h>
#include <string.h>
#include <avr/pgmspace.h>


//This function enquote and concate string from flash memory. Saves RAM
char *enquote(char *dest, const  __FlashStringHelper  *source)
{
  uint8_t len = strlen_P((const char*)source);
  char *temp = dest;
  *temp = '\"';
  temp++;
  strncpy_P(temp, (const char*)source, len);
  temp = temp + len;
  *temp = '\"';
  temp++;
  *temp = ':';
  temp++;
  return temp;
}
//This function enquote string from RAM directly. so source string consumes RAM
char *enquote(char *dest, const char *source)
{
  uint8_t len = strlen(source);
  char *temp = dest;
  *temp = '\"';
  temp++;
  strncat(temp, source, len);
  temp = temp + len;
  *temp = '\"';
  temp++;
  *temp = ':';
  temp++;
  return temp;
}

char *add_int(char *dest, int value)
{
  char *temp = dest;
  char buffer[12];
  itoa(value, buffer, 10);
  uint8_t len = strlen(buffer);
  strncat(temp, buffer, len);
  temp = temp + len;
  *temp = ',';
  temp++;
  return temp;
}

char *add_long(char *dest, long value)
{
  char *temp = dest;
  char buffer[12];
  ltoa(value, buffer, 10);
  uint8_t len = strlen(buffer);
  strncat(temp, buffer, len);
  temp = temp + len;
  *temp = ',';
  temp++;
  return temp;
}

char *add_float(char *dest, float value)
{
  char *temp = dest;
  char buffer[12];
  dtostrf(value,0,2,buffer);
  uint8_t len = strlen(buffer);
  strncat(temp, buffer, len);
  temp = temp + len;
  *temp = ',';
  temp++;
  return temp;
}
char *add_str(char *dest, const char *source)
{
  uint8_t len = strlen(source);
  char *temp = dest;
  *temp = '\"';
  temp++;
  strncat(temp, source, len);
  temp = temp + len;
  *temp = '\"';
  temp++;
  *temp= ',';
  temp++;
  return temp;
}

