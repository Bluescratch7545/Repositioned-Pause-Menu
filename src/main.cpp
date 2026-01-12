#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

#include "include/position.hpp"

class $modify(BetterPauseLayer, PauseLayer) {
    struct Fields {
        CCMenu* presetMenu = nullptr;
        int state = 0;
        int64_t type = 0;
        bool defaultToggleState = false;
        bool topToggleState = false;
        bool leftToggleState = false;
    };
    void customSetup() {
        auto posType = Mod::get()->getSavedValue<int64_t>("type");


        auto winSize = CCDirector::sharedDirector()->getWinSize();
        auto presetMenu = m_fields->presetMenu;

        presetMenu = CCMenu::create();
        presetMenu->setLayout(RowLayout::create());
        presetMenu->setVisible(false);

        PauseLayer::customSetup();

        presetMenu->setPosition({winSize.width / 2, winSize.height / 2});

        this->addChild(presetMenu);


        auto rightMenu = getChildByID("right-button-menu");

        auto menuBtn = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_plainBtn_001.png"),
            this,
            menu_selector(BetterPauseLayer::menuBtnClicked)
        );
        rightMenu->addChild(menuBtn);

        auto presetMenuBG = CCSprite::create("BPL_background_001.png"_spr);
        presetMenu->addChild(presetMenuBG);
        presetMenuBG->setPosition({winSize.width / 2, winSize.height / 2});
        presetMenuBG->setScale(1.95f);

        auto defaultPresetToggle = CCMenuItemToggler::create(
            CCSprite::create("BPL_btnTextureOff_001.png"_spr),
            CCSprite::create("BPL_btnTextureOn_001.png"_spr),
            this,
            menu_selector(BetterPauseLayer::defaultPresetSelected)
        );

        presetMenu->addChild(defaultPresetToggle);

        auto defaultPresetText = CCLabelBMFont::create("Default", "bigFont.fnt");

        defaultPresetToggle->addChild(defaultPresetText);
        defaultPresetToggle->setScale(0.175);
        defaultPresetToggle->setPosition({82.5, 276});
        defaultPresetToggle->toggle(m_fields->defaultToggleState);

        defaultPresetText->setPosition(defaultPresetToggle->getContentWidth() / 2, defaultPresetToggle->getContentHeight() / 2);

        auto topPresetToggle = CCMenuItemToggler::create(
            CCSprite::create("BPL_btnTextureOff_001.png"_spr),
            CCSprite::create("BPL_btnTextureOn_001.png"_spr),
            this,
            menu_selector(BetterPauseLayer::topPresetSelected)
        );

        presetMenu->addChild(topPresetToggle);

        auto topPresetText = CCLabelBMFont::create("Top", "bigFont.fnt");

        topPresetToggle->addChild(topPresetText);
        topPresetToggle->setScale(0.175);
        topPresetToggle->setPosition({135, 276});
        topPresetToggle->toggle(m_fields->topToggleState);

        topPresetText->setPosition(topPresetToggle->getContentWidth() / 2, topPresetToggle->getContentHeight() / 2);

        auto leftPresetToggle = CCMenuItemToggler::create(
            CCSprite::create("BPL_btnTextureOff_001.png"_spr),
            CCSprite::create("BPL_btnTextureOn_001.png"_spr),
            this,
            menu_selector(BetterPauseLayer::leftPresetSelected)
        );

        presetMenu->addChild(leftPresetToggle);

        auto leftPresetText = CCLabelBMFont::create("Left", "bigFont.fnt");

        leftPresetToggle->addChild(leftPresetText);
        leftPresetToggle->setScale(0.175);
        leftPresetToggle->setPosition({187.5, 276});
        leftPresetToggle->toggle(m_fields->leftToggleState);

        leftPresetText->setPosition(leftPresetToggle->getContentWidth() / 2, leftPresetToggle->getContentHeight() / 2);

        if (m_fields->type != 0) {
            Mod::get()->setSavedValue("type", m_fields->type);
        }

        setCenterPos(this, posType);

        presetMenu->setZOrder(999999);
        m_fields->presetMenu = presetMenu;
    }

    void menuBtnClicked(CCObject* sender) {
        if (m_fields->state == 0) {
            m_fields->presetMenu->setVisible(true);
            m_fields->state = 1;
        }
        else {
            m_fields->presetMenu->setVisible(false);
            m_fields->state = 0;
        }
    }

    void defaultPresetSelected(CCObject* sender) {
        m_fields->defaultToggleState = !static_cast<CCMenuItemToggler*>(sender)->isToggled();
        if (m_fields->defaultToggleState) {
            m_fields->type = 0;
            Mod::get()->setSavedValue("type", 0);
            setCenterPos(this, 0);
        }
    }

    void topPresetSelected(CCObject* sender) {
        m_fields->topToggleState = !static_cast<CCMenuItemToggler*>(sender)->isToggled();
        if (m_fields->topToggleState) {
            m_fields->type = 1;
            Mod::get()->setSavedValue("type", 1);
            setCenterPos(this, 1);
        }
    }

    void leftPresetSelected(CCObject* sender) {
        m_fields->leftToggleState = !static_cast<CCMenuItemToggler*>(sender)->isToggled();
        if (m_fields->leftToggleState) {
            m_fields->type = 2;
            Mod::get()->setSavedValue("type", 2);
            setCenterPos(this, 2);
        }
    }
};