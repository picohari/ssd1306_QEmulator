![QEmulator](https://github.com/picohari/ssd1306_QEmulator/raw/master/images/emulator.png)

# SSD1306 OLED Emulator for ADAFRUIT GFX Library

A simple QT Application emulating a SSD1306 OLED based display module with the ADAFRUIT GFX Library for Arduino.

## Getting Started

The main purpose of this project is to reduce time of development :) Sometimes programming the hardware takes too much time during debugging, so one can emulate the output of the ADAFRUIT GFX library with this little helper and check the results on the computer.  

### Prerequisites

You should already have your Arduino Project running with ADAFRUIT GFX Library. Currently you must prepare a separate file with *ONLY* the code for the display (see emulator.cpp) and replace "." with "->" for all `adafruit_ssd1306` - Functions.

A QT 5.x environment must be set up to compile the code:

```
sudo apt-get install qtcreator
```

### Installing

Clone this git repository to your harddisk:

```
git clone https://github.com/picohari/ssd1306_oled_emulator.git
```

Open `SSD1603_Emulator.pro` in QT Creator:

```
qtcreator SSD1603_Emulator.pro
```

Insert your code to test between these markers, for example:

```
    /* ==> INSERT CODE HERE - BEGIN <== */

    emulator->setTextSize(1);
    emulator->setTextColor(WHITE);

    emulator->setFont(&FreeSans12pt7b);
    emulator->setCursor(7, 31);

    static char tmp[36] = { 0 };
    sprintf(tmp, "%s", "Hallo Welt!");
    emulator->print(tmp);

    /* ==> INSERT CODE HERE - END <== */
```

Finaly build and run your project by hitting `CTRL + R`.

### Build from console:

Generate Makefile with `qmake` and build executable:

```
qmake SSD1603_Emulator.pro && make
```

## Built With

* [Qt Creator](http://www.qt.io/) - The Qt framework used
* [gcc](https://gcc.gnu.org/) - GNU C Compiler Suite
* [love](https://github.io/) - Used to generate the code

## Contributing

Please read [CONTRIBUTING.md](#) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](#). 

## Authors

* **balsa0** - *Initial work* - [balsa0](https://github.com/balsa0/Adafruit-OLED-emulator)
* **DK6YF** - *Continued work* - [picohari](https://https://github.com/picohari.com)

See also the list of [contributors](https://github.com/picohari/ssd1306_QEmulator/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Hat tip to anyone whose code was used
* Inspiration
* etc
