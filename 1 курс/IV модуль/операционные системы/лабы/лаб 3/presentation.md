---
## Front matter
lang: ru-RU
title: Лабораторная работа №3
subtitle: Выполнила: Маслова Анастасия, НКНбд-01-21
author: |
	Маслова Анастасия, НКНбд-01-21\inst{1}
institute: |
	\inst{1}RUDN University, Moscow, Russian Federation
date: NEC--2021, 30.04.2022, Russia, Moscow

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

Получить практические навыки работы с легковесным языком разметки Markdown, научится оформлять с его помощью отчеты.

## Задание:

- Сделать отчёт по предыдущей лабораторной работе в формате Markdown.
- В качестве отчёта предоставить отчёты в 3 форматах: pdf, docx и md (в архиве, поскольку он должен содержать скриншоты, Makefile и т.д.)

## Ход работы

Сначала я открыла шаблон отчета на github, и начала редактировать его в соответствии с инструкциями и требованиями, используя теоретические сводки, приведенные в лабораторной работе (рис.1-2). Далее с помощью pandoc я преобразовала файл отчета из .md в .docx, используя команду **pandoc report.md -o report.docx** (рис.3). После этого я, преобразовав в docx в pdf, отправила оба файла отчета в репозиторий (рис.4-6). 

## рис.1 Оформление кода и списков в markdown
![рис.1](https://github.com/asmaslova/study_2021-2022_os-intro/blob/master/labs/lab03/report/image/1.jpg)

## рис.2 Оформление ссылок и картинок в markdown
![рис.2](https://github.com/asmaslova/study_2021-2022_os-intro/blob/master/labs/lab03/report/image/2.jpg)

## рис.3 Преобразование файла markdown в docx с помощью pandoc
![рис.3](https://github.com/asmaslova/study_2021-2022_os-intro/blob/master/labs/lab03/report/image/3.jpg)

## рис.4 Отправка report.docx в репозиторий
![рис.4](https://github.com/asmaslova/study_2021-2022_os-intro/blob/master/labs/lab03/report/image/4.jpg)

## рис.5 Преобразование .docx в pdf
![рис.5](https://github.com/asmaslova/study_2021-2022_os-intro/blob/master/labs/lab03/report/image/5.jpg)

## рис.6 Отправка .pdf в репозиторий
![рис.6](https://github.com/asmaslova/study_2021-2022_os-intro/blob/master/labs/lab03/report/image/6.jpg)

## Выводы

В результате лабораторной работы я получила навыки работы с markdown и научилась правильно оформлять отчеты.

## Используемые источники
[Операционные системы. Лабораторная работа №3](https://esystem.rudn.ru/pluginfile.php/1383171/mod_resource/content/3/003-lab_markdown.pdf)
