#include <stdio.h>
#include <unistd.h>
#include "esc_interface.h"

int main()
{
  esc_interface_init_esc(2);
  esc_interface_print_data();

#if 1
  const int16_t rpm = 5000;
  while(1)
  {
    printf("Setting RPM: %d\n", rpm);
    esc_interface_set_rpm(rpm);
    usleep(50000);
  }
#endif

  return 0;
}
