# Chess
Программное обеспечение для игры в шахматы в консоли.

<!--Блок информации о репозитории в бейджах-->
<!--[![Github stats](https://img.shields.io/github/downloads/Sk9l9tik/Chess/total.svg?style=for-the-badge&color=red)](https://somsubhra.github.io/github-release-stats/?username=Sk9l9tik&repository=Chess)-->
![Static Badge](https://img.shields.io/badge/Sk9l9tik-Chess-Chess)
![GitHub top language](https://img.shields.io/github/languages/top/Sk9l9tik/Chess)
![GitHub](https://img.shields.io/github/license/Sk9l9tik/Chess)
![GitHub Repo stars](https://img.shields.io/github/stars/Sk9l9tik/Chess)
![GitHub issues](https://img.shields.io/github/issues/Sk9l9tik/Chess)

<!--Установка-->

## Установка под Windows через CMake

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


## Установка под Windows через Visual Studio

У вас должны быть установлены [зависимости проекта](https://github.com/Sk9l9tik/Chess#зависимости)

1. Клонирование репозитория 

```git clone https://github.com/Sk9l9tik/Chess.git```

2.  Перейти в директорию Chess.

```cd Chess```

3. Открыть проект Chess.sln

5. Выбрать тип сборки Release

6. Запустить борку, кликнув зеленый треугольник

![](https://sun9-42.userapi.com/impg/XDh7oGFxF4vIQ3xZUKq1jtKSLkvGYi7HowQX3g/9geXqDLGCAo.jpg?size=393x34&quality=96&sign=abd09b4a2299b911654eccc38af25726&type=album)

7. Запустится программа  Chess.exe, расположеная по пути ```x64/Release```


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
Пользовательскую документацию можно получить по [этой ссылке](./docs/ru/index.md).
[Релизы программы](https://github.com/Sk9l9tik/Chess).


<!--Поддержка-->
## Поддержка
Если у вас возникли сложности или вопросы по использованию пакета, создайте [обсуждение](https://github.com/Sk9l9tik/Chess/issues/new/choose) в данном репозитории.

<!--зависимости-->
## Зависимости
Эта программа написана на С. Для ее сборки нужен компилятор языка С/С++ ([gcc](https://gcc.gnu.org), [clang](clang.llvm.org) или компилятор Visual Studio) и [CMake](cmake.org). Для корректного отображения символов шахматных фигур должен быть установлен поддерживающий их шрифт. Рекомендуется использовать шрифт _[DejaVu Sans Mono](https://fonts-online.ru/fonts/dejavu-sans-mono)_. Позднее в обновлении появится установщик, который автоматически будет устанавливать необходимые зависимости. На даннывй момент программа не поддерживает символы шахматных фигру в unix системах.
Процесс сборки и запуска описан [здесь](https://github.com/Sk9l9tik/Chess#установка). Если у вас возникли какие-то проблемы, то напишите в [поддержку](https://github.com/Sk9l9tik/Chess#поддержка)
