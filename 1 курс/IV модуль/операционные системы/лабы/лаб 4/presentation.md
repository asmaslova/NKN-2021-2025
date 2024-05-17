---
## Front matter
lang: ru-RU
title: Лабораторная работа №4
author: |
	Maslova Anastasia{1}
institute: |
	\inst{1}RUDN University, NKNbd-01-21, Moscow, Russian Federation

## Formatting
toc: false
slide_level: 2
theme: metropolis
header-includes: 
 - \metroset{progressbar=frametitle,sectionpage=progressbar,numbering=fraction}
 - '\makeatletter'
 - '\beamer@ignorenonframefalse'
 - '\makeatother'
aspectratio: 43
section-titles: true
---


## Цель работы:

Приобретение практических навыков взаимодействия пользователя с системой посредством командной строки.

### Ход работы

## 1.
С помощью команды pwd я определила полное имя домашнего каталога (рис.1).

## 2. 
Далее я перешла в каталог /tmp, вывела на экран его содержимое (рис.1), а также попробовала использовать различные опции *ls* (рис.2-5). 

![рис.1](https://github.com/asmaslova/study_2021-2022_os-intro/blob/master/labs/lab04/presentation/images/1.png) 

рис.1 Результат работы функции *pwd* и переход в каталог tmp

##
![рис.2](https://github.com/asmaslova/study_2021-2022_os-intro/blob/master/labs/lab04/presentation/images/2.png) 

рис.2 Выполнение функции *ls* с опцией *-a*

##
![рис.3](https://github.com/asmaslova/study_2021-2022_os-intro/blob/master/labs/lab04/presentation/images/3.png) 

рис.3 Выполнение функции *ls* с опцией *-F*

##
![рис.4](https://github.com/asmaslova/study_2021-2022_os-intro/blob/master/labs/lab04/presentation/images/4.png) 

рис.4 Выполнение функции *ls* с опцией *-l*

##
![рис.5](https://github.com/asmaslova/study_2021-2022_os-intro/blob/master/labs/lab04/presentation/images/5.png) 

рис.5 Выполнение функции *ls* с опцией *-alF*


##
После с помощью команды *ls -a* я обнаружила, что в каталоге /var/spool не существует подкаталог с именем cron (рис.6)

![рис.6](https://github.com/asmaslova/study_2021-2022_os-intro/blob/master/labs/lab04/presentation/images/6.png) 

рис.6 Поиск подкаталога cron в /var/spool


##
С помощью команды *ls -alF* я узнала, кто является владельцем файлов и подкаталогов (рис.7)

![рис.7](https://github.com/asmaslova/study_2021-2022_os-intro/blob/master/labs/lab04/presentation/images/7.png) 

рис.7 Выполнение функции *ls* с опцией *-alF* на корневом каталоге


## 3. 
В домашнем каталоге я создала новый каталог с именем newdir. В каталоге ~/newdir я создала новый каталог с именем morefun. В домашнем каталоге я создала одной командой три новых каталога с именами letters, memos, misk. Затем я удалила эти каталоги одной командой. Далее я попробовала удалить ранее созданный каталог ~/newdir командой rm, но не смогла, так как без спец. опций функция *rm* не может удалять каталоги. Далее я удалила каталог ~/newdir/morefun из домашнего каталога с помощью *rmdir --ignore-fail-on-non-empty* (рис.8).

##
![рис.8](https://github.com/asmaslova/study_2021-2022_os-intro/blob/master/labs/lab04/presentation/images/8.png) 

рис.8 Создание новых подкаталогов и попытка их удалить


## 4. 
С помощью команды man я определила, что с командой *ls* нужно использовать опцию *-R* для просмотра содержимого не только указанного каталога, но и подкаталогов,
входящих в него (рис.9-10).

##
![рис.9](https://github.com/asmaslova/study_2021-2022_os-intro/blob/master/labs/lab04/presentation/images/9.png) 

рис.9 Результат вывода *man ls*


##
![рис.10](https://github.com/asmaslova/study_2021-2022_os-intro/blob/master/labs/lab04/presentation/images/10.png) 

рис.10  Часть результата работы *ls -R*


## 5. 
С помощью команды man я определила, что опции *-t -l* функции *ls* позволяющет отсортировать по времени последнего изменения выводимый список содержимого каталога с развёрнутым описанием файлов (рис.11).

##
![рис.11](https://github.com/asmaslova/study_2021-2022_os-intro/blob/master/labs/lab04/presentation/images/11.png) 

рис.11 Выполнение функции *ls* с опциями *-t -l* на корневом каталоге


## 6. 
С помощью команды man я просмотрела описания следующих команд: cd, pwd, mkdir, rmdir, rm (рис.12-16).

##
![рис.12](https://github.com/asmaslova/study_2021-2022_os-intro/blob/master/labs/lab04/presentation/images/12.png) 

рис.12  Часть результата работы команды *man cd*


##
![рис.13](https://github.com/asmaslova/study_2021-2022_os-intro/blob/master/labs/lab04/presentation/images/13.png) 

рис.13  Часть результата работы команды *man pwd*


##
![рис.14](https://github.com/asmaslova/study_2021-2022_os-intro/blob/master/labs/lab04/presentation/images/14.png) 

рис.14  Часть результата работы команды *man mkdir*


##
![рис.15](https://github.com/asmaslova/study_2021-2022_os-intro/blob/master/labs/lab04/presentation/images/15.png) 

рис.15  Часть результата работы команды *man rmdir*


##
![рис.16](https://github.com/asmaslova/study_2021-2022_os-intro/blob/master/labs/lab04/presentation/images/16.png) 

рис.16  Часть результата работы команды *man rm*


## 7. 
Используя информацию, полученную при помощи команды history, я выполнила модификацию и исполнение нескольких команд из буфера команд (рис.17-18).

![рис.17](https://github.com/asmaslova/study_2021-2022_os-intro/blob/master/labs/lab04/presentation/images/17.png) 

рис.17 Результат работы функции *history*


##
![рис.18](https://github.com/asmaslova/study_2021-2022_os-intro/blob/master/labs/lab04/presentation/images/18.png) 

рис.18 Результаты работы модификаций функции *history*

## Вывод

В результате работы я получила навыки взаимодействия с системой через командную строку.

