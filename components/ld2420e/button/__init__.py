import esphome.codegen as cg
from esphome.components import button
import esphome.config_validation as cv
from esphome.const import (
    DEVICE_CLASS_RESTART,
    ENTITY_CATEGORY_DIAGNOSTIC,
    ENTITY_CATEGORY_CONFIG,
    ICON_RESTART,
    ICON_RESTART_ALERT,
    ICON_DATABASE,
)
from .. import CONF_LD2420E_ID, LD2420EComponent, ld2420e_ns

LD2420EApplyConfigButton = ld2420e_ns.class_("LD2420EApplyConfigButton", button.Button)
LD2420ERevertConfigButton = ld2420e_ns.class_("LD2420ERevertConfigButton", button.Button)
LD2420ERestartModuleButton = ld2420e_ns.class_("LD2420ERestartModuleButton", button.Button)
LD2420EFactoryResetButton = ld2420e_ns.class_("LD2420EFactoryResetButton", button.Button)

CONF_APPLY_CONFIG = "apply_config"
CONF_REVERT_CONFIG = "revert_config"
CONF_RESTART_MODULE = "restart_module"
CONF_FACTORY_RESET = "factory_reset"


CONFIG_SCHEMA = {
    cv.GenerateID(CONF_LD2420E_ID): cv.use_id(LD2420EComponent),
    cv.Required(CONF_APPLY_CONFIG): button.button_schema(
        LD2420EApplyConfigButton,
        device_class=DEVICE_CLASS_RESTART,
        entity_category=ENTITY_CATEGORY_CONFIG,
        icon=ICON_RESTART_ALERT,
    ),
    cv.Optional(CONF_REVERT_CONFIG): button.button_schema(
        LD2420ERevertConfigButton,
        device_class=DEVICE_CLASS_RESTART,
        entity_category=ENTITY_CATEGORY_CONFIG,
        icon=ICON_RESTART,
    ),
    cv.Optional(CONF_RESTART_MODULE): button.button_schema(
        LD2420ERestartModuleButton,
        entity_category=ENTITY_CATEGORY_DIAGNOSTIC,
        icon=ICON_DATABASE,
    ),
    cv.Optional(CONF_FACTORY_RESET): button.button_schema(
        LD2420EFactoryResetButton,
        entity_category=ENTITY_CATEGORY_CONFIG,
        icon=ICON_DATABASE,
    ),
}


async def to_code(config):
    ld2420e_component = await cg.get_variable(config[CONF_LD2420E_ID])
    if apply_config := config.get(CONF_APPLY_CONFIG):
        b = await button.new_button(apply_config)
        await cg.register_parented(b, config[CONF_LD2420E_ID])
        cg.add(ld2420e_component.set_apply_config_button(b))
    if revert_config := config.get(CONF_REVERT_CONFIG):
        b = await button.new_button(revert_config)
        await cg.register_parented(b, config[CONF_LD2420E_ID])
        cg.add(ld2420e_component.set_revert_config_button(b))
    if restart_config := config.get(CONF_RESTART_MODULE):
        b = await button.new_button(restart_config)
        await cg.register_parented(b, config[CONF_LD2420E_ID])
        cg.add(ld2420e_component.set_restart_module_button(b))
    if factory_reset := config.get(CONF_FACTORY_RESET):
        b = await button.new_button(factory_reset)
        await cg.register_parented(b, config[CONF_LD2420E_ID])
        cg.add(ld2420e_component.set_factory_reset_button(b))
