#pragma once

#include "../ld2420e.h"
#include "esphome/components/select/select.h"

namespace esphome
{
  namespace ld2420e
  {

    class LD2420ESelect : public Component, public select::Select, public Parented<LD2420EComponent>
    {
    public:
      LD2420ESelect() = default;

    protected:
      void control(const std::string &value) override;
    };

  } // namespace ld2420e
} // namespace esphome
