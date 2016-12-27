#include "dsp_log.h"
#include "esc_interface.h"
#include <uart_esc.h>

UartEsc *esc;

int32 esc_interface_init_esc(uint32 model)
{
  esc = UartEsc::get_instance();
  esc->initialize(static_cast<esc_model_t>(model), "/dev/tty-2", 250000);
  for(int i = 0; i < 4; ++i)
    esc->reset_esc(i);
  return 0;
}

int32 esc_interface_print_data()
{
  LOG_MSG("Initialized: %d", esc->is_initialized());
  LOG_MSG("Min RPM: %d", esc->min_rpm());
  LOG_MSG("Max RPM: %d", esc->max_rpm());
  return 0;
}

int16 esc_interface_set_rpm(int16 rpm)
{
  int16_t rpms[4] = {rpm, rpm, rpm, rpm};
  return esc->send_rpms(rpms, 4);
}
