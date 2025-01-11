#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/CCLayer.hpp>
#include <Geode/modify/CCDirector.hpp>

using namespace geode::prelude;

#define HookClass(className)                           \
class className : public CCLayer {                     \
public:                                                \
    void HookClassInit();                              \
};                                                     \
class $modify(CCLayer) {                               \
    bool init() override;                              \
};                                                     \
void className::HookClassInit()

#define HookClass_Scene(unique, className)             \
class unique##Sillyclass {                             \
public:                                                \
    void HookClassInit(CCNode* _This);                 \
};                                                     \
class $modify(CCDirector) {                            \
    static void onModify(auto& self);                  \
    void willSwitchToScene(CCScene* scene) override;   \
};                                                     \
void unique##Sillyclass::HookClassInit(CCNode* _This)
