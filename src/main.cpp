#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/ui/Popup.hpp>

using namespace geode::prelude;

#include "include/position.hpp"
#include "include/presetMenu.hpp"
#include "include/publicVars.hpp"


class $modify(BetterPauseLayer, PauseLayer) {
    void customSetup() {
        PauseLayer::customSetup();

        auto posType = Mod::get()->getSavedValue<int64_t>("type");


        auto winSize = CCDirector::sharedDirector()->getWinSize();

        auto rightMenu = this->getChildByID("right-button-menu");

        auto menuToggleBtn = CCMenuItemExt::createSpriteExtra(
            ButtonSprite::create("Presets", 0.275),
            [this](auto menuToggleBtn) {
                PresetMenu::create(this)->show();
            }
        );
        
        rightMenu->addChild(menuToggleBtn);
        rightMenu->updateLayout();

        if (type != 0) {
            Mod::get()->setSavedValue("type", type);
        }

        setCenterPos(this, posType);
    }
    
};