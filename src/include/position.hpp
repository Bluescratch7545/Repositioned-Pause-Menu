#pragma once
#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include "publicVars.hpp"

inline void setCenterPos(
    CCNode* node,
    int value
) {
    if (type == 0) return;

    auto centerMenu = node->getChildByID("center-button-menu");
    auto levelName = node->getChildByID("level-name");
    auto progressBar = node->getChildByID("normal-progress-bar");
    auto progressLabel = node->getChildByID("normal-progress-label");
    auto modeLabel = node->getChildByID("normal-mode-label");
    auto pProgressBar = node->getChildByID("practice-progress-bar");
    auto pProgressLabel = node->getChildByID("practice-progress-label");
    auto pModeLabel = node->getChildByID("practice-mode-label");
    auto children = centerMenu->getChildrenExt();

    if (type == 1) {
        centerMenu->setPositionY(node->getContentSize().height - 60);

        levelName->setPositionY(levelName->getPositionY() - 81);

        progressBar->setPositionY(progressBar->getPositionY() - 90);
        progressLabel->setPositionY(progressLabel->getPositionY() - 90);
        modeLabel->setPositionY(modeLabel->getPositionY() - 90);

        pProgressBar->setPositionY(pProgressBar->getPositionY() - 90);
        pProgressLabel->setPositionY(pProgressLabel->getPositionY() - 90);
        pModeLabel->setPositionY(pModeLabel->getPositionY() - 90);
    }

    else if (type == 2) {
        auto leftButtonMenu = static_cast<CCMenu*>(node->getChildByID("left-button-menu"));

        for (int i = children.size() - 1; i >= 0; i--) {
            Ref child = children[i];
            child->removeFromParent();
            leftButtonMenu->addChild(child);
        }

        leftButtonMenu->setContentWidth(56);

        leftButtonMenu->updateLayout(); // To avoid bug
    }
    else if (type == 3) {
        auto musicSlider = node->getChildByID("music-slider");
        auto sfxSlider = node->getChildByID("sfx-slider");
        auto musicLabel = node->getChildByID("music-label");
        auto sfxLabel = node->getChildByID("sfx-label");

        centerMenu->setPositionY(49.f);

        levelName->setPositionY(200.f);

        progressBar->setPositionY(148.f);
        progressLabel->setPositionY(148.f);
        modeLabel->setPositionY(169.f);

        pProgressBar->setPositionY(101.f);
        pProgressLabel->setPositionY(101.f);
        pModeLabel->setPositionY(126.f);

        musicSlider->setPositionY(244.f);
        musicLabel->setPositionY(263.f);
        sfxSlider->setPositionY(244.f);
        sfxLabel->setPositionY(263.f);
    }
    else if (type == 4) {
        auto rightMenu = static_cast<CCMenu*>(node->getChildByID("right-button-menu"));

        levelName->setPositionY(levelName->getPositionY() - 81);

        progressBar->setPositionY(progressBar->getPositionY() - 90);
        progressLabel->setPositionY(progressLabel->getPositionY() - 90);
        modeLabel->setPositionY(modeLabel->getPositionY() - 90);

        pProgressBar->setPositionY(pProgressBar->getPositionY() - 90);
        pProgressLabel->setPositionY(pProgressLabel->getPositionY() - 90);
        pModeLabel->setPositionY(pModeLabel->getPositionY() - 90);

        for (int i = children.size() - 1; i >= 0; i--) {
            Ref child = children[i];
            child->removeFromParent();
            rightMenu->addChild(child);
        }

        rightMenu->setContentWidth(52);

        rightMenu->updateLayout();
    }
}