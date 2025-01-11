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
    bool init() {                                      \
        if (!CCLayer::init()) return false;            \
        if (auto x = typeinfo_cast<className*>(this)) {\
            queueInMainThread([=] { x->HookClassInit(); }); \
            return true;                               \
        }                                              \
        return true;                                   \
    }                                                  \
};                                                     \
void className::HookClassInit()

#define HookClass_Scene(unique, className)             \
class unique##Sillyclass {                             \
public:                                                \
    void HookClassInit(CCNode* _This);                 \
};                                                     \
class $modify(CCDirector) {                            \
    static void onModify(auto& self) {                 \
        (void)self.setHookPriority("CCDirector::willSwitchToScene", -999); \
    }                                                  \
    void willSwitchToScene(CCScene* scene) {           \
        CCDirector::willSwitchToScene(scene);          \
        if (CCLayer* child = scene->getChildByType<CCLayer>(0)) { \
            if (child->getID() == className) {         \
                unique##Sillyclass sillyInstance;      \
                sillyInstance.HookClassInit(child);    \
            }                                          \
        }                                              \
    }                                                  \
};                                                     \
void unique##Sillyclass::HookClassInit(CCNode* _This)
