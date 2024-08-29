#pragma once

#include "../ld2420e.h"
#include "esphome/components/sensor/sensor.h"

namespace esphome
{
  namespace ld2420e
  {

    class LD2420ESensor : public LD2420EListener, public Component, sensor::Sensor
    {
    public:
      void dump_config() override;
      void set_distance_sensor(sensor::Sensor *sensor) { this->distance_sensor_ = sensor; }
      void set_energy_sensor(int gate, sensor::Sensor *sensor) { this->energy_sensors_[gate] = sensor; }
      void on_distance(uint16_t distance) override
      {
        if (this->distance_sensor_ != nullptr)
        {
          if (this->distance_sensor_->get_state() != distance)
          {
            this->distance_sensor_->publish_state(distance);
          }
        }
      }
      void on_energy(uint16_t *gate_energy, size_t size) override
      {
        for (size_t active = 0; active < size; active++)
        {
          if (this->energy_sensors_[active] != nullptr)
          {
            this->energy_sensors_[active]->publish_state(gate_energy[active]);
          }
        }
      }

    protected:
      sensor::Sensor *distance_sensor_{nullptr};
      std::vector<sensor::Sensor *> energy_sensors_ = std::vector<sensor::Sensor *>(LD2420E_TOTAL_GATES);
    };

  } // namespace ld2420e
} // namespace esphome
