# RV-Upgrade
Arduino-powered panel in RV that controls gas sensors and ceiling fans

This sketch runs the added electronics for a small RV trailer
This new circuit running off the RV 12VDC battery will add:
  -12VDC circular power socket
  -2xUSB power sockets
  -RV battery voltmeter (checked with a momentary SPST switch)
  -This arduino (Uno R3)
    -CO detector
    -smoke/propane detector
    -gas alarm LEDs and buzzer
    -photoresist night light
    -ceiling vent fan (12v, powered by switching relay)

  This entire panel will be subject to a master 3PST switch
    3P = 12V/usb power, arduino power (via DC converter), 12V to relay for fan.

  If either (or both) gas sensors reads above a threshold value: a unique LED will light,
    the buzzer will sound, and the ceiling fan will activate.

160809 - Still writing first draft of code, and waiting for a few hardware pieces to arrive in the mail.
