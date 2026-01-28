#pragma once
#include <Geode/Geode.hpp>
#include <Geode/ui/Popup.hpp>

using namespace geode::prelude;

#include "./publicVars.hpp"

class BetterPauseLayer;

class PresetMenu : public geode::Popup {
protected:
    

    bool init(CCObject* layer) {
        if (!Popup::init(winSize.width - 35.f, 289.f, "GJ_square02.png")) return false;
        CCObject* m_bpl = layer;

        this->setTitle("Presets Menu");

        auto presetMenu = CCMenu::create();

        this->addChild(presetMenu);

        auto defaultPresetToggle = CCMenuItemToggler::create(
            CCSprite::create("BPL_btnTextureOff_001.png"_spr),
            CCSprite::create("BPL_btnTextureOn_001.png"_spr),
            m_bpl,
            menu_selector(PresetMenu::defaultPresetSelected)
        );

        m_buttonMenu->addChildAtPosition(defaultPresetToggle, Anchor::TopLeft, {48.f, -41.f}); 

        auto defaultPresetText = CCLabelBMFont::create("Default", "bigFont.fnt");

        defaultPresetToggle->addChildAtPosition(defaultPresetText, Anchor::Center);
        defaultPresetToggle->setScale(0.175);
        defaultPresetToggle->toggle(defaultToggleState);

        auto topPresetToggle = CCMenuItemToggler::create(
            CCSprite::create("BPL_btnTextureOff_001.png"_spr),
            CCSprite::create("BPL_btnTextureOn_001.png"_spr),
            m_bpl,
            menu_selector(PresetMenu::topPresetSelected)
        );

        m_buttonMenu->addChildAtPosition(topPresetToggle, Anchor::TopLeft, {100.5f, -41.f});

        auto topPresetText = CCLabelBMFont::create("Top", "bigFont.fnt");

        topPresetToggle->addChildAtPosition(topPresetText, Anchor::Center);
        topPresetToggle->setScale(0.175);
        topPresetToggle->toggle(topToggleState);

        auto leftPresetToggle = CCMenuItemToggler::create(
            CCSprite::create("BPL_btnTextureOff_001.png"_spr),
            CCSprite::create("BPL_btnTextureOn_001.png"_spr),
            m_bpl,
            menu_selector(PresetMenu::leftPresetSelected)
        );

        m_buttonMenu->addChildAtPosition(leftPresetToggle, Anchor::TopLeft, {153.f, -41.f});

        auto leftPresetText = CCLabelBMFont::create("Left", "bigFont.fnt");

        leftPresetToggle->addChildAtPosition(leftPresetText, Anchor::Center);
        leftPresetToggle->setScale(0.175);
        leftPresetToggle->toggle(leftToggleState);

        leftPresetText->setPosition(leftPresetToggle->getContentWidth() / 2, leftPresetToggle->getContentHeight() / 2);


        m_buttonMenu->updateLayout();

        return true;
    }

    void defaultPresetSelected(CCObject* sender) {
        defaultToggleState = !static_cast<CCMenuItemToggler*>(sender)->isToggled();
        if (defaultToggleState) {
            type = 0;
            Mod::get()->setSavedValue("type", 0);
            setCenterPos(this, 0);
        }
    }
    void topPresetSelected(CCObject* sender) {
        topToggleState = !static_cast<CCMenuItemToggler*>(sender)->isToggled();
        if (topToggleState) {
            type = 1;
            Mod::get()->setSavedValue("type", 1);
            setCenterPos(this, 1);
        }
    }

    
    void leftPresetSelected(CCObject* sender) {
        leftToggleState = !static_cast<CCMenuItemToggler*>(sender)->isToggled();
        if (leftToggleState) {
            type = 2;
            Mod::get()->setSavedValue("type", 2);
            setCenterPos(this, 2);
        }
    }


public:
    static PresetMenu* create(CCObject* layer) {
        auto ret = new PresetMenu();
        if (ret->init(layer)) {
            ret->autorelease();
            return ret;
        }

        delete ret;
        return nullptr;
    }
};