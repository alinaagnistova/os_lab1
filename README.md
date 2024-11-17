## Операционные системы 
### Лабораторная работа №1
#### Вариант: Windows ema-serach-str sort </br>
#### Задание </br>
#### Задание Часть 1. Запуск программ </br>

Необходимо реализовать собственную оболочку командной строки - shell. Выбор ОС для реализации производится на усмотрение студента. Shell должен предоставлять пользователю возможность запускать программы на компьютере с 
переданными аргументами командной строки и после завершения программы показывать реальное время ее работы (подсчитать самостоятельно как «время завершения» – «время запуска»). </br>

#### Задание Часть 2. Мониторинг и профилирование </br>

Разработать комплекс программ-нагрузчиков по варианту, заданному преподавателем. Каждый нагрузчик должен, как минимум, принимать параметр, который определяет количество повторений для алгоритма, указанного в задании. 
Программы должны нагружать вычислительную систему, дисковую подсистему или обе подсистемы сразу. Необходимо скомпилировать их без опций оптимизации компилятора.
Перед запуском нагрузчика, попробуйте оценить время работы вашей программы или ее результаты (если по варианту вам досталось измерение чего либо).
Постарайтесь обосновать свои предположения. Предположение можно сделать, основываясь на свой опыт, знания ОС и характеристики используемого аппаратного обеспечения.
Запустите программу-нагрузчик и зафиксируйте метрики ее работы с помощью инструментов для профилирования. Сравните полученные результаты с ожидаемыми. Постарайтесь найти объяснение наблюдаемому.
Определите количество нагрузчиков, которое эффективно нагружает все ядра процессора на вашей системе. Как распределяются времена  USER%, SYS%, WAIT%, а 
также реальное время выполнения нагрузчика, какое количество переключений контекста (вынужденных и невынужденных) происходит при этом?
Увеличьте количество нагрузчиков вдвое, втрое, вчетверо. Как изменились времена, указанные на предыдущем шаге? Как ведет себя ваша система?
Объедините программы-нагрузчики в одну, реализованную при помощи потоков выполнения, чтобы один нагрузчик эффективно нагружал все ядра вашей системы. 
Как изменились времена для того же объема вычислений? Запустите одну, две, три таких программы.
Добавьте опции агрессивной оптимизации для компилятора. Как изменились времена? На сколько сократилось реальное время исполнения программы нагрузчика? </br>

#### Ограничения

Программа (комплекс программ) должна быть реализован на языке C, C++.
Дочерние процессы должны быть созданы через заданные системные вызовы выбранной операционной системы, с обеспечением корректного запуска и и завершения процессов.  
Запрещено использовать высокоуровневые абстракции над системными вызовами. Необходимо использовать, в случае Unix, процедуры libc. </br>

#### Предположения о свойствах программ нагрузчиков
`ema-serach-str`: нагрузка на диск из-за множества операций чтения. Показатель USER% будет низким, потому что программа не выполняет сложных вычислений. 
SYS% будет высоким, так как системные вызовы (ввод-вывод) занимают значительное время. WAIT% (время ожидания) также будет значительным, так как процесс ожидает завершения операций чтения с диска. </br>

`sort`: USER% будет высоким, так как большая часть времени программы тратится на выполнение вычислений. WAIT% не должен становиться значительным, так как нет работы с диском. SYS% будет низким, так как операции ввода-вывода есть только в начале программы. Из ожидаемых системных вызовов остается только работа с памятью. </br>

#### Средства мониторинга
- Resmon – для мониторинга диска.
- Procexp – для отслеживания USER%, SYS% и переключений контекста.
- Диспетчер задач – для мониторинга процессора и диска. 
 #### Результаты измерений
 `ema-serach-str`  </br>
 1 нагрузчик
![image](https://github.com/user-attachments/assets/ed0d49d0-d154-4d32-a183-b9c40453a4a6)
 ![image](https://github.com/user-attachments/assets/6510c518-1b01-48cc-873e-86c58803cdd7)
 ![image](https://github.com/user-attachments/assets/16f96d3c-4d95-435b-a08f-140599e3b123)
 ![image](https://github.com/user-attachments/assets/a97a3b59-5d0e-4b6b-a395-c8f1f6c1892b)
 ![image](https://github.com/user-attachments/assets/24002b28-f4ad-4bd7-acb2-d03608a461a5)

![image](https://github.com/user-attachments/assets/64179d50-b73b-46bc-9814-95112fa593d1)
![image](https://github.com/user-attachments/assets/80b842ea-8ddd-428e-b4b7-3165b97a39bf)
![image](https://github.com/user-attachments/assets/32d1d0c7-a539-45b6-a8c3-5987bb040d9e)
![image](https://github.com/user-attachments/assets/f0c07855-d1d6-4f59-b2cc-047a4c15d0a9)

3 нагрузчика



 
