#pragma once
#include <Geode/Geode.hpp>
using namespace geode::prelude;

int state = 0;
int64_t type = 0;
bool defaultToggleState = false;
bool topToggleState = false;
bool leftToggleState = false;
bool bottomToggleState = false;
bool rightToggleState = false;
CCSize winSize = CCDirector::sharedDirector()->getWinSize();
float yOffset = -53.f;