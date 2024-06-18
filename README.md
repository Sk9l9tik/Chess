# Chess
Программное обеспечение для игры в шахматы в консоли.

<!--Блок информации о репозитории в бейджах-->
<!--[![Github stats](https://img.shields.io/github/downloads/Sk9l9tik/Chess/total.svg?style=for-the-badge&color=red)](https://somsubhra.github.io/github-release-stats/?username=Sk9l9tik&repository=Chess)-->
![Static Badge](https://img.shields.io/badge/Sk9l9tik-Chess-Chess)
![GitHub top language](https://img.shields.io/github/languages/top/Sk9l9tik/Chess)
![GitHub](https://img.shields.io/github/license/Sk9l9tik/Chess)
![GitHub Repo stars](https://img.shields.io/github/stars/Sk9l9tik/Chess)
![GitHub issues](https://img.shields.io/github/issues/Sk9l9tik/Chess)
![](https://p16-bot-sign-va.ciciai.com/tos-maliva-i-58bqazb02t-us/99ae837a4f804b97875105a3a1ff091e.png~tplv-58bqazb02t-image.image?rk3s=68e6b6b5&x-expires=1721287377&x-signature=d0jcgShOVnJda7ivEHJIrtN7ij0%3D)
<!--Установка-->

## Установка под Windows

У вас должны быть установлены [зависимости проекта](https://github.com/Sk9l9tik/Chess#зависимости)

1. Клонирование репозитория 

```git clone https://github.com/Sk9l9tik/Chess.git```

2.  Перейти в директорию Chess.

```cd Chess```

3.  Сгенерировать сборку

```cmake -S . -B build```

4. Сбилдить папку build

```cmake --build build --config Release```

5. Перейти в папку build, потом Release

```cd build/Release```

6.  Запустить файл Chess.exe

```./Chess.exe```

## Установка под Linux (Пока не поддерживаются символы фигур)
У вас должны быть установлены [зависимости проекта](https://github.com/Sk9l9tik/Chess#зависимости)

1. Клонирование репозитория 

```git clone https://github.com/Sk9l9tik/Chess.git```

2.  Перейти в директорию Chess.

```cd Chess```

3.  Сгенерировать сборку

```cmake -DCMAKE_BUILD_TYPE=Release -S . -B build```

4. Сбилдить папку build

```cmake --build build```

5. Перейти в папку build

```cd build```

6.  Запустить исполняемый файл "Chess.out"

```./Chess.out```


<!--Пользовательская документация-->
## Документация (В разработке)
Пользовательскую документацию можно получить по [этой ссылке](./docs/ru/index.md).[Релизы программы]: https://github.com/OkulusDev/Sk9l9tik/Chess


<!--Поддержка-->
## Поддержка
Если у вас возникли сложности или вопросы по использованию пакета, создайте [обсуждение](https://github.com/Sk9l9tik/Chess/issues/new/choose) в данном репозитории.

<!--зависимости-->
## Зависимости
Эта программа написана на С. Для ее сборки нужен компилятор языка С/С++ ([gcc](https://gcc.gnu.org) [clang](clang.llvm.org) или компилятор Visual Studio) и [CMake](cmake.org). Для корректного отображения символов шахматных фигур должен быть установлен поддерживающий их шрифт. Рекомендуется использовать шрифт _[DejaVu Sans Mono](https://fonts-online.ru/fonts/dejavu-sans-mono)_. Позднее в обновлении появится установщик, который автоматически будет устанавливать необходимые зависимости. На даннывй момент программа не поддерживает символы шахматных фигру в unix системах.
Процесс сборки и запуска описан [здесь](https://github.com/Sk9l9tik/Chess#установка). Если у вас возникли какие-то проблемы, то напишите в [поддержку](https://github.com/Sk9l9tik/Chess#поддержка)