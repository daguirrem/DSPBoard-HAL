
<p align="center">
  <img src="docs/usb_logo_github.png" height="150">
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <img src="docs/frame_logo_github.png" height="150">
</p>

# DSP Board HAL

## Español
[En desarrollo]  
Este repositorio contiene las librerías HAL para la tarjeta _DSP Board_ usadas por el kit de desarrollo de software _DSP Board SDK_, adicionalmente, en el apartado de *Releases* se podrá encontrar la última versión del instalador del SDK (Compatible únicamente con windows x64 por ahora) y la última versión de la PCB DSP Board. El manual de instalación y de uso se puede consultar en el archivo [SDK.md](SDK.md) e información detallada de la PCB se puede encontrar en el archivo [PCB.md](PCB.md).

### Estructura del repositorio

* **docs**  
  Esta carpeta contiene la documentación de la fuente de código generada por doxygen (Inglés) [Documentación de la API](https://daguirrem.github.io/DSPBoard-HAL/index.html)

* **src**  
  Esta carpeta contiene el codigo fuente de las siguientes librerías:  
  * [adc](src/adc)
  * [delay](src/delay)
  * [dsp](src/dsp)
  * [flash](src/flash)
  * [gpio](src/gpio)
  * [rcc](src/rcc)
  * [spi](src/spi)  
  <br />
  
  Cada una de las librerías contiene su carpeta de código fuente y de pruebas.

* **include**  
  Esta carpeta contiene los _include_ de las librerías usadas por _DSP Board SDK_

* **examples**  
  Esta carpeta contiene ejemplos de uso del HAL y de la tarjeta de desarrollo

### Licencia
  _DSP Board HAL_ es licenciado bajo licencia MIT, más información en [LICENSE.md](LICENSE.md)

## English
[In development]  
This repository have a custom HAL libraries to DSP Board used by software development kit _DSP Board SDK_

### Repository Structure

* **docs**  
  This folder contains a doxygen generated documentation of source code (English) [API Documentation](https://daguirrem.github.io/DSPBoardHAL/index.html)

* **src**  
  This folder contains a source code of each libary:  
  * [adc](src/adc)
  * [delay](src/delay)
  * [dsp](src/dsp)
  * [flash](src/flash)
  * [gpio](src/gpio)
  * [rcc](src/rcc)
  * [spi](src/spi)  
  <br />
  
  Every library have a source code folder and the test folder.

* **include**  
  This folder contains a library include files used by _DSP Board SDK_

* **examples**  
  This folder contains a DSP Board examples and HAL examples

### License
  _DSP Board HAL_ is licensed by MIT License, more information on [LICENSE.md](LICENSE.md)
