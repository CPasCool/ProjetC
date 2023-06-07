//
// Created by benfa on 07/06/2023.
//

#include "event.h"


int handleEvent(SDL_Renderer* renderer){
    SDL_Event event;
    SDL_bool quit = SDL_FALSE;
    while (!quit){
        while(SDL_PollEvent(&event))
            if(event.type == SDL_QUIT)
                quit = SDL_TRUE;
            else if (event.type == SDL_KEYDOWN)
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_UP:
                        break;
                    case SDL_SCANCODE_UNKNOWN:
                        break;
                    case SDL_SCANCODE_A:
                        break;
                    case SDL_SCANCODE_B:
                        break;
                    case SDL_SCANCODE_C:
                        break;
                    case SDL_SCANCODE_D:
                        break;
                    case SDL_SCANCODE_E:
                        break;
                    case SDL_SCANCODE_F:
                        break;
                    case SDL_SCANCODE_G:
                        break;
                    case SDL_SCANCODE_H:
                        break;
                    case SDL_SCANCODE_I:
                        break;
                    case SDL_SCANCODE_J:
                        break;
                    case SDL_SCANCODE_K:
                        break;
                    case SDL_SCANCODE_L:
                        break;
                    case SDL_SCANCODE_M:
                        break;
                    case SDL_SCANCODE_N:
                        break;
                    case SDL_SCANCODE_O:
                        break;
                    case SDL_SCANCODE_P:
                        break;
                    case SDL_SCANCODE_Q:
                        break;
                    case SDL_SCANCODE_R:
                        break;
                    case SDL_SCANCODE_S:
                        break;
                    case SDL_SCANCODE_T:
                        break;
                    case SDL_SCANCODE_U:
                        break;
                    case SDL_SCANCODE_V:
                        break;
                    case SDL_SCANCODE_W:
                        break;
                    case SDL_SCANCODE_X:
                        break;
                    case SDL_SCANCODE_Y:
                        break;
                    case SDL_SCANCODE_Z:
                        break;
                    case SDL_SCANCODE_1:
                        break;
                    case SDL_SCANCODE_2:
                        break;
                    case SDL_SCANCODE_3:
                        break;
                    case SDL_SCANCODE_4:
                        break;
                    case SDL_SCANCODE_5:
                        break;
                    case SDL_SCANCODE_6:
                        break;
                    case SDL_SCANCODE_7:
                        break;
                    case SDL_SCANCODE_8:
                        break;
                    case SDL_SCANCODE_9:
                        break;
                    case SDL_SCANCODE_0:
                        break;
                    case SDL_SCANCODE_RETURN:
                        break;
                    case SDL_SCANCODE_ESCAPE:
                        break;
                    case SDL_SCANCODE_BACKSPACE:
                        break;
                    case SDL_SCANCODE_TAB:
                        break;
                    case SDL_SCANCODE_SPACE:
                        break;
                    case SDL_SCANCODE_MINUS:
                        break;
                    case SDL_SCANCODE_EQUALS:
                        break;
                    case SDL_SCANCODE_LEFTBRACKET:
                        break;
                    case SDL_SCANCODE_RIGHTBRACKET:
                        break;
                    case SDL_SCANCODE_BACKSLASH:
                        break;
                    case SDL_SCANCODE_NONUSHASH:
                        break;
                    case SDL_SCANCODE_SEMICOLON:
                        break;
                    case SDL_SCANCODE_APOSTROPHE:
                        break;
                    case SDL_SCANCODE_GRAVE:
                        break;
                    case SDL_SCANCODE_COMMA:
                        break;
                    case SDL_SCANCODE_PERIOD:
                        break;
                    case SDL_SCANCODE_SLASH:
                        break;
                    case SDL_SCANCODE_CAPSLOCK:
                        break;
                    case SDL_SCANCODE_F1:
                        break;
                    case SDL_SCANCODE_F2:
                        break;
                    case SDL_SCANCODE_F3:
                        break;
                    case SDL_SCANCODE_F4:
                        break;
                    case SDL_SCANCODE_F5:
                        break;
                    case SDL_SCANCODE_F6:
                        break;
                    case SDL_SCANCODE_F7:
                        break;
                    case SDL_SCANCODE_F8:
                        break;
                    case SDL_SCANCODE_F9:
                        break;
                    case SDL_SCANCODE_F10:
                        break;
                    case SDL_SCANCODE_F11:
                        break;
                    case SDL_SCANCODE_F12:
                        break;
                    case SDL_SCANCODE_PRINTSCREEN:
                        break;
                    case SDL_SCANCODE_SCROLLLOCK:
                        break;
                    case SDL_SCANCODE_PAUSE:
                        break;
                    case SDL_SCANCODE_INSERT:
                        break;
                    case SDL_SCANCODE_HOME:
                        break;
                    case SDL_SCANCODE_PAGEUP:
                        break;
                    case SDL_SCANCODE_DELETE:
                        break;
                    case SDL_SCANCODE_END:
                        break;
                    case SDL_SCANCODE_PAGEDOWN:
                        break;
                    case SDL_SCANCODE_RIGHT:
                        break;
                    case SDL_SCANCODE_LEFT:
                        break;
                    case SDL_SCANCODE_DOWN:
                        break;
                    case SDL_SCANCODE_NUMLOCKCLEAR:
                        break;
                    case SDL_SCANCODE_KP_DIVIDE:
                        break;
                    case SDL_SCANCODE_KP_MULTIPLY:
                        break;
                    case SDL_SCANCODE_KP_MINUS:
                        break;
                    case SDL_SCANCODE_KP_PLUS:
                        break;
                    case SDL_SCANCODE_KP_ENTER:
                        break;
                    case SDL_SCANCODE_KP_1:
                        break;
                    case SDL_SCANCODE_KP_2:
                        break;
                    case SDL_SCANCODE_KP_3:
                        break;
                    case SDL_SCANCODE_KP_4:
                        break;
                    case SDL_SCANCODE_KP_5:
                        break;
                    case SDL_SCANCODE_KP_6:
                        break;
                    case SDL_SCANCODE_KP_7:
                        break;
                    case SDL_SCANCODE_KP_8:
                        break;
                    case SDL_SCANCODE_KP_9:
                        break;
                    case SDL_SCANCODE_KP_0:
                        break;
                    case SDL_SCANCODE_KP_PERIOD:
                        break;
                    case SDL_SCANCODE_NONUSBACKSLASH:
                        break;
                    case SDL_SCANCODE_APPLICATION:
                        break;
                    case SDL_SCANCODE_POWER:
                        break;
                    case SDL_SCANCODE_KP_EQUALS:
                        break;
                    case SDL_SCANCODE_F13:
                        break;
                    case SDL_SCANCODE_F14:
                        break;
                    case SDL_SCANCODE_F15:
                        break;
                    case SDL_SCANCODE_F16:
                        break;
                    case SDL_SCANCODE_F17:
                        break;
                    case SDL_SCANCODE_F18:
                        break;
                    case SDL_SCANCODE_F19:
                        break;
                    case SDL_SCANCODE_F20:
                        break;
                    case SDL_SCANCODE_F21:
                        break;
                    case SDL_SCANCODE_F22:
                        break;
                    case SDL_SCANCODE_F23:
                        break;
                    case SDL_SCANCODE_F24:
                        break;
                    case SDL_SCANCODE_EXECUTE:
                        break;
                    case SDL_SCANCODE_HELP:
                        break;
                    case SDL_SCANCODE_MENU:
                        break;
                    case SDL_SCANCODE_SELECT:
                        break;
                    case SDL_SCANCODE_STOP:
                        break;
                    case SDL_SCANCODE_AGAIN:
                        break;
                    case SDL_SCANCODE_UNDO:
                        break;
                    case SDL_SCANCODE_CUT:
                        break;
                    case SDL_SCANCODE_COPY:
                        break;
                    case SDL_SCANCODE_PASTE:
                        break;
                    case SDL_SCANCODE_FIND:
                        break;
                    case SDL_SCANCODE_MUTE:
                        break;
                    case SDL_SCANCODE_VOLUMEUP:
                        break;
                    case SDL_SCANCODE_VOLUMEDOWN:
                        break;
                    case SDL_SCANCODE_KP_COMMA:
                        break;
                    case SDL_SCANCODE_KP_EQUALSAS400:
                        break;
                    case SDL_SCANCODE_INTERNATIONAL1:
                        break;
                    case SDL_SCANCODE_INTERNATIONAL2:
                        break;
                    case SDL_SCANCODE_INTERNATIONAL3:
                        break;
                    case SDL_SCANCODE_INTERNATIONAL4:
                        break;
                    case SDL_SCANCODE_INTERNATIONAL5:
                        break;
                    case SDL_SCANCODE_INTERNATIONAL6:
                        break;
                    case SDL_SCANCODE_INTERNATIONAL7:
                        break;
                    case SDL_SCANCODE_INTERNATIONAL8:
                        break;
                    case SDL_SCANCODE_INTERNATIONAL9:
                        break;
                    case SDL_SCANCODE_LANG1:
                        break;
                    case SDL_SCANCODE_LANG2:
                        break;
                    case SDL_SCANCODE_LANG3:
                        break;
                    case SDL_SCANCODE_LANG4:
                        break;
                    case SDL_SCANCODE_LANG5:
                        break;
                    case SDL_SCANCODE_LANG6:
                        break;
                    case SDL_SCANCODE_LANG7:
                        break;
                    case SDL_SCANCODE_LANG8:
                        break;
                    case SDL_SCANCODE_LANG9:
                        break;
                    case SDL_SCANCODE_ALTERASE:
                        break;
                    case SDL_SCANCODE_SYSREQ:
                        break;
                    case SDL_SCANCODE_CANCEL:
                        break;
                    case SDL_SCANCODE_CLEAR:
                        break;
                    case SDL_SCANCODE_PRIOR:
                        break;
                    case SDL_SCANCODE_RETURN2:
                        break;
                    case SDL_SCANCODE_SEPARATOR:
                        break;
                    case SDL_SCANCODE_OUT:
                        break;
                    case SDL_SCANCODE_OPER:
                        break;
                    case SDL_SCANCODE_CLEARAGAIN:
                        break;
                    case SDL_SCANCODE_CRSEL:
                        break;
                    case SDL_SCANCODE_EXSEL:
                        break;
                    case SDL_SCANCODE_KP_00:
                        break;
                    case SDL_SCANCODE_KP_000:
                        break;
                    case SDL_SCANCODE_THOUSANDSSEPARATOR:
                        break;
                    case SDL_SCANCODE_DECIMALSEPARATOR:
                        break;
                    case SDL_SCANCODE_CURRENCYUNIT:
                        break;
                    case SDL_SCANCODE_CURRENCYSUBUNIT:
                        break;
                    case SDL_SCANCODE_KP_LEFTPAREN:
                        break;
                    case SDL_SCANCODE_KP_RIGHTPAREN:
                        break;
                    case SDL_SCANCODE_KP_LEFTBRACE:
                        break;
                    case SDL_SCANCODE_KP_RIGHTBRACE:
                        break;
                    case SDL_SCANCODE_KP_TAB:
                        break;
                    case SDL_SCANCODE_KP_BACKSPACE:
                        break;
                    case SDL_SCANCODE_KP_A:
                        break;
                    case SDL_SCANCODE_KP_B:
                        break;
                    case SDL_SCANCODE_KP_C:
                        break;
                    case SDL_SCANCODE_KP_D:
                        break;
                    case SDL_SCANCODE_KP_E:
                        break;
                    case SDL_SCANCODE_KP_F:
                        break;
                    case SDL_SCANCODE_KP_XOR:
                        break;
                    case SDL_SCANCODE_KP_POWER:
                        break;
                    case SDL_SCANCODE_KP_PERCENT:
                        break;
                    case SDL_SCANCODE_KP_LESS:
                        break;
                    case SDL_SCANCODE_KP_GREATER:
                        break;
                    case SDL_SCANCODE_KP_AMPERSAND:
                        break;
                    case SDL_SCANCODE_KP_DBLAMPERSAND:
                        break;
                    case SDL_SCANCODE_KP_VERTICALBAR:
                        break;
                    case SDL_SCANCODE_KP_DBLVERTICALBAR:
                        break;
                    case SDL_SCANCODE_KP_COLON:
                        break;
                    case SDL_SCANCODE_KP_HASH:
                        break;
                    case SDL_SCANCODE_KP_SPACE:
                        break;
                    case SDL_SCANCODE_KP_AT:
                        break;
                    case SDL_SCANCODE_KP_EXCLAM:
                        break;
                    case SDL_SCANCODE_KP_MEMSTORE:
                        break;
                    case SDL_SCANCODE_KP_MEMRECALL:
                        break;
                    case SDL_SCANCODE_KP_MEMCLEAR:
                        break;
                    case SDL_SCANCODE_KP_MEMADD:
                        break;
                    case SDL_SCANCODE_KP_MEMSUBTRACT:
                        break;
                    case SDL_SCANCODE_KP_MEMMULTIPLY:
                        break;
                    case SDL_SCANCODE_KP_MEMDIVIDE:
                        break;
                    case SDL_SCANCODE_KP_PLUSMINUS:
                        break;
                    case SDL_SCANCODE_KP_CLEAR:
                        break;
                    case SDL_SCANCODE_KP_CLEARENTRY:
                        break;
                    case SDL_SCANCODE_KP_BINARY:
                        break;
                    case SDL_SCANCODE_KP_OCTAL:
                        break;
                    case SDL_SCANCODE_KP_DECIMAL:
                        break;
                    case SDL_SCANCODE_KP_HEXADECIMAL:
                        break;
                    case SDL_SCANCODE_LCTRL:
                        break;
                    case SDL_SCANCODE_LSHIFT:
                        break;
                    case SDL_SCANCODE_LALT:
                        break;
                    case SDL_SCANCODE_LGUI:
                        break;
                    case SDL_SCANCODE_RCTRL:
                        break;
                    case SDL_SCANCODE_RSHIFT:
                        break;
                    case SDL_SCANCODE_RALT:
                        break;
                    case SDL_SCANCODE_RGUI:
                        break;
                    case SDL_SCANCODE_MODE:
                        break;
                    case SDL_SCANCODE_AUDIONEXT:
                        break;
                    case SDL_SCANCODE_AUDIOPREV:
                        break;
                    case SDL_SCANCODE_AUDIOSTOP:
                        break;
                    case SDL_SCANCODE_AUDIOPLAY:
                        break;
                    case SDL_SCANCODE_AUDIOMUTE:
                        break;
                    case SDL_SCANCODE_MEDIASELECT:
                        break;
                    case SDL_SCANCODE_WWW:
                        break;
                    case SDL_SCANCODE_MAIL:
                        break;
                    case SDL_SCANCODE_CALCULATOR:
                        break;
                    case SDL_SCANCODE_COMPUTER:
                        break;
                    case SDL_SCANCODE_AC_SEARCH:
                        break;
                    case SDL_SCANCODE_AC_HOME:
                        break;
                    case SDL_SCANCODE_AC_BACK:
                        break;
                    case SDL_SCANCODE_AC_FORWARD:
                        break;
                    case SDL_SCANCODE_AC_STOP:
                        break;
                    case SDL_SCANCODE_AC_REFRESH:
                        break;
                    case SDL_SCANCODE_AC_BOOKMARKS:
                        break;
                    case SDL_SCANCODE_BRIGHTNESSDOWN:
                        break;
                    case SDL_SCANCODE_BRIGHTNESSUP:
                        break;
                    case SDL_SCANCODE_DISPLAYSWITCH:
                        break;
                    case SDL_SCANCODE_KBDILLUMTOGGLE:
                        break;
                    case SDL_SCANCODE_KBDILLUMDOWN:
                        break;
                    case SDL_SCANCODE_KBDILLUMUP:
                        break;
                    case SDL_SCANCODE_EJECT:
                        break;
                    case SDL_SCANCODE_SLEEP:
                        break;
                    case SDL_SCANCODE_APP1:
                        break;
                    case SDL_SCANCODE_APP2:
                        break;
                    case SDL_SCANCODE_AUDIOREWIND:
                        break;
                    case SDL_SCANCODE_AUDIOFASTFORWARD:
                        break;
                    case SDL_SCANCODE_SOFTLEFT:
                        break;
                    case SDL_SCANCODE_SOFTRIGHT:
                        break;
                    case SDL_SCANCODE_CALL:
                        break;
                    case SDL_SCANCODE_ENDCALL:
                        break;
                    case SDL_NUM_SCANCODES:
                        break;
                }
            else{
                SDL_RenderPresent(renderer);
            }
    }
    return 0;
}