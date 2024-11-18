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

![image](https://github.com/user-attachments/assets/f85684ba-9cae-419a-a802-393e64dee29d)
![image](https://github.com/user-attachments/assets/248c61fc-209f-4f50-bb14-4025642c5c6c)

![image](https://github.com/user-attachments/assets/a439fa32-0875-4177-ae0d-e234ea5fc0c8)


![image](https://github.com/user-attachments/assets/bd9dbe39-8af3-4ff3-a633-d47b6a2c9f20)
![image](https://github.com/user-attachments/assets/bd9da691-f824-468a-8c12-6194a13f05a4)
//1

![image](https://github.com/user-attachments/assets/d1df9443-ab4e-4cab-921d-a1a453b93bc7)

 ![image](https://github.com/user-attachments/assets/368cbb20-2a1b-4450-af32-9a4fdf791cb8)
 
![image](https://github.com/user-attachments/assets/411f4b8c-41e6-4e86-a089-385adc870d03)
//3
![image](https://github.com/user-attachments/assets/a0c12965-4a3b-430a-922b-f5b902a37dcf)
![image](https://github.com/user-attachments/assets/cd0fc131-88cc-4983-96b0-aca67cb3fefb)
![image](https://github.com/user-attachments/assets/128da663-112b-4e0f-9bc2-c8a36f04a8be)
//5
![image](https://github.com/user-attachments/assets/e60592f9-33e9-4039-b402-4b56ec77a3d8)
![image](https://github.com/user-attachments/assets/4edfcdf2-9d82-4df6-87f2-2306b7101dc1)
![image](https://github.com/user-attachments/assets/030c5eff-46dc-47fe-bccc-8ff91e3309ff)
![image](https://github.com/user-attachments/assets/39280c9d-48f3-48e7-931e-8ee7cd9cc079)
![image](https://github.com/user-attachments/assets/8af1379b-de07-4e13-85ab-aeaf888fbec3)

![image](https://github.com/user-attachments/assets/149a0281-6e8e-4671-823a-cb91d72ddfac)

sort
//1
![image](https://github.com/user-attachments/assets/f992008f-ef7e-4371-afc7-ba6e51b99a8b)
![image](https://github.com/user-attachments/assets/2dd123e4-bc29-4aac-877b-ad9d84c05253)
![image](https://github.com/user-attachments/assets/e3ede237-9e93-4fec-bb28-b4c445025b9c)
![image](https://github.com/user-attachments/assets/17fe6221-9869-46f6-830f-2c15bdeb5f58)
//1 148
![image](https://github.com/user-attachments/assets/31bed94d-42fb-4ffa-938e-b521262236e5)
![image](https://github.com/user-attachments/assets/e7f5a5a2-a66b-4b8c-81ce-a07916f3405b)
![image](https://github.com/user-attachments/assets/0cf572d2-91f5-4a4f-9a0b-7c75033f5b7e)
//10

![image](https://github.com/user-attachments/assets/a1a8ef6d-54b6-4650-8c9e-904722767bd3)
![image](https://github.com/user-attachments/assets/ce4b6c57-f194-4b68-b400-18738a89bc5f)
![image](https://github.com/user-attachments/assets/3e4fe686-9bfa-466e-ae99-498df696f464)
//15
А больше 10 запустить не выйдет, ноут не вывозит....
multi-bench:
//1
![image](https://github.com/user-attachments/assets/6e9ed31a-cc2a-4d8c-b433-e2e41eda23c1)
![image](https://github.com/user-attachments/assets/99a048b9-0ef3-49da-a907-61631daf116b)
![image](https://github.com/user-attachments/assets/3a5d7abd-6aed-48aa-a3d1-66c180835f29)
![image](https://github.com/user-attachments/assets/86f8cb89-72da-4c16-ba7c-6fddbbe8902f)
//3
![image](https://github.com/user-attachments/assets/93dac60c-04d0-4fbd-a7a0-ea252cb38827)
![image](https://github.com/user-attachments/assets/5ce8dbe5-b4d0-4b91-a813-04b7a7091a32)
![image](https://github.com/user-attachments/assets/955e9cbe-ab8a-4244-8403-a93ac70602ff)
![image](https://github.com/user-attachments/assets/3f1dbe50-520b-4883-ad43-f99d3450d85f)
//5
![image](https://github.com/user-attachments/assets/b1dc4c38-c8fb-4f64-9456-150d6cfbbafc)
![image](https://github.com/user-attachments/assets/5748efea-95a1-4c6a-9086-99aae3f341fc)
![image](https://github.com/user-attachments/assets/2ff6b5bd-0976-4cb3-8f19-e88340c9c492)
![image](https://github.com/user-attachments/assets/3d56decc-7474-4068-9b25-523d352231c0)

С оптимизацией:
//1
![image](https://github.com/user-attachments/assets/acacd58f-d3bd-44ae-8460-300aa18641bd)
//2
![image](https://github.com/user-attachments/assets/92e60733-1be4-42b2-a813-863e9a3ea551)
//3
![image](https://github.com/user-attachments/assets/6df0c4c0-f06a-4c09-b0b8-2ce7a162a381)







