#include "ld2420e_sensor.h"
#include "esphome/core/helpers.h"
#include "esphome/core/log.h"

namespace esphome
{
  namespace ld2420e
  {

    static const char *const TAG = "LD2420E.sensor";

    void LD2420ESensor::dump_config()
    {
      ESP_LOGCONFIG(TAG, "LD2420E Sensor:");
      LOG_SENSOR("  ", "Distance", this->distance_sensor_);
      for (size_t x = 0; x < 16; x++)
      {
        LOG_SENSOR("  ", "Energy " + char(x), this->energy_sensors_[x]);
      }
    }

  } // namespace ld2420e
} // namespace esphome
