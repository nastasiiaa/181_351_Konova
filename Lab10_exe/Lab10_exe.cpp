// Lab10_exe.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "..\library\lib.h"
//include "..\где лежит lib.h"

int main()

{
	setlocale(LC_ALL, "Russian");
	matrix a, b;

	a.input(); a.print();
	b.input(); b.print();

	(a + b).print();
	(a * b).print();
}

/*
Код из динамической библиотеки может использоваться одновременно многими приложениями
из одного и того же *.dll файла, загруженного в ОП

если несколько *.exe используют один и тот же *.dll, 
*.dll может быть единственным на машине  и использоваться всеми

по сути ОС представляет собой набор типовых наиболее часто используемых программами функций,
собранных в динамические библиотеки: функции для работы с файлами, с сетью, с устройствами
функции безопасности, менеджмент процессов и т.д.
прикладные приложения, работая на ОС, не нужждаются в собственном коде для таких тривиальных
операций 
преимущества
1. снижение размера приложений
2. унификация
3. безопасность  (варианты взаимодействия приложений с системными ресурсами: файлами, аппаратурой
ограничены типовым и безопасным набором

огромное количество сторонних, в т.ч. и открытых бесплатных библиотек собирается и подключается

2. статические библиотеки преимущества, недостатки

3.1 ДИНАМИЧЕСКИЕ БИБЛИОТЕКИ. ПОНЯТИЕ, ПРЕИМУЩЕСТВА, НЕДОСТАТКИ
Динамические бибилиотеки в виндовс имеют расширение dll (dinamic link library)
в линуксе so (sors object)

dll файлы поставляются отдельно одним и тем же dll файлом на машине пользователя, могут пользоваться 
несколько приложений одновременно (системные dll, библиотеки сред разработки)

преимущества

1. отдельным файлом могут пользоваться сразу несколько приложений
2. размер самого ехе файла не увеличивается при использовании библиотечных функций с длл в отличае от либ
3. длл может быть загружена в память только в тот момент, когда она потребуется и затем выгружена
недостатки
1. хранятся в виде отдельных файлов и могут потеряться
2. более сложная структура кода, более сложное подключение в ехе
3. тщательно следить за версией
4. требуется наличие инстолятора для развертываания нужных файлов на машине пользователя

3.2. Два типа подключения dll 
статическое и динамическое связывание
Статическое связывание: длл грузится в оп сразу при запускке приложения 
при отсутсвии длл происодит сбой, приложение не работает
также такой подход требует наличие трех файлов:
саму готовую dll, header, промежуточный либ библиотеки которая хранит для сборщика приложения
адреса используемы функций в dll 

 Динамическое подключение длл: длл грузится не при запуске приложения в тот момент, который определил 
 программист в коде с помощью вызова спец функции load library 
 третий либ файл с таблицей соответствия не нужен
 функции внутри длл ищутся по имени системной функции 
 второй функцией внутри загруженной длл ищем функции которые нам нужны - getprocadress
 преимущества 
 не нужен 3 файл с таблицей
 библиотека подключается по требованию в нужный момент рациональным образом (по необходимости)
 недостатки
 усложняется работа с кодомм в приложении

  3.3 подключение длл в проект приложения
  в случае статического связывания: 
  в иходных код подключается хедер с объявлениями 
  в настройки компановщика подключается либ с таблицей и определяется путь к либ
  длл должна быть размещена рядом с ехе либо в системных директориях
  в случае динамического связывания:
  в исходнй код приложения должен быть подключен хедер и длл должна лежать рядом с ехе
  в коде в нужный момент перед использованием какой либо из библиотечных файлов
  вызывается load library
  перед использованием любая билиотечная функция ищется с помощью getprocadress

  3.4. точка входа бибилотеки
  в длл можно определить специальную функцию 
  дллмейн, которая будет вызываться автоматически при загрузке библиотеки 

 1. Библиотеки, подключаемые в виде исходных кодов (header-only)
Как правило, файл с расширением *.h или *.hpp, либо пара файлов
 *.h и *.cpp с одинаковым названием. Содержат объявления и определения
 переменных, констант, функций и классов. Подключаются в приложение
 через #include заголовочного файла
 В *.h как правило приводится объявление сущностей, а в *.cpp раскрывается
 определение (реализация). Такой подход повышает читаемость структурированность
 кода, однако ничто не мешает реализацию (определение) также поместить в *.h файл
 Преимущества:
 1) Исходный код открыть
 2) его всегда можно модифицировать и исправить
 3) простота подключения
 Недостатки:
 1) пересборка всей библиотеки при каждой пересборке приложения, замедление сборки
 2. СТАТИЧЕСКИЕ БИБЛИОТЕКИ
 2.1
 *.lib (англ. library) - файлы статически подключаемых библиотек
 Недостаток прошлого подхода компенсируется, если библиотечный код предварительно
 скомпилировать и построить, и уже скомпилированный бинарный файл
 подключать в приложение
 Преимущества:
 1) более быстрая пересборка проекта
 2) так как код из библиотеки встраивается в *.exe, он не потеряется
 Недостатки:
 1) бинарники *.lib надо сначала найти или построить самим из исходников
 2) бинарная несовместимость: *.lib должны подходить под
 -платформу (ОС и окружение)
 -аппаратура (тип процессора и разрядность)
 -компилятор и т.д.
 3) затруднительность аудита безопасности бинарных файлов
 по данной причине библиотеки, связанные с ИБ, шифрованием, защитой
 распространяются ТОЛЬКО в виде исходников, из которых разработчик
 на месте должен сначала построить *.lib
 в *.nix системах аналог *.lib файла имеет расширение *.a
 4) размер EXE файла увеличивается, так как код функций из *.lib
 дописывается к EXE
 2.2 ПОДКЛЮЧЕНИЕ СТАТИЧЕСКОЙ БИБЛИОТЕКИ
 1. При отсутствии бинарников исходники библиотеки собирать в
 *.lib(настройки -> "Тип конфигурации")
 2. В настройках проекта VS "Компоновщик" -> "Ввод"
 добавить название файла библиотеки *.lib
 3. В "Каталоги VC++" добавить путь к библиотеке
 4. В исходниках вашего проекта объявить функцию со спецификатором extern
 или добавить *.h файл библиотеки
 Сведение приложения и подключенной статической библиотеки
 производится уже после компиляции, на следующем этапе - этапе сборки (linking)
 Линкер ищет функцию по имени в *.lib-файле. Если находит - берёт машинный код
 функции и дописывает к *.exe. Если нет - возникает ошибка LNK2019 или
 схожие
 3. ДИНАМИЧЕСКИЕ БИБЛИОТЕКИ
 *.dll (Dynamic Link Library) - файлы динамически подключаемых библиотек
 *.so (англ. source object) - динамические библиотеки в Linux

 Библиотека *.lib или *.dll - файл, содержащий готовый машинный код для
 многократного повторного использования
 Код из статических библиотек помещается в *.exe в момент его сборки (после компиляции)
 и далее является частью самого *.exe

 если несколько *.exe используют один и тот же *.lib код дублируется в каждом *.exe

 Код из динамической библиотеки может использоваться одновременно многими приложенинями
 из одного и того же *.dll файла, загруженного в ОП
 если нескольког *.exe используют один и тот же *.dll, *.dll может быть единственным на машине
 и использоваться всеми

 по сути ОС представляет собой набор типовых наиболее часто используемых программами функций,
 собранных в динамические библиотеки: функции для работы с файлами, с сетью, с устройствами,
 функции безопасности, менеджмент процессов и т.д.
 прикладные приложения, работая на ОС, не нуждаются в собственном коде для таких тривиальных операций
 преимущества 1) снижение размера приложений 2) унификация 3) безопасность (варианты взаимодействия
 приложений с системными ресурсами: файлами, аппаратурой ограничены типовым и безопасным набором
 системных функций)
 огромное количество сторонних, в т.ч. и открытых бесплатных библиотек собирается и подключается
 именно в виде lib или dll (PoDoFo - для работы и криптографической подписи PDF, множество эталонных
 библиотек libjpeg, libpng для работы со сжатием изображений, криптографические библиотеки OpenSSL, OpenSSH)

*/