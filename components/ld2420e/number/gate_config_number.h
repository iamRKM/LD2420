#pragma once

#include "esphome/components/number/number.h"
#include "../ld2420e.h"

namespace esphome
{
  namespace ld2420e
  {

    class LD2420ETimeoutNumber : public number::Number, public Parented<LD2420EComponent>
    {
    public:
      LD2420ETimeoutNumber() = default;

    protected:
      void control(float timeout) override;
    };

    class LD2420EMinDistanceNumber : public number::Number, public Parented<LD2420EComponent>
    {
    public:
      LD2420EMinDistanceNumber() = default;

    protected:
      void control(float min_gate) override;
    };

    class LD2420EMaxDistanceNumber : public number::Number, public Parented<LD2420EComponent>
    {
    public:
      LD2420EMaxDistanceNumber() = default;

    protected:
      void control(float max_gate) override;
    };

    class LD2420EGateSelectNumber : public number::Number, public Parented<LD2420EComponent>
    {
    public:
      LD2420EGateSelectNumber() = default;

    protected:
      void control(float gate_select) override;
    };

    class LD2420EMoveSensFactorNumber : public number::Number, public Parented<LD2420EComponent>
    {
    public:
      LD2420EMoveSensFactorNumber() = default;

    protected:
      void control(float move_factor) override;
    };

    class LD2420EStillSensFactorNumber : public number::Number, public Parented<LD2420EComponent>
    {
    public:
      LD2420EStillSensFactorNumber() = default;

    protected:
      void control(float still_factor) override;
    };

    class LD2420EStillThresholdNumbers : public number::Number, public Parented<LD2420EComponent>
    {
    public:
      LD2420EStillThresholdNumbers() = default;
      LD2420EStillThresholdNumbers(uint8_t gate);

    protected:
      uint8_t gate_;
      void control(float still_threshold) override;
    };

    class LD2420EMoveThresholdNumbers : public number::Number, public Parented<LD2420EComponent>
    {
    public:
      LD2420EMoveThresholdNumbers() = default;
      LD2420EMoveThresholdNumbers(uint8_t gate);

    protected:
      uint8_t gate_;
      void control(float move_threshold) override;
    };

  } // namespace ld2420e
} // namespace esphome
