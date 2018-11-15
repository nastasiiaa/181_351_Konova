// Lab10_exe.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "..\library\lib.h"
#include <iostream>
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



*/