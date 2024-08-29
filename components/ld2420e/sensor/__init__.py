import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor
from esphome.const import CONF_ID, DEVICE_CLASS_DISTANCE, DEVICE_CLASS_ENERGY, UNIT_CENTIMETER, UNIT_EMPTY
from .. import ld2420e_ns, LD2420EComponent, CONF_LD2420E_ID

LD2420ESensor = ld2420e_ns.class_("LD2420ESensor", sensor.Sensor, cg.Component)

CONF_MOVING_DISTANCE = "moving_distance"
CONF_GATE_ENERGY = "gate_energy"

CONFIG_SCHEMA = cv.Schema(
    {
            cv.GenerateID(): cv.declare_id(LD2420ESensor),
            cv.GenerateID(CONF_LD2420E_ID): cv.use_id(LD2420EComponent),
            cv.Optional(CONF_MOVING_DISTANCE): sensor.sensor_schema(
                device_class=DEVICE_CLASS_DISTANCE, unit_of_measurement=UNIT_CENTIMETER
            ),       
    }
)

CONFIG_SCHEMA = CONFIG_SCHEMA.extend(
    {
        cv.Optional(CONF_GATE_ENERGY + f"_{x}"): sensor.sensor_schema(
                device_class=DEVICE_CLASS_ENERGY, unit_of_measurement=UNIT_EMPTY
        )   
        for x in range(16)
    }
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    if CONF_MOVING_DISTANCE in config:
        sens = await sensor.new_sensor(config[CONF_MOVING_DISTANCE])
        cg.add(var.set_distance_sensor(sens))
    for x in range(16):
        if gate_energy_conf := config.get(f"gate_{x}_energy"):
            sens = await sensor.new_sensor(gate_energy_conf)
            cg.add(var.set_energy_sensor(x, sens))
    ld2420e = await cg.get_variable(config[CONF_LD2420E_ID])
    cg.add(ld2420e.register_listener(var))
