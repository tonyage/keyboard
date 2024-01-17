#include QMK_KEYBOARD_H

bool apply_autocorrect(uint8_t backspaces, const char *str, char *typo, char *correct) {
#ifdef OLED_ENABLE
    oled_write_P(PSTR("Auto-corrected"), false);
#endif
#ifdef CONSOLE_ENABLE
    printf("'%s' was corrected to '%s'\n", typo, correct);
#endif
    return true;
}
