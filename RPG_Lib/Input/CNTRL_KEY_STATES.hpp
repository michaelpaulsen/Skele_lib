#pragma once
#include <SDL.h> 
namespace Skele_lib {
    namespace GameEngine {
        namespace Input {
            static struct {
                bool lctrl = false;
                bool rctrl = false;
                bool ctrl = false;
                bool lalt = false;
                bool ralt = false;
                bool alt = false;
                bool rgui = false;
                bool lgui = false;
                bool gui = false;
                bool mode = false;
                bool num_lock = false;
                bool reserved = false;
                bool caps_lock = false;
                void set(long keymod) {
                    keymod -= (4096); // I have no idea why but the keymodifiers start at 4096
                    // this caused me a huge headach looking for the enum that the mod keys are stored in
                    // they're stored in SDL_keycode.h for future referance
                    // alt keys
                    alt = (keymod == KMOD_LALT || keymod == KMOD_RALT);
                    lalt = (keymod == KMOD_LALT);
                    ralt = (keymod == KMOD_RALT);
                    //control keys
                    ctrl = (keymod == KMOD_LCTRL || keymod == KMOD_RCTRL);
                    lctrl = (keymod == KMOD_LCTRL);
                    rctrl = (keymod == KMOD_RCTRL);
                    //GUI keys (menu keys?)
                    gui = (keymod == KMOD_LGUI || keymod == KMOD_RGUI);
                    lgui = (keymod == KMOD_LGUI);
                    rgui = (keymod == KMOD_RGUI);
                    //misc keys that i want to hadle 
                    num_lock = (keymod == KMOD_NUM);
                    caps_lock = (keymod == KMOD_CAPS);
                    reserved = (keymod == KMOD_RESERVED);
                }
            } ctrl_keys;
            // this is a list of all of the control keys that are listened to by SDL this set by the set function
        }
    }
}