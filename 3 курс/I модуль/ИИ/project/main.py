# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

#Создать скрапер новостей, касающихся развития медицины в РФ, льгот для мед. работников
#преподавателей ВУЗа на основе токенов: «врач, препод, медсестр, рак, инсульт, …». Полученные новости
#структурировать на html странице в порядке: картинка – текст. Ссылки для скрапинга:
#https://medportal.ru/mednovosti/ https://minobrnauki.gov.ru/press-center/ https://rscf.ru/news/
#https://medvestnik.ru/content/roubric/medicine Предполагаемые библиотеки: bs4, requests. Язык: Python 3.9+. Часть 2:
#Составьте словарь уникальных слов в тексте публикаций из части 1, отфильтруйте предлоги/союзы и нарисуйте
#график частотности слов. Часть 3: Произведите замеры важности слов на основе TF-IDF меры. Примените
#рекуррентную сеть для классификации тематики новостей.



def print_hi(name):
    # Use a breakpoint in the code line below to debug your script.
    print(f'Hi, {name}')  # Press Ctrl+F8 to toggle the breakpoint.


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    print_hi('PyCharm')

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
