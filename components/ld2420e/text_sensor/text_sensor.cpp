#include "text_sensor.h"
#include "esphome/core/helpers.h"
#include "esphome/core/log.h"

namespace esphome
{
  namespace ld2420e
  {

    static const char *const TAG = "LD2420E.text_sensor";

    void LD2420ETextSensor::dump_config()
    {
      ESP_LOGCONFIG(TAG, "LD2420E TextSensor:");
      LOG_TEXT_SENSOR("  ", "Firmware", this->fw_version_text_sensor_);
    }

  } // namespace ld2420e
} // namespace esphome
