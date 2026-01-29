#pragma once
#include <Geode/Geode.hpp>
#include <Geode/ui/Popup.hpp>

using namespace geode::prelude;

#include "publicVars.hpp"
#include "position.hpp"

class PresetMenu : public geode::Popup {
protected:
    

    bool init(CCObject* m_bpl) {
        if (!Popup::init(winSize.width - 35.f, 289.f, "GJ_square02.png")) return false;

        this->setTitle("Presets Menu");

        auto presetMenu = CCMenu::create();

        this->addChild(presetMenu);

        auto defaultPresetToggle = CCMenuItemToggler::create(
            CCSprite::create("BPL_btnTextureOff_001.png"_spr),
            CCSprite::create("BPL_btnTextureOn_001.png"_spr),
            m_bpl,
            menu_selector(PresetMenu::defaultPresetSelected)
        );

        m_buttonMenu->addChildAtPosition(defaultPresetToggle, Anchor::TopLeft, {48.f, yOffset}); 

        auto defaultPresetText = CCLabelBMFont::create("Default", "bigFont.fnt");

        defaultPresetToggle->addChildAtPosition(defaultPresetText, Anchor::Center);
        defaultPresetToggle->setScale(0.175f);
        defaultPresetToggle->toggle(defaultToggleState);

        auto topPresetToggle = CCMenuItemToggler::create(
            CCSprite::create("BPL_btnTextureOff_001.png"_spr),
            CCSprite::create("BPL_btnTextureOn_001.png"_spr),
            m_bpl,
            menu_selector(PresetMenu::topPresetSelected)
        );

        m_buttonMenu->addChildAtPosition(topPresetToggle, Anchor::TopLeft, {100.5f, yOffset});

        auto topPresetText = CCLabelBMFont::create("Top", "bigFont.fnt");

        topPresetToggle->addChildAtPosition(topPresetText, Anchor::Center);
        topPresetToggle->setScale(0.175f);
        topPresetToggle->toggle(topToggleState);

        auto leftPresetToggle = CCMenuItemToggler::create(
            CCSprite::create("BPL_btnTextureOff_001.png"_spr),
            CCSprite::create("BPL_btnTextureOn_001.png"_spr),
            m_bpl,
            menu_selector(PresetMenu::leftPresetSelected)
        );

        m_buttonMenu->addChildAtPosition(leftPresetToggle, Anchor::TopLeft, {153.f, yOffset});

        auto leftPresetText = CCLabelBMFont::create("Left", "bigFont.fnt");

        leftPresetToggle->addChildAtPosition(leftPresetText, Anchor::Center);
        leftPresetToggle->setScale(0.175f);
        leftPresetToggle->toggle(leftToggleState);

        auto bottomPresetToggle = CCMenuItemToggler::create(
            CCSprite::create("BPL_btnTextureOff_001.png"_spr),
            CCSprite::create("BPL_btnTextureOn_001.png"_spr),
            m_bpl,
            menu_selector(PresetMenu::bottomPresetSelected)
        );

        m_buttonMenu->addChildAtPosition(bottomPresetToggle, Anchor::TopLeft, {203.5f, yOffset});

        auto bottomPresetText = CCLabelBMFont::create("Bottom", "bigFont.fnt");

        bottomPresetToggle->addChildAtPosition(bottomPresetText, Anchor::Center);
        bottomPresetToggle->setScale(0.175);
        bottomPresetToggle->toggle(bottomToggleState);

        auto rightPresetToggle = CCMenuItemToggler::create(
            CCSprite::create("BPL_btnTextureOff_001.png"_spr),
            CCSprite::create("BPL_btnTextureOn_001.png"_spr),
            m_bpl,
            menu_selector(PresetMenu::rightPresetSelected)
        );

        m_buttonMenu->addChildAtPosition(rightPresetToggle, Anchor::TopLeft, {256.f, yOffset});

        auto rightPresetText = CCLabelBMFont::create("Right", "bigFont.fnt");

        rightPresetToggle->addChildAtPosition(rightPresetText, Anchor::Center);
        rightPresetToggle->setScale(0.175f);
        rightPresetToggle->toggle(rightToggleState);

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

    void bottomPresetSelected(CCObject* sender) {
        bottomToggleState = !static_cast<CCMenuItemToggler*>(sender)->isToggled();
        if (bottomToggleState) {
            type = 3;
            Mod::get()->setSavedValue("type", 3);
            setCenterPos(this, 3);
        }
    }

    void rightPresetSelected(CCObject* sender) {
        rightToggleState = !static_cast<CCMenuItemToggler*>(sender)->isToggled();
        if (rightToggleState) {
            type = 4;
            Mod::get()->setSavedValue("type", 4);
            setCenterPos(this, 4);
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