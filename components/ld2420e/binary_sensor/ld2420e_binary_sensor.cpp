#include "ld2420e_binary_sensor.h"
#include "esphome/core/helpers.h"
#include "esphome/core/log.h"

namespace esphome
{
  namespace ld2420e
  {

    static const char *const TAG = "LD2420E.binary_sensor";

    void LD2420EBinarySensor::dump_config()
    {
      ESP_LOGCONFIG(TAG, "LD2420E BinarySensor:");
      LOG_BINARY_SENSOR("  ", "Presence", this->presence_bsensor_);
    }

  } // namespace ld2420e
} // namespace esphome
