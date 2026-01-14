#pragma once
#include <Geode/Geode.hpp>

using namespace geode::prelude;

inline void setCenterPos(
    CCNode* parent,
    int type
) {
    if (type == 0) return;

    auto centerMenu = parent->getChildByID("center-button-menu");
    auto levelName = parent->getChildByID("level-name");
    auto progressBar = parent->getChildByID("normal-progress-bar");
    auto progressLabel = parent->getChildByID("normal-progress-label");
    auto modeLabel = parent->getChildByID("normal-mode-label");
    auto pProgressBar = parent->getChildByID("practice-progress-bar");
    auto pProgressLabel = parent->getChildByID("practice-progress-label");
    auto pModeLabel = parent->getChildByID("practice-mode-label");

    if (type == 1) {
        centerMenu->setPosition(parent->getContentSize().width / 2, parent->getContentSize().height - 60);

        levelName->setPosition(levelName->getPositionX(), levelName->getPositionY() - 81);

        progressBar->setPosition(progressBar->getPositionX(), progressBar->getPositionY() - 90);
        progressLabel->setPosition(progressLabel->getPositionX(), progressLabel->getPositionY() - 90);
        modeLabel->setPosition(modeLabel->getPositionX(), modeLabel->getPositionY() - 90);

        pProgressBar->setPosition(pProgressBar->getPositionX(), pProgressBar->getPositionY() - 90);
        pProgressLabel->setPosition(pProgressLabel->getPositionX(), pProgressLabel->getPositionY() - 90);
        pModeLabel->setPosition(pModeLabel->getPositionX(), pModeLabel->getPositionY() - 90);
    }

    else if (type == 2) {
        auto leftButtonMenu = static_cast<CCMenu*>(parent->getChildByID("left-button-menu"));

        auto children = centerMenu->getChildrenExt();
        for (int i = children.size() - 1; i >= 0; i--) {
            Ref child = children[i];
            child->removeFromParent();
            leftButtonMenu->addChild(child);
        }

        leftButtonMenu->setContentWidth(56);

        leftButtonMenu->updateLayout(); // To avoid bug
    }
}