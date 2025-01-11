#include "HookClass.hpp"

bool $modify(CCLayer)::init() {
    if (!CCLayer::init()) return false;
    if (auto x = typeinfo_cast<className*>(this)) {
        queueInMainThread([=] { x->HookClassInit(); });
        return true;
    }
    return true;
}

void $modify(CCDirector)::onModify(auto& self) {
    (void)self.setHookPriority("CCDirector::willSwitchToScene", -999);
}

void $modify(CCDirector)::willSwitchToScene(CCScene* scene) {
    CCDirector::willSwitchToScene(scene);
    if (CCLayer* child = scene->getChildByType<CCLayer>(0)) {
        if (child->getID() == className) {
            unique##Sillyclass sillyInstance;
            sillyInstance.HookClassInit(child);
        }
    }
}
