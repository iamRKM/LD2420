# ESPHome Hi-Link HKL-LD2420 Extended

This external [ESPHome](https://esphome.io) component extends the functionalities of the [Hi-Link HKL-LD2420](https://www.hlktech.net/index.php?id=1150) Human presence sensor of ESPHome.

In addition to the standard moving distance sensor, it adds one energy sensor per gate, from `gate_energy_0` to `gate_energy_15`.

These sensors can be used to fine tune gates' thresholds. 

Note: all references to `ld2420` sensor have been renamed as `ld2420e`.

## Sample configuration

```yaml
uart:
  id: ld2420e_uart
  tx_pin: GPIO17
  rx_pin: GPIO16
  baud_rate: 115200
  parity: NONE
  stop_bits: 1

ld2420e:

select:
  - platform: ld2420e
    operating_mode:
      name: Operating Mode

sensor:
  - platform: ld2420e
    gate_energy_0:
      name : Gate 0 Energy
    gate_energy_1:
      name : Gate 1 Energy
    gate_energy_2:
      name : Gate 2 Energy
    gate_energy_3:
      name : Gate 3 Energy
```

