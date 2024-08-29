#include "reconfig_buttons.h"
#include "esphome/core/helpers.h"
#include "esphome/core/log.h"

static const char *const TAG = "LD2420E.button";

namespace esphome
{
    namespace ld2420e
    {

        void LD2420EApplyConfigButton::press_action() { this->parent_->apply_config_action(); }
        void LD2420ERevertConfigButton::press_action() { this->parent_->revert_config_action(); }
        void LD2420ERestartModuleButton::press_action() { this->parent_->restart_module_action(); }
        void LD2420EFactoryResetButton::press_action() { this->parent_->factory_reset_action(); }

    } // namespace ld2420e
} // namespace esphome
