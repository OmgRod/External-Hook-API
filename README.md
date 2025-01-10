# External Hook API

i'm too lazy to create docs so here's some below from geodify:

### External Mods

For external mods that modify the background of a specific menu, you can use the following example. This shows how to hook into `GlobedLevelListLayer` to add a custom background.

```cpp
#include <Geode/Geode.hpp>
#include "../../SwelvyBG.hpp"
#include "../../Hooks/Hooker.hpp" 
using namespace geode::prelude;

Viper_Hookclass(GlobedLevelListLayer) {
        if (auto bg = this->getChildByID("background")) {
            bg->setVisible(false);
        }

        SwelvyBG* swelvyBG = SwelvyBG::create();
        swelvyBG->setZOrder(-1);
        swelvyBG->setID("swelvy-background");
        this->addChild(swelvyBG);
}

```
This way is new from v1.7.0+!

### External Mods Fix

For external mods that really don't like you to modify the background of a specific menu, you can use the following example. This shows how to hook into `cvolton.betterinfo/CustomCreatorLayer` to add a custom background.

Please do not do this unless like in this example it's the only way since Viper_Hookclass won't work on it!

```cpp
#include <Geode/Geode.hpp>
#include "../../SwelvyBG.hpp"
#include "../../Hooks/Hooker.hpp" 
using namespace geode::prelude;
// class name to store in code, Hook to (the real layer id)
Viper_Hookclass_Scene(cvolton_betterinfo_CustomCreatorLayer,"cvolton.betterinfo/CustomCreatorLayer") {
         if (auto bg = _This->getChildByID("cvolton.betterinfo/background")) {
            bg->setVisible(false);
            SwelvyBG* swelvyBG = SwelvyBG::create();
            swelvyBG->setZOrder(-1);
            swelvyBG->setID("swelvy-background");
            _This->addChild(swelvyBG);
        }
}
```
This way is new from v1.7.0+!
