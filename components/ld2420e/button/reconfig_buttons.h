#pragma once

#include "esphome/components/button/button.h"
#include "../ld2420e.h"

namespace esphome
{
  namespace ld2420e
  {

    class LD2420EApplyConfigButton : public button::Button, public Parented<LD2420EComponent>
    {
    public:
      LD2420EApplyConfigButton() = default;

    protected:
      void press_action() override;
    };

    class LD2420ERevertConfigButton : public button::Button, public Parented<LD2420EComponent>
    {
    public:
      LD2420ERevertConfigButton() = default;

    protected:
      void press_action() override;
    };

    class LD2420ERestartModuleButton : public button::Button, public Parented<LD2420EComponent>
    {
    public:
      LD2420ERestartModuleButton() = default;

    protected:
      void press_action() override;
    };

    class LD2420EFactoryResetButton : public button::Button, public Parented<LD2420EComponent>
    {
    public:
      LD2420EFactoryResetButton() = default;

    protected:
      void press_action() override;
    };

  } // namespace ld2420e
} // namespace esphome
