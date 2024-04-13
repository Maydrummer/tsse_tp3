# Trabajo Práctico Número 3

Seleccionar una biblioteca (o componente) del software a desarrollar en el TP final de la
carrera de especialización / maestría y escribir un test unitario con ceedling que incluya por
lo menos 5 test cases. El archivo de test debe tener por lo menos 65 líneas de extensión

## Uso del repositorio

Este repositorio utiliza las siguientes herramientas:

1. [clang-format] () para el mantenimiento del formato del código escrito en lenguaje C
1. [pre-commit](https://pre-commit.com) para validaciones generales de formato del repositorio
1. [ceedling]() para ejecutar las pruebas unitarias en forma automatizada
1. [lcov]() para generar los informes de cobertura de las pruebas unitarias

Después de clonar el repositorio usted debería ejecutar el siguiente comando:

```bash
pre-commit install
git add .
pre-commit
git commit -m "lo que se desee comentar"
git push origin main
```


Dentro del repositorio base se tiene:
- inc
- src
- .clang-format
- .gitignore
- .pre-commit-config.yaml
- doxyfile
- LICENSE.txt
- makefile
- README.md

Se debe instalar ruby, gocv y ceedling
```bash
sudo apt-get install ruby cogv
sudo gem install ceedling
sudo apt install gcovr
```
Se instala gcovr si al tipear gcovr --version, nos muestra como comando desconocido.

Ahora iniciamos un nuevo proyecto ceedling, es importante no tener creado la carpeta test y tampo tener el archivo project.yml. Luego de ejecutar el siguiente comando, buscar una plantilla de project.yaml completa.
``` bash
ceedling new .
```

Para ejecutar las pruebas unitarias se utiliza el siguiente comando:

```bash
ceedling test:all
```

Para generar el informe de cobertura de las pruebas se utiliza el siguiente comando:

```bash
ceedling clobber gcov:all utils:gcov
```

Para generar la documentación del proyecto se utiliza el siguiente comando:

```bash
make doc

```

Para compilar el proyecto se utiliza el siguiente comando:

```bash
make all

```

## Componente a testear

Se trata de una biblioteca que verifica si los comandos recibidos por I2C son permitidos por el slave. El slave sera el STM32G070CBT6 y el master una ORANGEPI5. Este pequeno componente abarca una parte de un proyecto donde se requiere enviar comandos I2C al micro para que este realice acciones.

### Test a realizar
- [x] La funcion *validar_comando* retorna un 1 si el comando que se le pasa pertenece a la lista de comandos predefinidos.
- [x] La funcion *validar_comando* retorna un 0 si el comando que se le pasa no pertenece a la lista de comandos predefinidos.
- [x] Inicializar un metadata con valores randonds y probar que una funcion lo inicialice con todos sus campos en cero.
- [x] Pasar un buffer de 4 bytes con un 5to byte que contiene el XOR De todos los bytes incorrectos y verificar si la funcion returno un cero para este caso
- [x] Pasar un buffer de 4 bytes con el XOR correcto y verificar si la funcion retorna un 1 en este caso.
- [x] Verificar si la funcion ascii_to_int convierte correctamente el ascii a int.
- [x] Pasar un valor fuera de rango de la funcion ascii_to_int para ver si retorna un cero.
