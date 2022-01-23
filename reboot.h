const int rebootButton = 9; // my reboot pin on the board

void initReboot() {
    pinMode(rebootButton, INPUT_PULLUP);
}

void doReboot() {
    Serial.println("rebooting");
    // send reboot command
    SCB_AIRCR = 0x05FA0004;
}
