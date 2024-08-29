#include "operating_mode_select.h"
#include "esphome/core/helpers.h"
#include "esphome/core/log.h"

namespace esphome
{
  namespace ld2420e
  {

    static const char *const TAG = "LD2420E.select";

    void LD2420ESelect::control(const std::string &value)
    {
      this->publish_state(value);
      this->parent_->set_operating_mode(value);
    }

  } // namespace ld2420e
} // namespace esphome
